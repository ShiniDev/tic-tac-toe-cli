#include "game.hpp"
#include <myinputoutput.hpp>
#include <iostream>
#include <string>

Game::Game()
{
    srand(time(nullptr));
    init();
}

void Game::init()
{
    const int maxLength = 50;
    std::cout << std::setfill('#');
    //See myinputoutput.hpp
    print("\0",maxLength+1,'#');
    std::cout << std::setfill(' ');
    print("Tic-Tac-Toe Game",maxLength,'#');
    print("By: ShiniDev",maxLength,'#');
    std::cout << std::setfill('#');
    print("\0",maxLength+1,'#');
    std::cout << std::setfill(' ');
    std::string cmd;
    std::cout << "\nConfigurations\n";
    std::cout << "[1]Computer\n[2]Two Players\n";
    while(true)
    {
        std::cout << "> ";
        std::cin >> cmd;
        switch(cmd[0])
        {
            case '1':
                ai = true;
                break;
            case '2':
                ai = false;
                break;
            default:
                break;
        }
        if(cmd[0]=='1'||cmd[0]=='2')
        {
            break;
        }
    }
    std::cout << "Choose your piece\n";
    std::cout << "[X] or [O]\n";
    while(true)
    {
        std::cout << "> ";
        std::cin >> cmd;
        to_upper(cmd);
        switch(cmd[0])
        {
            case 'X':
                userPiece = 'X';
                enemyPiece = 'O';
                break;
            case 'O':
                userPiece = 'O';
                enemyPiece = 'X';
                break;
            default:
                break;
        }
        if(cmd[0]=='X'||cmd[0]=='O')
        {
            break;
        }
    }
    std::cout << std::endl;
}

void Game::start()
{
    playing = true;
    while(playing)
    {
        if(ai)
        {
            play_ai();
        }
        else
        {
            play();
        }
        std::cout << "Play again?(y/n)\n";
        std::string cmd;
        while(true)
        {
            std::cout << "> ";
            std::cin >> cmd;
            to_lower(cmd);
            if(cmd[0]=='y')
            {
                break;
            }
            else if(cmd[0]=='n')
            {
                playing = false;
                break;
            }
        }
        gameBoard.clear_board();
    }
}

void Game::play()
{
    std::string cmd;
    int pieceCount = 0;
    while(true)
    {
        gameBoard.draw_board();
        std::cout << "<User1> Enter column(x) and row(y)\n";
        int c,r;
        while(true)
        {
            std::cout << "> ";
            std::cin >> cmd;
            //Avoid error from invalid inputs
            if(is_integer(cmd))
            {
                c = std::stoi(cmd);
            }
            else
            {
                std::cout << "Error: Integers only\n";
                continue;
            }
            std::cin >> cmd;
            if(is_integer(cmd))
            {
                r = std::stoi(cmd);
            }
            else
            {
                std::cout << "Error: Integers only\n";
                continue;
            }
            if(!gameBoard.add_piece(r,c,userPiece))
            {
                std::cout << "Error: already has piece in there\n";
                continue;
            }
            break;
        }
        gameBoard.draw_board();
        pieceCount++;
        if(gameLogic.win(gameBoard,userPiece))
        {
            std::cout << "User1 wins!\n";
            break;
        }
        if(pieceCount==9)
        {
            std::cout << "Draw!\n";
            break;
        }
        std::cout << "<User2> Enter column(x) and row(y)\n";
        while(true)
        {
            std::cout << "> ";
            std::cin >> cmd;
            if(is_integer(cmd))
            {
                c = std::stoi(cmd);
            }
            else
            {
                std::cout << "Error: Integers only\n";
                continue;
            }
            std::cin >> cmd;
            if(is_integer(cmd))
            {
                r = std::stoi(cmd);
            }
            else
            {
                std::cout << "Error: Integers only\n";
                continue;
            }
            if(!gameBoard.add_piece(r,c,enemyPiece))
            {
                std::cout << "Error: already has piece in there\n";
                continue;
            }
            break;
        }
        pieceCount++;
        gameBoard.draw_board();
        if(gameLogic.win(gameBoard,enemyPiece))
        {
            std::cout << "User2 wins!\n";
            break;
        }
        if(pieceCount==9)
        {
            std::cout << "Draw!\n";
            break;
        }
    }
}

void Game::play_ai()
{
    std::string cmd;
    int pieceCount = 0;
    while(true)
    {
        gameBoard.draw_board();
        std::cout << "<User> Enter column(x) and row(y)\n";
        int c,r;
        while(true)
        {
            std::cout << "> ";
            std::cin >> cmd;
            if(is_integer(cmd))
            {
                c = std::stoi(cmd);
            }
            else
            {
                std::cout << "Error: Integers only\n";
                continue;
            }
            std::cin >> cmd;
            if(is_integer(cmd))
            {
                r = std::stoi(cmd);
            }
            else
            {
                std::cout << "Error: Integers only\n";
                continue;
            }
            if(!gameBoard.add_piece(r,c,userPiece))
            {
                std::cout << "Error: already has piece in there\n";
                continue;
            }
            break;
        }
        gameBoard.draw_board();
        pieceCount++;
        if(gameLogic.win(gameBoard,userPiece))
        {
            std::cout << "User wins!\n";
            break;
        }
        if(pieceCount==9)
        {
            std::cout << "Draw!\n";
            break;
        }
        while(true)
        {
            //Ai is just random (for now)
            r = rand()%3;
            c = rand()%3;
            if(gameBoard.add_piece(r,c,enemyPiece))
            {
                std::cout << "<Computer> Enter column(x) and row(y)\n> " << c << " " << r << '\n';
                break;
            }
        }
        gameBoard.draw_board();
        pieceCount++;
        if(gameLogic.win(gameBoard,enemyPiece))
        {
            std::cout << "Computer wins!\n";
            break;
        }
        if(pieceCount==9)
        {
            std::cout << "Draw!\n";
            break;
        }
    }
}