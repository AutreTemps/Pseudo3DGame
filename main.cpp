#include <iostream>
#include <SFML/Graphics.hpp>
#include "screen.hpp"
#include "camera.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(1800, 900), "Pseudo-3D Game");
    
    Screen screen;
    Camera camera;
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
            
        }
        
        window.clear(sf::Color::Black);
        screen.draw(window);
        camera.update(time);
        camera.draw(window);
        window.display();
    }

    return 0;
}