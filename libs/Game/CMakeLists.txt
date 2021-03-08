add_library(
    my_game
    game.cpp
)

target_link_libraries(my_game my_logic my_utilities)
target_include_directories(my_game PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")