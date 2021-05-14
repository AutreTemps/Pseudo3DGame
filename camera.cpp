#include "camera.hpp"
#include <iostream>

Camera::Camera() {
    generate();
}

void Camera::generate() {
    player = sf::CircleShape(8.f);
    player.setOrigin(sf::Vector2f(8.f, 8.f));
    player.setFillColor(sf::Color(255, 171, 87));
    player.setOutlineThickness(2.f);
    player.setOutlineColor(sf::Color::White);
    player.setPosition(sf::Vector2f(300.f, 300.f));
    direction = 90;

    //sf::Mouse::setPosition(sf::Vector2i(900, 450));
}

void Camera::draw(sf::RenderWindow& window) {
    window.draw(player);
    //std::cout << sf::Mouse::getPosition().x << ' ' << sf::Mouse::getPosition().y << '\n';
}

void Camera::update(const float& time) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        player.move(sf::Vector2f(0.f, -1.f * movement_speed * time));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        player.move(sf::Vector2f(0.f, movement_speed * time));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        //player.move(sf::Vector2f(-1.f * movement_speed * time, 0.f));
        player.rotate(-1.f * rotation_speed * time);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        //player.move(sf::Vector2f(movement_speed * time, 0.f));
        player.rotate(rotation_speed * time);
    }
}