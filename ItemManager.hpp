#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>

#include "Item.hpp"

#ifndef ITEM_MANAGER_HPP
#define ITEM_MANAGER_HPP

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
	sf::Texture texture;
	
	std::vector<std::string> itemNames;
	std::vector<int> itemScores;

	sf::Time spawnTimer;
	// Upper and lower spawn timer in seconds
	int lowerSpawnTimer;
	int upperSpawnTimer;
};

#endif