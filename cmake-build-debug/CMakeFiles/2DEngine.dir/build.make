# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Chris\Dev\2DEngine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Chris\Dev\2DEngine\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/2DEngine.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/2DEngine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/2DEngine.dir/flags.make

CMakeFiles/2DEngine.dir/main.cpp.obj: CMakeFiles/2DEngine.dir/flags.make
CMakeFiles/2DEngine.dir/main.cpp.obj: CMakeFiles/2DEngine.dir/includes_CXX.rsp
CMakeFiles/2DEngine.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Chris\Dev\2DEngine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/2DEngine.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\2DEngine.dir\main.cpp.obj -c C:\Users\Chris\Dev\2DEngine\main.cpp

CMakeFiles/2DEngine.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2DEngine.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Chris\Dev\2DEngine\main.cpp > CMakeFiles\2DEngine.dir\main.cpp.i

CMakeFiles/2DEngine.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2DEngine.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Chris\Dev\2DEngine\main.cpp -o CMakeFiles\2DEngine.dir\main.cpp.s

CMakeFiles/2DEngine.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/2DEngine.dir/main.cpp.obj.requires

CMakeFiles/2DEngine.dir/main.cpp.obj.provides: CMakeFiles/2DEngine.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\2DEngine.dir\build.make CMakeFiles/2DEngine.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/2DEngine.dir/main.cpp.obj.provides

CMakeFiles/2DEngine.dir/main.cpp.obj.provides.build: CMakeFiles/2DEngine.dir/main.cpp.obj


CMakeFiles/2DEngine.dir/textures/Texture.cpp.obj: CMakeFiles/2DEngine.dir/flags.make
CMakeFiles/2DEngine.dir/textures/Texture.cpp.obj: CMakeFiles/2DEngine.dir/includes_CXX.rsp
CMakeFiles/2DEngine.dir/textures/Texture.cpp.obj: ../textures/Texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Chris\Dev\2DEngine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/2DEngine.dir/textures/Texture.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\2DEngine.dir\textures\Texture.cpp.obj -c C:\Users\Chris\Dev\2DEngine\textures\Texture.cpp

CMakeFiles/2DEngine.dir/textures/Texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2DEngine.dir/textures/Texture.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Chris\Dev\2DEngine\textures\Texture.cpp > CMakeFiles\2DEngine.dir\textures\Texture.cpp.i

CMakeFiles/2DEngine.dir/textures/Texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2DEngine.dir/textures/Texture.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Chris\Dev\2DEngine\textures\Texture.cpp -o CMakeFiles\2DEngine.dir\textures\Texture.cpp.s

CMakeFiles/2DEngine.dir/textures/Texture.cpp.obj.requires:

.PHONY : CMakeFiles/2DEngine.dir/textures/Texture.cpp.obj.requires

CMakeFiles/2DEngine.dir/textures/Texture.cpp.obj.provides: CMakeFiles/2DEngine.dir/textures/Texture.cpp.obj.requires
	$(MAKE) -f CMakeFiles\2DEngine.dir\build.make CMakeFiles/2DEngine.dir/textures/Texture.cpp.obj.provides.build
.PHONY : CMakeFiles/2DEngine.dir/textures/Texture.cpp.obj.provides

CMakeFiles/2DEngine.dir/textures/Texture.cpp.obj.provides.build: CMakeFiles/2DEngine.dir/textures/Texture.cpp.obj


CMakeFiles/2DEngine.dir/textures/sprites/renderers/TileRenderer.cpp.obj: CMakeFiles/2DEngine.dir/flags.make
CMakeFiles/2DEngine.dir/textures/sprites/renderers/TileRenderer.cpp.obj: CMakeFiles/2DEngine.dir/includes_CXX.rsp
CMakeFiles/2DEngine.dir/textures/sprites/renderers/TileRenderer.cpp.obj: ../textures/sprites/renderers/TileRenderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Chris\Dev\2DEngine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/2DEngine.dir/textures/sprites/renderers/TileRenderer.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\2DEngine.dir\textures\sprites\renderers\TileRenderer.cpp.obj -c C:\Users\Chris\Dev\2DEngine\textures\sprites\renderers\TileRenderer.cpp

CMakeFiles/2DEngine.dir/textures/sprites/renderers/TileRenderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2DEngine.dir/textures/sprites/renderers/TileRenderer.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Chris\Dev\2DEngine\textures\sprites\renderers\TileRenderer.cpp > CMakeFiles\2DEngine.dir\textures\sprites\renderers\TileRenderer.cpp.i

CMakeFiles/2DEngine.dir/textures/sprites/renderers/TileRenderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2DEngine.dir/textures/sprites/renderers/TileRenderer.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Chris\Dev\2DEngine\textures\sprites\renderers\TileRenderer.cpp -o CMakeFiles\2DEngine.dir\textures\sprites\renderers\TileRenderer.cpp.s

CMakeFiles/2DEngine.dir/textures/sprites/renderers/TileRenderer.cpp.obj.requires:

.PHONY : CMakeFiles/2DEngine.dir/textures/sprites/renderers/TileRenderer.cpp.obj.requires

CMakeFiles/2DEngine.dir/textures/sprites/renderers/TileRenderer.cpp.obj.provides: CMakeFiles/2DEngine.dir/textures/sprites/renderers/TileRenderer.cpp.obj.requires
	$(MAKE) -f CMakeFiles\2DEngine.dir\build.make CMakeFiles/2DEngine.dir/textures/sprites/renderers/TileRenderer.cpp.obj.provides.build
.PHONY : CMakeFiles/2DEngine.dir/textures/sprites/renderers/TileRenderer.cpp.obj.provides

CMakeFiles/2DEngine.dir/textures/sprites/renderers/TileRenderer.cpp.obj.provides.build: CMakeFiles/2DEngine.dir/textures/sprites/renderers/TileRenderer.cpp.obj


CMakeFiles/2DEngine.dir/objects/Timer.cpp.obj: CMakeFiles/2DEngine.dir/flags.make
CMakeFiles/2DEngine.dir/objects/Timer.cpp.obj: CMakeFiles/2DEngine.dir/includes_CXX.rsp
CMakeFiles/2DEngine.dir/objects/Timer.cpp.obj: ../objects/Timer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Chris\Dev\2DEngine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/2DEngine.dir/objects/Timer.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\2DEngine.dir\objects\Timer.cpp.obj -c C:\Users\Chris\Dev\2DEngine\objects\Timer.cpp

CMakeFiles/2DEngine.dir/objects/Timer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2DEngine.dir/objects/Timer.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Chris\Dev\2DEngine\objects\Timer.cpp > CMakeFiles\2DEngine.dir\objects\Timer.cpp.i

CMakeFiles/2DEngine.dir/objects/Timer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2DEngine.dir/objects/Timer.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Chris\Dev\2DEngine\objects\Timer.cpp -o CMakeFiles\2DEngine.dir\objects\Timer.cpp.s

CMakeFiles/2DEngine.dir/objects/Timer.cpp.obj.requires:

.PHONY : CMakeFiles/2DEngine.dir/objects/Timer.cpp.obj.requires

CMakeFiles/2DEngine.dir/objects/Timer.cpp.obj.provides: CMakeFiles/2DEngine.dir/objects/Timer.cpp.obj.requires
	$(MAKE) -f CMakeFiles\2DEngine.dir\build.make CMakeFiles/2DEngine.dir/objects/Timer.cpp.obj.provides.build
.PHONY : CMakeFiles/2DEngine.dir/objects/Timer.cpp.obj.provides

CMakeFiles/2DEngine.dir/objects/Timer.cpp.obj.provides.build: CMakeFiles/2DEngine.dir/objects/Timer.cpp.obj


CMakeFiles/2DEngine.dir/objects/entity/player/EntityPlayer.cpp.obj: CMakeFiles/2DEngine.dir/flags.make
CMakeFiles/2DEngine.dir/objects/entity/player/EntityPlayer.cpp.obj: CMakeFiles/2DEngine.dir/includes_CXX.rsp
CMakeFiles/2DEngine.dir/objects/entity/player/EntityPlayer.cpp.obj: ../objects/entity/player/EntityPlayer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Chris\Dev\2DEngine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/2DEngine.dir/objects/entity/player/EntityPlayer.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\2DEngine.dir\objects\entity\player\EntityPlayer.cpp.obj -c C:\Users\Chris\Dev\2DEngine\objects\entity\player\EntityPlayer.cpp

CMakeFiles/2DEngine.dir/objects/entity/player/EntityPlayer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2DEngine.dir/objects/entity/player/EntityPlayer.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Chris\Dev\2DEngine\objects\entity\player\EntityPlayer.cpp > CMakeFiles\2DEngine.dir\objects\entity\player\EntityPlayer.cpp.i

CMakeFiles/2DEngine.dir/objects/entity/player/EntityPlayer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2DEngine.dir/objects/entity/player/EntityPlayer.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Chris\Dev\2DEngine\objects\entity\player\EntityPlayer.cpp -o CMakeFiles\2DEngine.dir\objects\entity\player\EntityPlayer.cpp.s

CMakeFiles/2DEngine.dir/objects/entity/player/EntityPlayer.cpp.obj.requires:

.PHONY : CMakeFiles/2DEngine.dir/objects/entity/player/EntityPlayer.cpp.obj.requires

CMakeFiles/2DEngine.dir/objects/entity/player/EntityPlayer.cpp.obj.provides: CMakeFiles/2DEngine.dir/objects/entity/player/EntityPlayer.cpp.obj.requires
	$(MAKE) -f CMakeFiles\2DEngine.dir\build.make CMakeFiles/2DEngine.dir/objects/entity/player/EntityPlayer.cpp.obj.provides.build
.PHONY : CMakeFiles/2DEngine.dir/objects/entity/player/EntityPlayer.cpp.obj.provides

CMakeFiles/2DEngine.dir/objects/entity/player/EntityPlayer.cpp.obj.provides.build: CMakeFiles/2DEngine.dir/objects/entity/player/EntityPlayer.cpp.obj


CMakeFiles/2DEngine.dir/objects/block/Tile.cpp.obj: CMakeFiles/2DEngine.dir/flags.make
CMakeFiles/2DEngine.dir/objects/block/Tile.cpp.obj: CMakeFiles/2DEngine.dir/includes_CXX.rsp
CMakeFiles/2DEngine.dir/objects/block/Tile.cpp.obj: ../objects/block/Tile.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Chris\Dev\2DEngine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/2DEngine.dir/objects/block/Tile.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\2DEngine.dir\objects\block\Tile.cpp.obj -c C:\Users\Chris\Dev\2DEngine\objects\block\Tile.cpp

CMakeFiles/2DEngine.dir/objects/block/Tile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2DEngine.dir/objects/block/Tile.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Chris\Dev\2DEngine\objects\block\Tile.cpp > CMakeFiles\2DEngine.dir\objects\block\Tile.cpp.i

CMakeFiles/2DEngine.dir/objects/block/Tile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2DEngine.dir/objects/block/Tile.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Chris\Dev\2DEngine\objects\block\Tile.cpp -o CMakeFiles\2DEngine.dir\objects\block\Tile.cpp.s

CMakeFiles/2DEngine.dir/objects/block/Tile.cpp.obj.requires:

.PHONY : CMakeFiles/2DEngine.dir/objects/block/Tile.cpp.obj.requires

CMakeFiles/2DEngine.dir/objects/block/Tile.cpp.obj.provides: CMakeFiles/2DEngine.dir/objects/block/Tile.cpp.obj.requires
	$(MAKE) -f CMakeFiles\2DEngine.dir\build.make CMakeFiles/2DEngine.dir/objects/block/Tile.cpp.obj.provides.build
.PHONY : CMakeFiles/2DEngine.dir/objects/block/Tile.cpp.obj.provides

CMakeFiles/2DEngine.dir/objects/block/Tile.cpp.obj.provides.build: CMakeFiles/2DEngine.dir/objects/block/Tile.cpp.obj


CMakeFiles/2DEngine.dir/objects/World.cpp.obj: CMakeFiles/2DEngine.dir/flags.make
CMakeFiles/2DEngine.dir/objects/World.cpp.obj: CMakeFiles/2DEngine.dir/includes_CXX.rsp
CMakeFiles/2DEngine.dir/objects/World.cpp.obj: ../objects/World.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Chris\Dev\2DEngine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/2DEngine.dir/objects/World.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\2DEngine.dir\objects\World.cpp.obj -c C:\Users\Chris\Dev\2DEngine\objects\World.cpp

CMakeFiles/2DEngine.dir/objects/World.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2DEngine.dir/objects/World.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Chris\Dev\2DEngine\objects\World.cpp > CMakeFiles\2DEngine.dir\objects\World.cpp.i

CMakeFiles/2DEngine.dir/objects/World.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2DEngine.dir/objects/World.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Chris\Dev\2DEngine\objects\World.cpp -o CMakeFiles\2DEngine.dir\objects\World.cpp.s

CMakeFiles/2DEngine.dir/objects/World.cpp.obj.requires:

.PHONY : CMakeFiles/2DEngine.dir/objects/World.cpp.obj.requires

CMakeFiles/2DEngine.dir/objects/World.cpp.obj.provides: CMakeFiles/2DEngine.dir/objects/World.cpp.obj.requires
	$(MAKE) -f CMakeFiles\2DEngine.dir\build.make CMakeFiles/2DEngine.dir/objects/World.cpp.obj.provides.build
.PHONY : CMakeFiles/2DEngine.dir/objects/World.cpp.obj.provides

CMakeFiles/2DEngine.dir/objects/World.cpp.obj.provides.build: CMakeFiles/2DEngine.dir/objects/World.cpp.obj


CMakeFiles/2DEngine.dir/objects/gui/GUI.cpp.obj: CMakeFiles/2DEngine.dir/flags.make
CMakeFiles/2DEngine.dir/objects/gui/GUI.cpp.obj: CMakeFiles/2DEngine.dir/includes_CXX.rsp
CMakeFiles/2DEngine.dir/objects/gui/GUI.cpp.obj: ../objects/gui/GUI.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Chris\Dev\2DEngine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/2DEngine.dir/objects/gui/GUI.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\2DEngine.dir\objects\gui\GUI.cpp.obj -c C:\Users\Chris\Dev\2DEngine\objects\gui\GUI.cpp

CMakeFiles/2DEngine.dir/objects/gui/GUI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2DEngine.dir/objects/gui/GUI.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Chris\Dev\2DEngine\objects\gui\GUI.cpp > CMakeFiles\2DEngine.dir\objects\gui\GUI.cpp.i

CMakeFiles/2DEngine.dir/objects/gui/GUI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2DEngine.dir/objects/gui/GUI.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Chris\Dev\2DEngine\objects\gui\GUI.cpp -o CMakeFiles\2DEngine.dir\objects\gui\GUI.cpp.s

CMakeFiles/2DEngine.dir/objects/gui/GUI.cpp.obj.requires:

.PHONY : CMakeFiles/2DEngine.dir/objects/gui/GUI.cpp.obj.requires

CMakeFiles/2DEngine.dir/objects/gui/GUI.cpp.obj.provides: CMakeFiles/2DEngine.dir/objects/gui/GUI.cpp.obj.requires
	$(MAKE) -f CMakeFiles\2DEngine.dir\build.make CMakeFiles/2DEngine.dir/objects/gui/GUI.cpp.obj.provides.build
.PHONY : CMakeFiles/2DEngine.dir/objects/gui/GUI.cpp.obj.provides

CMakeFiles/2DEngine.dir/objects/gui/GUI.cpp.obj.provides.build: CMakeFiles/2DEngine.dir/objects/gui/GUI.cpp.obj


CMakeFiles/2DEngine.dir/objects/handlers/GUIHandler.cpp.obj: CMakeFiles/2DEngine.dir/flags.make
CMakeFiles/2DEngine.dir/objects/handlers/GUIHandler.cpp.obj: CMakeFiles/2DEngine.dir/includes_CXX.rsp
CMakeFiles/2DEngine.dir/objects/handlers/GUIHandler.cpp.obj: ../objects/handlers/GUIHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Chris\Dev\2DEngine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/2DEngine.dir/objects/handlers/GUIHandler.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\2DEngine.dir\objects\handlers\GUIHandler.cpp.obj -c C:\Users\Chris\Dev\2DEngine\objects\handlers\GUIHandler.cpp

CMakeFiles/2DEngine.dir/objects/handlers/GUIHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2DEngine.dir/objects/handlers/GUIHandler.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Chris\Dev\2DEngine\objects\handlers\GUIHandler.cpp > CMakeFiles\2DEngine.dir\objects\handlers\GUIHandler.cpp.i

CMakeFiles/2DEngine.dir/objects/handlers/GUIHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2DEngine.dir/objects/handlers/GUIHandler.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Chris\Dev\2DEngine\objects\handlers\GUIHandler.cpp -o CMakeFiles\2DEngine.dir\objects\handlers\GUIHandler.cpp.s

CMakeFiles/2DEngine.dir/objects/handlers/GUIHandler.cpp.obj.requires:

.PHONY : CMakeFiles/2DEngine.dir/objects/handlers/GUIHandler.cpp.obj.requires

CMakeFiles/2DEngine.dir/objects/handlers/GUIHandler.cpp.obj.provides: CMakeFiles/2DEngine.dir/objects/handlers/GUIHandler.cpp.obj.requires
	$(MAKE) -f CMakeFiles\2DEngine.dir\build.make CMakeFiles/2DEngine.dir/objects/handlers/GUIHandler.cpp.obj.provides.build
.PHONY : CMakeFiles/2DEngine.dir/objects/handlers/GUIHandler.cpp.obj.provides

CMakeFiles/2DEngine.dir/objects/handlers/GUIHandler.cpp.obj.provides.build: CMakeFiles/2DEngine.dir/objects/handlers/GUIHandler.cpp.obj


CMakeFiles/2DEngine.dir/objects/block/GameObject.cpp.obj: CMakeFiles/2DEngine.dir/flags.make
CMakeFiles/2DEngine.dir/objects/block/GameObject.cpp.obj: CMakeFiles/2DEngine.dir/includes_CXX.rsp
CMakeFiles/2DEngine.dir/objects/block/GameObject.cpp.obj: ../objects/block/GameObject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Chris\Dev\2DEngine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/2DEngine.dir/objects/block/GameObject.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\2DEngine.dir\objects\block\GameObject.cpp.obj -c C:\Users\Chris\Dev\2DEngine\objects\block\GameObject.cpp

CMakeFiles/2DEngine.dir/objects/block/GameObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2DEngine.dir/objects/block/GameObject.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Chris\Dev\2DEngine\objects\block\GameObject.cpp > CMakeFiles\2DEngine.dir\objects\block\GameObject.cpp.i

CMakeFiles/2DEngine.dir/objects/block/GameObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2DEngine.dir/objects/block/GameObject.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Chris\Dev\2DEngine\objects\block\GameObject.cpp -o CMakeFiles\2DEngine.dir\objects\block\GameObject.cpp.s

CMakeFiles/2DEngine.dir/objects/block/GameObject.cpp.obj.requires:

.PHONY : CMakeFiles/2DEngine.dir/objects/block/GameObject.cpp.obj.requires

CMakeFiles/2DEngine.dir/objects/block/GameObject.cpp.obj.provides: CMakeFiles/2DEngine.dir/objects/block/GameObject.cpp.obj.requires
	$(MAKE) -f CMakeFiles\2DEngine.dir\build.make CMakeFiles/2DEngine.dir/objects/block/GameObject.cpp.obj.provides.build
.PHONY : CMakeFiles/2DEngine.dir/objects/block/GameObject.cpp.obj.provides

CMakeFiles/2DEngine.dir/objects/block/GameObject.cpp.obj.provides.build: CMakeFiles/2DEngine.dir/objects/block/GameObject.cpp.obj


CMakeFiles/2DEngine.dir/objects/handlers/GameObjectHandler.cpp.obj: CMakeFiles/2DEngine.dir/flags.make
CMakeFiles/2DEngine.dir/objects/handlers/GameObjectHandler.cpp.obj: CMakeFiles/2DEngine.dir/includes_CXX.rsp
CMakeFiles/2DEngine.dir/objects/handlers/GameObjectHandler.cpp.obj: ../objects/handlers/GameObjectHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Chris\Dev\2DEngine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/2DEngine.dir/objects/handlers/GameObjectHandler.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\2DEngine.dir\objects\handlers\GameObjectHandler.cpp.obj -c C:\Users\Chris\Dev\2DEngine\objects\handlers\GameObjectHandler.cpp

CMakeFiles/2DEngine.dir/objects/handlers/GameObjectHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2DEngine.dir/objects/handlers/GameObjectHandler.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Chris\Dev\2DEngine\objects\handlers\GameObjectHandler.cpp > CMakeFiles\2DEngine.dir\objects\handlers\GameObjectHandler.cpp.i

CMakeFiles/2DEngine.dir/objects/handlers/GameObjectHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2DEngine.dir/objects/handlers/GameObjectHandler.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Chris\Dev\2DEngine\objects\handlers\GameObjectHandler.cpp -o CMakeFiles\2DEngine.dir\objects\handlers\GameObjectHandler.cpp.s

CMakeFiles/2DEngine.dir/objects/handlers/GameObjectHandler.cpp.obj.requires:

.PHONY : CMakeFiles/2DEngine.dir/objects/handlers/GameObjectHandler.cpp.obj.requires

CMakeFiles/2DEngine.dir/objects/handlers/GameObjectHandler.cpp.obj.provides: CMakeFiles/2DEngine.dir/objects/handlers/GameObjectHandler.cpp.obj.requires
	$(MAKE) -f CMakeFiles\2DEngine.dir\build.make CMakeFiles/2DEngine.dir/objects/handlers/GameObjectHandler.cpp.obj.provides.build
.PHONY : CMakeFiles/2DEngine.dir/objects/handlers/GameObjectHandler.cpp.obj.provides

CMakeFiles/2DEngine.dir/objects/handlers/GameObjectHandler.cpp.obj.provides.build: CMakeFiles/2DEngine.dir/objects/handlers/GameObjectHandler.cpp.obj


CMakeFiles/2DEngine.dir/textures/sprites/renderers/SpriteRenderer.cpp.obj: CMakeFiles/2DEngine.dir/flags.make
CMakeFiles/2DEngine.dir/textures/sprites/renderers/SpriteRenderer.cpp.obj: CMakeFiles/2DEngine.dir/includes_CXX.rsp
CMakeFiles/2DEngine.dir/textures/sprites/renderers/SpriteRenderer.cpp.obj: ../textures/sprites/renderers/SpriteRenderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Chris\Dev\2DEngine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/2DEngine.dir/textures/sprites/renderers/SpriteRenderer.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\2DEngine.dir\textures\sprites\renderers\SpriteRenderer.cpp.obj -c C:\Users\Chris\Dev\2DEngine\textures\sprites\renderers\SpriteRenderer.cpp

CMakeFiles/2DEngine.dir/textures/sprites/renderers/SpriteRenderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2DEngine.dir/textures/sprites/renderers/SpriteRenderer.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Chris\Dev\2DEngine\textures\sprites\renderers\SpriteRenderer.cpp > CMakeFiles\2DEngine.dir\textures\sprites\renderers\SpriteRenderer.cpp.i

CMakeFiles/2DEngine.dir/textures/sprites/renderers/SpriteRenderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2DEngine.dir/textures/sprites/renderers/SpriteRenderer.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Chris\Dev\2DEngine\textures\sprites\renderers\SpriteRenderer.cpp -o CMakeFiles\2DEngine.dir\textures\sprites\renderers\SpriteRenderer.cpp.s

CMakeFiles/2DEngine.dir/textures/sprites/renderers/SpriteRenderer.cpp.obj.requires:

.PHONY : CMakeFiles/2DEngine.dir/textures/sprites/renderers/SpriteRenderer.cpp.obj.requires

CMakeFiles/2DEngine.dir/textures/sprites/renderers/SpriteRenderer.cpp.obj.provides: CMakeFiles/2DEngine.dir/textures/sprites/renderers/SpriteRenderer.cpp.obj.requires
	$(MAKE) -f CMakeFiles\2DEngine.dir\build.make CMakeFiles/2DEngine.dir/textures/sprites/renderers/SpriteRenderer.cpp.obj.provides.build
.PHONY : CMakeFiles/2DEngine.dir/textures/sprites/renderers/SpriteRenderer.cpp.obj.provides

CMakeFiles/2DEngine.dir/textures/sprites/renderers/SpriteRenderer.cpp.obj.provides.build: CMakeFiles/2DEngine.dir/textures/sprites/renderers/SpriteRenderer.cpp.obj


# Object files for target 2DEngine
2DEngine_OBJECTS = \
"CMakeFiles/2DEngine.dir/main.cpp.obj" \
"CMakeFiles/2DEngine.dir/textures/Texture.cpp.obj" \
"CMakeFiles/2DEngine.dir/textures/sprites/renderers/TileRenderer.cpp.obj" \
"CMakeFiles/2DEngine.dir/objects/Timer.cpp.obj" \
"CMakeFiles/2DEngine.dir/objects/entity/player/EntityPlayer.cpp.obj" \
"CMakeFiles/2DEngine.dir/objects/block/Tile.cpp.obj" \
"CMakeFiles/2DEngine.dir/objects/World.cpp.obj" \
"CMakeFiles/2DEngine.dir/objects/gui/GUI.cpp.obj" \
"CMakeFiles/2DEngine.dir/objects/handlers/GUIHandler.cpp.obj" \
"CMakeFiles/2DEngine.dir/objects/block/GameObject.cpp.obj" \
"CMakeFiles/2DEngine.dir/objects/handlers/GameObjectHandler.cpp.obj" \
"CMakeFiles/2DEngine.dir/textures/sprites/renderers/SpriteRenderer.cpp.obj"

# External object files for target 2DEngine
2DEngine_EXTERNAL_OBJECTS =

2DEngine.exe: CMakeFiles/2DEngine.dir/main.cpp.obj
2DEngine.exe: CMakeFiles/2DEngine.dir/textures/Texture.cpp.obj
2DEngine.exe: CMakeFiles/2DEngine.dir/textures/sprites/renderers/TileRenderer.cpp.obj
2DEngine.exe: CMakeFiles/2DEngine.dir/objects/Timer.cpp.obj
2DEngine.exe: CMakeFiles/2DEngine.dir/objects/entity/player/EntityPlayer.cpp.obj
2DEngine.exe: CMakeFiles/2DEngine.dir/objects/block/Tile.cpp.obj
2DEngine.exe: CMakeFiles/2DEngine.dir/objects/World.cpp.obj
2DEngine.exe: CMakeFiles/2DEngine.dir/objects/gui/GUI.cpp.obj
2DEngine.exe: CMakeFiles/2DEngine.dir/objects/handlers/GUIHandler.cpp.obj
2DEngine.exe: CMakeFiles/2DEngine.dir/objects/block/GameObject.cpp.obj
2DEngine.exe: CMakeFiles/2DEngine.dir/objects/handlers/GameObjectHandler.cpp.obj
2DEngine.exe: CMakeFiles/2DEngine.dir/textures/sprites/renderers/SpriteRenderer.cpp.obj
2DEngine.exe: CMakeFiles/2DEngine.dir/build.make
2DEngine.exe: C:/Program\ Files\ (x86)/mingw-w64/i686-7.2.0-posix-dwarf-rt_v5-rev1/mingw32/lib/libSDL2main.a
2DEngine.exe: C:/Program\ Files\ (x86)/mingw-w64/i686-7.2.0-posix-dwarf-rt_v5-rev1/mingw32/lib/libSDL2.dll.a
2DEngine.exe: C:/Program\ Files\ (x86)/mingw-w64/i686-7.2.0-posix-dwarf-rt_v5-rev1/mingw32/lib/libSDL2_image.dll.a
2DEngine.exe: C:/Program\ Files\ (x86)/mingw-w64/i686-7.2.0-posix-dwarf-rt_v5-rev1/mingw32/lib/libSDL2_ttf.dll.a
2DEngine.exe: CMakeFiles/2DEngine.dir/linklibs.rsp
2DEngine.exe: CMakeFiles/2DEngine.dir/objects1.rsp
2DEngine.exe: CMakeFiles/2DEngine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Chris\Dev\2DEngine\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable 2DEngine.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\2DEngine.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/2DEngine.dir/build: 2DEngine.exe

.PHONY : CMakeFiles/2DEngine.dir/build

CMakeFiles/2DEngine.dir/requires: CMakeFiles/2DEngine.dir/main.cpp.obj.requires
CMakeFiles/2DEngine.dir/requires: CMakeFiles/2DEngine.dir/textures/Texture.cpp.obj.requires
CMakeFiles/2DEngine.dir/requires: CMakeFiles/2DEngine.dir/textures/sprites/renderers/TileRenderer.cpp.obj.requires
CMakeFiles/2DEngine.dir/requires: CMakeFiles/2DEngine.dir/objects/Timer.cpp.obj.requires
CMakeFiles/2DEngine.dir/requires: CMakeFiles/2DEngine.dir/objects/entity/player/EntityPlayer.cpp.obj.requires
CMakeFiles/2DEngine.dir/requires: CMakeFiles/2DEngine.dir/objects/block/Tile.cpp.obj.requires
CMakeFiles/2DEngine.dir/requires: CMakeFiles/2DEngine.dir/objects/World.cpp.obj.requires
CMakeFiles/2DEngine.dir/requires: CMakeFiles/2DEngine.dir/objects/gui/GUI.cpp.obj.requires
CMakeFiles/2DEngine.dir/requires: CMakeFiles/2DEngine.dir/objects/handlers/GUIHandler.cpp.obj.requires
CMakeFiles/2DEngine.dir/requires: CMakeFiles/2DEngine.dir/objects/block/GameObject.cpp.obj.requires
CMakeFiles/2DEngine.dir/requires: CMakeFiles/2DEngine.dir/objects/handlers/GameObjectHandler.cpp.obj.requires
CMakeFiles/2DEngine.dir/requires: CMakeFiles/2DEngine.dir/textures/sprites/renderers/SpriteRenderer.cpp.obj.requires

.PHONY : CMakeFiles/2DEngine.dir/requires

CMakeFiles/2DEngine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\2DEngine.dir\cmake_clean.cmake
.PHONY : CMakeFiles/2DEngine.dir/clean

CMakeFiles/2DEngine.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Chris\Dev\2DEngine C:\Users\Chris\Dev\2DEngine C:\Users\Chris\Dev\2DEngine\cmake-build-debug C:\Users\Chris\Dev\2DEngine\cmake-build-debug C:\Users\Chris\Dev\2DEngine\cmake-build-debug\CMakeFiles\2DEngine.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/2DEngine.dir/depend

