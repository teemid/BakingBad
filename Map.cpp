#include <iostream>
#include <fstream>
#include <sstream>
#include <istream>
#include <SFML/Graphics.hpp>

#include "Game.hpp"
#include "Map.hpp"

Map::Map(void) : height(15), width(18)
{
	// Standard values for grid height and width
	tiles = new Tile[height * width];
	position = sf::Vector2f(0.0f, 0.0f); // Dersom du endrer offsettet m� du huske � fikse getTileType, ellers blir det bare tull
	vel = sf::Vector2f(0.0f, 0.0f);
	type = EntityType::MAP;
}

Map::~Map()
{
	delete tiles;
}

bool Map::Load(void)
{
	bool loaded = LoadMap("test.txt") && LoadTexture("tileset.png");

	if (loaded)
	{
		for (int i = 0; i < width; ++i)
		{
			for (int j = 0; j < height; ++j)
			{
				if (GetTileType(i * 32, j * 32) == TileType::NOTHING)
				{
					locations.push_back(sf::Vector2f(i * 32, j * 32));
				}
			}
		}
	}

	return loaded;
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
	s.copy(buf, len, pos + 1); // starter p� char etter s�ke symbolet/strengen
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
			int tempWidth;
			int tempHeight;
			std::getline(infile, s); // width
			sToI(s, "=", &tempWidth);

			std::getline(infile, s); // height
			sToI(s, "=", &tempHeight);

			// If the map is larger or smaller than the standard map size
			if (width != tempWidth && height != tempHeight)
			{
				// delete the old map
				delete tiles;
				// create the new map with the new size
				tiles = new Tile[ width * height ];
			}
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
	}

	infile.close();
	return true;
}

void Map::Draw(sf::Time delta, sf::RenderWindow * window)
{
    // TODO: G� gjennom tiles og tegn til texture
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

TileType Map::GetTileType(int x, int y)
{
    int cx = x / Game::TILE_WIDTH;
    int cy = y / Game::TILE_HEIGHT;

    if (cx < 0 || cx > width - 1 || cy < 0 || cy > height - 1)
	{
        return TileType::NOTHING; // b�r skiftes ut med solid, men er nothing for debug
	}
    else
    {
        return tiles[cy * width + cx].GetType();
    }
}

sf::Vector2f Map::GetItemSpawnLocation()
{
	int i = std::rand() % locations.size();

	return locations[i];
}