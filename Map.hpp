#ifndef MAP_HPP
#define MAP_HPP

#include "Entity.hpp"
#include "Tile.hpp"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>
// Doesn't work for some reason
//#include <SFML/System/String.hpp>
// Using std::string
#include <string>

class Map : public Entity
{
public:
	Map( void );
	~Map();

	bool Load( void );

	Tile GetCoord( sf::Vector2i position );
private:
	bool LoadTexture( const std::string filename );
	bool LoadMap( const std::string filename );
	sf::Texture spriteSheet;

	int width;
	int height;
	Tile * tiles;
};

#endif
