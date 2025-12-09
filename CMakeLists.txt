cmake_minimum_required(VERSION 3.14)
project(HelloWorld LANGUAGES CXX)

# -----------------------------
# Compiler settings
# -----------------------------
# Use a modern standard (C++17 or C++20)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# -----------------------------
# Source Code Library (Best Practice)
# -----------------------------
# Group your source code into a library for clean linking
add_library(MathOps math_operations.cpp)
target_include_directories(MathOps PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}) # If headers are in the root

# -----------------------------
# Main executable
# -----------------------------
add_executable(hello main.cpp)
target_link_libraries(hello PRIVATE MathOps)

# -----------------------------
# GoogleTest integration
# -----------------------------
include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

# This setting ensures compatibility with MSVC/Windows builds. Keep it.
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# -----------------------------
# Unit tests (Wrapped in conditional)
# -----------------------------
option(BUILD_TESTS "Build unit tests" ON)

if(BUILD_TESTS)
  # Файл тепер у tests/unit_tests.cpp
  add_executable(unit_tests
    tests/unit_tests.cpp
  )

  # Link MathOps library, which includes the source and include path
  target_link_libraries(unit_tests PRIVATE GTest::gtest_main MathOps)
  
  # Remove the redundant/deprecated line:
  # target_include_directories(unit_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

  add_test(NAME unit_tests COMMAND unit_tests)
else()
  message(STATUS "Unit tests are disabled.")
endif()
