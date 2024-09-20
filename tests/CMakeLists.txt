include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.2
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)

# Add src as an include so that we can include the header files in the tests
include_directories(${CMAKE_SOURCE_DIR}/src)

# Add the doubly_linked_list library
add_library(doubly_linked_list_lib SHARED ../src/doubly_linked_list.cpp)

# Add the test executable
add_executable(test_doubly_linked_list test_doubly_linked_list.cpp)

# Link the test executable with the doubly_linked_list library and GTest
target_link_libraries(
  test_doubly_linked_list
  doubly_linked_list_lib
  GTest::gtest_main
)

# Add the test to the test suite
gtest_discover_tests(test_doubly_linked_list)
