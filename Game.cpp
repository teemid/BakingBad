#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>

#include "Game.hpp"
#include "Player.hpp"

// TODO: STATE-MACHINE

Game::Game(const std::string title = "Untitled")
{
	// Create a window and a render context
	this->window = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), title);
	// Initialize resources
	Initialize();
	// Load game assets
	Load();
	// Enter the game loop
	Run();
}

Game::~Game(void)
{
    delete window;
}

void Game::Run(void)
{
	// main game loop
    while(window->isOpen())
    {
        sf::Time t = timer.restart();

        Update(t);
        Draw(t);

        // Handle events
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

                default: continue;
            }
        }

		// Stall for framerate control
        while(timer.getElapsedTime().asMilliseconds() < 1000/FPS);
    }
}

void Game::Initialize(void)
{
	map = new Map();
	AddEntity(map);

	itemManager = new ItemManager();

	// Player initialization
	Player * player;
		
	player = new Player(sf::Vector2f(500.0f, 0.0f), "player1.png"); // TODO: erstatt position med start position, global
	sf::Keyboard::Key keys[5] = {sf::Keyboard::Left, sf::Keyboard::Up, sf::Keyboard::Right, sf::Keyboard::Down, sf::Keyboard::RControl};
	player->SetKeys(keys);
	AddEntity(player);

	// Create and add the second player to entities
	player = new Player(sf::Vector2f(500.0f, 0.0f), "player2.png"); // TODO: erstatt position med start position, global
	sf::Keyboard::Key keys2[5] = {sf::Keyboard::A, sf::Keyboard::W, sf::Keyboard::D, sf::Keyboard::S, sf::Keyboard::LControl};
	player->SetKeys(keys2);
	AddEntity(player);
}

const bool Game::Load(void)
{
	// TODO: HARD coded
	itemManager->Load("items.txt");

	// loop through 
	for (std::vector<Entity *>::iterator i = std::begin(entities); i != std::end(entities); ++i)
	{
		(*i)->Load();
	}

	return true;
}

void Unload(void)
{
	// TODO: does anything need to be deallocated?
}

void Game::Update(const sf::Time delta)
{
	SpawnItems(delta);

    for (std::vector<Entity *>::iterator it = std::begin(entities); it != std::end(entities); ++it)
    {
        (*it)->Update(delta); // må sende med map for collision testing, UGLY

		Player * player;

		sf::Vector2f p = (*it)->GetPosition();
		sf::Vector2f v = (*it)->GetVelocity();

        float x = p.x;
        float y = p.y;

        int vx = v.x;
        int vy = v.y;

        if ((*it)->GetEntityType() == EntityType::PLAYER)
        {
			player = static_cast<Player *>(*it);

			int w = player->GetWidth();
            int h = player->GetHeight();
            int playerSpeed = player->GetSpeed();

            x += vx;
            y += vy;

            if (vx > 0)
            {
                if (map->GetTileType(x + w, y    ) == TileType::SOLID &&
                    map->GetTileType(x + w, y + h) == TileType::SOLID)
				{
                    x = (int)(x / 32) * 32 + (32.0f - w) / 2;
				}
                else if (map->GetTileType(x + w, y + h) == TileType::SOLID) // bare nederste
                {
                    y -= playerSpeed; // her bør man bruke speed fra player eller noe
                    x -= vx;
                }
                else if (map->GetTileType(x + w, y) == TileType::SOLID) // bare øverste
                {
                    y += playerSpeed;
                    x -= vx;
                }
            } // vx > 0
            else if (vx < 0)
            {
                if (map->GetTileType(x, y    ) == TileType::SOLID &&
                    map->GetTileType(x, y + h) == TileType::SOLID)
				{
                    x = ((int)(x / 32) + 1) * 32 + (32.0f - w) / 2;
				}
                else if (map->GetTileType(x, y + h) == TileType::SOLID) // bare nederste
                {
                    y -= playerSpeed;
                    x -= vx;
                }
                else if (map->GetTileType(x, y) == TileType::SOLID) // bare øverste
                {
                    y += playerSpeed;
                    x -= vx;
                }
            } // vx < 0
            if (vy > 0)
            {
                if (map->GetTileType(x    , y + h) == TileType::SOLID && 
					map->GetTileType(x + w, y + h) == TileType::SOLID) // begge
				{
                    y = ((int)(y / 32) * 32) + (32.0f - h) / 2;
				}
                else if (map->GetTileType(x, y + h) == TileType::SOLID) // bare mot venstre
                {
                    x += playerSpeed;
                    y -= vy;
                }
                else if (map->GetTileType(x + w, y + h) == TileType::SOLID) // bare mot høyre
                {
                    x -= playerSpeed;
                    y -= vy;
                }
            } // vy > 0
            else if (vy < 0)
            {
                if (map->GetTileType(x, y) == TileType::SOLID && map->GetTileType(x + w, y) == TileType::SOLID) // begge
				{
                    y = (((int)(y / 32) + 1) * 32) + (32.0f - h) / 2;
				}
                else if (map->GetTileType(x, y) == TileType::SOLID) // bare mot venstre
                {
                    x += playerSpeed;
                    y -= vy;
                }
                else if (map->GetTileType(x + w, y) == TileType::SOLID)
                {
                    x -= playerSpeed;
                    y -= vy;
                }
            } // vy < 0

			player->SetPosition(sf::Vector2f(x, y));
		} // (*it)->GetEntityType() == EntityType::PLAYER
    }

	RemoveEntities();
}

void Game::SpawnItems(const sf::Time delta)
{
	itemManager->Update(delta);
	// Select a random id
	int id = std::rand() % itemManager->GetUpperItemId();
	// Get a free spawn location from the map
	sf::Vector2f position = map->GetItemSpawnLocation();
	// Spawn an item if possible
	AddEntity(itemManager->SpawnItem(id, position, sf::seconds(5.0f)));
}

void Game::Draw(const sf::Time delta)
{
    window->clear();

    sf::Time t;
    for (std::vector<Entity*>::iterator it = std::begin(entities); it != std::end(entities); ++it)
	{
        (*it)->Draw(t, window);
	}

    window->display();
}

void Game::AddEntity(Entity * const entity)
{
    entities.push_back(entity);
}

void Game::RemoveEntities(void)
{
	for (std::vector<Entity *>::iterator i = std::begin(entities); i != std::end(entities); ++i)
	{
		if ((*i)->IsExpired())
		{
			Entity * temp = *i;		// Get the entity to be deleted
			entities.erase(i--);	// delete the element from the vector and decrement the iterator
			delete temp;			// Clean up the entity refence
		}
	}
}
