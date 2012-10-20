#include "Game.hpp"
#include "Entity.hpp"
#include "Map.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>


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

void Game::Initialize( void )
{
	Map * map = new Map();
	AddEntity( map );
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
    // keyboard input

    // TODO: Collision testing
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

void Game::AddEntity(Entity *entity)
{
    entities.push_back(entity);
}

void RemoveEntity(Entity *entity)
{
    // Må skrives. Delete entity og fjern fra vector (entities)
}
