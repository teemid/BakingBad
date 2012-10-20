#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Game.hpp"
#include <ctime>

int main()
{
    srand(time(0));
    Game game = Game( "Baking Bad" );
}
