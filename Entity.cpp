#include "Entity.hpp"

Entity::Entity() : width(0), height(0), expired(false)
{
}

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