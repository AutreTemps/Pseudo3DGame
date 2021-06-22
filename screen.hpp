#pragma once

#include "frame.hpp"
#include "map.hpp"
#include "camera.hpp"
#include "visualized3d.hpp"

class Screen {
private:

    Frame frame;
    Map map;
    Camera camera;
    Playground playground;

public:

    Screen();

    void draw(sf::RenderWindow&);

    void update(const float&);

};