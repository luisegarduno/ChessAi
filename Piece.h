/*
 * EnigmaChess
 * ------------------
 * Created by Luis G.
 */

#ifndef PIECE_H
#define PIECE_H

class Piece {
  public:
    // Piece Type
    const int None   = 0; // 000
    const int King   = 1; // 001
    const int Pawn   = 2; // 010
    const int Knight = 3; // 011
    const int Bishop = 4; // 100
    const int Rook   = 5; // 101
    const int Queen  = 6; // 110

    // Piece Color
    const int White  = 8;  // 8  : 01 000
    const int Black  = 16; // 10 : 10 000
};

#endif // PIECE_H
