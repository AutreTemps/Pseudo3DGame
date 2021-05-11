#pragma onse
#include <SFML/Graphics.hpp>

enum Type {
    TRIANGLE,
    RECTANGLE,
    CIRCLE
};

class Figure : public sf::RectangleShape, public sf::CircleShape, public sf::VertexArray {
private:

    Type type;

public:

    Figure(const sf::CircleShape&);

    Figure(const sf::RectangleShape&);
    
    Figure(const sf::VertexArray&);

    void draw(sf::RenderWindow&);

    void setFillColor(const sf::Color&);
};
