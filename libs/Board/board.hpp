#ifndef BOARD_HPP_
#define BOARD_HPP_

class Board
{
    public:
        enum
        {
            Board_Row_Length = 3,
            Board_Column_Length = 3
        };
        //Initializes the value of map[][]
        Board();

        //Draws the map[][]
        void draw_board();
        //Clears the map[][]
        void clear_board();
        //Adds piece to the map[][]
        bool add_piece(int row,int column, char piece);

        //Get map by reference
        const char (&get_map())[Board_Row_Length][Board_Column_Length]{return map;}
    private:
        char map[Board_Row_Length][Board_Column_Length];
        void draw_vertical();
        void draw_boarder();
};

#endif