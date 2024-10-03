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

# Add the include directory for header files (do NOT add it as a subdirectory)
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add the libraries for students and dynamic array
add_library(students_lib SHARED ${CMAKE_SOURCE_DIR}/src/students.cpp)
add_library(dynamic_array_lib SHARED ${CMAKE_SOURCE_DIR}/src/dyn_array.cpp)

# Add the test executables
add_executable(test_students ${CMAKE_SOURCE_DIR}/tests/tests.cpp)
add_executable(test_dynamic_array ${CMAKE_SOURCE_DIR}/tests/test_arr.cpp)

# Link the test executables with the corresponding libraries and GTest
target_link_libraries(
  test_students
  students_lib
  GTest::gtest_main
)

target_link_libraries(
  test_dynamic_array
  dynamic_array_lib
  GTest::gtest_main
)

# Discover the tests in both test executables
gtest_discover_tests(test_students)
gtest_discover_tests(test_dynamic_array)