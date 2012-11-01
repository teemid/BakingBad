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

bool Player::Load(void)
{
	return true;
}

void Player::Update(sf::Time delta)
{
    // get keyboard
    if (sf::Keyboard::isKeyPressed(keyLeft))
	{
		move(-speed, 0);
	}
    else if (sf::Keyboard::isKeyPressed(keyRight))
	{
        move(speed, 0);
	}
    else if (sf::Keyboard::isKeyPressed(keyUp))
	{
        move(0, -speed);
	}
	else if (sf::Keyboard::isKeyPressed(keyDown))
	{
		move(0, speed);
	}
    else
	{
        move(0,0);
	}
}

sf::Vector2f Player::GetPositon()
{
	return position;
}

void Player::SetPosition(sf::Vector2f position)
{
	this->position = position;
}

int Player::GetSpeed()
{
	return speed;
}

int Player::GetWidth()
{
	return width;
}

int Player::GetHeight()
{
	return height;
}

void Player::AddItem(int id)
{
	items[id]++;
}

void Player::RemoveItem(int id)
{
	(--items[id]) > -1 ? items[id] : 0;
}

void Player::SetKeys(sf::Keyboard::Key * keys)
{
    keyLeft = keys[0];
    keyUp = keys[1];
    keyRight = keys[2];
    keyDown = keys[3];
    keyAction = keys[4];
}

// move har ny funksjonalitet og burde vel egentlig skifte navn
void Player::move(int vx, int vy)
{
    vel.x = vx;
    vel.y = vy;
}
