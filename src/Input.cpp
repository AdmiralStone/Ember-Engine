#include "Input.hpp"

namespace ember{
    
    void Input::update(const sf::Event& event){
        if(event.type == sf::Event::KeyPressed){
            keyState_[event.key.code] = true;
        }else if(event.type == sf::Event::KeyReleased){
            keyState_[event.key.code] = false;
        }

        if(event.type == sf::Event::MouseButtonPressed){
            mouseButtonState_[event.mouseButton.button] = true;
        }else if(event.type == sf::Event::MouseButtonReleased){
            mouseButtonState_[event.mouseButton.button] = false;
        }
    }

    bool Input::isKeyPressed(sf::Keyboard::Key key)const{
        auto it = keyState_.find(key);
        if(it != keyState_.end()){
            return it->second;
        }
        return false;
    }

    bool Input::isMouseButtonPressed(sf::Mouse::Button button)const{
        auto it = mouseButtonState_.find(button);
        if(it != mouseButtonState_.end()){
            return it->second;
        }
        return false;
    }

    sf::Vector2i Input::getMousePosition(const sf::RenderWindow& window)const {
        return sf::Mouse::getPosition(window);
    }
}// namespace ember
