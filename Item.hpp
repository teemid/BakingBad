#ifndef ITEM_HPP
#define ITEM_HPP

#include "Entity.hpp"

class Item : public Entity
{
public:
	Item(const std::string itemName, const int score, sf::Texture * const texture, const sf::IntRect texRect);
	const bool Load(void);
	void Update(const sf::Time delta);

	int id;
	std::string itemName;
	int score;
	sf::Time timeToLive;
};

#endif