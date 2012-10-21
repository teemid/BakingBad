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

// TODO: Skrive denne riktig med bit shifting, bare temp nå
int Tile::GetType()
{
    // Bare for å teste.
    int id = properties & 63;
    if (id == 17)
        return SOLID;
    else
        return NOTHING;
}
