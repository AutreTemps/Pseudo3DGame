#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "camera.hpp"

class Playground {
private:

    std::vector<sf::Vector2f> vision;
    double render_distance;
    const double default_height = 900.f;
    const double min_height = 400.f;
    const double left_border = 395.f;
    const double right_border = 1805.f;
    const double middle_line = 450.f;

public:

    Playground();

    void update(const Camera&);

    void draw(sf::RenderWindow&) const;

};