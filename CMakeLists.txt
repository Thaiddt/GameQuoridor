# CMakeLists.txt
cmake_minimum_required(VERSION 3.12)
project(GameQuoridor)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

add_executable(GameQuoridor 
    client/main.cpp
    client/NetworkUtilsClient.cpp
    client/Client.cpp
    server/main.cpp
    server/NetworkUtilsServer.cpp
    server/Server.cpp
)

target_link_libraries(GameQuoridor sfml-graphics)
