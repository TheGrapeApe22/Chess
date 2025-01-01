#pragma once
#include <string>

constexpr bool goofyEnPassant = false;
constexpr bool freedom = true;
constexpr int stonkfish_depth = 3;


const std::string starting_fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

constexpr int square_size {128};
constexpr float circle_scale {0.125};
const sf::Vector2i board_shift {square_size*3/4, square_size*3/4};

const std::string project_dir = "C:/Users/rohan/OneDrive/Documents/codee/cpp/chess";
// const std::string project_dir = "../..";

// add castle/en passant flags instead of k/j/r/q
// make fen work with castled kings
