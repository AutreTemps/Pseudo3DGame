#include <iostream>
#include <SFML/Graphics.hpp>
#include "screen.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(1800, 900), "Pseudo-3D Game");
    window.setMouseCursorVisible(false);
    
    Screen screen;
    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        float time = clock.getElapsedTime().asMilliseconds();
        clock.restart();
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
            }
        }
        
        window.clear(sf::Color::Black);

        screen.update(time);
        screen.draw(window);
        
        window.display();
    }

    return 0;
}