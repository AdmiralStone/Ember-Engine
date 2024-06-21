#include <SFML/Graphics.hpp>
#include <iostream>
#include "Input.hpp"

int main(){
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800,600), "Ember Engine");

    /* Development Code START*/

    // Create a circle shape
    sf::CircleShape circle(50); // Radius of 50
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(350,250); // Position it in the middle of the window


    /*********************************************/
    // Load a Texture
    sf::Texture texture;
    if(!texture.loadFromFile("../assets/example.png")){
        std::cerr<<"Error loading texture"<< std::endl;
        return -1;
    }

    // Create a Sprite
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(200,150);

    // Set up the clock for time management
    sf::Clock clock;
    float spriteSpeed = 200.0f; // Pixels per sec

    /*********************************************/

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
        sf::Time deltaTime = clock.restart();

        // Move the sprite
        float moveDistance = spriteSpeed * deltaTime.asSeconds();
        if(input.isKeyPressed(sf::Keyboard::Right)){
            sprite.move(moveDistance,0); // Move sprite right
        }
        if(input.isKeyPressed(sf::Keyboard::Left)){
            sprite.move(-moveDistance,0); // Move sprite left
        }
        if(input.isKeyPressed(sf::Keyboard::Up)){
            sprite.move(0,-moveDistance); // Move sprite up
        }
        if(input.isKeyPressed(sf::Keyboard::Down)){
            sprite.move(0,moveDistance); // Move sprite down
        }

        

        // Clear screen
        window.clear(sf::Color::White);

        //  Draw the circle
        // window.draw(circle);

        // Render the sprite
        window.draw(sprite);


        // Update wthe window
        window.display();
    }

    return 0;
}
