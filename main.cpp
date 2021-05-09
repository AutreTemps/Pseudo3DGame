#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "screen.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(1800, 900), "Pseudo-3D Game");
    
    Screen screen;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        screen.draw(window);
        window.display();
    }
    
    return 0;
}