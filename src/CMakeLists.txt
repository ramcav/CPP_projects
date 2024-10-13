include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(smart OBJECT smart.cpp)
link_libraries(smart)

add_executable(main main.cpp)