#pragma once
#include <SFML/Graphics.hpp>
#include <boardstates.h>

class Bd;

namespace game {
    void init ();
    void tick (sf::RenderWindow&);
    void setPieceBoard (const Bd&);
    
    // user events
    void mousePressed (sf::Vector2f);
    void mouseReleased (sf::Vector2f);
    void flipBoard (int);
    void stonkfishMove ();
    void printBoard ();
    void undoMove ();
    void redoMove ();
    void debug ();
}
