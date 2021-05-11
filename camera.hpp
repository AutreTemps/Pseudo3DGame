#pragma onse
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

class Camera {
private:

    sf::CircleShape player;
    std::vector<std::pair<float, sf::Vertex>> seeing;
    float direction;
    const float viewing_angle = 20.f;
    const float movement_speed = 0.1f;
    const float rotation_speed = 1.f;

public:

    Camera();

    void draw(sf::RenderWindow&);

    void update(float&);

private:

    void generate();

};