cmake_minimum_required(VERSION 3.10)
project(Plunder_DnD_Loot)

# includes cmake/FindSDL2.cmake
#set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 11)

file(GLOB SOURCES src/*.cpp)
set(SOURCE_FILES ${SOURCES})

add_executable(Plunder_DnD_Loot ${SOURCE_FILES})
target_link_libraries(Plunder_DnD_Loot ${SDL2_LIBRARY} -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer -mwindows)