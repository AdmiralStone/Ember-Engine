cmake_minimum_required(VERSION 3.10)
project(EmberEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)
include_directories(include/core)
include_directories(include/physics)
include_directories(include/systems)
include_directories(include/components)

# Source files
file(GLOB CORE_SOURCES "src/core/*.cpp")
file(GLOB PHYSICS_SOURCES "src/physics/*.cpp")
file(GLOB SYSTEMS_SOURCES "src/systems/*.cpp")
file(GLOB COMPONENTS_SOURCES "src/components/*.cpp")
set(MAIN_SOURCE "src/main.cpp")

# Find SFML
set(SFML_DIR "/usr/local/Cellar/sfml/2.6.1/lib/cmake/SFML")
find_package(SFML 2.6 COMPONENTS system window graphics network audio REQUIRED)

# Add executable
add_executable(EmberEngine ${MAIN_SOURCE} ${CORE_SOURCES} ${PHYSICS_SOURCES} ${SYSTEMS_SOURCES} ${COMPONENTS_SOURCES})

# Link SFML libraries
target_link_libraries(EmberEngine sfml-system sfml-window sfml-graphics sfml-audio)
