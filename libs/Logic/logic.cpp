#include "logic.hpp"

Logic::Logic()
{}

//Checks the board if there is a 3 consecutive piece horizontally
bool Logic::check_horizontal(Board& board,char piece)
{
    auto map = board.get_map();
    for(int i = 0; i < Board::Board_Row_Length; i++)
    {
        if(map[i][2]==piece&&map[i][1]==piece&&map[i][0]==piece)
        {
            return true;
        }
    }
    return false;
}

//Checks the board if there is a 3 consecutive piece vertically
bool Logic::check_vertical(Board& board,char piece)
{
    auto map = board.get_map();
    for(int i = 0; i < Board::Board_Row_Length; i++)
    {
        if(map[2][i]==piece&&map[1][i]==piece&&map[0][i]==piece)
        {
            return true;
        }
    }
    return false;
}

//Checks the board if there is a 3 consecutive piece diagonally
bool Logic::check_diagonal(Board& board,char piece)
{
    auto map = board.get_map();
    return ((map[0][2]==piece&&map[1][1]==piece&&map[2][0]==piece) || (map[0][0]==piece&&map[1][1]==piece&&map[2][2]==piece));
}

bool Logic::win(Board& board,char piece)
{
    return (check_horizontal(board,piece)||check_vertical(board,piece)||check_diagonal(board,piece));
}