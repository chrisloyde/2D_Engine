cmake_minimum_required(VERSION 3.9)
project(2DEngine)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
set(CMAKE_CXX_STANDARD 11)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR})

add_executable(2DEngine main.cpp textures/Texture.cpp textures/Texture.h textures/sprites/renderers/TileRenderer.cpp textures/sprites/renderers/headers/TileRenderer.h objects/Timer.cpp objects/headers/Timer.h objects/entity/player/EntityPlayer.cpp objects/entity/headers/EntityPlayer.h objects/block/Tile.cpp objects/block/headers/Tile.h objects/World.cpp objects/headers/World.h)
target_link_libraries(2DEngine ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARY})