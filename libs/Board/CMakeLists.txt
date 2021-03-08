add_library(
    my_board
    board.cpp
)

target_include_directories(my_board PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")