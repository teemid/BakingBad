#ifndef GAME_HPP
#define GAME_HPP

#include "Entity.hpp"
#include <vector>

#include <SFML/System/Clock.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Game
{
public:
	static const int FPS = 30;
	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 600;

	Game( std::string title );
	~Game();

	bool AddEntity();
	bool RemoveEntity();

	void Start();
private:
	bool Load( void );
	void Unload( void );
	void Update( sf::Time delta );
	void Draw( sf::Time delta );

	std::string title;
	std::vector<Entity> entites;

	sf::Clock time;
	sf::RenderWindow * window;
};

#endif