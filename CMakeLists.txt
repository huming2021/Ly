
cmake_minimum_required(VERSION 3.26)
project(Ly)
# set(CMAKE_GENERATOR "Unix Makefiles")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})
set(CppFiles ./Ly.cpp)
add_executable(${PROJECT_NAME} ${CppFiles})