#ifndef TILE_HPP
#define TILE_HPP

#include <SFML/System/Vector2.hpp>
#include <SFML/System/Time.hpp>

//enum TileType 
//{
//	NOTHING = 0,
//	SOLID = 2,
//	SHOP = 4,
//	SHOP2 = 8
//};

class Tile
{
public:
	Tile();
	bool Collision( );
	void Draw( sf::Time delta );
private:
	sf::Vector2i position;
	int properties;
};

#endif