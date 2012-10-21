#include "Player.hpp"
#include <string>

Player::Player(sf::Vector2f position, std::string filename)
{
	this->position = position;
	this->texture.loadFromFile(filename.c_str());
	sprite.setTexture(this->texture, true);
	speed = 2;
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

    sprite.setPosition(position); // Haxx

}

void Player::Draw(sf::Time delta, sf::RenderWindow * window)
{
    window->draw(sprite);
}

bool Player::IsExpired()
{
	return expired;
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
}

void Player::move(int vx, int vy)
{
    // collision testing
    position.x += vx;
    position.y += vy;
}
