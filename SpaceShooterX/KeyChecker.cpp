#include <SFML/Graphics.hpp>

class KeyChecker
{
public:
    KeyChecker()
    {
        Check();
    }

    bool Left, Right, Up, Down, LeftClick, RightClick;
    void Check()
    {
        Left = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
        Right = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
        Up = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
        Down = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
        LeftClick = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
        RightClick = sf::Mouse::isButtonPressed(sf::Mouse::Button::Right);
    }

    bool BotherMoving()
    {
        return Left || Right || Up || Down;
    }

    bool LeftClickFired()
    {
        return LeftClick;
    }

    bool RightClickFired()
    {
        return RightClick;
    }
};