#include "frame.hpp"

Frame::Frame() {
    const sf::Color FRAME_COLOR = sf::Color(255, 224, 148);
    sf::RectangleShape vertical_delim(sf::Vector2f(5.f, 900.f));
    vertical_delim.setPosition(sf::Vector2f(400.f, 0.f));
    vertical_delim.setFillColor(FRAME_COLOR);
    frame_objects.push_back(vertical_delim);

    sf::RectangleShape horizontal_delim(sf::Vector2f(400.f, 5.f));
    horizontal_delim.setPosition(sf::Vector2f(0.f, 400.f));
    horizontal_delim.setFillColor(FRAME_COLOR);
    frame_objects.push_back(horizontal_delim);

    sf::RectangleShape edge_l(sf::Vector2f(5.f, 900.f));
    edge_l.setPosition(sf::Vector2f(0.f, 0.f));
    edge_l.setFillColor(FRAME_COLOR);
    frame_objects.push_back(edge_l);

    sf::RectangleShape edge_r(sf::Vector2f(5.f, 900.f));
    edge_r.setPosition(sf::Vector2f(1795.f, 0.f));
    edge_r.setFillColor(FRAME_COLOR);
    frame_objects.push_back(edge_r);

    sf::RectangleShape edge_t(sf::Vector2f(1800.f, 5.f));
    edge_t.setPosition(sf::Vector2f(0.f, 0.f));
    edge_t.setFillColor(FRAME_COLOR);
    frame_objects.push_back(edge_t);
    
    sf::RectangleShape edge_b(sf::Vector2f(1800.f, 5.f));
    edge_b.setPosition(sf::Vector2f(0.f, 895.f));
    edge_b.setFillColor(FRAME_COLOR);
    frame_objects.push_back(edge_b);
}

void Frame::draw(sf::RenderWindow& window) {
    for (auto& object : frame_objects) {
        window.draw(object);
    }
}