#include <SFML/Graphics.hpp>

int main(){
    //Create the main window
    sf::RenderWindow window(sf::VideoMode(800,600), "Ember Engine");

    //Start the game loop
    while(window.isOpen()){
        //Process Event
        sf::Event event;
        while(window.pollEvent(event)){
            //Close window : exit
            if(event.type == sf::Event::Closed){
                window.close();
            }

        }

        //Clear screen
        window.clear();

        //Update wthe window
        window.display();
    }

    return 0;
}
