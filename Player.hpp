#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/System/Vector2.hpp>
#include <string>
#include <map>

#include "Entity.hpp"

class Player : public Entity
{
public:
	Player( sf::Vector2f position );

	bool Load(void);
	void Update(sf::Time delta);
	void Draw(sf::Time delta, sf::RenderWindow * window);
	bool IsExpired();

	sf::Vector2f GetPositon();
	void SetPosition(sf::Vector2f position);

	void AddItem( int id );
	void RemoveItem( int id );
	void RemoveAllItems();
private:
	std::vector<int> items;
};

#endif