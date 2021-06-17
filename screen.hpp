#pragma once
#include "frame.hpp"
#include "map.hpp"
#include "camera.hpp"

class Screen {
private:

    Frame frame;
    Map map;
    Camera camera;

public:

    Screen();

    void draw(sf::RenderWindow&);

    void update(const float&);

};