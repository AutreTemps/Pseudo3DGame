#include "camera.hpp"

Camera::Camera() {
    generate();
}

void Camera::generate() {
    player = sf::CircleShape(8.f);
    player.setFillColor(sf::Color(255, 171, 87));
    player.setOutlineThickness(2.f);
    player.setOutlineColor(sf::Color::White);
    player.setPosition(sf::Vector2f(300.f, 300.f));
    direction = 90;
}

void Camera::draw(sf::RenderWindow& window) {
    window.draw(player);
    /*sf::RectangleShape d(sf::Vector2f(1, 20));
    d.setPosition(308, 280);
    window.draw(d);*/
}

void Camera::update(float& time) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        player.move(sf::Vector2f(0.f, -1.f * movement_speed * time));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        player.move(sf::Vector2f(0.f, movement_speed * time));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        player.move(sf::Vector2f(-1.f * movement_speed * time, 0.f));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        player.move(sf::Vector2f(movement_speed * time, 0.f));
    }
}