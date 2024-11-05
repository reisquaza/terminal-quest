cmake_minimum_required(VERSION 3.10)

project(terminal-quest)

file(GLOB SOURCES "src/*.cpp" "src/*.h" "*.cpp" "*.h")

add_executable(${PROJECT_NAME} main.cpp ${SOURCES}) 

