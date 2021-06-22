#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "map.hpp"

class Camera {
private:

    sf::CircleShape player;
    std::vector<sf::Vertex> seeing;
    std::vector<sf::Vertex> view;
    double direction;
    const double viewing_angle = 40.f;
    const double movement_speed = 0.1f;
    const double rotation_speed = 0.3f;
    const double seeing_radius = 240.f;
    sf::CircleShape demo;
    std::vector<sf::Vertex> demo_area;

public:

    Camera();

    void draw(sf::RenderWindow&) const;
    
    void update(const double&, Map&);

    std::vector<sf::Vector2f> getVisiblePoints() const;

    double getRenderDistance() const;

private:

    void generate();

    void updateRays(Map&);

    void updateMovement(const double&);

};