#ifndef LOGIC_HPP_
#define LOGIC_HPP_

#include <board.hpp>

class Logic
{
    public:
        Logic();

        //Checks the board if the specific piece won
        bool win(Board& board,char piece);
    private:
        //Checks the board for three consecutive piece on different directions
        bool check_horizontal(Board& board,char piece);
        bool check_vertical(Board& board,char piece);
        bool check_diagonal(Board& board,char piece);
};

#endif