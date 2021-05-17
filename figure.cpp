#include "figure.hpp"

Figure::Figure(const sf::CircleShape& circle) : sf::CircleShape(circle) {
    type = CIRCLE;
}

Figure::Figure(const sf::RectangleShape& rect) : sf::RectangleShape(rect) {
    type = RECTANGLE;
}

Figure::Figure(const sf::VertexArray& arr) : sf::VertexArray(arr) {
    type = TRIANGLE;
}

void Figure::draw(sf::RenderWindow& window) const {
    if (type == RECTANGLE) {
        window.draw((sf::RectangleShape) *this);
    }
    else if (type == CIRCLE) {
        window.draw((sf::CircleShape) *this);
    }
    else if (type == TRIANGLE) {
        window.draw((sf::VertexArray) *this);
    }
}

void Figure::setFillColor(const sf::Color& color) {
    if (type == RECTANGLE) {
        sf::RectangleShape::setFillColor(color);
    }
    else if (type == CIRCLE) {
        sf::CircleShape::setFillColor(color);
    }
    else if (type == TRIANGLE) {
        for (int i = 0; i < this->getVertexCount(); ++i) {
            (*this)[i].color = color;
        }
    }
}

std::size_t Figure::getPointCount() const {
    if (type == RECTANGLE) {
        return sf::RectangleShape::getPointCount();
    }
    else if (type == CIRCLE) {
        return sf::CircleShape::getPointCount();
    }
    else if (type == TRIANGLE) {
        return sf::VertexArray::getVertexCount();
    }
}

sf::Vector2f Figure::getPoint(std::size_t index) const {
    if (type == RECTANGLE) {
        return sf::RectangleShape::getPoint(index);
    }
    else if (type == CIRCLE) {
        return sf::CircleShape::getPoint(index);
    }
    else if (type == TRIANGLE) {
        return ((sf::VertexArray) *this)[index].position;
    }
}