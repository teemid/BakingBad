#include "Game.hpp"

Game::Game( std::string title = "Untitled" )
{
	this->window = new sf::RenderWindow( sf::VideoMode( SCREEN_WIDTH, SCREEN_HEIGHT ), title );
}

Game::~Game()
{
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