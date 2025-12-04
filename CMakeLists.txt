cmake_minimum_required(VERSION 3.10)

# Set the project name
project(ProjectName LANGUAGES CXX)

# Set C++ standard to at least C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Collect all source files in src/
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp src/*.cxx src/*.cc)

# Optionally, add the include/ directory (if it exists)
include_directories(${PROJECT_SOURCE_DIR}/include)

# Define the executable target
add_executable(${PROJECT_NAME} ${SOURCES})
