#ifndef ENTITY_HPP
#define ENTTIY_HPP

#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Entity
{
public:
	virtual bool Load();
	virtual void Update( sf::Time delta );
	virtual void Draw( sf::Time delta );
private:
	sf::Vector2f position;
	sf::Sprite sprite;
};

#endif
