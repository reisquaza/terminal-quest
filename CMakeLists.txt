cmake_minimum_required(VERSION 3.10)

project(terminal-quest)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

file(GLOB SOURCES
    "src/*.cpp"
    "src/levels/*.cpp"
    "main.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})

