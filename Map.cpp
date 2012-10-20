#include "Map.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

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
	return LoadTexture("tiletest.png") && LoadMap( "test.txt" );
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
    if (!spriteSheet.loadFromFile(filename)) return EXIT_FAILURE;
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
