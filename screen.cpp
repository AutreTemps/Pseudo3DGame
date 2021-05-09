#include "screen.hpp"

Screen::Screen() {
    frame = Frame();
    map = Map();
}

void Screen::draw(sf::RenderWindow& window) {
    frame.draw(window);
    map.draw(window);
}