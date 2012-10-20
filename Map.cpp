#include "Map.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <istream>

Map::Map( void )
{
	// Standard values for grid height and width
	this->height = 15;
	this->width = 18;
	this->tiles = new Tile[ width * height ];
}

Map::~Map()
{
	delete tiles;
}

bool Map::Load( void )
{
	return LoadMap( "test.txt" ) && LoadTexture("tiletest.png");
}

void Map::Unload( void )
{
}

void Map::Update( sf::Time delta )
{

}

void Map::Draw( sf::Time delta )
{

}

bool Map::LoadTexture( const std::string filename )
{
	// TODO: 
    //if (!spriteSheet.loadFromFile(filename)) return EXIT_FAILURE;
	return false;
}

bool Map::LoadMap(const std::string filename )
{
	std::ifstream infile(filename.c_str());

	if ( !infile )
	{
		return false;
	}

	std::string s;
	std::istringstream iss;
	while ( infile.good() )
	{
		std::getline( infile, s );

		if (s == "type=background")
		{
			// Read the "data=" line
			std::getline(infile, s);

			int index = 0;
			for (int row = 0; row < height; ++row)
			{
				for (int col = 0; col < width; ++col)	
				{
					std::getline(infile, s, ',');
					tiles[index++] = Tile(row, col, std::atoi(s.c_str()));
				}
			}
		}
	}

	infile.close();

	return true;
}

