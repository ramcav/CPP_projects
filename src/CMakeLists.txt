include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(expression OBJECT expression.cpp)
link_libraries(expression)

add_executable(main main.cpp)