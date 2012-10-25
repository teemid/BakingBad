#include <SFML/System/Vector2.hpp>
#include <SFML/System/Time.hpp>

#ifndef TILE_HPP
#define TILE_HPP

enum TileType
{
	NOTHING = 0,
	SOLID = 2,
	SHOP = 4,
    SHOP2 = 8
};

class Tile
{
public:
	Tile();
	Tile(int properties);
	Tile(int x, int y, int properties);

	bool Collision( );
	TileType GetType(); // returnerer type (SOLID, NOTHING osv), kanskje skrive om til enum :P

	TileType type;
	sf::Vector2i position;
	int properties;
};

#endif
