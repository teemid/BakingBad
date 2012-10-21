#include "Game.hpp"
#include "Entity.hpp"
#include "Map.hpp"
#include "Player.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <iostream> // debug

#include <windows.h>// DEBUG



// TODO: STATE-MACHINE

Game::Game( std::string title = "Untitled" )
{
	this->window = new sf::RenderWindow( sf::VideoMode( SCREEN_WIDTH, SCREEN_HEIGHT ), title );
	Initialize();
	Load();
	Run();
}

Game::~Game()
{
    delete window;
}

void Game::Run()
{
    while(window->isOpen())
    {
        sf::Time t = timer.restart();

        Update(t);
        Draw(t);

        // window close event
        sf::Event event;
        while(window->pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
					{
                    window->close();
					break;
					}

                default: ; // do nothing
            }
        }

        while(timer.getElapsedTime().asMilliseconds() < 1000/FPS);
    }
}
sf::Texture playerTexture;
void Game::Initialize( void )
{
	map = new Map();
	AddEntity( map );

	itemManager = new ItemManager();

	Player* player = new Player(sf::Vector2f(500.0f,0.0f), "player1.png"); // TODO: erstatt position med start position, global
	sf::Keyboard::Key keys[5] = {sf::Keyboard::Left, sf::Keyboard::Up, sf::Keyboard::Right, sf::Keyboard::Down, sf::Keyboard::RControl};
	player->setKeys(keys);
	AddEntity(player);

	player = new Player(sf::Vector2f(500.0f,0.0f), "player2.png"); // TODO: erstatt position med start position, global
	sf::Keyboard::Key keys2[5] = {sf::Keyboard::A, sf::Keyboard::W, sf::Keyboard::D, sf::Keyboard::S, sf::Keyboard::LControl};
	player->setKeys(keys2);
	AddEntity(player);

}

bool Game::Load( void )
{
	// TODO: haaaaaaaaaaaaaaaaaaaaaaaaaaard coded
	itemManager->Load("items.txt");
	AddEntity(itemManager->SpawnItem("wheat", sf::Vector2f(400.0f, 300.0f), sf::seconds(5.0f)));
	AddEntity(itemManager->SpawnItem("raisins", sf::Vector2f(64.0f, 64.0f), sf::seconds(10.0f)));
	AddEntity(itemManager->SpawnItem("bacon", sf::Vector2f(128.0f, 128.0f), sf::seconds(15.0f)));
	AddEntity(itemManager->SpawnItem("bread", sf::Vector2f(128.0f, 32.0f), sf::seconds(20.0f)));

	for (std::vector<Entity*>::iterator i = entities.begin(); i != entities.end(); ++i)
	{
		(*i)->Load();
	}
	return true;
}

void Unload( void )
{
	// TODO: does anything need to be deallocated?
}

void Game::Update( sf::Time delta )
{
    for (std::vector<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it)
    {
        (*it)->Update(delta); // må sende med map for collision testing, UGLY

        float x = (*it)->position.x;
        float y = (*it)->position.y;

        int vx = (*it)->vel.x;
        int vy = (*it)->vel.y;

        if ((*it)->type == Entity::TYPE_PLAYER)
        {
            // To the right --> | x+width
            int w = 24; // skal være player width og height
            int h = 24;
            int playerSpeed = 8; // skal være speed som ligger i player, men ikke tilgang slik det er nå

            x += vx;
            y+=vy;

            if (vx > 0)
            {
                if (map->GetTileType(x+w, y) == Tile::SOLID &&
                    map->GetTileType(x+w, y+h) == Tile::SOLID)
                    x = (int)(x/32) * 32 + (32.0f-w)/2;
                else if (map->GetTileType(x+w, y+h) == Tile::SOLID) // bare nederste
                {
                    y -= playerSpeed; // her bør man bruke speed fra player eller noe
                    x -= vx;
                }
                else if (map->GetTileType(x+w, y) == Tile::SOLID) // bare øverste
                {
                    y += playerSpeed;
                    x -= vx;
                }
            }
            else if (vx < 0)
            {

                if (map->GetTileType(x, y) == Tile::SOLID &&
                                    map->GetTileType(x, y+h) == Tile::SOLID)
                    x = ((int)(x/32) + 1) * 32 + (32.0f-w)/2;
                else if (map->GetTileType(x, y+h) == Tile::SOLID) // bare nederste
                {
                    y -= playerSpeed;
                    x -= vx;
                }
                else if (map->GetTileType(x, y) == Tile::SOLID) // bare øverste
                {
                    y += playerSpeed;
                    x-=vx;
                }
            }

            if (vy > 0)
            {
                if (map->GetTileType(x, y+h) == Tile::SOLID && map->GetTileType(x+w, y+h) == Tile::SOLID) // begge
                    y = ((int)(y/32) * 32) + (32.0f-h)/2;
                else if (map->GetTileType(x, y+h) == Tile::SOLID) // bare mot venstre
                {
                    x += playerSpeed;
                    y-=vy;
                }
                else if (map->GetTileType(x+w, y+h) == Tile::SOLID) // bare mot høyre
                {
                    x -= playerSpeed;
                    y-=vy;
                }


            }
            else if (vy < 0)
            {
                if (map->GetTileType(x, y) == Tile::SOLID && map->GetTileType(x+w, y) == Tile::SOLID) // begge
                    y = (((int)(y/32) + 1) * 32) + (32.0f-h)/2;
                else if (map->GetTileType(x, y) == Tile::SOLID) // bare mot venstre
                {
                    x += playerSpeed;
                    y -= vy;
                }
                else if (map->GetTileType(x+w, y) == Tile::SOLID)
                {
                    x -= playerSpeed;
                    y -= vy;
                }
            }

            (*it)->position.x = x;
            (*it)->position.y = y;
        }
    }

    // collision testing
    // move stuff

	RemoveEntities();
}

void Game::Draw( sf::Time delta )
{
    window->clear();

    sf::Time t;
    for (std::vector<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it)
        (*it)->Draw(t, window);

    window->display();
}

// Slett denne DrawSprite :P
void Game::DrawSprite(sf::Sprite *sprite)
{
    window->draw(*sprite);
}

void Game::AddEntity(Entity * entity)
{
    entities.push_back(entity);
}

void Game::RemoveEntities()
{
    // Må skrives. Delete entity og fjern fra vector (entities)
	for (std::vector<Entity *>::iterator i = entities.begin(); i != entities.end(); ++i)
	{
		if ((*i)->IsExpired())
		{
			Entity * temp = *i;
			entities.erase(i--);

			delete temp;
		}
	}
}
