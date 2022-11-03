/*
 * EnigmaChess
 * ------------------
 * Created by Luis G.
 */

#include <iostream>
#include <vector>

// For every index location: store number of squares to edge
static std::vector<std::vector<int>> nSquaresToEdge(64);

static void PrecomputedMoveData(){

   /* Compass Rose
   *
   *         NW         N          NE
   *             +7    +8     +9
   *                 \  |  /
   *         W   -1 <-  0  -> +1   E
   *                 /  |  \
   *             -9    -8     -7
   *         SW         S          SE
   *
   * For index location, determine numbre of squares from edge,
   * for all directions shown in compass rose, which includes:
   * N,S,W,E, as well as, NW,SE,NE,SW
   */

  for(int file = 0; file < 8; file++){
    for(int rank = 0; rank < 8; rank++){

      int nNorth = 7 - rank;
      int nEast  = 7 - file;
      int nSouth = rank;
      int nWest  = file;

      // Calculate square index (0-63) using file & rank
      int sIdx = rank * 8 + file;

      // nSquaresToEdge[sIdx] = N,S,W,E,NW,SE,NE,SW
      nSquaresToEdge[sIdx] = {
        nNorth, nSouth, nWest, nEast,
        std::min(nNorth, nWest),
        std::min(nSouth, nEast),
        std::min(nNorth, nEast),
        std::min(nSouth, nWest)
      };
    }
  }
}

static void printAllSquaresToEdge(){
  for(int x = 0; x < 64; x++){
    int n = nSquaresToEdge[x][0], s = nSquaresToEdge[x][1], w = nSquaresToEdge[x][2], e = nSquaresToEdge[x][3];
    int nw = nSquaresToEdge[x][4], se = nSquaresToEdge[x][5], ne = nSquaresToEdge[x][6], sw = nSquaresToEdge[x][7];

    std::cout << "\t +" << nw << "   +" << n <<  "   +" << ne << std::endl;
    std::cout << "\t    \u2196  \u2191  \u2197" << std::endl;
    std::cout << "\t-" << w << " \u2190  " << x << "  \u2192 +"  << e << std::endl;
    std::cout << "\t    \u2199  \u2193  \u2198" << std::endl;
    std::cout << "\t -" << sw << "   -" << s << "   -" << se << std::endl;
    std::cout << "\t<============>" << std::endl;
  }
}
