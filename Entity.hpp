#ifndef ENTITY_HPP
#define ENTITY_HPP


#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>


class Entity
{
public:
	virtual bool Load();
	virtual void Update( sf::Time delta );
	virtual void Draw( sf::Time delta , sf::RenderWindow *window);

protected:
	sf::Vector2f position;
	sf::Sprite sprite;
	int width;
	int height;
};

#endif
