#include "map.hpp"

Map::Map() {
    generate();
}

void Map::generate() {

    const sf::Color MAP_COLOR = sf::Color(144, 207, 255);

    sf::RectangleShape edge_l(sf::Vector2f(10.f, 395.f));
    edge_l.setPosition(sf::Vector2f(5.f, 5.f));
    objects.push_back(edge_l);

    sf::RectangleShape edge_r(sf::Vector2f(10.f, 395.f));
    edge_r.setPosition(sf::Vector2f(390.f, 5.f));
    objects.push_back(edge_r);

    sf::RectangleShape edge_t(sf::Vector2f(395.f, 10.f));
    edge_t.setPosition(sf::Vector2f(5.f, 5.f));
    objects.push_back(edge_t);

    sf::RectangleShape edge_b(sf::Vector2f(395.f, 10.f));
    edge_b.setPosition(sf::Vector2f(5.f, 390.f));
    objects.push_back(edge_b);

    sf::CircleShape column1(40, 4);
    column1.setPosition(sf::Vector2f(95.f, 110.f));
    objects.push_back(column1);

    sf::VertexArray triangle_lt(sf::Triangles, 3);
    triangle_lt[0].position = sf::Vector2f(15.f, 15.f);
    triangle_lt[1].position = sf::Vector2f(70.f, 15.f);
    triangle_lt[2].position = sf::Vector2f(15.f, 70.f);
    objects.push_back(triangle_lt);

    sf::VertexArray triangle_rb(sf::Triangles, 3);
    triangle_rb[0].position = sf::Vector2f(390.f, 390.f);
    triangle_rb[1].position = sf::Vector2f(335.f, 390.f);
    triangle_rb[2].position = sf::Vector2f(390.f, 335.f);
    objects.push_back(triangle_rb);

    sf::RectangleShape wall1(sf::Vector2f(10.f, 120.f));
    wall1.setPosition(sf::Vector2f(250.f, 15.f));
    objects.push_back(wall1);

    sf::RectangleShape wall2(sf::Vector2f(70.f, 10.f));
    wall2.setPosition(sf::Vector2f(260.f, 135.f));
    objects.push_back(wall2);

    sf::VertexArray triangle_wall1(sf::Triangles, 3);
    triangle_wall1[0].position = sf::Vector2f(260.f, 135.f);
    triangle_wall1[1].position = sf::Vector2f(260.f, 125.f);
    triangle_wall1[2].position = sf::Vector2f(270.f, 135.f);
    objects.push_back(triangle_wall1);

    sf::VertexArray triangle_wall2(sf::Triangles, 3);
    triangle_wall2[0].position = sf::Vector2f(260.f, 135.f);
    triangle_wall2[1].position = sf::Vector2f(260.f, 145.f);
    triangle_wall2[2].position = sf::Vector2f(250.f, 135.f);
    objects.push_back(triangle_wall2);

    sf::CircleShape column2(50);
    column2.setPosition(sf::Vector2f(50.f, 250.f));
    objects.push_back(column2);

    sf::RectangleShape wall3(sf::Vector2f(10.f, 60.f));
    wall3.setPosition(sf::Vector2f(95.f, 340.f));
    objects.push_back(wall3);

    sf::RectangleShape wall4(sf::Vector2f(10.f, 120.f));
    wall4.setPosition(sf::Vector2f(130.f, 10.f));
    objects.push_back(wall4);

    for (auto& object : objects) {
        object.setFillColor(MAP_COLOR);
    }
}

void Map::draw(sf::RenderWindow& window) const {
    for (auto& object : objects) {
        object.draw(window);
    }
}

Figure& Map::operator[](std::size_t i) {
    return objects[i];
}

std::size_t Map::getMapObjNumber() const {
    return objects.size();
}