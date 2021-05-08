#pragma onse
#include <SFML/Graphics.hpp>

class Frame {
private:

    std::vector<sf::RectangleShape> frame_objects;


public:

    Frame();

    void draw(sf::RenderWindow&);
};