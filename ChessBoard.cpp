/*
 * EnigmaChess
 * ------------------
 * Created by Luis G.
 */

#include "ChessBoard.h"

#include <map>
#include <string>
#include <vector>
#include <ctype.h>
#include <stdio.h>
#include <iostream>
#include <unordered_map>

#define DEBUGS false

using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;

// ----------------------------------------------------
// Default Constructor : Dynamically creates a 2D Array
// ----------------------------------------------------
ChessBoard::ChessBoard(){
  if(DEBUGS) std::cout << "--> Creating empty 8x8 ChessBoard" << endl;

  clearBoard();

  if(DEBUGS) cout << "--> Done." << endl;
}

// ----------------------------------------------------
// loadFEN : Load Board w/ FEN string -----------------
// ----------------------------------------------------
void ChessBoard::loadFEN(std::string s){
  strip_FEN(s);
  std::string fen_str = getFEN();

  std::unordered_map<char, int> pieceTypeFromSymbol;
  pieceTypeFromSymbol.insert({'k', pieces.King});
  pieceTypeFromSymbol.insert({'p', pieces.Pawn});
  pieceTypeFromSymbol.insert({'n', pieces.Knight});
  pieceTypeFromSymbol.insert({'b', pieces.Bishop});
  pieceTypeFromSymbol.insert({'r', pieces.Rook});
  pieceTypeFromSymbol.insert({'q', pieces.Queen});

  int file = 0, rank = 7;
  for(int i = 0; i < fen_str.size(); i++){
    if(fen_str[i] == '/'){
      file = 0;
      rank--;
    }
    else{
      if(fen_str[i] >= 48 && fen_str[i] <= 57) { file += int(fen_str[i]) - 48; }
      else{
        int pieceColor = (std::isupper(fen_str[i])) ? pieces.White : pieces.Black;
        int pieceType = pieceTypeFromSymbol[std::tolower(fen_str[i])];

        this->m[rank * 8 + file] = pieceType | pieceColor;
        file++;
      }
    }
  }
  if(DEBUGS) cout << "\n--> FEN Successfully loaded onto board" << endl;
}

// ----------------------------------------------------
// pieceAt : return piece at location row,col ---------
// ----------------------------------------------------
char ChessBoard::pieceAt(int idx){
  int t = this->m[idx];

  if(t <= 14){
    if(t == 9) return 'K';
    if(t == 10) return 'P';
    if(t == 11) return 'N';
    if(t == 12) return 'B';
    if(t == 13) return 'R';
    if(t == 14) return 'Q';
  }

  if(t >= 17){
    if(t == 17) return 'k';
    if(t == 18) return 'p';
    if(t == 19) return 'n';
    if(t == 20) return 'b';
    if(t == 21) return 'r';
    if(t == 22) return 'q';
  }

  return ' ';
}

// ----------------------------------------------------
// movePiece : move piece to new location on board ----
// ----------------------------------------------------
void ChessBoard::movePiece(int s, int e){

  if(s < 0 || s > 63 || e < 0 || e > 63)
    cout << "Invalid start/end: Only enter values between 0-63!" << endl;

  bool valid = false;

  if(m[s] == 10 || m[s] == 18) valid = checkPawn(s, e);
  if(m[s] == 13 || m[s] == 21) valid = checkRook(s, e);

  if(valid){

    // Move piece to new location
    this->m[e] = m[s];

    // Remove letter from initial location
    this->m[s] = 0;
  }

  else {
    cout << "Invalid Move: Pawn" << endl;
  }
}

// ----------------------------------------------------
// checkPawn : Check to see if valid pawn move --------
// ----------------------------------------------------
bool ChessBoard::checkPawn(int s, int e){

  // Valid Pawn Move
  if(m[s] == 10 && s < 56){
    if(e - s == 8 || (m[e] != 0 && (s + 7 == e || s + 9 == e)))
      return true;
    if(e - s == 16 && s <= 15 && s >= 8)
      return true;
  }

  if(m[s] == 18 && s > 7){
    if(s - e == 8 || (m[e] != 0 && (s - 7 == e || s - 9 == e)))
      return true;
    if(s - e == 16 && s <= 55 && s >= 48)
      return true;
  }

  return false;
}

// ----------------------------------------------------
// checkRook : Check to see if valid Rook move --------
// ----------------------------------------------------
bool ChessBoard::checkRook(int s, int e){

  int row = s / 8;
  int minH = row * 2;
  int maxH = minH + 7;

  if(minH <= e && maxH >= e){}

  
  return false;
}


// ----------------------------------------------------
// strip_FEN : Breakdown FEN into sections ------------
// ----------------------------------------------------
void ChessBoard::strip_FEN(std::string s){
  std::string str = ""; std::vector<std::string> v;
      
  for(int i = 0; i <= s.size(); i++){
    if(s[i] != ' ' && i != s.size() && s[i] != '"') str += s[i];
    else if(s[i] != '"') {v.push_back(str); str = "";}
  }

  setFEN(v[0]);
}

// ----------------------------------------------------
// setFEN : Initialize/Declare FEN String -------------
// ----------------------------------------------------
void ChessBoard::setFEN(std::string s){
  this->startFEN = s;
}

// ----------------------------------------------------
// getFEN : Retrieve FEN String -----------------------
// ----------------------------------------------------
std::string ChessBoard::getFEN(){
  return this->startFEN;
}

// ----------------------------------------------------
// clearBoard : Completely wipe board -----------------
// ----------------------------------------------------
void ChessBoard::clearBoard(){
    this->m.clear();
}

// ----------------------------------------------------
// display : Pretty prints the Chess Board ------------
// ----------------------------------------------------
void ChessBoard::display(){

  std::unordered_map<int, const char *> u;

  u.insert({0, " "});

  // Piece Color: White [8] | Piece Type: K P N B R Q 
  u.insert({9, "\u2654"});  // WHITE King
  u.insert({14, "\u2655"}); // WHITE Queen
  u.insert({13, "\u2656"}); // WHITE Rook
  u.insert({12, "\u2657"}); // WHITE Bishop
  u.insert({11, "\u2658"}); // WHITE Knight
  u.insert({10, "\u2659"}); // WHITE Pawn

  // Piece Color: Black [16] | Piece Type: k p n b r q
  u.insert({17, "\u265A"}); // BLACK King 
  u.insert({22, "\u265B"}); // BLACK Queen
  u.insert({21, "\u265C"}); // BLACK Rook
  u.insert({20, "\u265D"}); // BLACK Bishop
  u.insert({19, "\u265E"}); // BLACK Knight
  u.insert({18, "\u265F"}); // BLACK Pawn

  int j = 8;
  std::string aa = "\t+---+---+---+---+---+---+---+---+\n\t| ";

  for(int i = 56; i >= 0; i -= 8){
    cout << aa << u[this->m[i]] << " | " << u[this->m[i+1]] << " | " << u[this->m[i+2]] << " | " << u[this->m[i+3]] << " | "
    << u[this->m[i+4]] << " | " << u[this->m[i+5]] << " | " << u[this->m[i+6]] << " | " << u[this->m[i+7]] << " | " << j-- << endl;
  }

  cout << "\t+---+---+---+---+---+---+---+---+" << endl;
  cout <<   "\t  a   b   c   d   e   f   g   h\n" << endl;
}

// ----------------------------------------------------
// Default Deconstructor : Deallocate dynamic memory --
// ----------------------------------------------------
ChessBoard::~ChessBoard(){
  if(DEBUGS) cout << "~~> Deallocating ChessBoard from Memory" << endl;
  if(DEBUGS) cout << "~~> Done :)" << endl;
}

