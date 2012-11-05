#include "Player.hpp"
#include <string>

Player::Player(sf::Vector2f position, std::string filename)
{
	this->position = position;
	// Load and set the texture to a sprite (TODO: This should be in the Load function)
	this->texture.loadFromFile(filename.c_str());
	sprite.setTexture(this->texture, true);
	// Get the dimensions of the sprite and set the width and height
	sf::IntRect rect = sprite.getTextureRect();
	width = rect.width;
	height = rect.height;
	speed = 8; // TODO: make this number non-magical?
	type = EntityType::PLAYER;
}

const bool Player::Load(void)
{
	return true;
}

void Player::Update(const sf::Time delta)
{
    // get keyboard
    if (sf::Keyboard::isKeyPressed(keyLeft))
	{
		Move(-speed, 0);
	}
    else if (sf::Keyboard::isKeyPressed(keyRight))
	{
        Move(speed, 0);
	}
    else if (sf::Keyboard::isKeyPressed(keyUp))
	{
        Move(0, -speed);
	}
	else if (sf::Keyboard::isKeyPressed(keyDown))
	{
		Move(0, speed);
	}
    else
	{
        Move(0, 0);
	}
}

int Player::GetSpeed(void) const
{
	return speed;
}

int Player::GetWidth(void) const
{
	return width;
}

int Player::GetHeight(void) const
{
	return height;
}

void Player::AddItem(const int id)
{
	items[id]++;
}

void Player::RemoveItem(const int id)
{
	(--items[id]) > -1 ? items[id] : 0;
}

void Player::SetKeys(sf::Keyboard::Key * const keys)
{
    keyLeft = keys[0];
    keyUp = keys[1];
    keyRight = keys[2];
    keyDown = keys[3];
    keyAction = keys[4];
}

// move har ny funksjonalitet og burde vel egentlig skifte navn
void Player::Move(const int vx, const int vy)
{
    velocity = sf::Vector2f(vx, vy);
}
