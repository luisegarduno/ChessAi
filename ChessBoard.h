/*
 * EnigmaChess
 * ------------------
 * Created by Luis G.
 */

#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "Piece.h"
#include <iostream>
#include <unordered_map>

class ChessBoard{

  public:
    ChessBoard();
    void initBoard(std::string s);
    void clearBoard();
    
    void display();

    // FEN functions
    void loadFEN(std::string s);
    void strip_FEN(std::string s);
    void setFEN(std::string s);
    std::string getFEN();



    char pieceAt(int idx);
    void movePiece(int s, int e);

    Piece pieces;
    bool checkPawn(int s, int e);
    bool checkRook(int s, int e);

    void changeTurn();

    /* @todo: finish board class */

    bool isCheck(int checkColor);
    bool isCheckmate(int checkColor);

    char curTurn;
    ~ChessBoard();

  private:
    char** board_array;
    std::unordered_map<int, int> m;
    std::string startFEN;
};

#endif // CHESSBOARD_H
