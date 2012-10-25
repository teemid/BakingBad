#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <string>

#include "Entity.hpp"

class Player : public Entity
{
public:
	Player(sf::Vector2f position, std::string filename);

	bool Load(void);
	void Update(sf::Time delta);

	sf::Vector2f GetPositon();
	void SetPosition(sf::Vector2f position);

	void AddItem(int id);
	void RemoveItem(int id);
	void RemoveAllItems();
	void setKeys(sf::Keyboard::Key * keys);
private:
	sf::Texture texture;
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
