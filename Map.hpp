#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include <string>

#include "Entity.hpp"
#include "Tile.hpp"

class Map : public Entity
{
public:
	Map( void );
	virtual ~Map();

	bool Load( void );
	void Unload( void );
	void Update( sf::Time delta );
    void Draw( sf::Time delta, sf::RenderWindow *window);

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
