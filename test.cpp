#include "catch.hpp"
#include "ChessBoard.h"

TEST_CASE("ChessBoard class", "[ChessBoard]"){

    /* Each section has *minimum* 4-5 cases
     
       Examples:
        String s[2];
        s[0] = String("test");

        SECTION("Example Function"){
            String str = "test";
            REQUIRE(str == s[0]);       //  = Operator
            REQUIRE(s[0] < s[1]);       //  < Operator
            REQUIRE(s[0][1] == ' ');    // [] Operator
            REQUIRE(!(s[0] == s[1]));   // == Operator
            REQUIRE(s[0].size() == 4);  // string size
            REQUIRE(String("str") == s[0]+s[1]);            // + Operator
            REQUIRE(s[0].substr(0, 5) == String("testS"));  // Substring
    }*/

    ChessBoard * board = new ChessBoard();
    board->loadFEN("rnbq1k1r/pp1Pbppp/2p5/8/2B5/8/PPP1NnPP/RNBQK2R w KQ - 1 8");

    SECTION("Piece-at Function"){
        REQUIRE(board->pieceAt(0) == 'R');
        REQUIRE(board->pieceAt(10) == 'P');
        REQUIRE(board->pieceAt(5) == ' ');
        REQUIRE(board->pieceAt(13) == 'n');
        REQUIRE(board->pieceAt(42) == 'p');
    }

    SECTION("Change turn Function"){
        REQUIRE(board->curTurn == 'w');
        board->changeTurn();
        REQUIRE(board->curTurn == 'b');
        board->changeTurn();
        board->changeTurn();
        board->changeTurn();
        REQUIRE(board->curTurn == 'w');
    }

    delete board;

}
