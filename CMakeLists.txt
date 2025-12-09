cmake_minimum_required(VERSION 3.14)
project(MathProject CXX)

# ------------------------------
# Use C++17
# ------------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ------------------------------
# Main library
# ------------------------------
add_library(math_operations math_operations.cpp)

# ------------------------------
# GoogleTest via FetchContent (Git)
# ------------------------------
include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.14.0
)

# For Windows: prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Make GoogleTest available
FetchContent_MakeAvailable(googletest)

# ------------------------------
# Enable testing
# ------------------------------
enable_testing()

# ------------------------------
# Unit tests executable
# ------------------------------
add_executable(unit_tests tests/unit_tests.cpp)
target_link_libraries(unit_tests PRIVATE math_operations gtest_main)

# ------------------------------
# Auto-discover tests
# ------------------------------
include(GoogleTest)
gtest_discover_tests(unit_tests)
