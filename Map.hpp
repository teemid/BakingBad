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
	Map(void);
	~Map(void);

	const bool Load(void);
	void Update(const sf::Time delta);
    void Draw(const sf::Time delta, sf::RenderWindow * const window);

	const TileType GetTileType(const int x, const int y) const; // Get tile type at position (ex: SOLID, NOTHING, see Tile.hpp)
	sf::Vector2f GetItemSpawnLocation() const;
private:
	const bool LoadTexture(const std::string filename);
	const bool LoadMap(const std::string filename);
	
	sf::Texture spriteSheet;
	std::vector<sf::Vector2f> locations;

	int width;
	int height;
	Tile * tiles;
};

#endif
