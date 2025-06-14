cmake_minimum_required(VERSION 3.31)
project(Integrative_Project)

set(CMAKE_CXX_STANDARD 20)

add_executable(Integrative_Project main.cpp
        Videos.cpp
        Videos.h
        movies.cpp
        movies.h
        series.cpp
        series.h
        episodes.cpp
        episodes.h)
