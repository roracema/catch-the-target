cmake_minimum_required(VERSION 3.10)
project(CatchTheTarget)

set(CMAKE_TOOLCHAIN_FILE "/home/roracema/Documents/projects/catch-the-target/vcpkg/scripts/buildsystems/vcpkg.cmake")

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(CatchTheTarget main.cpp sprites/PlayerSprite.cpp sprites/GameMapSprite.cpp)
target_link_libraries(CatchTheTarget sfml-graphics sfml-window sfml-system sfml-audio)