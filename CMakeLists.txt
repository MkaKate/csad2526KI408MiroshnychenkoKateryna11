cmake_minimum_required(VERSION 3.10)

project(ProjectName LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# -----------------------------
#     FIND ALL SOURCE FILES
# -----------------------------
file(GLOB_RECURSE SOURCES
    CONFIGURE_DEPENDS
    src/*.cpp
    src/*.cxx
    src/*.cc
    main.cpp
    math_operations.cpp
)

# -----------------------------
#     INCLUDE ROOT FOLDER
# -----------------------------
include_directories(${PROJECT_SOURCE_DIR})

# -----------------------------
#     MAIN EXECUTABLE
# -----------------------------
add_executable(${PROJECT_NAME} ${SOURCES})

# -----------------------------
# GOOGLE TEST (FetchContent)
# -----------------------------
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# -----------------------------
#     UNIT TESTS
# -----------------------------
add_executable(unit_tests
    tests/unit_tests.cpp
)

# Тести бачать корінь проєкту
target_include_directories(unit_tests PRIVATE ${PROJECT_SOURCE_DIR})

# Зв’язування з GTest і main-проєктом (якщо треба)
target_link_libraries(unit_tests
    PRIVATE
    ProjectName
    gtest
    gtest_main
)

add_test(NAME all_tests COMMAND unit_tests)
