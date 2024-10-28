include_directories(${CMAKE_SOURCE_DIR}/include)

# Add library and link matplotplusplus
add_library(zipf OBJECT zipf.cpp)
target_include_directories(zipf PUBLIC ${matplotplusplus_SOURCE_DIR}/include)
target_link_libraries(zipf PUBLIC matplot)

add_library(zipf_algo OBJECT zipf_algo.cpp)
target_include_directories(zipf_algo PUBLIC ${matplotplusplus_SOURCE_DIR}/include)
target_link_libraries(zipf_algo PUBLIC matplot)

# Add main executable and link zipf library and matplotplusplus
add_executable(main main.cpp)
target_include_directories(main PUBLIC ${matplotplusplus_SOURCE_DIR}/include)
target_link_libraries(main PUBLIC zipf zipf_algo matplot)

add_custom_command(
    TARGET main PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/img
)
add_custom_command(
    TARGET main PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/output
)

add_custom_command(
    TARGET main POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_SOURCE_DIR}/data/mobby.txt
            ${CMAKE_BINARY_DIR}
)

add_custom_command(
    TARGET main POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_SOURCE_DIR}/data/quijote.txt
            ${CMAKE_BINARY_DIR}
)

add_custom_target(run_plot_script
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_SOURCE_DIR}/src/plot_script.py
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running plot_script.py"
)

add_custom_target(run_plot_script_vs
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_SOURCE_DIR}/src/plot_script_vs.py
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running plot_script_vs.py"
)
