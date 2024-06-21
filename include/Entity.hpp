#pragma once

#include <unordered_map>
#include <typeindex>
#include <memory>
#include <cstdint>

namespace ember{
    using Entity = std::uint32_t; ///< Type definition for entities
    constexpr Entity MAX_ENTITIES = 5000; ///< Maximum number of entities supported

    /**
     * @class EntityManager
     * @brief Manages the creation, destruction, and component association of entities.
     */

    class EntityManager{
        public:
            /**
            * @brief Constructor for EntityManager
            */
            EntityManager();

            /**
             * @brief Create a new Entity object
             * @return The created entity
             */
            Entity createEntity();

            /**
             * @brief Destroys an existing entity
             * @param entity The entity to destroy
             */
            void destroyEntity(Entity entity);


            /**
             * @brief Adds a component to an entity
             * @tparam T The type of component.
             * @param entity The entity to add the component to.
             * @param component The component to add.
             */
            template <typename T>
            void addComponent(Entity entity, T component);

            /**
             * @brief Removes a component associated with an entity
             * @tparam T the type of component
             * @param enity The entity to remove the component from
             */
            template <typename T>
            void removeComponent(Entity entity);

            /**
             * @brief Gets a component associated with an entity
             * @tparam T the type of component.
             * @param entity The entity to get the component from
             * @return The component associated with the entity
             */

            template<typename T>
            T& getComponent(Entity Entity);

        private:
            std::unordered_map<Entity, std::unordered_map<std::type_index, std::shared_ptr<void>>> entityComponents_;
            Entity nextEntity_; ///< The next available entity ID



    };

}