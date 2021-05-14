#pragma onse
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

class Camera {
private:

    sf::CircleShape player;
    std::vector<sf::Vertex> seeing;
    float direction;
    const float viewing_angle = 20.f;
    const float movement_speed = 0.1f;
    const float rotation_speed = 0.2f;

public:

    Camera();

    void draw(sf::RenderWindow&);

    void update(const float&);

private:

    void generate();

};