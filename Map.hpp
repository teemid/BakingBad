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

	bool Load(void);
	void Unload(void);
	void Update(sf::Time delta);
    void Draw(sf::Time delta, sf::RenderWindow * window);

	bool IsExpired();

	int GetTileType(int x, int y); // Get tile type at position (ex: SOLID, NOTHING, see Tile.hpp)
private:
	bool LoadTexture(const std::string filename);
	bool LoadMap(const std::string filename);
	sf::Texture spriteSheet;

	int width;
	int height;
	Tile * tiles;
};

#endif
