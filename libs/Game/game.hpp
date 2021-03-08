#ifndef GAME_HPP_
#define GAME_HPP_

#include <logic.hpp>

class Game
{
    public:
        //Calls init() inside constructor
        Game();

        //Calls either play_ai() or play() based on user preference
        void start();
    private:
        //Initializes user preferences
        void init();
        void play_ai();
        //Two player mode
        void play();
        Logic gameLogic;
        Board gameBoard;
        char userPiece;
        char enemyPiece;
        bool ai;
        bool playing;
};

#endif