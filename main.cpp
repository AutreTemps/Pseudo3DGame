#include <iostream>
#include <SFML/Graphics.hpp>
#include "screen.hpp"

double vector_multiply(const sf::Vector2f& a, const sf::Vector2f& b) {
    return a.x * b.y - b.x * a.y;
}

bool check_intersection(const sf::Vector2f& a1, const sf::Vector2f& a2, 
                        const sf::Vector2f& b1, const sf::Vector2f& b2) {

    sf::Vector2f v1 = b1 - a1;
    sf::Vector2f v2 = b2 - a1;
    sf::Vector2f a = a2 - a1;
    if (vector_multiply(a, v1) * vector_multiply(a, v2) < 0) {
        return true;
    }
    return false;
}

sf::Vector2f find_intersection(const sf::Vector2f& a1, const sf::Vector2f& a2, 
                                const sf::Vector2f& b1, const sf::Vector2f& b2) {

    if (!(check_intersection(a1, a2, b1, b2) && check_intersection (b1, b2, a1, a2))) {
        return a2;
    }

    sf::Vector2f v1 = b1 - a1;
    sf::Vector2f v2 = b2 - a1;
    sf::Vector2f a = a2 - a1;
    double z1 = vector_multiply(a, v1);
    double z2 = vector_multiply(a, v2);
    return sf::Vector2f(b1.x + (b2.x - b1.x) * std::abs(z1 / (z2 - z1)), 
                        b1.y + (b2.y - b1.y) * std::abs(z1 / (z2 - z1)));
}

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