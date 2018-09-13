2DEngine Developed in C++ using CLion and SDL2 Libraries

Description: 2DEngine is planned to be an all in one game development engine capable of handling basic game development and structure. This project is meant to be a learning experience as I dive into c++ game development and uses a lot of code from lazyfoo.net for the fundamentals, as I grow more experienced and the engine grows the similarities will begin to disappear.

Current Capabilites: Keyboard and mouse input; Sprite and Texture management and rendering (spritesheet support); GameObject and GUI handlers; Simple world and tiling handler.

Libraries: SDL2, SDL2_Image, SDL2_ttf

Future Capabilities: audio capabilities, GUI is still very barebones at the moment so I'd like to implement a way you can pass basic properties to GUI to tell it to do something (currently the only way would be to create a whole new object for every element). Although upon further thought that would probably be required anyways.

Memory Usage: I imagine memory usage is probably not so good, again this is a learning project and at the moment I'm trying to make things work, upon completion (or a decent place to consider it complete) I'd like to go through and clean up any memory leaks, etc.

Working Directory must be set to project's root directory.
CMake.txt does not belong in the src folder!! The src folder acts as a subdirectory in the main project folder, if you were to open this project in Clion you would need to create a project, add the src folder in, and move cmake.txt to the projects main directory.
