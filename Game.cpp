#include "Game.hpp"

Game::Game( std::string title = "Untitled" )
{
	this->window = new sf::RenderWindow( sf::VideoMode( SCREEN_WIDTH, SCREEN_HEIGHT ), title );
}

Game::~Game()
{
	delete window;
}

bool Game::Load( void )
{
	for ( std::vector<Entity>::iterator i = entities.begin(); i != entities.end(); ++i )
	{
		if ( !i->Load() ) return false;
	}

	return true;
}

void Game::Unload( void )
{
	for ( std::vector<Entity>::iterator i = entities.begin(); i != entities.end(); ++i )
	{
		i->Unload();
	}
}

void Game::Update( sf::Time delta )
{
	for ( std::vector<Entity>::iterator i = this->entities.begin(); i != this->entities.end(); ++i )
	{
		i->Update( delta );
	}
}

void Game::Draw( sf::Time delta )
{
}

void Game::AddEntity( Entity entity )
{
	entities.push_back( entity );
}