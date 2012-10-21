#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>

class Entity
{
public:
	virtual bool Load() = 0;
	virtual void Update(sf::Time delta) = 0;
	virtual void Draw(sf::Time delta , sf::RenderWindow * window) = 0;
	virtual bool IsExpired() = 0;

protected:
	sf::Vector2f position;
	sf::Sprite sprite;
	sf::Texture texture;
	int width;
	int height;
	bool expired;
};

#endif
