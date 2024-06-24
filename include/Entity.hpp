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

            /**
             * @brief Checks if an entity has a specific component
             * @tparam T the type of component
             * @param entity The entity to check
             * @return True if the entity has the component, false otherwise
             */
            template<typename T>
            bool hasComponent(Entity entity);

        private:
            std::unordered_map<Entity, std::unordered_map<std::type_index, std::shared_ptr<void>>> entityComponents_;
            Entity nextEntity_; ///< The next available entity ID



    };

    template<typename T>
    void EntityManager::addComponent(Entity entity, T component){
        entityComponents_[entity][std::type_index(typeid(T))] = std::make_shared<T>(component);

    }

    template<typename T>
    void EntityManager::removeComponent(Entity entity){
        entityComponents_[entity].erase(std::type_index(typeid(T)));
    }

    template <typename T>
    T& EntityManager::getComponent(Entity entity){
        return *std::static_pointer_cast<T>(entityComponents_[entity][std::type_index(typeid(T))]);
    }

    template<typename T>
    bool EntityManager::hasComponent(Entity entity){
        auto entityIt = entityComponents_.find(entity);
        if(entityIt != entityComponents_.end()){
            auto componentIt = entityIt->second.find(std::type_index(typeid(T)));
            if(componentIt != entityIt->second.end()){
                return true;
            }
        }
        return false;
    }

}