#include <boardstates.h>
#include <iostream>
#include <settings.h>
#include <unordered_map>
#include <stdio.h>
#include <cmath>

void Bd::loadFromFen (const std::string& fen) {
    int x = 0;
    int y = 0;
    for (int i = 0; i < fen.size(); i++) {
        char c = fen[i];

        if (isalpha(c)) {
            board[x][y] = c;
        }
        if (isdigit(c)) {
            int temp = x;
            x += (c - '0');
            for (int i = temp; i < x; i++) {
                board[i][y] = ' ';
            }
        }
        else x++;

        if (c == '/') {
            x = 0;
            y++;
            if (y > 7) break;
        }
        if (c == ' ') {
            isWhiteTurn = (fen[i+1] == 'w');
            i += 3;
            // initial state: no one can castle
            castle_state.reset();
            while (fen[i] != ' ') {
                switch (fen[i]) {
                    case 'K':
                        castle_state[0] = true;
                        break;
                    case 'Q':
                        castle_state[1] = true;
                        break;
                    case 'k':
                        castle_state[2] = true;
                        break;
                    case 'q':
                        castle_state[3] = true;
                        break;
                }
                i++;
            }
            return;
        }
    }
    // todo
}
std::string Bd::getFen () {
    std::string output = "";
    for (int y = 0; y < 8; y++) {
        int numSpaces = 0;
        for (int x = 0; x < 8; x++) {
            char type = board[x][y];
            
            if (type == ' ') numSpaces++;
            else {
                if (numSpaces > 0) {
                    output += std::to_string(numSpaces);
                    numSpaces = 0;
                }
                output += type;
            }
        }
        if (numSpaces > 0) output += std::to_string(numSpaces);
        if (y < 7) output += "/";
    }
    output += " ";
    output += (isWhiteTurn ? "w" : "b");
    output += " ";
    if (castle_state[0]) output += 'K';
    if (castle_state[1]) output += 'Q';
    if (castle_state[2]) output += 'k';
    if (castle_state[3]) output += 'q';

    return output;
}

void Bd::print () {
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            std::cout << board[x][y] << " ";
        }
        std::cout << "\n";
    }
    std::cout << getFen() << "\n" << castle_state << "\n";
}

std::vector<Bd::Move> Bd::getMoves (const sf::Vector2i& startPos) const {
    std::vector<Move> out {};

    char type = board[startPos.x][startPos.y];

    if (type == ' ') {
        std::cout << "not a piece - Bd::getMoves()" << std::endl;
        return out;
    }

    std::vector <sf::Vector2i> relative_moves;

    char lowerType = tolower(type);
    // knight
    if (lowerType == 'n') {
        relative_moves = {
            sf::Vector2i {-1,  2},
            sf::Vector2i { 1,  2},
            sf::Vector2i { 2,  1},
            sf::Vector2i { 2, -1},
            sf::Vector2i { 1, -2},
            sf::Vector2i {-1, -2},
            sf::Vector2i {-2, -1},
            sf::Vector2i {-2,  1},
        };
    }
    // king
    if (lowerType == 'k') {
        relative_moves = {
            sf::Vector2i { 1,  0},
            sf::Vector2i { 1,  1},
            sf::Vector2i { 0,  1},
            sf::Vector2i {-1,  1},
            sf::Vector2i {-1,  0},
            sf::Vector2i {-1, -1},
            sf::Vector2i { 0, -1},
            sf::Vector2i { 1, -1},
        };
    }
    // castles
    if (lowerType == 'k' && startPos.x == 4) {
        // kingside
        if (board[startPos.x+1][startPos.y] == ' ' && board[startPos.x+2][startPos.y] == ' ' && tolower(board[startPos.x+3][startPos.y]) == 'r') {
            if (castle_state[0] && isupper(type) || castle_state[2] && islower(type))
                relative_moves.push_back(sf::Vector2i {2, 0});
        }
        // queenside
        if (board[startPos.x-1][startPos.y] == ' ' && board[startPos.x-2][startPos.y] == ' ' && board[startPos.x-3][startPos.y] == ' ' && tolower(board[startPos.x-4][startPos.y]) == 'r') {
            if (castle_state[1] && isupper(type) || castle_state[3] && islower(type))
                relative_moves.push_back(sf::Vector2i {-2, 0});
        }
    }
    // pawn
    if (lowerType == 'p') {
        // move up/down depending on color
        int push1 = isupper(type) ? -1 : 1;
        relative_moves = {
            sf::Vector2i {0, push1},
            sf::Vector2i {1, push1},
            sf::Vector2i {-1, push1},
        };
        // push 2 squares
        if (startPos.y == 1 || startPos.y == 6)
            relative_moves.push_back(sf::Vector2i {0, push1 * 2});
    }
    // all pieces that move in a line
    if (lowerType == 'b' || lowerType == 'q' || lowerType == 'r') {
        std::vector <sf::Vector2i> lineMoves {};

        // diagonal moves
        if (lowerType == 'b' || lowerType == 'q') {
            lineMoves.push_back(sf::Vector2i { 1,  1});
            lineMoves.push_back(sf::Vector2i { 1, -1});
            lineMoves.push_back(sf::Vector2i {-1,  1});
            lineMoves.push_back(sf::Vector2i {-1, -1});
        }

        // vertical/horizontal moves
        if (lowerType == 'r' || lowerType == 'q') {
            lineMoves.push_back(sf::Vector2i { 1,  0});
            lineMoves.push_back(sf::Vector2i {-1,  0});
            lineMoves.push_back(sf::Vector2i { 0,  1});
            lineMoves.push_back(sf::Vector2i { 0, -1});
        }

        for (sf::Vector2i lMove : lineMoves) {
            for (int i = 1; i <= 8; i++) {
                sf::Vector2i endPos {startPos + lMove * i};
                
                // check out of bounds
                if (endPos.x < 0 || endPos.x > 7 || endPos.y < 0 || endPos.y > 7) break;

                // stop if piece found
                char dest = board[endPos.x][endPos.y];
                relative_moves.push_back(lMove * i);
                if (dest != ' ') {
                    break;
                }
                // else keep moving along the line
            }
        }
    }

    // filter
    for (sf::Vector2i move : relative_moves) {
        sf::Vector2i endPos {startPos + move};
        // check out of bounds
        if (endPos.x < 0 || endPos.x > 7 || endPos.y < 0 || endPos.y > 7) continue;

        char capture = board[endPos.x][endPos.y];
        bool isCastle = false;
        bool isEnPassant = false;

        // check if capturing same color
        if (capture != ' ') {
            if (isupper(capture) == isupper(type))
                continue;
        }

        // filter pawn moves
        if (lowerType == 'p') {
            // if move is diagonal and there is no piece to capture
            if (abs(move.x) == 1) {
                // check en passant
                if (ep_pawn.x != -1) {
                    if (ep_pawn.y == startPos.y && ep_pawn.x == endPos.x
                        && (isupper(board[ep_pawn.x][ep_pawn.y]) != isupper(type)))
                        isEnPassant = true;
                }
                else if (goofyEnPassant && board[endPos.x][startPos.y] != ' ')
                    isEnPassant = true;

                // if no en passant
                if (capture == ' ' && !isEnPassant)
                    continue;
            }
            // if move is forward and there is a piece blocking
            else if (capture != ' ')
                continue;
            // if move is 2 spaces
            else if (abs(move.y) == 2) {
                // check if the first space is blocked
                if (board[endPos.x][startPos.y + move.y/2] != ' ') {
                    continue;
                }
            }
        }
        if (lowerType == 'k' && abs(move.x) == 2)
            isCastle = true;

        // return legal endPos
        out.push_back(Move {startPos, endPos, capture, isCastle, isEnPassant, castle_state});
    }

    return std::move(out);
}

void Bd::makeMove (const Move& m) {
    const sf::Vector2i& start = m.start;
    const sf::Vector2i& end = m.end;

    char type = board[start.x][start.y];
    if (type == ' ') {
        std::cout << "Not a piece: bd::makeMove" << std::endl;
        return;
    }

    board[end.x][end.y] = type;

    ep_pawn = {-1, -1};

    if (tolower(type) == 'p') {
        if (m.isEnPassant) {
            board[end.x][start.y] = ' ';
        }

        // enable future en passant
        if (abs(end.y - start.y) == 2) {
            ep_pawn = {end};
        }

        // check pawn promotion
        if (end.y == 0 || end.y == 7) {
            board[end.x][end.y] = (isupper(type) ? 'Q' : 'q');
        }
    }
    // check castle
    else if (m.isCastle) {
        // short castles, move rook
        if (end.x - start.x == 2) {
            board[end.x-1][end.y] = isupper(type) ? 'R' : 'r';
            board[end.x+1][end.y] = ' ';
        }
        // long castles, move rook
        else if (end.x - start.x == -2) {
            board[end.x+1][end.y] = isupper(type) ? 'R' : 'r';
            board[end.x-2][end.y] = ' ';
        }

        // disable castling
        castle_state.reset();
    }
    // disable castling
    if (tolower(type) == 'r') {
        if (m.start.x == 0) {
            if (m.start.y == 0)
                castle_state[3] = false;
            if (m.start.y == 7)
                castle_state[1] = false;
        } else if (m.start.x == 7) {
            if (m.start.y == 0)
                castle_state[2] = false;
            if (m.start.y == 7)
                castle_state[0] = false;
        }
    }
    else if (tolower(type) == 'k') {
        
    }

    // remove piece from old square
    board[start.x][start.y] = ' ';
    
    isWhiteTurn = !isWhiteTurn;
}
void Bd::undoMove (const Move& m) {
    board[m.start.x][m.start.y] = board[m.end.x][m.end.y];
    board[m.end.x][m.end.y] = m.captured_piece;

    isWhiteTurn = !isWhiteTurn;
    
    if (m.isEnPassant) {
        ep_pawn = {m.end.x, m.start.y};
        board[ep_pawn.x][ep_pawn.y] = isWhiteTurn ? 'p' : 'R';
    }
    if (m.isCastle) {
        if (m.end.x - m.start.x == 2) {
            board[7][m.end.y] = isWhiteTurn ? 'R' : 'r';
            board[5][m.end.y] = ' ';
        } else {
            board[0][m.end.y] = isWhiteTurn ? 'R' : 'r';
            board[3][m.end.y] = ' ';
        }
    }
    castle_state = m.prev_castle_state;
}

const std::unordered_map<char, float> piece_values = {
    {'p', 1},
    {'n', 3},
    {'b', 3},
    {'r', 5},
    {'s', 5},
    {'q', 7},
    {'k', 100}
};
std::vector<float> row_values = {0.98, 0.99, 1.00, 1.01, 1.01, 1.00, 0.99, 0.98};

float Bd::static_eval () const {
    float total = 0;
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            char c = board[x][y];
            char lower = tolower(c);

            if (c == ' ') continue;
            int multiplier = isupper(c) ? 1 : -1;

            float value = piece_values.at(lower);

            std::vector<Move> moves = getMoves(sf::Vector2i {x, y});
            
            float mobility = moves.size();
            mobility = sqrt(mobility) / piece_values.at(lower);
            // haha hardcoding go brrr
            if (lower == 'p' || lower == 'q') mobility *= 0.01f;

            value += mobility * 0.01f * row_values[x] * row_values[y];
            
            value *= multiplier;
            total += value;
        }
    }
    return total;
}
std::string getCoord(sf::Vector2i p) {
    std::string out = "";
    out += ('a' + p.x);
    out += ('8' - p.y);
    return out;
}

int numCalls = 0;
int numPruned = 0;
Bd::MoveData Bd::minimax (int depth, float alpha, float beta) {
    numCalls++;
    
    if (numCalls > 500000) {
        std::cout << "abortion\n";
        abort();
    }

    if (depth <= 0) return MoveData {static_eval()};
    
    int multiplier = isWhiteTurn ? 1 : -1;
    MoveData out {-200.f * multiplier};
    Move bestMove {};

    // for every piece
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            char type = board[x][y];
            if (type == ' ') continue;
            if (isupper(type) != isWhiteTurn) continue;
            
            std::vector<Move> moves = getMoves(sf::Vector2i {x, y});

            for (Move& move : moves) {
                // check win
                if (tolower(move.captured_piece) == 'k') {
                    out.moveStack.push(move);
                    out.eval = -999.f * (isupper(move.captured_piece) ? 1 : -1);
                    return out;
                }

                // move
                makeMove(move);

                // recursion + eval
                MoveData child = minimax(depth - 1, alpha, beta);
                
                if (child.eval * multiplier > out.eval * multiplier) {
                    out.eval = child.eval;
                    out = child;
                    bestMove = move;
                }

                undoMove(move);

                // alpha-beta pruning
                if (isWhiteTurn) {
                    alpha = std::max(alpha, out.eval);
                }
                else {
                    beta = std::min(beta, out.eval);
                }
                // prune if opponent will choose a different eval over this one
                if (alpha >= beta) {
                    numPruned++;
                    break;
                }
            }
        }
    }
    out.moveStack.push(bestMove);

    return out;
}

void Bd::stonkfish () {
    numCalls = 0;
    numPruned = 0;
    
    std::cout << "static eval: " << static_eval() << "\n";

    MoveData bestMove = minimax(stonkfish_depth, -1000, 1000);
    std::cout << numCalls << " calls, " << numPruned << " pruned ";
    
    while (!bestMove.moveStack.empty()) {
        std::cout << "(" << getCoord(bestMove.moveStack.top().start) << ", "
            << getCoord(bestMove.moveStack.top().end) << ") ";
        bestMove.moveStack.pop();
    }
    std::cout << bestMove.eval;
    std::cout << std::endl;
}
