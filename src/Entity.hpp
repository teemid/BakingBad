#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

enum EntityType
{
	PLAYER	= 0,
	ITEM	= 1,
	MAP		= 2,
};

class Entity
{
public:
	Entity(void);
	// Purely virtual functions
	virtual const bool Load(void) = 0;
	virtual void Update(const sf::Time delta) = 0;
	// Virtual functions
	virtual void Draw(const sf::Time delta , sf::RenderWindow * const window);
	// Getters and Setters
	virtual void SetPosition(const sf::Vector2f position);
	virtual sf::Vector2f GetPosition(void) const;

	virtual void SetVelocity(const sf::Vector2f velocity);
	virtual sf::Vector2f GetVelocity(void) const;

	virtual const EntityType GetEntityType(void) const;
	virtual const bool IsExpired(void) const;
protected:
	EntityType type;
	
	sf::Sprite sprite;
	sf::Vector2f position;
	sf::Vector2f velocity;

	int width;
	int height;
	bool expired;
};

#endif
