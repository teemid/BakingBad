#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <string>

#include "Entity.hpp"
#include "Tile.hpp"

class Map : Entity
{
public:
	Map( void );
	virtual ~Map();

	bool Load( void );
	void Unload( void );
	void Update( sf::Time delta );
	void Draw( sf::Time delta );

	Tile GetCoord( sf::Vector2i position );
private:
	bool LoadTexture( const std::string filename );
	bool LoadMap( const std::string filename );

	int width;
	int height;
	Tile * tiles;
};

#endif