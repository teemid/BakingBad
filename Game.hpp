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

	void Initialize(void);
	void AddEntity(Entity *entity);
	void RemoveEntity(Entity *entity);

	void Start();
	void DrawSprite(sf::Sprite *sprite);
private:
	bool Load( void );
	void Unload( void );
	void Update( sf::Time delta );
	void Draw( sf::Time delta );
	void Run();

	std::string title;
	std::vector<Entity*> entities;

	sf::Clock timer;
	sf::RenderWindow * window;
};

#endif
