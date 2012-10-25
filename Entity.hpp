#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

enum EntityType
{
	PLAYER = 0,
	ITEM = 1,
	MAP = 2
};

class Entity
{
public:
	virtual bool Load() = 0;
	virtual void Update(sf::Time delta) = 0;
	virtual void Draw(sf::Time delta , sf::RenderWindow * window);

	virtual EntityType GetEntityType();
	virtual bool IsExpired();

	sf::Vector2f position;
	sf::Vector2f vel; // velocity
protected:
	EntityType type;

	sf::Sprite sprite;
	int width;
	int height;
	bool expired;
};

#endif
