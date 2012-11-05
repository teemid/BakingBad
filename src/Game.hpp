#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/System/Clock.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>

#include "ItemManager.hpp"
#include "Map.hpp"

class Game
{
public:
	static const int FPS = 30;
	static const int SCREEN_WIDTH = 18 * 32;
	static const int SCREEN_HEIGHT = 15 * 32;
	static const int TILE_WIDTH = 32;
	static const int TILE_HEIGHT = 32;

	Game(const std::string title);
	~Game(void);

	void Initialize(void);
	void AddEntity(Entity * const entity);
private:
	const bool Load(void);				// Load resources
	void Unload(void);					// Unload resources if needed
	void Update(const sf::Time delta);	// update game logic
	void Draw(const sf::Time delta);	// draw all entities 
	void Run(void);						// start the game loop

	void SpawnItems(const sf::Time delta);

	void RemoveEntities(void); // remove entites that have expired

	std::string title; // window title
	std::vector<Entity *> entities; // game entities that are updated and drawn

	// Clock for time
	sf::Clock timer;
	// Window reference, handles events
	sf::RenderWindow * window;

	// Map reference needed for doing game logic
	Map * map;
	// ItemManager reference needed for doing game logic
	ItemManager * itemManager;
};

#endif
