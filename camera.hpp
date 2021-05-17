#pragma onse
#include <SFML/Graphics.hpp>
#include <vector>

class Camera {
private:

    sf::CircleShape player;
    std::vector<sf::Vertex> seeing;
    float direction;
    const float viewing_angle = 20.f;
    const float movement_speed = 0.1f;
    const float rotation_speed = 0.3f;

public:

    Camera();

    void draw(sf::RenderWindow&) const;
    
    void update(const float&);

private:

    void generate();

    void update_rays();

    void update_movement(const float&);

};