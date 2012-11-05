#include "Entity.hpp"

Entity::Entity(void) : width(0), height(0), expired(false)
{
}

void Entity::Draw(const sf::Time delta, sf::RenderWindow * const window)
{
	sprite.setPosition(position);
	window->draw(sprite);
}

void Entity::SetPosition(const sf::Vector2f position)
{
	this->position = position;
}

sf::Vector2f Entity::GetPosition(void) const
{
	return position;
}

void Entity::SetVelocity(const sf::Vector2f velocity)
{
	this->velocity = velocity;
}

sf::Vector2f Entity::GetVelocity(void) const
{
	return velocity;
}

const EntityType Entity::GetEntityType(void) const
{
	return type;
}

const bool Entity::IsExpired(void) const
{
	return expired;
}