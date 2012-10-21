#include "Game.hpp"
#include "Entity.hpp"
#include "Map.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include "Player.hpp"
#include <iostream> // debug



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
        sf::Time t;
        timer.restart();

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

	Player* player = new Player(sf::Vector2f(32,128), "player1.png"); // TODO: erstatt position med start position, global
	sf::Keyboard::Key keys[5] = {sf::Keyboard::Left, sf::Keyboard::Up, sf::Keyboard::Right, sf::Keyboard::Down, sf::Keyboard::RControl};
	player->setKeys(keys);
	AddEntity(player);

	player = new Player(sf::Vector2f(320, 0), "player2.png");
    sf::Keyboard::Key keys2[5] = {sf::Keyboard::A, sf::Keyboard::W, sf::Keyboard::D, sf::Keyboard::S, sf::Keyboard::LControl};
    player->setKeys(keys2);
	AddEntity(player);

}

bool Game::Load( void )
{
	for (std::vector<Entity*>::iterator i = entities.begin(); i != entities.end(); ++i)
	{
		(*i)->Load();
	}
	return true;
}

void Unload( void )
{

}

void Game::Update( sf::Time delta )
{
    sf::Time t;
    for (std::vector<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it)
    {
        (*it)->Update(t); // må sende med map for collision testing, UGLY

        int x = (*it)->position.x;
        int y = (*it)->position.y;

        int vx = (*it)->vel.x;
        int vy = (*it)->vel.y;

        if ((*it)->type == Entity::TYPE_PLAYER)
        {
            // collision testing
            // RIGHT
            if (map->GetTileType(x+32+vx, y) == Tile::SOLID)
            {
                vx = 0;
                x = ((x/32)+1) * 32;
            }
            else if (map->GetTileType(x+vx, y) == Tile::SOLID)
            {
                vx = 0;
                x = (x/32) * 32;
            }
            else
                x += vx;

            // nede
            if (map->GetTileType(x, y+32+vy) == Tile::SOLID)
            {
                vy = 0;
                y = (y/32) * 32;
            }
            else if (map->GetTileType(x, y+vy) == Tile::SOLID)
            {
                vy = 0;
                y = (y/32) * 32;
            }
            else
                y += vy;

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
			entities.erase(i--);
		}
	}
}
