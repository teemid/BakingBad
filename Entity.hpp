#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Entity
{
public:
	virtual bool Load( void ) = 0;
	virtual void Unload( void ) = 0;
	virtual void Update( sf::Time delta ) = 0;
	virtual void Draw( sf::Time delta ) = 0;
protected:
	sf::Vector2f position;
	sf::Sprite sprite;
};

#endif
