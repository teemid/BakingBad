#include "ItemManager.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include <fstream>

ItemManager::ItemManager(void)
{
	lowerSpawnTimer = 2.0f;
	upperSpawnTimer = 5.0f;
	spawnTimer = sf::seconds(0.0f);
}

ItemManager::~ItemManager(void)
{
}

const bool ItemManager::Load(const std::string filename)
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

void ItemManager::Update(const sf::Time delta)
{
	spawnTimer -= delta;
}

const sf::Time ItemManager::GetSpawnTimer(void) const
{
	return spawnTimer;
}

void ItemManager::ResetSpawnTimer(void)
{
	spawnTimer = sf::seconds(std::rand() % (upperSpawnTimer - lowerSpawnTimer) + lowerSpawnTimer);
}

const int ItemManager::GetUpperItemId(void) const
{
	return itemNames.size();
}

Item * ItemManager::SpawnItem(const int id, const sf::Vector2f position)
{
	Item * i;
	if (spawnTimer.asSeconds() <= 0.0f && id <= itemNames.size())
	{
		sf::IntRect rect = sf::IntRect(id * 32, 0, 32, 32);
		i = new Item(itemNames[id], itemScores[id], &texture, rect);
		i->SetPosition(position);
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

Item * ItemManager::SpawnItem(const int id, const sf::Vector2f position, const sf::Time timeToLive)
{
	Item * i = SpawnItem(id, position);
	i->timeToLive = timeToLive;
	
	return i;
}

Item * ItemManager::SpawnItem(const std::string itemName, const sf::Vector2f position)
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
		i = SpawnItem(id, position);
	}
	else
	{
		i = new Item("", 0.0f, NULL, sf::IntRect(0, 0, 0, 0));
		i->timeToLive = sf::seconds(0.0f);
	}

	return i;
}

Item * ItemManager::SpawnItem(const std::string itemName, const sf::Vector2f position, const sf::Time timeToLive)
{
	Item * i = SpawnItem(itemName, position);
	i->timeToLive = timeToLive;

	return i;
}