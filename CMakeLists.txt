# Every CMake project needs to start with these two lines
cmake_minimum_required(VERSION 3.20) # This is the minimum version of CMake required
project(MyProject VERSION 1.0) # This is the name of the project and its version
find_package(Python3 REQUIRED) # This line is used to find the Python3 package (FOR PYTHON PLOT)
include(FetchContent)

FetchContent_Declare(
    matplotplusplus
    GIT_REPOSITORY https://github.com/alandefreitas/matplotplusplus
    GIT_TAG origin/master
)

FetchContent_GetProperties(matplotplusplus)
if(NOT matplotplusplus_POPULATED)
    FetchContent_Populate(matplotplusplus)
    add_subdirectory(${matplotplusplus_SOURCE_DIR} ${matplotplusplus_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()


set(CMAKE_CXX_STANDARD 20) # This sets the C++ standard to C++17
set(CMAKE_CXX_STANDARD_REQUIRED True) # This tells CMake that the stdandard must be available

# We place the executables in the bin directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# We place the libraries in the lib directory
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# We normally have a CMakeLists.txt file in each directory that has something that needs to be built
add_subdirectory(src)
enable_testing() # This line allows to call ctest after compilation
add_subdirectory(tests)
add_subdirectory(docs)