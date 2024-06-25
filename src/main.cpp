#include <SFML/Graphics.hpp>
#include <iostream>
#include "core/Input.hpp"
#include "core/Entity.hpp"
#include "components/PositionComponent.hpp"
#include "components/VelocityComponent.hpp"
#include "physics/PhysicsComponent.hpp"
#include "physics/CollisionComponent.hpp"
#include "systems/MovementSystem.hpp"
#include "physics/PhysicsSystem.hpp"
#include "physics/CollisionSystem.hpp"

int main() {
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ember Engine");

    // Create an entity manager
    ember::EntityManager entityManager;

    // Create the movement, physics, and collision systems
    ember::MovementSystem movementSystem;
    ember::PhysicsSystem physicsSystem;
    ember::CollisionSystem collisionSystem;

    // Create an entity and add components
    ember::Entity player = entityManager.createEntity();
    entityManager.addComponent(player, ember::PositionComponent{200, 150});
    entityManager.addComponent(player, ember::VelocityComponent{50, 50}); // Velocity in pixels per second
    entityManager.addComponent(player, ember::PhysicsComponent{10.0f, 1.5f}); // Mass and drag
    entityManager.addComponent(player, ember::CollisionComponent{20, 20}); // Width and height for collision

    // Initialize the Input handler
    ember::Input input;

    // Set up the clock for time management
    sf::Clock clock;

    // Start the game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            input.update(event);

            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
            // Close window when Escape key is pressed
            if (input.isKeyPressed(sf::Keyboard::Escape))
                window.close();
        }

        // Get the elapsed time
        float deltaTime = clock.restart().asSeconds();

        // Update systems
        physicsSystem.update(entityManager, deltaTime);
        collisionSystem.update(entityManager);
        movementSystem.update(entityManager, deltaTime);

        // Get the updated position of the player
        auto& position = entityManager.getComponent<ember::PositionComponent>(player);

        // Clear screen
        window.clear();

        // Draw the updated position of the player
        sf::CircleShape playerShape(10);
        playerShape.setFillColor(sf::Color::Green);
        playerShape.setPosition(position.x, position.y);
        window.draw(playerShape);

        // Update the window
        window.display();
    }

    return 0;
}
