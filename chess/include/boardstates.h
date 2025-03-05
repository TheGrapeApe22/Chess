#pragma once
#include <SFML/Graphics.hpp>
#include <pieces.h>
#include <vector>
#include <stack>
#include <bitset>

class Bd {
    public:
    struct Move {
        sf::Vector2i start {};
        sf::Vector2i end {};
        char captured_piece = ' ';
        bool isCastle {};
        bool isEnPassant {};
        bool isPromotion {};
        std::bitset<6> castle_state;
        inline bool operator== (const Bd::Move& other) const {
            return start == other.start
             && end == other.end;
        }
    };

    struct MoveData {
        float eval {};
        std::stack<Move> moveStack {};
    };
    
    // attributes
    std::vector<std::vector<char>> board {8, std::vector(8, ' ')};
    bool isWhiteTurn {true};
    
    // (0) white king didn't move, (1) Q rook didn't move, (2) K rook didn't move, 
    // (3) black king didn't move, (4) q rook didn't move, (5) k rook didn't move, 
    std::bitset<6> castle_state {"111111"};
    sf::Vector2i ep_pawn {-1, -1};

    // constructors
    Bd (const std::string& fen) {
        loadFromFen(fen);
    };
    /*Bd (const Bd& copy) {
        board = copy.board;
        castle_state = copy.castle_state;
        ep_pawn = {copy.ep_pawn};
    }*/

    // methods
    void getMoves (const sf::Vector2i&, std::vector<Move>&) const;
    void getAllMoves (std::vector<Move>&) const;
    void loadFromFen (const std::string&);
    std::string getFen ();
    
    void makeMove (const Move&);
    void undoMove (const Move&);
    void print ();
    
    float static_eval () const;

    MoveData minimax (int depth, float alpha, float beta);

    void stonkfish ();

    inline bool operator== (const Bd& other) const { return board == other.board; }
};
