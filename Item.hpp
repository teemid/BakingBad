#ifndef ITEM_HPP
#define ITEM_HPP

#include "Entity.hpp"
#include <SFML/Graphics/Texture.hpp>

class Item : public Entity
{
public:
	Item(std::string itemName, int score, sf::Texture * texture, sf::IntRect texRect);
	bool Load();
	void Update(sf::Time delta);
	void Draw(sf::Time delta, sf::RenderWindow * window);
	bool IsExpired();

	int id;
	std::string itemName;
	int score;
	sf::Time timeToLive;
};

#endif