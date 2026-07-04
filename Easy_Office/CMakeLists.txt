cmake_minimum_required(VERSION 4.2)
project(Open)

set(CMAKE_CXX_STANDARD 20)

add_library(Open SHARED open.cpp
        Open.h
        Methods.h
        Excel_Methods.cpp
        Excel_Methods.h
        Word_Methods.cpp
        Word_Methods.h
        PPT_Methods.cpp
        PPT_Methods.h
        OutLook.cpp
        OutLook.h
        Methods.cpp)

target_link_libraries(Open ole32)
