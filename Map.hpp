#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include <string>

#include "Entity.hpp"
#include "Tile.hpp"

#ifndef MAP_HPP
#define MAP_HPP

class Map : public Entity
{
public:
	Map(void);
	~Map(void);

	bool Load(void);
	void Unload(void);
	void Update(sf::Time delta);
    void Draw(sf::Time delta, sf::RenderWindow * window);

	bool IsExpired();

	TileType GetTileType(int x, int y); // Get tile type at position (ex: SOLID, NOTHING, see Tile.hpp)
	sf::Vector2f GetItemSpawnLocation();
private:
	bool LoadTexture(const std::string filename);
	bool LoadMap(const std::string filename);
	sf::Texture spriteSheet;

	std::vector<sf::Vector2f> locations;

	int width;
	int height;
	Tile * tiles;
};

#endif
