#pragma once

namespace ember{
    /**
     * @class PhysicsComponent
     * @brief Stores physical properties of an entity
     */
    struct PhysicsComponent{
        float mass; ///< Mass of the entity
        float drag; ///< Drag coefficient of the entity
    };
}// namespace ember