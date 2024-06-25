#include "MovementSystem.hpp"

namespace ember{
    void MovementSystem::update(EntityManager& entityManager, float deltaTime){
        for(Entity entity = 0;entity < MAX_ENTITIES;++entity){
            if(entityManager.hasComponent<PositionComponent>(entity) && 
                entityManager.hasComponent<VelocityComponent>(entity)){
                    auto& position = entityManager.getComponent<PositionComponent>(entity);
                    auto& velocity = entityManager.getComponent<VelocityComponent>(entity);

                    position.x += velocity.vx * deltaTime;
                    position.y += velocity.vx * deltaTime;

                }
        }
    }
} //namespace ember