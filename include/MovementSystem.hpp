#pragma once

#include "Entity.hpp"
#include "PositionComponent.hpp"
#include "VelocityComponent.hpp"

namespace ember{
    /**
     * @class MovementSystem
     * @brief System that updates the position of entities based on their velocity
     */
    class MovementSystem{
        public:
            /**
             * @brief Updates the position of the entitites based on their velocity
             * @param entityManager The entity manager that manages entities and their components.
             * @param deltaTime The time elapsed since the last update.
             */
            void update(EntityManager& entityManager, float deltaTime);
    };
} // namespace ember