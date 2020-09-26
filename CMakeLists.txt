cmake_minimum_required(VERSION 3.17)
project(Arcanoid)

set(CMAKE_CXX_STANDARD 20)
set(SFML_DIR ../SFML-2.5.1/lib/cmake/SFML)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(Arcanoid
        src/main.cpp
        src/ball.cpp
        src/ball.hpp
        src/paddle.cpp
        src/paddle.hpp
        src/paddle_collider.cpp
        src/paddle_collider.hpp
        src/block.cpp
        src/block.hpp
        src/block_collider.cpp
        src/block_collider.hpp
        src/game.cpp
        src/game.hpp
        src/assets_manager.cpp
        src/assets_manager.hpp)

target_link_libraries(Arcanoid sfml-graphics sfml-audio)