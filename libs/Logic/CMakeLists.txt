add_library(
    my_logic
    logic.cpp
)

target_link_libraries(my_logic my_board)
target_include_directories(my_logic PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
