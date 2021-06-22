#include "visualized3d.hpp"
#include <cmath>

double module(const sf::Vector2f& v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

Playground::Playground() {
}

void Playground::update(const Camera& camera) {
    render_distance = camera.getRenderDistance();
    vision = camera.getVisiblePoints();
}

void Playground::draw(sf::RenderWindow& window) const {
    double stripe_width = (right_border - left_border) / vision.size();
    for (int i = 0; i < vision.size(); ++i) {
        double distance = (int) (module(vision[i]) + 0.01f);
        if (distance < render_distance) {
            double aspect = (render_distance - distance) / render_distance;
            double stripe_height = (default_height - min_height) * aspect + min_height;
            sf::RectangleShape stripe(sf::Vector2f(stripe_width, stripe_height));
            stripe.setOrigin(sf::Vector2f(stripe_width / 2, stripe_height / 2));
            stripe.setPosition(sf::Vector2f(left_border + i * stripe_width, middle_line));
            stripe.setFillColor(sf::Color(255, 255, 255, 255 * aspect * 0.7));
            window.draw(stripe);
        }
    }
}