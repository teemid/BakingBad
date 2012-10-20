#include "Player.hpp"

Player::Player(sf::Vector2f position)
{
	this->position = position;
}

bool Player::Load(void)
{
	return false;
}

void Player::Update(sf::Time delta)
{
}

void Player::Draw(sf::Time delta, sf::RenderWindow * window)
{
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