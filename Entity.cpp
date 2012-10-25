#include "Entity.hpp"

void Entity::Draw(sf::Time delta, sf::RenderWindow * window)
{
	sprite.setPosition(position);
	window->draw(sprite);
}

EntityType Entity::GetEntityType()
{
	return type;
}

bool Entity::IsExpired()
{
	return expired;
}