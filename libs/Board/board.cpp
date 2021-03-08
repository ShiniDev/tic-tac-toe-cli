#include "board.hpp"
#include <iostream>

Board::Board()
{
    //Initializes map array to iwhitespaces
    for(int i = 0; i < Board_Row_Length; i++)
    {
        for(int j = 0; j < Board_Column_Length; j++)
        {
            map[i][j] = ' ';
        }
    }
}

void Board::draw_vertical()
{
    std::cout << "   |   |   ";
}

void Board::draw_boarder()
{
    std::cout << "___|___|___";
}

void Board::draw_board()
{
    std::cout << "   0   1   2\n";
    for(int i = 0; i < Board_Row_Length; i++)
    {
        std::cout << "  ";
        if(i!=0)
        {
            draw_vertical();
        }
        std::cout << std::endl;
        std::cout << i << " ";
        for(int j = 0; j < Board_Column_Length; j++)
        {
            std::cout << " " << map[i][j] << " ";
            if(j!=2)
            {
                std::cout << "|";
            }
        }
        std::cout << std::endl;
        if(i!=2)
        {
            std::cout << "  ";
            draw_boarder();
        }
        std::cout << std::endl;
    }
}

void Board::clear_board()
{
    //Clears the board again to whitespaces
    for(int i = 0; i < Board_Row_Length; i++)
    {
        for(int j = 0; j < Board_Column_Length; j++)
        {
            map[i][j] = ' ';
        }
    }
}

bool Board::add_piece(int row,int column, char piece)
{
    //Checks if piece is added
    if(map[row][column]==' ')
    {
        map[row][column]=piece;
        return true;
    }
    return false;
}