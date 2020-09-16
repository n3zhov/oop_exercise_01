cmake_minimum_required(VERSION 3.10)

project(OOP1)

add_executable(oop_exercise_01 main.cpp)
set_target_properties(main PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        )