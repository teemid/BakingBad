#ifndef GAME_HPP
#define GAME_HPP

#include "ItemManager.hpp"
#include "Entity.hpp"
#include "Map.hpp"
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
	static const int TILE_WIDTH = 32;
	static const int TILE_HEIGHT = 32;

	Game( std::string title );
	~Game();

	void Initialize(void);
	void AddEntity(Entity * entity);

	void Start();
	void DrawSprite(sf::Sprite * sprite);

private:
	bool Load( void ); // Load resources
	void Unload( void ); // Unload resources if needed
	void Update( sf::Time delta ); // update game logic
	void Draw( sf::Time delta ); // draw all entities 
	void Run(); // start the game loop

	void SpawnItems(sf::Time delta);

	void RemoveEntities(); // remove entites that have expired

	std::string title; // window title
	std::vector<Entity *> entities; // game entities that are updated and drawn

	sf::Clock timer;
	sf::RenderWindow * window;

	// references to map and item manager needed for game logic
	Map * map;
	ItemManager * itemManager;

	int player1;
	int player2;
};

#endif
