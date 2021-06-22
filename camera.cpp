#include "camera.hpp"
#include <cmath>

#define PI 3.14159265

double len(const sf::Vector2f& a, const sf::Vector2f& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double vector_multiply(const sf::Vector2f& a, const sf::Vector2f& b) {
    return a.x * b.y - b.x * a.y;
}

bool check_intersection(const sf::Vector2f& a1, const sf::Vector2f& a2, 
                        const sf::Vector2f& b1, const sf::Vector2f& b2) {

    sf::Vector2f v1 = b1 - a1;
    sf::Vector2f v2 = b2 - a1;
    sf::Vector2f a = a2 - a1;
    if (vector_multiply(a, v1) * vector_multiply(a, v2) < 0) {
        return true;
    }
    return false;
}

sf::Vector2f find_intersection(const sf::Vector2f& a1, const sf::Vector2f& a2, 
                                const sf::Vector2f& b1, const sf::Vector2f& b2) {

    if (!(check_intersection(a1, a2, b1, b2) && check_intersection (b1, b2, a1, a2))) {
        return a2;
    }
    sf::Vector2f v1 = b1 - a1;
    sf::Vector2f v2 = b2 - a1;
    sf::Vector2f a = a2 - a1;
    double z1 = vector_multiply(a, v1);
    double z2 = vector_multiply(a, v2);
    return sf::Vector2f(b1.x + (b2.x - b1.x) * std::abs(z1 / (z2 - z1)), 
                        b1.y + (b2.y - b1.y) * std::abs(z1 / (z2 - z1)));
}

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

    demo = sf::CircleShape(8.f);
    demo.setOrigin(sf::Vector2f(8.f, 8.f));
    demo.setFillColor(sf::Color(255, 171, 87));
    demo.setOutlineThickness(2.f);
    demo.setOutlineColor(sf::Color::White);
    demo.setPosition(sf::Vector2f(200.f, 700.f));
    demo_area.resize(360);

    view.resize(viewing_angle * 2);
}

void Camera::draw(sf::RenderWindow& window) const {
    window.draw(player);
    window.draw(demo);
    window.draw(&demo_area[0], demo_area.size(), sf::Points);
    window.draw(&view[0], view.size(), sf::TriangleFan);
}

void Camera::update(const double& time, Map& map) {
    updateMovement(time);
    updateRays(map);
}

void Camera::updateMovement(const double& time) {
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

void Camera::updateRays(Map& map) {
    for (int i = 0; i < 360; ++i) {
        seeing[i] = sf::Vertex(player.getPosition() + sf::Vector2f(cos(i * PI / 180) * seeing_radius,
                                                                 -1 * sin(i * PI / 180) * seeing_radius));
    }

    std::size_t n = map.getMapObjNumber();
    for (int k = 0; k < 360; ++k) {
        double min = seeing_radius;
        for (std::size_t i = 0; i < n; ++i) {
            std::size_t m = map[i].getPointCount();
            for (std::size_t j = 0; j < m - 1; ++j) {
                sf::Vector2f point = find_intersection(player.getPosition(), seeing[k].position,
                                                map[i].getPoint(j), map[i].getPoint(j + 1));
                double current_radius = len(player.getPosition(), point);
                if (current_radius < min) {
                    min = current_radius;
                }
            }
            sf::Vector2f point = find_intersection(player.getPosition(), seeing[k].position,
                                                map[i].getPoint(0), map[i].getPoint(m - 1));
            double current_radius = len(player.getPosition(), point);
            if (current_radius < min) {
                min = current_radius;
            }
        }
        seeing[k] = sf::Vertex(player.getPosition() + sf::Vector2f(cos(k * PI / 180) * min, -1 * sin(k * PI / 180) * min));
    }
    
    for (int i = 0; i < 360; ++i) {
        demo_area[i] = sf::Vertex(sf::Vector2f((seeing[i].position - player.getPosition()).x * 170.f / seeing_radius,
                                (seeing[i].position - player.getPosition()).y * 170.f / seeing_radius) + demo.getPosition());
    }

    view[0] = sf::Vertex(player.getPosition());
    direction;
    for (int i = 1; i < viewing_angle; ++i) {
        int d = direction + i;
        if (d >= 360) {
            d -= 360;
        }
        view[i + viewing_angle] = seeing[d];
    }
    view[viewing_angle] = seeing[direction];
    for (int i = 1; i < viewing_angle; ++i) {
        int d = direction - i;
        if (d < 0) {
            d += 360;
        }
        view[viewing_angle - i] = seeing[d];
    }
    for (auto& v : view) {
        v.color = sf::Color(190, 145, 125, 120);
    }
}

std::vector<sf::Vector2f> Camera::getVisiblePoints() const {
    std::vector<sf::Vector2f> res;
    double rotation_angle = (direction - 90) * PI / 180;
    for (int i = view.size(); i > 1; --i) {
        sf::Vector2f original_vector = view[i].position - player.getPosition();
        sf::Vector2f rotated_vector(original_vector.x * cos(rotation_angle) - original_vector.y * sin(rotation_angle),
                                    original_vector.x * sin(rotation_angle) + original_vector.y * cos(rotation_angle));
        res.push_back(rotated_vector);
    }
    return res;
}

double Camera::getRenderDistance() const {
    return seeing_radius;
}