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
    seeing.resize(360);
    for (int i = 0; i < 360; ++i) {
        area_of_seeing.push_back(sf::Vertex(sf::Vector2f(sin(i * PI / 180) * seeing_radius,
                                                        cos(i * PI / 180) * seeing_radius)));
    }

    demo = sf::CircleShape(8.f);
    demo.setOrigin(sf::Vector2f(8.f, 8.f));
    demo.setFillColor(sf::Color(255, 171, 87));
    demo.setOutlineThickness(2.f);
    demo.setOutlineColor(sf::Color::White);
    demo.setPosition(sf::Vector2f(200.f, 700.f));
    demo_area.resize(360);
}

void Camera::draw(sf::RenderWindow& window) const {
    window.draw(player);
    window.draw(demo);
    window.draw(&demo_area[0], demo_area.size(), sf::Points);
}

void Camera::update(const float& time) {
    update_movement(time);
    update_rays();
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

void Camera::update_rays() {
    for (int i = 0; i < 360; ++i) {
        seeing[i] = player.getPosition() + area_of_seeing[i].position;
    }


    for (int i = 0; i < 360; ++i) {
        demo_area[i] = sf::Vertex(sf::Vector2f((seeing[i].position - player.getPosition()).x * 3,
                                            (seeing[i].position - player.getPosition()).y * 3) + demo.getPosition());
    }
}