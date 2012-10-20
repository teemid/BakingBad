#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/System/Clock.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>

#include "Entity.hpp"

class Game
{
public:
	static const int FPS = 30;
	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 600;

	Game( std::string title );
	~Game();

	void AddEntity( Entity * entity );
	bool RemoveEntity();

private:
	bool Load( void );
	void Unload( void );
	void Update( sf::Time delta );
	void Draw( sf::Time delta );

	std::string title;
	std::vector<Entity> entities;

	sf::Clock timer;
	sf::RenderWindow * window;
};

#endif