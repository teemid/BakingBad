#include "Map.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <istream>
#include <SFML/Graphics.hpp>
#include <cstdlib>

Map::Map( void )
{
	// Standard values for grid height and width
	this->height = 15;
	this->width = 18;
	this->tiles = new Tile[ height * width ];
	position.x = 0;
	position.y = 32;
}

Map::~Map()
{
	delete tiles;
}

bool Map::Load(void)
{
	return LoadMap("test.txt") &&  LoadTexture("tileset.png");
}

void Map::Unload(void)
{
}

void Map::Update(sf::Time delta)
{

}

bool Map::LoadTexture(const std::string filename)
{
	if ( !spriteSheet.loadFromFile(filename.c_str())) return EXIT_FAILURE;
}

bool Map::LoadMap(const std::string filename)
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
					std::cout << s << std::endl;
					tiles[index++] = Tile(row, col, std::atoi(s.c_str())-1);
				}
			}
		}
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
        val = tiles[i].properties & 63;
        // Regner med at spriteSheet er 10 i bredden => 10 * 32 totalt = 320 px
        int srcx = (val % 16) * 32;
        int srcy = (val / 16) * 32;

        int targetX = (i % width) * 32 + position.x;
        int targetY = (i / width) * 32 + position.y;
        spr.setPosition(sf::Vector2f(targetX, targetY));

        spr.setTextureRect(sf::IntRect(srcx,srcy, 32, 32));
        window->draw(spr);
    }
}
