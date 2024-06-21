cmake_minimum_required(VERSION 3.10)
project(EmberEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Source files 
file(GLOB SOURCES "src/*.cpp")

# Find SFML
set(SFML_DIR "/opt/homebrew/Cellar/sfml/2.6.1/lib/cmake/SFML")
find_package(SFML 2.6 COMPONENTS system window graphics network audio REQUIRED)

#Add executable
add_executable(EmberEngine ${SOURCES})

#Link SFML libraries
target_link_libraries(EmberEngine sfml-system sfml-window sfml-graphics sfml-audio)
