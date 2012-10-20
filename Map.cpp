#include "Map.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

Map::Map( void )
{
	// Standard values for grid height and width
	this->height = 15;
	this->width = 18;
	this->tiles = new Tile[ 15 * 18 ];
}

Map::~Map()
{
	delete tiles;
}

bool Map::Load( void )
{
	return LoadTexture( "map.png") && LoadMap( "test.txt" );
}

void Map::Unload( void )
{
	// TODO: Complete function
	return;
}

void Map::Update( sf::Time delta )
{
	// TODO: Complete function
	return;
}

/*
 *  Loop through the tiles of the map and draw them
 */
void Map::Draw( sf::Time delta )
{
	// TODO: Complete function
	return;
}

/*
 *  Load the Sprite Sheet with the map tiles
 */
bool Map::LoadTexture( const std::string filename )
{
	//this->spriteSheet.loadFromFile( filename );

	// TODO: change return value
	return true;
}

/*
 *  Read the map from a text file
 */
bool Map::LoadMap( const std::string filename )
{
	std::ifstream infile( filename.c_str() );

	// Stop if the file can't be opened
	if ( !infile )
	{
		return false;
	}

	std::string s;
	std::istringstream ss;
	while ( infile.good() )
	{
		std::getline( infile, s );

		if ( s == "[header]" )
		{
			std::cout << "We're at the header" << std::endl;
		}
	}

	infile.close();
	
	return true;
}