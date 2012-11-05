#include "Item.hpp"

Item::Item(const std::string itemName, const int score, sf::Texture * const texture, const sf::IntRect texRect)
{
	this->itemName = itemName;
	this->score = score;
	this->timeToLive = sf::seconds(10.0f);
	// Need type information for collision detection 
	// in the Update() function in Game.cpp
	this->type = EntityType::ITEM;

	if (texture != NULL)
	{
		this->sprite.setTexture(*texture, true);
		this->sprite.setTextureRect(texRect);
	}
}

// Do not use Item::Load, textures are loaded in the ItemManager class
const bool Item::Load(void)
{
	return true;
}
//----------------------------------------------------------

void Item::Update(sf::Time delta)
{
	expired = ((timeToLive -= delta) < sf::seconds(0.0f));
}