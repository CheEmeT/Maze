cmake_minimum_required(VERSION 3.29.0)

project(maze)

file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp") # Define PROJECT_SOURCES as a list of all source files
set(PROJECT_INCLUDE "${CMAKE_CURRENT_LIST_DIR}/src/") # Define PROJECT_INCLUDE to be the path to the include directory of the project

include(FetchContent)
message(STATUS "Fetching raylib...")

set(FETCHCONTENT_QUIET FALSE)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # don't build the supplied example games

FetchContent_Declare(
	raylib
	GIT_REPOSITORY https://github.com/raysan5/raylib.git
	GIT_TAG 5.5
	GIT_SHALLOW 1
	GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(raylib)

add_subdirectory(ui)

add_executable(maze ${PROJECT_SOURCES})
target_link_libraries(maze ui raylib)
