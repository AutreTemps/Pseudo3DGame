#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Frame {
private:

    std::vector<sf::RectangleShape> objects;
    //sf::Text demo_label;

public:

    Frame();

    void draw(sf::RenderWindow&) const;

private:
    
    void generate();
};