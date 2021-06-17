#include "screen.hpp"

Screen::Screen() {}

void Screen::draw(sf::RenderWindow& window) {
    frame.draw(window);
    map.draw(window);
    camera.draw(window);
}

void Screen::update(const float& time) {
    camera.update(time, map);
}