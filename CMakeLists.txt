cmake_minimum_required(VERSION 3.3)
project(tcodRL)

include_directories(include)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/Actor.cpp src/Actor.hpp src/Map.cpp src/Map.hpp src/Engine.cpp src/Engine.hpp src/main.hpp src/Destructible.cpp src/Destructible.hpp src/Attacker.cpp src/Attacker.hpp src/Ai.cpp src/Ai.hpp)
add_executable(tcodRL ${SOURCE_FILES})

file(COPY terminal.png DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

## LINKER LIBRARIES
FIND_LIBRARY(LIBTCOD NAMES tcod PATHS lib)
FIND_LIBRARY(LIBTCODXX NAMES tcodxx
        PATHS lib)
target_link_libraries(tcodRL ${LIBTCOD} ${LIBTCODXX})
