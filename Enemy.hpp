#include "Entity.hpp"

#ifndef ENEMY_HPP
#define ENEMY_HPP

class Enemy : public Entity
{
public:
	bool Load(void);
	void Update(sf::Time delta);
private:
	sf::Texture texture;
}

#endif