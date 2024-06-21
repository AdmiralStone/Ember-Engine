#include "Entity.hpp"

namespace ember{
    EntityManager::EntityManager():nextEntity_(0){}

    Entity EntityManager::createEntity(){
        return nextEntity_++;
    }

    void EntityManager::destroyEntity(Entity entity){
        entityComponents_.erase(entity);
    }

    template<typename T>
    void EntityManager::addComponent(Entity entity, T component){
        entityComponents_[entity][std::type_index(typeid(T))] = std::make_shared<T>(component);

    }

    template<typename T>
    void EntityManager::removeComponent(Entity entity){
        entityComponents_[entity].erase(std::type_index(typeid(T)));
    }

    template <typename T>
    T& EntityManager::getComponent(Entity entity){
        return *std::static_pointer_cast<T>(entityComponents_[entity][std::type_index(typeid(T))]);
    }
}// namespace ember