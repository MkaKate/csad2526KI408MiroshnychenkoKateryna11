cmake_minimum_required(VERSION 3.14)
project(MathProject CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Main library
add_library(math_operations math_operations.cpp)

# GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.14.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings.
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Unit tests executable
add_executable(unit_tests tests/unit_tests.cpp)
target_link_libraries(unit_tests PRIVATE math_operations gtest_main)

include(GoogleTest)
gtest_discover_tests(unit_tests)
