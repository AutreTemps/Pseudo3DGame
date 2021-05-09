#pragma onse
#include <SFML/Graphics.hpp>

class Figure : public sf::RectangleShape, public sf::CircleShape, public sf::VertexArray {
private:

    char type;

    static const char RECTANGLE = 'r';
    static const char CIRCLE = 'c';
    static const char TRIANGLE = 't';

public:

    Figure(const sf::CircleShape&);

    Figure(const sf::RectangleShape&);
    
    Figure(const sf::VertexArray&);

    void draw(sf::RenderWindow&);

    void setFillColor(const sf::Color&);
};
