# Our C++ project contains a single executable built from main.cpp
# It uses the definitions in my_library.cpp,  which are defined in the header file my_library.h
# Lets compile the library first
add_library(doubly_linked_list SHARED doubly_linked_list.cpp)
# Now we compile the executable
# We need to tell CMake that we want to build an executable
add_executable(main main.cpp)
# We need to tell CMake that the executable depends on the library
# This is done by linking the library to the executable
target_link_libraries(main doubly_linked_list)

# Create the casting executable from casting.cpp
add_executable(casting casting.cpp)

# Create the pointer_arithmetic executable from pointer_arithmetic.cpp
add_executable(pointer_arithmetic pointer_arithmetic.cpp)

add_executable(inject inject.cpp)