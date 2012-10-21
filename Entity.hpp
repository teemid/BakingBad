#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>

class Entity
{
public:
    static const int TYPE_PLAYER = 0;
    static const int TYPE_ITEM = 1;

	virtual bool Load() = 0;
	virtual void Update(sf::Time delta) = 0;
	virtual void Draw(sf::Time delta , sf::RenderWindow * window) = 0;
	virtual bool IsExpired() = 0;

	sf::Vector2f position;
	sf::Vector2f vel; // velocity
	int type; // burde kun være read, men, men, må bli ferdig!

protected:
	sf::Sprite sprite;
	sf::Texture texture;
	int width;
	int height;
	bool expired;
};

#endif
