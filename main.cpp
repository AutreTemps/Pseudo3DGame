#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "frame.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(1800, 900), "Pseudo-3D Game");
    Frame frame;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        frame.draw(window);
        window.display();
    }

    return 0;
}