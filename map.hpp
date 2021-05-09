#pragma onse
#include <SFML/Graphics.hpp>
#include <vector>
#include "figure.hpp"

class Map {
private:

    std::vector<Figure> objects;

public:

    Map();

    void draw(sf::RenderWindow&);

private:

    void generate();

};
