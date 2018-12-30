# Ruin2D

***
**[Description]** I decided I wanted to make a 2D Engine, using SDL2 libraries, as a way of learning C++ and improving my programming skills altogether. The goal is to create an Engine where making 2D games can be as theoretically simple as inherting the correct parent objects and adding independant code and resources for each individual game which can be kept seperate from the engine itself. I do not plan for this engine to compete with any other engines and it is lacking many features that you can find elsewhere.

***
**[Setting up]** This engine was developed in **Visual Studio 2017** so this guide will be primarily focused around the VS IDE, however the steps are not complex and should translate to other IDEs. 

On your local computer, create a repository where you want the root of your project to be, for Visual Studio this is where the IDE creates all files by default (directory contains the .vcxproj files by default).

Pull this repository as a submodule to your created repository, name it ruin_engine. This is required for the Engine to load files it requires on runtime; Visual studio requires file paths to start from root directory.

At this point you will need to setup the **required** .dlls in Visual studio, and add the required .dlls to the project's base directory.

To start creating a game you will want to look over the GameRunner.h and GameRunner.cpp files. Create a new class which inherits the GameRunner class and define the required pure virutal functions. In main, calling run will handle the rest and give you a window on your screen showing that everything is working properly. 

***
**[Requirements]**

  SDL2       (x86 development)    https://www.libsdl.org/download-2.0.php

  SDL2_image (x86 development)    https://www.libsdl.org/projects/SDL_image/
  
  SDL2_ttf   (x86 development)    https://www.libsdl.org/projects/SDL_ttf/

**Visual Studio Requirements**

I have not tested this engine with other IDEs besides Visual Studio, but Visual Studio 2017 requires certain .dlls to be in the root folder of your project (folder, by default, containing .vcxproj files). These dlls can be found in your SDL libraries' ~/lib/x86 folder.

SDL2.dll, SDL2_image.dll, SDL2_ttf.dll, libfreetype-6.dll, libjpeg-9.dll, libpng16-16.dll, libtiff-5.dll, libwebp-7.dll, zlib1.dll. 



***
**[Future Inclusions]**

  SDL2_Mixer support.
  
  x64 support.


***
**[Known Issues]**

  There may be some memory leak issues.

  Engine does not appear to be optimised very well and framerate drops happen when there are ~100 objects on camera at once (have not       determined if this is a rendering or update issue).
  
***
**[Downloads]**
Snake example: [Download](https://petersonchris.me/downloads/Snake.zip)
