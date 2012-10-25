#include "Player.hpp"
#include <string>

Player::Player(sf::Vector2f position, std::string filename)
{
	this->position = position;
	this->texture.loadFromFile(filename.c_str());
	sprite.setTexture(this->texture, true);
	speed = 8;
	type = EntityType::PLAYER;
	expired = false;
}

bool Player::Load(void)
{
	return false;
}

void Player::Update(sf::Time delta)
{
    // get keyboard
    if (sf::Keyboard::isKeyPressed(keyLeft))
        move(-speed, 0);
    else if (sf::Keyboard::isKeyPressed(keyRight))
        move(speed, 0);
    else if (sf::Keyboard::isKeyPressed(keyUp))
        move(0, -speed);
    else if (sf::Keyboard::isKeyPressed(keyDown))
        move(0, speed);
    else
        move(0,0);
}

sf::Vector2f Player::GetPositon()
{
	return position;
}

void Player::SetPosition(sf::Vector2f position)
{
	this->position = position;
}

void Player::AddItem(int id)
{
	items[id]++;
}

void Player::RemoveItem(int id)
{
	(--items[id]) > -1 ? items[id] : 0;
}

void Player::setKeys(sf::Keyboard::Key *keys)
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
