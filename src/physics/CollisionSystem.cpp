#include "CollisionSystem.hpp"

namespace ember {

void CollisionSystem::update(EntityManager& entityManager) {
    for (Entity entityA = 0; entityA < MAX_ENTITIES; ++entityA) {
        if (entityManager.hasComponent<PositionComponent>(entityA) &&
            entityManager.hasComponent<CollisionComponent>(entityA)) {
            auto& positionA = entityManager.getComponent<PositionComponent>(entityA);
            auto& collisionA = entityManager.getComponent<CollisionComponent>(entityA);

            for (Entity entityB = entityA + 1; entityB < MAX_ENTITIES; ++entityB) {
                if (entityManager.hasComponent<PositionComponent>(entityB) &&
                    entityManager.hasComponent<CollisionComponent>(entityB)) {
                    auto& positionB = entityManager.getComponent<PositionComponent>(entityB);
                    auto& collisionB = entityManager.getComponent<CollisionComponent>(entityB);

                    // Simple AABB collision detection
                    if (positionA.x < positionB.x + collisionB.width &&
                        positionA.x + collisionA.width > positionB.x &&
                        positionA.y < positionB.y + collisionB.height &&
                        positionA.y + collisionA.height > positionB.y) {
                        // Handle collision (e.g., stop movement, bounce, etc.)
                    }
                }
            }
        }
    }
}

} // namespace ember
