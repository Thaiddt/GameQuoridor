# CMakeLists.txt
cmake_minimum_required(VERSION 3.12)
project(GameQuoridor)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

add_executable(GameQuoridor 
    src/game/Game.cpp
    src/game/Player.cpp
    src/game/Board.cpp
    src/main.cpp
)

target_link_libraries(GameQuoridor sfml-graphics)
