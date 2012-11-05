#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Entity.hpp"

class Enemy : public Entity
{
public:
	const bool Load(void);
	void Update(const sf::Time delta);
private:
	sf::Texture texture;
}

#endif