cmake_minimum_required(VERSION 3.10)

project(ProjectName LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Collect all .cpp files from src/ (recursively) and from project root
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/*.cpp"
)

# If no sources found, fail with a helpful message
if(NOT SOURCES)
    message(FATAL_ERROR "No source files found. Make sure you have a main() implementation in src/ (e.g. src/main.cpp) or in the project root (main.cpp).")
endif()

add_executable(${PROJECT_NAME} ${SOURCES})
