#pragma onse
#include "frame.hpp"
#include "map.hpp"

class Screen {
private:

    Frame frame;
    Map map;

public:

    Screen();

    void draw(sf::RenderWindow&);

};