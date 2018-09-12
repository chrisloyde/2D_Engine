cmake_minimum_required(VERSION 3.9)
project(2DEngine)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/src/cmake)
set(CMAKE_CXX_STANDARD 11)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

file(GLOB_RECURSE 2DEngine_SRC "src/*.h" "src/*.cpp")

include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR})

add_executable(2DEngine ${2DEngine_SRC})
target_link_libraries(2DEngine ${PROJECT_LIBRARY} ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARY})