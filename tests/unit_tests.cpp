cmake_minimum_required(VERSION 3.14)
project(ProjectName VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# build the core library from src/
add_library(core STATIC
    src/math_operations.cpp
)

# make the header in src/ available to any target that links core
target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

# main executable
add_executable(ProjectName src/main.cpp)
target_link_libraries(ProjectName PRIVATE core)

# GoogleTest subdirectory (assumes you add it as a submodule or FetchContent)
# add_subdirectory(_deps/googletest-build/googlemock ...)  <-- keep whatever you already use

# unit tests
enable_testing()
add_executable(unit_tests tests/unit_tests.cpp)
target_link_libraries(unit_tests PRIVATE core gtest_main)
# make sure the test target can find headers in src/
target_include_directories(unit_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

include(GoogleTest)
gtest_discover_tests(unit_tests)
