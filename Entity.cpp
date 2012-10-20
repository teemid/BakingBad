#include "Entity.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

bool Entity::Load( void )
{
	return false;
}

void Entity::Update( sf::Time delta )
{

}

void Entity::Draw( sf::Time delta , sf::RenderWindow *window)
{
    sprite.setTextureRect(sf::IntRect(0, 0, width, height)); // Foreløpig bare dette
    window->draw(sprite);
}
