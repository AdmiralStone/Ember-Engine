#pragma once

#include "Entity.hpp"
#include "PhysicsComponent.hpp"
#include "PositionComponent.hpp"
#include "VelocityComponent.hpp"

namespace ember{
    /**
     * @class PhysicsSystem
     * @brief System that updates the entities' position based on their physics properties and velocities.
     */
    class PhysicsSystem{
        public:
            /**
             * @brief Updates the position of entities based on their physics properties and velocities
             * @param entityManager The entity manager that manages entities and their components
             * @param deltaTime the time elapsed since the last update
             */
            void update(EntityManager& entityManager, float deltaTime);
    };
}// namespace ember