#include <SFML\Graphics.hpp>
#include <cassert>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
class KeyChecker
{
    public:
        KeyChecker()
        {
            Check();
        }

        bool Left, Right, Up, Down;
        void Check()
        {
            Left = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
            Right = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
            Up = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
            Down = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
        }

        bool BotherMoving()
        {
            return Left || Right || Up || Down;
        }
};

class MoveHandler {
private:
    KeyChecker checker;
public:
    void CheckAndMove(sf::Sprite *sprite) {
        checker.Check();
        if (checker.BotherMoving())
        {
            float x = 0;
            float y = 0;
            if (checker.Left)
            {
                x -= .1;
            }
            if (checker.Right)
            {
                x += .1;
            }
            if (checker.Up)
            {
                y -= .1;
            }
            if (checker.Down)
            {
                y += .1;
            }
            sprite->move(x, y);
        }
    }
};

int main() {
    sf::RenderWindow sfmlWin(sf::VideoMode(800, 600), "Hello World SFML Window");
    sf::Texture texture;

    //You need to pass the font file location
    if (!texture.loadFromFile(/*
                           Put the filename that identify the font file you want to load*/"C:\\SFML-2.5.1\\test.jpg")) {
        return -1;
    }
    
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setScale(.1, .1);
    MoveHandler handler;
    while (sfmlWin.isOpen()) {
        sfmlWin.clear();
        handler.CheckAndMove(&sprite);
        sfmlWin.draw(sprite);
        sfmlWin.display();
    }
    return 0;
}