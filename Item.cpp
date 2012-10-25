#include "Item.hpp"

Item::Item(std::string itemName, int score, sf::Texture * texture, sf::IntRect texRect)
{
	this->itemName = itemName;
	this->score = score;
	expired = false;
	this->timeToLive = sf::seconds(10.0f);

	if (texture != NULL)
	{
		this->sprite.setTexture(*texture, true);
		this->sprite.setTextureRect(texRect);
	}
}

// ikke bruk bool Item::Load, alt lastes inn fra ItemManager
bool Item::Load()
{
	return true;
}
//----------------------------------------------------------

void Item::Update(sf::Time delta)
{
	timeToLive -= delta;
}