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
        std::bitset<4> prev_castle_state;
        bool isCastle {};
        bool isEnPassant {};
        bool isPromotion {};
        
        inline bool operator== (const Bd::Move& other) const {
            return start == other.start
             && end == other.end;
        }
        bool isNullMove () const {return start.x == 0 && start.y == 0 && end.x == 0 && end.y == 0;}
    };

    struct MoveData {
        float eval {};
        std::stack<Move> moveStack {};
    };
    
    // attributes
    std::vector<std::vector<char>> board {8, std::vector(8, ' ')};
    bool isWhiteTurn {true};
    
    // KQkq are possible
    std::bitset<4> castle_state {"1111"};
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
    std::vector<Move> getMoves (const sf::Vector2i& startPos, bool captures_only) const;
    std::vector<Bd::Move> Bd::getAllMoves (bool captures_only) const;
    
    void loadFromFen (const std::string&);
    std::string getFen ();
    
    void makeMove (const Move&);
    void undoMove (const Move&);
    void print ();
    
    float static_eval () const;

    MoveData minimax (int depth, float alpha, float beta, bool capture_only);

    void stonkfish ();

    inline bool operator== (const Bd& other) const { return board == other.board; }
};
