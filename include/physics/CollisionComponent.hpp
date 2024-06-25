#pragma once

namespace ember
{
    /**
     * @class CollisionComponent
     * @brief Stores collision-related data of an entity
     */
    struct CollisionComponent{
        float width; ///< Width of the entity's bounding box
        float height; ///< Height of the entity's bounding box 
    };
} // namespace ember
