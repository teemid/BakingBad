#ifndef ITEM_MANAGER_HPP
#define ITEM_MANAGER_HPP

#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>

#include "Item.hpp"

class ItemManager
{
public:
	ItemManager(void);
	~ItemManager(void);
	
	const bool Load(const std::string filename);
	void Update(const sf::Time delta);

	const sf::Time GetSpawnTimer(void) const;
	void ResetSpawnTimer(void);

	const int GetUpperItemId(void) const;

	Item * SpawnItem(const int id, const sf::Vector2f position);
	Item * SpawnItem(const int id, const sf::Vector2f position, const sf::Time timeToLive);
	Item * SpawnItem(const std::string itemName, const sf::Vector2f position);
	Item * SpawnItem(const std::string itemName, const sf::Vector2f position, const sf::Time timeToLive);
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