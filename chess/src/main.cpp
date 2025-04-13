#include <SFML/Graphics.hpp>
#include <iostream>
#include <board_ui.h>
#include <boardstates.h>
#include <settings.h>

int stonkfish_depth = 3;

int main() {

    sf::RenderWindow window (
        sf::VideoMode(sf::Vector2u {square_size * 8 + 2*board_shift.x, square_size * 8 + 2*board_shift.y}),
        "Segmentation fault (core dumped) (real) (fr) (on god) (no cap) (trustmebro.click)" // nothing to see here
    );
    window.setSize(sf::Vector2u {1024, 1024});
    window.setFramerateLimit(30);
    
    game::init();
    
    // game loop
    while (window.isOpen()) {
        // write a given window event to ev
        while (const std::optional ev = window.pollEvent()) {
            // mouse pressed
            if (ev->is<sf::Event::MouseButtonPressed>()) {
                game::mousePressed(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
            }
            // mouse released
            if (ev->is<sf::Event::MouseButtonReleased>()) {
                game::mouseReleased(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
            }

            // key pressed
            if (ev->is<sf::Event::KeyPressed>()) {
                switch (ev->getIf<sf::Event::KeyPressed>()->code) {
                    case sf::Keyboard::Key::F:
                        game::flipBoard(window.getSize().y);
                        break;
                    case sf::Keyboard::Key::P:
                        game::printBoard();
                        break;
                    case sf::Keyboard::Key::Left:
                        game::undoMove();
                        break;
                    case sf::Keyboard::Key::Right:
                        game::redoMove();
                        break;
                    case sf::Keyboard::Key::D:
                        // debug
                        game::debug();
                        break;
                    case sf::Keyboard::Key::E:
                        game::debug2();
                        break;
                    case sf::Keyboard::Key::Num3:
                        stonkfish_depth = 3;
                        std::cout << "Stonkfish depth is now " << stonkfish_depth << std::endl;
                        break;
                    case sf::Keyboard::Key::Num4:
                        stonkfish_depth = 4;
                        std::cout << "Stonkfish depth is now " << stonkfish_depth << std::endl;
                        break;
                    case sf::Keyboard::Key::Space:
                        game::stonkfishMove();
                        break;
                    case sf::Keyboard::Key::Escape:
                        window.close();
                        break;
                }
            }
            
            // window resized
            if (ev->is<sf::Event::Resized>()) {
                auto size = ev->getIf<sf::Event::Resized>()->size;
                // keep it square
                const int newSize = std::min(size.x, size.y);
                window.setSize(sf::Vector2u(newSize, newSize));
            }

            // close window
            if (ev->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        window.clear();
        game::tick(window);
        window.display();
    }
}
