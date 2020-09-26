cmake_minimum_required(VERSION 3.17)
project(Arcanoid)

set(CMAKE_CXX_STANDARD 20)
set(SFML_DIR ../SFML-2.5.1/lib/cmake/SFML)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(Arcanoid
        main.cpp
        ball.cpp
        ball.hpp
        paddle.cpp
        paddle.hpp
        paddle_collider.cpp
        paddle_collider.hpp
        block.cpp
        block.hpp
        block_collider.cpp
        block_collider.hpp
        game.cpp
        game.hpp
        assets_manager.cpp
        assets_manager.hpp)

target_link_libraries(Arcanoid sfml-graphics sfml-audio)