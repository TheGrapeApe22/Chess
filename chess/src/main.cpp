#include <SFML/Graphics.hpp>
#include <iostream>
#include <board_runner.h>
#include <boardstates.h>
#include <settings.h>

int main() {
    sf::RenderWindow window (
        sf::VideoMode(square_size * 8 + 2*board_shift.x, square_size * 8 + 2*board_shift.y),
        "Segmentation fault (core dumped)" // nothing to see here
    );
    window.setSize(sf::Vector2u {1024, 1024});
    window.setFramerateLimit(30);
    
    game::init();
    
    // game loop
    while (window.isOpen()) {
        sf::Event ev;
        // write a given window event to ev
        while (window.pollEvent(ev)) {
            // mouse pressed
            if (ev.type == sf::Event::MouseButtonPressed) {
                game::mousePressed(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
            }
            // mouse released
            if (ev.type == sf::Event::MouseButtonReleased) {
                game::mouseReleased(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
            }

            // key pressed
            if (ev.type == sf::Event::KeyPressed) {
                switch (ev.key.code) {
                    case sf::Keyboard::F:
                        game::flipBoard(window.getSize().y);
                        break;
                    case sf::Keyboard::P:
                        game::printBoard();
                        break;
                    case sf::Keyboard::Left:
                        game::undoMove();
                        break;
                    case sf::Keyboard::Right:
                        game::redoMove();
                        break;
                    case sf::Keyboard::D:
                        // debug
                        game::debug();
                        break;
                    case sf::Keyboard::Space:
                        game::stonkfishMove();
                        break;
                    case sf::Keyboard::Escape:
                        window.close();
                        break;
                }
            }
            
            // window resized
            if (ev.type == sf::Event::Resized) {
                // keep it square
                const int newSize = std::min(ev.size.width, ev.size.height);
                window.setSize(sf::Vector2u(newSize, newSize));
            }

            // close window
            if (ev.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        game::tick(window);
        window.display();
    }
}
