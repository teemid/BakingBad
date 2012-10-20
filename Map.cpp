#include "Map.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <cstdlib>

Map::Map( void )
{
	// Standard values for grid height and width
	this->height = 16;
	this->width = 25;
	this->tiles = new Tile[ height * width ];
	position.x = 0;
	position.y = 32;
}

Map::~Map()
{
	delete tiles;
}

bool Map::Load( void )
{
	return LoadTexture("testtiles.png") && LoadMap( "test.txt" );
}

bool Map::LoadTexture( const std::string filename )
{
    if (!spriteSheet.loadFromFile(filename.c_str())) return EXIT_FAILURE;
}

bool Map::LoadMap(const std::string filename )
{
	std::ifstream infile(filename.c_str());

	if ( !infile )
	{
		return false;
	}

	std::string s;
	std::istringstream ss;
	while ( infile.good() )
	{
		std::getline( infile, s );
	}

	infile.close();

	return true;
}

void Map::Draw( sf::Time delta, sf::RenderWindow *window)
{
    // TODO: Gå gjennom tiles og tegn til texture
    int val;
    sf::Sprite spr(spriteSheet);
    for (int i = 0; i < height * width; ++i) // TODO: Erstatt 15 * 18 med riktige verdier
    {
        val = tiles[i].getValue();
        // Regner med at spriteSheet er 10 i bredden => 10 * 32 totalt = 320 px
        int srcx = (val % 10) * 32;
        int srcy = (val / 10) * 32;

        int targetX = (i % width) * 32 + position.x;
        int targetY = (i / width) * 32 + position.y;
        spr.setPosition(sf::Vector2f(targetX, targetY));

        spr.setTextureRect(sf::IntRect(srcx,srcy, 32, 32));
        window->draw(spr);
    }
}
