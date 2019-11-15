cmake_minimum_required(VERSION 3.15)
project(Stained_Glass_Game)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Stained_Glass_Game
        joueur.cpp
        joueur.h
        lots.cpp
        lots.h
        main.cpp
        vitrail.cpp
        vitrail.h)
