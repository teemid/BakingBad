#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Entity.hpp"

class Enemy : public Entity
{
public:
	bool Load(void);
	void Update(sf::Time delta);
private:
	sf::Texture texture;
}

#endif