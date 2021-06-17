#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "map.hpp"

class Camera {
private:

    sf::CircleShape player;
    std::vector<sf::Vertex> seeing;
    std::vector<sf::Vertex> view;
    float direction;
    const float viewing_angle = 40.f;
    const float movement_speed = 0.1f;
    const float rotation_speed = 0.3f;
    const float seeing_radius = 150.f;
    sf::CircleShape demo;
    std::vector<sf::Vertex> demo_area;

public:

    Camera();

    void draw(sf::RenderWindow&) const;
    
    void update(const float&, Map&);

private:

    void generate();

    void update_rays(Map&);

    void update_movement(const float&);

};