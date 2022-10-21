cmake_minimum_required(VERSION 3.16)
project(EnigmaChess)
set (EXE_NAME EnigmaEngine)

link_libraries(-lstdc++fs)

#####################################
# Enter name of input files in quotes
set (input01 "")
set (input02 "")
#####################################

# Copy data files to build directory
foreach(file IN LISTS input01 input02)
  configure_file(${file} ${file} COPYONLY)
endforeach()

set(CMAKE_CXX_STANDARD 17)
add_executable(${EXE_NAME} main.cpp ChessBoard.h ChessBoard.cpp Piece.h test.cpp catch.hpp)
