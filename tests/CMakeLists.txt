# FetchContent setup for GoogleTest
include(FetchContent)

# Fetch GoogleTest
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.2
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Add the test executable
add_executable(test_zipf ${CMAKE_SOURCE_DIR}/tests/test.cpp)

target_compile_definitions(test_zipf PRIVATE TEST_FILE_PATH="${CMAKE_BINARY_DIR}/test.txt")

# Include project headers and Matplot++ headers
target_include_directories(test_zipf PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Link the test executable with existing libraries and GoogleTest
target_link_libraries(
    test_zipf
    zipf             # Link with the existing zipf library
    zipf_algo        # Link with the existing zipf_algo library
    GTest::gtest_main
)

# Discover and enable GoogleTest
include(GoogleTest)
gtest_discover_tests(test_zipf)

# Copy any necessary test files to the build directory
add_custom_command(
    TARGET test_zipf POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_SOURCE_DIR}/tests/test.txt
            ${CMAKE_BINARY_DIR}
)
