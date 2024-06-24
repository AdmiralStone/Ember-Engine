#include "Entity.hpp"

namespace ember{
    EntityManager::EntityManager():nextEntity_(0){}

    Entity EntityManager::createEntity(){
        return nextEntity_++;
    }

    void EntityManager::destroyEntity(Entity entity){
        entityComponents_.erase(entity);
    }

}// namespace ember