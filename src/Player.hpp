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
	Player(const sf::Vector2f position, const std::string filename);

	const bool Load(void);
	void Update(const sf::Time delta);

	int GetSpeed(void) const;
	int GetWidth(void) const;
	int GetHeight(void) const;

	void AddItem(const int id);
	void RemoveItem(const int id);
	void RemoveAllItems(void);
	void SetKeys(sf::Keyboard::Key * const keys);
private:
	void Move(const int vx, const int vy);

	sf::Texture texture;
	std::vector<int> items;
	sf::Keyboard::Key keyLeft;
	sf::Keyboard::Key keyRight;
	sf::Keyboard::Key keyUp;
	sf::Keyboard::Key keyDown;
	sf::Keyboard::Key keyAction;
    int speed;
};

#endif
