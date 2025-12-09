cmake_minimum_required(VERSION 3.14)
project(HelloWorld LANGUAGES CXX)

# -----------------------------
# 1. Compiler settings
# -----------------------------
# Рекомендовано C++17 або вище для сучасних проектів
set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# -----------------------------
# 2. Shared Library (Спільний код)
# -----------------------------
# Створюємо статичну бібліотеку для 'math_operations.cpp'
add_library(MathOps STATIC
    math_operations.cpp
)
# Додаємо поточну директорію для заголовків, які можуть використовуватись ззовні
target_include_directories(MathOps PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


# -----------------------------
# 3. Main executable
# -----------------------------
add_executable(hello
    src/main.cpp
)
# Лінкуємо основний застосунок до бібліотеки
target_link_libraries(hello PRIVATE MathOps)


# -----------------------------
# 4. GoogleTest integration
# -----------------------------
include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
  # Виправлення попередження CMake про часову мітку (DOWNLOAD_EXTRACT_TIMESTAMP)
  DOWNLOAD_EXTRACT_TIMESTAMP true 
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# -----------------------------
# 5. Unit tests
# -----------------------------
option(BUILD_TESTS "Build unit tests" ON)

if(BUILD_TESTS)
  # Створюємо виконуваний файл тестів
  add_executable(unit_tests
      tests/unit_tests.cpp
  )

  # Лінкуємо тести до спільної бібліотеки MathOps та GTest
  target_link_libraries(unit_tests PRIVATE MathOps GTest::gtest_main)
  
  # Додаємо тест до системи CTest
  add_test(NAME unit_tests COMMAND unit_tests)
else()
  message(STATUS "Unit tests are disabled (BUILD_TESTS=OFF).")
endif()
