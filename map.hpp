#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "figure.hpp"

class Map {
private:

    std::vector<Figure> objects;

public:

    Map();

    void draw(sf::RenderWindow&) const;

    Figure& operator[](std::size_t);

    std::size_t getMapObjNumber();

private:

    void generate();

};
