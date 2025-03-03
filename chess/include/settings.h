#pragma once
#include <string>

constexpr bool goofyEnPassant = false;
constexpr bool freedom = true;
constexpr int stonkfish_depth = 3;
constexpr int capture_depth = 2;

const std::string starting_fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
// const std::string starting_fen = "4k3/8/4K1R1/8/8/8/8/8 w";

constexpr int square_size {128};
constexpr float circle_scale {0.125};
const sf::Vector2i board_shift {square_size*3/4, square_size*3/4};

const std::string project_dir = "C:/Users/rohan/OneDrive/Documents/codee/cpp/chess";
// const std::string project_dir = "../..";

