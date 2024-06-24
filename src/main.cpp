#include <SFML/Graphics.hpp>
#include <iostream>
#include "Input.hpp"
#include "Entity.hpp"
#include "PositionComponent.hpp"
#include "VelocityComponent.hpp"
#include "MovementSystem.hpp"

int main(){
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800,600), "Ember Engine");

    // Create an entity manager
    ember::EntityManager entityManager;

    // Create Movement system
    ember::MovementSystem movementSystem;

    // Create an entity and add components
    ember::Entity player = entityManager.createEntity();
    entityManager.addComponent(player,ember::PositionComponent{200,150});
    entityManager.addComponent(player,ember::VelocityComponent{50,50});


    // Set up the clock for time management
    sf::Clock clock;
    // float spriteSpeed = 200.0f; // Pixels per sec

    /* Development Code END*/

    ember::Input input;

    // Start the game loop
    while(window.isOpen()){
        // Process Event
        sf::Event event;
        while(window.pollEvent(event)){
            //Update the input event
            input.update(event);

            // Close window : exit
            if(event.type == sf::Event::Closed) window.close();

            // Close window when Escape key is pressed
            if(input.isKeyPressed(sf::Keyboard::Escape))window.close();
        }

        // Get the elapsed time
        float deltaTime = clock.restart().asSeconds();

        // Move the sprite
        // float moveDistance = spriteSpeed * deltaTime.asSeconds();
        // if(input.isKeyPressed(sf::Keyboard::Right)){
        //     sprite.move(moveDistance,0); // Move sprite right
        // }
        // if(input.isKeyPressed(sf::Keyboard::Left)){
        //     sprite.move(-moveDistance,0); // Move sprite left
        // }
        // if(input.isKeyPressed(sf::Keyboard::Up)){
        //     sprite.move(0,-moveDistance); // Move sprite up
        // }
        // if(input.isKeyPressed(sf::Keyboard::Down)){
        //     sprite.move(0,moveDistance); // Move sprite down
        // }

        // Update the movement system
        movementSystem.update(entityManager,deltaTime);

        // Get the update position os the player
        auto& position = entityManager.getComponent<ember::PositionComponent>(player);

        

        // Clear screen
        window.clear(sf::Color::White);

        // Render the sprite
        // window.draw(sprite);

        // Draw the updated position of the player
        sf::CircleShape playerShape(10);
        playerShape.setFillColor(sf::Color::Green);
        playerShape.setPosition(position.x,position.y);
        window.draw(playerShape);


        // Update wthe window
        window.display();
    }

    return 0;
}
