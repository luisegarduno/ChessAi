/*
 * EnigmaChess v0.0.1
 * ------------------
 * Created by Luis G.
*/

#define CATCH_CONFIG_RUNNER
#include <iostream>
#include "catch.hpp"
#include "ChessBoard.h"

using namespace std;

#define TEST true

// Runs test.cpp using Catch2 library
int runCatchTests(int argc, char * argv[]){
  return Catch::Session().run(argc,argv);
}

int main(int argc, char * argv[]){

  if(TEST) return runCatchTests(argc, argv);

  //else{

    ChessBoard * board = new ChessBoard();

    // Display empty board
    //board->display();
    //cout << "\n\t------------------------------\n" << endl;

    string fen = "rnbq1k1r/pp1Pbppp/2p5/8/2B5/8/PPP1NnPP/RNBQK2R w KQ - 1 8";
    board->loadFEN(fen);

    // Display loaded-in board
    board->display();
    cout << "\n\t------------------------------\n" << endl;

    int s = 0, e = 0;

    cout << "StartPos Index: "; cin >> s;
    cout << "EndPos Index: "; cin >> e;
    board->movePiece(s, e);

    // Display updated board
    board->display();
    cout << "\n\t------------------------------\n" << endl;
  //} 

  return 0;
}
