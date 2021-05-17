#pragma onse
#include <SFML/Graphics.hpp>



class Figure : public sf::RectangleShape, public sf::CircleShape, public sf::VertexArray {
private:

    enum Type {
        TRIANGLE,
        RECTANGLE,
        CIRCLE
    } type;

public:

    Figure(const sf::CircleShape&);

    Figure(const sf::RectangleShape&);
    
    Figure(const sf::VertexArray&);

    void draw(sf::RenderWindow&) const;

    void setFillColor(const sf::Color&);

    std::size_t getPointCount() const;

    sf::Vector2f getPoint(std::size_t) const;

};
