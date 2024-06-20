#include <SFML/Graphics.hpp>
#include <iostream>

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

    // Start the game loop
    while(window.isOpen()){
        // Process Event
        sf::Event event;
        while(window.pollEvent(event)){
            // Close window : exit
            if(event.type == sf::Event::Closed) window.close();

            // Close window when Escape key is pressed
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)window.close();
        }

        // Get the elapsed time
        sf::Time deltaTime = clock.restart();

        // Move the sprite
        float moveDistance = spriteSpeed * deltaTime.asSeconds();
        sprite.move(moveDistance,0); //MOve sprite to the right 

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
