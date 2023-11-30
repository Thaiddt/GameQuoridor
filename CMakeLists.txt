cmake_minimum_required(VERSION 3.22)
project(GameQuoridor)

set(CMAKE_CXX_STANDARD 11)

add_executable(GameQuoridor src/Main.cpp)
target_link_libraries(GameQuoridor sfml-system sfml-window sfml-graphics sfml-network sfml-audio)

