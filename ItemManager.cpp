#include "ItemManager.hpp"

#include <SFML/Graphics/Sprite.hpp>

#include <iostream>
#include <fstream>

ItemManager::ItemManager()
{
	itemLimit = 10;
	spawnTimer = sf::seconds(0.0f);
}

ItemManager::~ItemManager()
{
}

bool ItemManager::Load(std::string filename)
{
	std::ifstream infile(filename.c_str());

	std::string s;
	while (infile >> s)
	{
		if (s == "[image]")
		{
			infile >> s;
			texture.loadFromFile(s.c_str());
		}
		else if (s == "[items]")
		{
			while(infile.good())
			{
				std::string name;
				std::string score;
				infile >> name; // get name of the item
				infile >> score; // get the score of the item
				itemNames.push_back(name);
				itemScores.push_back(std::atoi(score.c_str()));
			}
		}
	}

	return true;
}

void ItemManager::Update(sf::Time delta)
{
	spawnTimer -= delta;
}

sf::Time ItemManager::GetSpawnTimer()
{
	return spawnTimer;
}

void ItemManager::ResetSpawnTimer()
{
	spawnTimer = spawnTimer = sf::seconds(std::rand() % (upperSpawnTimer - lowerSpawnTimer) + lowerSpawnTimer);
}

int ItemManager::GetUpperItemId()
{
	return itemNames.size();
}

Item * ItemManager::SpawnItem(int id, sf::Vector2f position)
{
	Item * i;
	if (spawnTimer.asSeconds() <= 0.0f && id <= itemNames.size())
	{
		sf::IntRect rect = sf::IntRect(id * 32, 0, 32, 32);
		i = new Item(itemNames[id], itemScores[id], &texture, rect);
		i->position = position;
		
		itemPositions.push_back(position);
		ResetSpawnTimer();
	}
	// If the item doesn't exists return an empty item with 0s of timeToLive
	else
	{
		i = new Item("", 0.0f, NULL, sf::IntRect(0, 0, 0, 0));
		i->timeToLive = sf::seconds(0.0f);
	}

	return i;
}

Item * ItemManager::SpawnItem(int id, sf::Vector2f position, sf::Time timeToLive)
{
	Item * i = SpawnItem(id, position);
	i->timeToLive = timeToLive;
	
	return i;
}

Item * ItemManager::SpawnItem(std::string itemName, sf::Vector2f position)
{
	Item * i;
	bool found = false;
	int id = 0;
	// check to see if the item is in the map
	for (std::vector<std::string>::iterator iter = itemNames.begin(); iter != itemNames.end(); ++iter)
	{
		if (*iter == itemName)
		{
			found = true;
			break;
		}
		++id;
	}
	if (spawnTimer.asSeconds() < 0.0f && found)
	{
		sf::IntRect rect = sf::IntRect(32, 0, 32, 32);
		i = new Item(itemNames[id], itemScores[id], &texture, rect);
		i->position = position;

		itemPositions.push_back(position);
		ResetSpawnTimer();
	}
	else
	{
		i = new Item("", 0.0f, NULL, sf::IntRect(0, 0, 0, 0));
		i->timeToLive = sf::seconds(0.0f);
	}

	return i;
}

Item * ItemManager::SpawnItem(std::string itemName, sf::Vector2f position, sf::Time timeToLive)
{
	Item * i = SpawnItem(itemName, position);
	i->timeToLive = timeToLive;

	return i;
}