cmake_minimum_required(VERSION 3.14)
project(MathProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the library (source file must exist in project root)
add_library(math_operations STATIC math_operations.cpp)
target_include_directories(math_operations PUBLIC ${CMAKE_SOURCE_DIR})

# GoogleTest via FetchContent
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.14.0.zip
)
# Prevent overriding compiler/linker settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Unit tests executable (ensure the source path is correct)
add_executable(unit_tests tests/unit_tests.cpp)
target_link_libraries(unit_tests PRIVATE math_operations GTest::gtest_main)

# Make sure the tests can find the headers
target_include_directories(unit_tests PRIVATE ${CMAKE_SOURCE_DIR})

# Discover and register tests with CTest
include(GoogleTest)
gtest_discover_tests(unit_tests)
