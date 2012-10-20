#include "Tile.hpp"

Tile::Tile() : properties(0)
{
}

Tile::Tile(int properties) : properties(0)
{
}

Tile::Tile(int x, int y, int properties)
{
	this->position.x = x;
	this->position.y = y;
	this->properties = properties;
}
