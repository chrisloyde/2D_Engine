# 2DEngine
Developed in C++

***
**[Description]** I decided I wanted to make a 2DEngine, using SDL2 libraries, as a way of learning C++ and improving my programming skills altogether. The goal is to create an Engine where making 2D games can be as theoretically simple as inherting the correct parent objects and adding independant code and resources for each individual game which can be kept seperate from the engine itself. All required DLLs (visual studio) are included in the repository and are x86 versions of SDL2. 

***
**[Setting up]** To setup the engine for Visual Studio I highly recommend looking at lazyfoo's guides (http://lazyfoo.net/) for setting up your enviroment. You can then simply copy the entire repository into your Visual Studio project's directory, as long as Visual Studio is setup to use SDL2 and other requirements, and it will compile and run correctly. 

***
**[Requirements]**

  SDL2       (x86 development)    https://www.libsdl.org/download-2.0.php

  SDL2_image (x86 development)    https://www.libsdl.org/projects/SDL_image/
  
  SDL2_ttf   (x86 development)    https://www.libsdl.org/projects/SDL_ttf/

***
**[Future Inclusions]**

  SDL2_Mixer support.
  
  x86 and x64 support.
  
  Main loader, instead of having to adjust main for each individual project I'd like to be able to load individual main functions for increased independence and structure.

***
**[Known Issues]**

  Not optimized to prevent memory leaks.
  
  There may be an issue with creating and destroying objects rapidly.
  
  Engine and example projects are not well documented.
  
