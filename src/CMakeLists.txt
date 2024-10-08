include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(split OBJECT split.cpp)
link_libraries(split)

add_executable(main main.cpp)