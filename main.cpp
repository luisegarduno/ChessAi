/*
 * EnigmaChess v0.0.1
 * ------------------
 * Created by Luis G.
*/

#include <iostream>
#include "ChessBoard.h"

using namespace std;

int main(int argc, char * argv[]){


  ChessBoard * board = new ChessBoard();
  board->display();

  cout << "\n\t------------------------------\n" << endl;

  string fen = "rnbq1k1r/pp1Pbppp/2p5/8/2B5/8/PPP1NnPP/RNBQK2R w KQ - 1 8";

  board->loadFEN(fen);
  board->display();

  cout << "\n\t------------------------------\n" << endl;

  int s = 0, e = 0;

  cout << "Enter S: ";
  cin >> s;

  cout << "Enter E: ";
  cin >> e;

  board->movePiece(s, e);
  board->display();

  cout << "\n\t------------------------------\n" << endl;

  return 0;
}
