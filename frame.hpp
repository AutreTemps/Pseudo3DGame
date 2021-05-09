#pragma onse
#include <SFML/Graphics.hpp>
#include <vector>

class Frame {
private:

    std::vector<sf::RectangleShape> objects;

public:

    Frame();

    void draw(sf::RenderWindow&);

private:
    
    void generate();
};