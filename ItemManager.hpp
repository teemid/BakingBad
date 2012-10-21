#ifndef ITEM_MANAGER_HPP
#define ITEM_MANAGER_HPP

#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>
#include <map>

#include "Entity.hpp"
#include "Item.hpp"

class ItemManager
{
public:
	ItemManager();
	~ItemManager();
	
	bool Load(std::string filename);
	void Update(sf::Time delta);

	sf::Time GetSpawnTimer();
	void ResetSpawnTimer();

	int GetUpperItemId();

	Item * SpawnItem(int id, sf::Vector2f position);
	Item * SpawnItem(int id, sf::Vector2f position, sf::Time timeToLive);
	Item * SpawnItem(std::string itemName, sf::Vector2f position);
	Item * SpawnItem(std::string itemName, sf::Vector2f position, sf::Time timeToLive);
private:
	// Upper and lower spawn timer in seconds
	static const int upperSpawnTimer = 5.0f;
	static const int lowerSpawnTimer = 2.0f;

	int itemLimit;

	sf::Time spawnTimer;

	std::vector<std::string> itemNames;
	std::vector<int> itemScores;
	std::vector<sf::Vector2f> itemPositions;

	sf::Texture texture;
};

#endif