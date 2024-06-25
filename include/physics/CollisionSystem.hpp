#pragma once

#include "Entity.hpp"
#include "CollisionComponent.hpp"
#include "PositionComponent.hpp"

namespace ember {

/**
 * @class CollisionSystem
 * @brief System that detects and handles collisions between entities.
 */
class CollisionSystem {
public:
    /**
     * @brief Detects and handles collisions between entities.
     * @param entityManager The entity manager that manages entities and their components.
     */
    void update(EntityManager& entityManager);
};

} // namespace ember
