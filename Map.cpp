#include "Map.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <istream>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "Game.hpp"

Map::Map( void )
{
	// Standard values for grid height and width
	height = 15;
	width = 18;
	tiles = new Tile[ height * width ];
	expired = false;
	position = sf::Vector2f(0.0f, 0.0f); // Dersom du endrer offsettet må du huske å fikse getTileType, ellers blir det bare tull
	vel = sf::Vector2f(0.0f, 0.0f);
	type = Entity::TYPE_MAP;
}

Map::~Map()
{
	delete tiles;
}

bool Map::Load(void)
{
	return LoadMap("test.txt") && LoadTexture("tileset.png");
}

void Map::Unload(void)
{
}

void Map::Update(sf::Time delta)
{

}

bool Map::LoadTexture(const std::string filename)
{
	if (!spriteSheet.loadFromFile(filename.c_str())) return EXIT_FAILURE;
	return true;
}

void sToI(std::string s, std::string search, int * value)
{
	int pos = s.find(search);
	int len = s.length() - pos;

	char buf[32];
	s.copy(buf, len, pos + 1); // starter på char etter søke symbolet/strengen
	buf[len] = '\0';
	*value = std::atoi(buf);
}

bool Map::LoadMap(const std::string filename)
{
	std::ifstream infile(filename.c_str());

	if (!infile)
	{
		std::cerr << "Couldn't open the file: " << filename << std::endl;
		return false;
	}

	std::string s;
	while (infile.good())
	{
		std::getline(infile, s);

		if (s == "[header]")
		{
			std::getline(infile, s); // width
			sToI(s, "=", &width);

			std::getline(infile, s); // height
			sToI(s, "=", &height);
		}
		else if (s == "type=background")
		{
			// Read the "data=" line
			std::getline(infile, s);

			int index = 0;
			for (int row = 0; row < height; ++row)
			{
				for (int col = 0; col < width; ++col)
				{
					std::getline(infile, s, ',');
					// Initialize the tiles based on the flare map
					tiles[index++] = Tile(row, col, std::atoi(s.c_str()) - 1);
				}
			}
		}
		else if (s == "type=collision")
		{
			// Read the "data=" line
			std::getline(infile, s);

			int index = 0;
			for (int row = 0; row < height; ++row)
			{
				for (int col = 0; col < width; ++col)
				{
					std::getline(infile, s, ',');
					// Add the property
					// TODO: Skal skifte (6 + map verdi) bits mot minst signifikante bit
					// Antar at verdiene starter på 1 slik at minste verdi blir 7 bits for properties
					int shift = 6 + std::atoi(s.c_str() - 1);
					//tiles[index++] = Tile(row, col, std::atoi(s.c_str()) - 1);
					tiles[index++].properties |= (1 << shift);
				}
			}
		}
	}

	infile.close();
	return true;
}

void Map::Draw(sf::Time delta, sf::RenderWindow *window)
{
    // TODO: Gå gjennom tiles og tegn til texture
    int val;
    sf::Sprite spr(spriteSheet);
    for (int i = 0; i < height * width; ++i) // TODO: Erstatt 15 * 18 med riktige verdier
    {
        val = tiles[i].properties & 63;
        // Regner med at spriteSheet er 10 i bredden => 10 * 32 totalt = 320 px
        int srcx = (val % 16) * Game::TILE_WIDTH;
        int srcy = (val / 16) * Game::TILE_HEIGHT;

        int targetX = (i % width) * 32 + (int)position.x;
        int targetY = (i / width) * 32 + (int)position.y;
        spr.setPosition(sf::Vector2f(targetX, targetY));

        spr.setTextureRect(sf::IntRect(srcx, srcy, 32, 32));
        window->draw(spr);
    }
}

bool Map::IsExpired()
{
	return expired;
}

int Map::GetTileType(int x, int y)
{
    //int cx = (int)(((float)x - position.x) / (float)Game::TILE_WIDTH);
    //int cy = (int)(((float)y - position.y) / (float)Game::TILE_HEIGHT);
    int cx = x / Game::TILE_WIDTH;
    int cy = y / Game::TILE_HEIGHT;

    if (cx < 0 || cx > width-1 || cy < 0 || cy > height-1)
        return Tile::NOTHING; // bør skiftes ut med solid, men er nothing for debug
    else
    {
        /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
        {
            std::cout << "pos: " << (x-position.x) << ", " << (y-position.y) << "...\n";
            std::cout << "(x, y) = (" << cx << ", " << cy << ")\n";
        }*/
        return tiles[cy*width + cx].GetType();
    }
}
