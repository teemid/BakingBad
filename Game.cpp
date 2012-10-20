#include "Game.hpp"
#include "Entity.hpp"
#include "Map.hpp"
#include <SFML/Window.hpp>
#include <vector>

// TODO: STATE-MACHINE

Game::Game( std::string title = "Untitled" )
{
	this->window = new sf::RenderWindow( sf::VideoMode( SCREEN_WIDTH, SCREEN_HEIGHT ), title );
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
                    window->close();
                break;

                default: ; // do nothing
            }
        }

        while(timer.getElapsedTime().asMilliseconds() < 1000/FPS);
    }
}

bool Game::Load( void )
{
    // Lag entity, burde vel egentlig flyttes, men, men :P
    Map *map = new Map(); // Er entity, så slettingen bør skje i removeEntity()
    map->Load(); // if-test
    AddEntity(map);

	return true;
}

void Unload( void )
{

}

void Game::Update( sf::Time delta )
{

}

void Game::Draw( sf::Time delta )
{
    sf::Time t;
    for (std::vector<Entity*>::iterator it = entites.begin(); it != entites.end(); ++it)
        (*it)->Draw(t);
}

void Game::DrawSprite(sf::Sprite *sprite)
{
    window->draw(*sprite);
}

bool Game::AddEntity(Entity *entity)
{
    entites.push_back(entity);
}

bool RemoveEntity(Entity *entity)
{
    // Må skrives. Delete entity
}
