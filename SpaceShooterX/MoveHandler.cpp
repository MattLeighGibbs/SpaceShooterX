#include "KeyChecker.cpp"
class MoveHandler {
private:
    KeyChecker checker;
public:
    void CheckAndMove(sf::Sprite* sprite) {
        checker.Check();
        if (checker.BotherMoving())
        {
            float x = 0;
            float y = 0;
            if (checker.Left)
            {
                x -= .2;
            }
            if (checker.Right)
            {
                x += .2;
            }
            if (checker.Up)
            {
                y -= .2;
            }
            if (checker.Down)
            {
                y += .2;
            }
            sprite->move(x, y);
        }
    }

    bool ShouldFire()
    {
        checker.Check();
        if (checker.LeftClick)
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
};
