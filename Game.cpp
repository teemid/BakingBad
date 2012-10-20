#include "Game.hpp"
#include <SFML/Window.hpp>

// TODO: STATE-MACHINE

Game::Game( std::string title = "Untitled" )
{
	this->window = new sf::RenderWindow( sf::VideoMode( SCREEN_WIDTH, SCREEN_HEIGHT ), title );
	Run(); // skift ut denne med load og kjør run etter load er OK
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
	return false;
}

void Unload( void )
{

}

void Game::Update( sf::Time delta )
{

}

void Game::Draw( sf::Time delta )
{

}
