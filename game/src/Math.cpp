#include "Math.h"
sf::Vector2f Math::NormalizeVector(sf::Vector2f vector)
{
    float m = sqrt(vector.x * vector.x + vector.y * vector.y);
    sf::Vector2f normalizedVector;

    normalizedVector.x = vector.x / m;
    normalizedVector.y = vector.y / m;
    return  normalizedVector;
}
bool Math::DidRectCollide(sf::FloatRect rect1, sf::FloatRect rect2)
{
    if (rect1.position.x + rect1.size.x > rect2.position.x &&
        rect2.position.x + rect2.size.x > rect1.position.x &&
        rect2.position.y + rect2.size.y > rect1.position.y &&
        rect1.position.y + rect1.size.y > rect2.position.y)
    {
        return true;
    }

    return false;
}