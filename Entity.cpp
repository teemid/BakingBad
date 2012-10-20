#include "Entity.hpp"

bool Entity::Load( void )
{
	return false;
}

void Entity::Update( sf::Time delta )
{

}

void Entity::Draw( sf::Time delta )
{
    sprite.setTextureRect(sf::IntRect(0, 0, width, height)); // Foreløpig bare dette
}
