cmake_minimum_required(VERSION 3.29.0)

project(ui)

file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp") # Define PROJECT_SOURCES as a list of all source files
set(PROJECT_INCLUDE "${CMAKE_CURRENT_LIST_DIR}/include/") # Define PROJECT_INCLUDE to be the path to the include directory of the project

include_directories("${PROJECT_INCLUDE}")

add_library(ui STATIC ${PROJECT_SOURCES})
target_include_directories(ui INTERFACE "${PROJECT_INCLUDE}")