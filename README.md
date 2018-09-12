2DEngine Developed in C++ using CLion and SDL2 Libraries

Description: 2DEngine is planned to be an all in one game development engine capable of handling basic game development and structure. This project is meant to be a learning experience as I dive into c++ game development and uses a lot of code from lazyfoo.net for the fundamentals, as I grow more experienced and the engine grows the similarities will begin to disappear.

Current Capabilites: Basic Keyboard input, Sprite and Texture management and rendering.

Libraries: SDL2, SDL2_Image, SDL2_ttf

Future Capabilities: Mouse input, parental objects to make extensions and modifications easier, audio capabiliites, world, player, etc. managers, and a proper rendering and updating system to make game management and modification simple.

Working Directory must be set to project's root directory.
CMake.txt does not belong in the src folder!! The src folder acts as a subdirectory in the main project folder, if you were to open this project in Clion you would need to create a project, add the src folder in, and move cmake.txt to the projects main directory.
