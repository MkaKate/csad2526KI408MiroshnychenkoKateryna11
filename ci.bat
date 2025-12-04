@echo off
REM Create build directory
if not exist build mkdir build

REM Change into the build directory
cd build

REM Configure the project using CMake
cmake ..

REM Build the project
cmake --build .

REM Run tests using CTest
ctest

REM Go back to project root directory
cd ..

REM (Optional) Make batch file read-only if needed (Windows has no direct equivalent to chmod +x)
