#pragma onse
#include <SFML/Graphics.hpp>
#include <vector>
#include "figure.hpp"

class Map {
private:

    std::vector<Figure> objects;

public:

    Map();

    void draw(sf::RenderWindow&) const;

    Figure& operator[](std::size_t) const;

private:

    void generate();

};
