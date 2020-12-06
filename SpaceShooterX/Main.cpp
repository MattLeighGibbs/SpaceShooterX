#include <SFML\Graphics.hpp>
#include <cassert>

int main() {
    sf::RenderWindow sfmlWin(sf::VideoMode(600, 360), "Hello World SFML Window");
    sf::Texture texture;
    //You need to pass the font file location
    if (!texture.loadFromFile(/*
                           Put the filename that identify the font file you want to load*/"C:\\SFML-2.5.1\\test.png")) {
        return -1;
    }
    sf::Sprite sprite;
    sprite.setTexture(texture);
    while (sfmlWin.isOpen()) {

        sf::Event e;
        while (sfmlWin.pollEvent(e)) {

            switch (e.type) {
            case sf::Event::EventType::Closed:
                sfmlWin.close();
                break;
            }
        }

        sfmlWin.clear();
        sfmlWin.draw(sprite);
        sfmlWin.display();
    }
    return 0;
}