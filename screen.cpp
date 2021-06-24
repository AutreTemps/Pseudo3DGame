#include "screen.hpp"

Screen::Screen() {}

void Screen::draw(sf::RenderWindow& window) {
    playground.draw(window);
    map.draw(window);
    camera.draw(window);
    frame.draw(window);
}

void Screen::update(const float& time) {
    camera.update(time, map);
    playground.update(camera);
}