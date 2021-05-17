#include "camera.hpp"
#include <iostream>
#include <cmath>

#define PI 3.14159265

Camera::Camera() {
    generate();
}

void Camera::generate() {
    player = sf::CircleShape(8.f, 3);
    player.setOrigin(sf::Vector2f(8.f, 8.f));
    player.setFillColor(sf::Color(255, 171, 87));
    player.setOutlineThickness(2.f);
    player.setOutlineColor(sf::Color::White);
    player.setPosition(sf::Vector2f(300.f, 300.f));
    direction = 90;
}

void Camera::draw(sf::RenderWindow& window) const {
    window.draw(player);
}

void Camera::update(const float& time) {
    update_movement(time);
    //update_rays();
}

void Camera::update_movement(const float& time) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        player.move(sf::Vector2f(cos(direction * PI / 180) * movement_speed * time, 
                                -1.f * sin(direction * PI / 180) * movement_speed * time));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        player.move(sf::Vector2f(-1.f * cos(direction * PI / 180) * movement_speed * time, 
                                sin(direction * PI / 180) * movement_speed * time));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        player.rotate(-1.f * rotation_speed * time);
        direction += rotation_speed * time;
        if (direction < 0.f) {
            direction += 360.f;
        }
        else if (direction >= 360.f) {
            direction -= 360.f;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        player.rotate(rotation_speed * time);
        direction -= rotation_speed * time;
        if (direction < 0.f) {
            direction += 360.f;
        }
        else if (direction >= 360.f) {
            direction -= 360.f;
        }
    }
}