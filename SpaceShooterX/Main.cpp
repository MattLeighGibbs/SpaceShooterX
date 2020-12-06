#include <SFML\Graphics.hpp>
#include "MoveHandler.cpp"
#include <cassert>
class Bullet : public sf::Sprite {
public:
    Bullet(sf::Sprite *player) {
        sf::Texture texture;
        texture.loadFromFile("C:\\SFML-2.5.1\\projectile.png");
        setTexture(texture);
        setPosition(player->getPosition().x + player->getGlobalBounds().width / 2, player->getPosition().y);
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
    std::vector<sf::Sprite> bullets;
    int bulletCount = 0;

    while (sfmlWin.isOpen()) {
        sfmlWin.clear();
        handler.CheckAndMove(&sprite);   

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            Bullet newBullet = Bullet(&sprite);
            bullets.push_back(newBullet);
            bulletCount++;
        }
        if (bulletCount > 0)
        {
            if (bulletCount > 50)
            {
                bullets.pop_back();
                bullets.pop_back();
            }
            for (auto& it : bullets) {

                sfmlWin.draw(it);
            }
        }

        sfmlWin.draw(sprite);
            
        sfmlWin.display();
    }

    return 0;
}