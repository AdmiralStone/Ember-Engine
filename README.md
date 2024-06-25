# Ember Engine

Ember Engine is a simple, lightweight 2D game engine built with C++ and SFML. This project is a foundation for developing 2D games, with plans to add 3D support in the future.

## Table of Contents
- [Motivation](#motivation)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [License](#license)
- [Acknowledgements](#acknowledgements)

## Motivation
This project is a learning experience for me. I am creating Ember to deepen my understanding of how game engines work, improve my C++ skills, and explore the intricacies of 2D and eventually 3D game development. Through this project I am to build a comprehensive and modular game engine from scratch, learning and implementing various components step by step.

## Features
- [x] Basic window creation
- [x] Basic input handling
- [x] Simple shape rendering
- [x] Texture loading and rendering
- [x] Game loop and time management
- [x] Entity Component System
- [x] Basic physics and collision detection
- [ ] Audio playback (sound effects and music)
- [ ] Scripting support
- [ ] UI system
- [ ] Scene management
- [ ] Optimization and debugging tools

## Installation

### Prerequisites
- C++17 compatible compiler
- CMake 3.10 or higher
- SFML 2.6.1

### Building the Project
1. Clone the repository:
    ```bash
    git clone https://github.com/AdmiralStone/Ember-Engine.git
    cd Ember-Engine
2. Install SFML using Homebrew (if not already installed):
    ```bash
    brew install sfml
3. Create build directory and navigate into it:
    ```bash
    mkdir build
    cd build
4. Generate the build files using CMake and build the project:
    ```bash
    cmake ..
    make
5. Run the executable:
    ```bash
    ./EmberEngine

## Usage
Upon running the executable, a window titled "Ember Engine" will appear. This window servers as the initial test to confirm that SFML is properly setup.

## License
This project is licensed under the MIT License

## Acknowledgements
- SFML - Simple and Fast Multimedia Library

### Note
This project is still under development. I will update the readme after each significant change.

