#pragma once
#include <SFML/Graphics.hpp>
#include <board_ui.h>
#include <settings.h>

sf::Vector2f getRealPos (float, float);
sf::Vector2f getRealPos (const sf::Vector2i&);

class Piece {
    public:
    
    char type {};
    bool toggled {};

    sf::Texture texture {};
    sf::Sprite sprite {};

    sf::Vector2<int> boardPos {};
    sf::Vector2f realPos {};
    
    Piece (char type1, sf::Vector2i boardPos1):
    type {type1}, boardPos {boardPos1} {
        this->init();
    }
    Piece (const Piece& p):
    Piece(p.type, p.boardPos) {
    }

    void draw (sf::RenderWindow&);
    void resetPos ();
    void init ();
    void moveToMouse (sf::Vector2f);
    inline bool containsPoint (sf::Vector2f mousePos) {
        return this->sprite.getGlobalBounds().contains(sf::Vector2f(mousePos.x, mousePos.y));
    }
};

class Square {
    public:
    const int size {};
    sf::Vector2i boardPos {};
    sf::RectangleShape rect {};
    
    Square (int x, int y, int s=square_size):
    boardPos {x, y}, size {s} {
        this->init();
    }
    Square (const Square& sq):
    boardPos {sq.boardPos}, size {sq.size} {
        this->init();
    }
    
    void init();
};
