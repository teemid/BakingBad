#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Game.hpp"
#include "Map.hpp"

int main()
{
    Game game = Game( "Baking Bad" );

	game.AddEntity( &Map() );
}
