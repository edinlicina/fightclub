cmake_minimum_required(VERSION 3.26)
project(fightclub)

set(CMAKE_CXX_STANDARD 17)

add_executable(fightclub main.cpp attack.cpp fighter.cpp game.cpp saiyan.cpp human.cpp team.cpp)