#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/System/Vector2.hpp>
#include <string>
#include <map>

#include "Entity.hpp"
#include <string>

class Player : public Entity
{
public:
	Player( sf::Vector2f position, std::string filename);

	bool Load(void);
	void Update(sf::Time delta);
	void Draw(sf::Time delta, sf::RenderWindow * window);
	bool IsExpired();

	sf::Vector2f GetPositon();
	void SetPosition(sf::Vector2f position);

	void AddItem( int id );
	void RemoveItem( int id );
	void RemoveAllItems();
	void setKeys(sf::Keyboard::Key *keys);
private:
	std::vector<int> items;
	sf::Keyboard::Key keyLeft;
	sf::Keyboard::Key keyRight;
	sf::Keyboard::Key keyUp;
	sf::Keyboard::Key keyDown;
	sf::Keyboard::Key keyAction;
    int speed;
	void move(int vx, int vy);
};

#endif
