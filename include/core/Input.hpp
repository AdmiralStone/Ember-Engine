#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <unordered_map>

/**
 * @namespace ember
 * @brief Namespace for all Ember Engine related code.
 */
namespace ember {

/**
 * @class Input
 * @brief Handles input from keyboard and mouse.
 */
class Input {
public:
    /**
     * @brief Updates the state of keys and mouse buttons based on the events received.
     * @param event The event received from the SFML window.
     */
    void update(const sf::Event& event);

    /**
     * @brief Checks if a specific key is currently pressed.
     * @param key The key to check.
     * @return True if the key is pressed, false otherwise.
     */
    bool isKeyPressed(sf::Keyboard::Key key) const;

    /**
     * @brief Checks if a specific mouse button is currently pressed.
     * @param button The mouse button to check.
     * @return True if the mouse button is pressed, false otherwise.
     */
    bool isMouseButtonPressed(sf::Mouse::Button button) const;

    /**
     * @brief Retrieves the current position of the mouse relative to the window.
     * @param window The reference to the SFML window.
     * @return The position of the mouse as a vector.
     */
    sf::Vector2i getMousePosition(const sf::RenderWindow& window) const;

private:
    std::unordered_map<sf::Keyboard::Key, bool> keyState_; ///< State of keys.
    std::unordered_map<sf::Mouse::Button, bool> mouseButtonState_; ///< State of mouse buttons.
};

} // namespace ember
