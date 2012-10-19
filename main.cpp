#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ctime>
#include <cstdlib>

int main()
{
    const int FPS = 40;
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;

    srand(time(0));
    sf::Clock fpsTimer;
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Baking Bad");

    while(window.isOpen())
    {
        fpsTimer.restart();

        sf::Event event;
        while(window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    window.close();
                break;

                default: ; // do nothing
            }
        }
    }

    while (fpsTimer.getElapsedTime().asMilliseconds() < 1000/FPS) ;
}
