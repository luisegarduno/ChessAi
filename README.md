<p align="center">
  <img src="https://user-images.githubusercontent.com/30121656/195773070-262469d6-dc1d-425a-bf6b-726606e19ee5.png" width="500" />
</p>

------------------------------------

# _Enigma Chess_

EnigmaChess is a chess engine with clean & efficient code. 

## Prerequisites:
- Recommended - __Shell__: Bash, __OS__: Ubuntu v20.04
- Have the following packages installed: C++
  - `$ sudo apt install build-essential`


## Instructions:

__Option 1 (fastest)__     
  1. Run the included build (`$ ./EnigmaEngine`)     

<br>

__Option 2 (fresh build)__     
  1. In line 14 of `main.cpp`, replace _true_ with _false_     
  2. Compile the program (`$ g++ *.cpp *.h -std=c++17 -o EnigmaEngine`)     
  3. Run the generated file (`$ ./EnigmaEngine`)


<br>

----------------

(_at the moment_): Program creates a board using a FEN string that is defined in `main.cpp`.

Each square is assigned a number between 0-63. Once the initial board is created, it prompts the user to enter _S_, and _E_ afterwards.
- S = Starting index location for the piece you would like to move.
- E = End index location for where you would like to move the piece.

Example: if you would like to move the white pawn from c2 to c3, then S=10, E=18.

** Making a user input moves in this type of notation is very confusing. I also believe that the only s & e values that work are s=10 & e=18. Please note that both of these issues are something that i'm working on fixing. Once fixed, the program will be using the current standard for chess notation: algebraic notation. 
