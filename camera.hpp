#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "map.hpp"

class Camera {
private:

    sf::CircleShape player;
    std::vector<sf::Vertex> seeing;
    std::vector<sf::Vertex> area_of_seeing;
    float direction;
    const float viewing_angle = 20.f;
    const float movement_speed = 0.1f;
    const float rotation_speed = 0.3f;
    const float seeing_radius = 50.f;
    sf::CircleShape demo;
    std::vector<sf::Vertex> demo_area;

public:

    Camera();

    void draw(sf::RenderWindow&) const;
    
    void update(const float&);

private:

    void generate();

    void update_rays();

    void update_movement(const float&);

};