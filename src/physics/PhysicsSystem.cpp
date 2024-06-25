#include "PhysicsSystem.hpp"

namespace ember{
    void PhysicsSystem::update(EntityManager& entityManager, float deltaTime){
        for(Entity entity = 0; entity < MAX_ENTITIES;++entity){
            if (entityManager.hasComponent<PositionComponent>(entity) &&
                entityManager.hasComponent<VelocityComponent>(entity)&&
                entityManager.hasComponent<PhysicsComponent>(entity)){
                    auto& position = entityManager.getComponent<PositionComponent>(entity);
                    auto& velocity = entityManager.getComponent<VelocityComponent>(entity);
                    auto& physics = entityManager.getComponent<PhysicsComponent>(entity);


                    // Apply drag
                    velocity.vx *= (1.0f - physics.drag * deltaTime);
                    velocity.vy *= (1.0f - physics.drag * deltaTime);

                    // Update position
                    position.x += velocity.vx * deltaTime;
                    position.y += velocity.vy * deltaTime;
                }
        }
    }
}// namespace ember