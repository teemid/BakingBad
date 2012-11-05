#include "Tile.hpp"

Tile::Tile(void) : properties(0)
{
}

Tile::Tile(const int properties)
{
	this->properties = properties;
}

Tile::Tile(const int x, const int y, const int properties)
{
	this->position.x = x;
	this->position.y = y;
	this->properties = properties;
}

// TODO: Complete this function
const TileType Tile::GetType(void) const
{
    int id = properties & 63;

	return (id == 17) ? SOLID : NOTHING;
}
