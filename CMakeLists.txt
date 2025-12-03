cmake_minimum_required(VERSION 3.28)

project(PracticeClasses LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)

add_executable(PracticeClasses
    src/main.cpp
    src/Date.cpp
)

target_include_directories(PracticeClasses PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)