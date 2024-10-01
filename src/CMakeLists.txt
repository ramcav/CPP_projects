include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(students OBJECT students.cpp)
link_libraries(students)
add_library(dyn_array OBJECT dyn_array.cpp)
link_libraries(dyn_array)
add_library(person OBJECT person.cpp)
link_libraries(person)

add_executable(main main.cpp)