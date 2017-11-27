#ifndef CHESS_H_
#define CHESS_H_

typedef unsigned char uchar;                                // 8-bit byte
//typedef unsigned long uint;                                 // 32-bit word

// Define general constants
const uchar TOTAL_SQUARES = 64;		                        // Total squares in 8x8 board
const uchar BOARD_WIDTH = 8;                                // The width of the chessboard

// Define constants for checkboard
// TODO: CHANGE ALL OF THESE TO UINTS
/*const uchar W_PAWN_A   = 0b00000000000000000000000000000001;// Code for white pawn A2
const uchar W_PAWN_B   = 0b00000000000000000000000000000010;// Code for white pawn
const uchar W_PAWN_C   = 0b00000000000000000000000000000100;// Code for white pawn
const uchar W_PAWN_D   = 0b00000000000000000000000000001000;// Code for white pawn
const uchar W_PAWN_E   = 0b00000000000000000000000000010000;// Code for white pawn
const uchar W_PAWN_F   = 0b00000000000000000000000000100000;// Code for white pawn
const uchar W_PAWN_G   = 0b00000000000000000000000001000000;// Code for white pawn
const uchar W_PAWN_H   = 0b00000000000000000000000010000000;// Code for white pawn
const uchar W_ROOK_K   = 0b00000000000000000000000100000000;// Code for white rook
const uchar W_ROOK_Q   = 0b00000000000000000000001000000000;// Code for white rook
const uchar W_KNIGHT_K = 0b00000000000000000000010000000000;// Code for white knight
const uchar W_KNIGHT_Q = 0b00000000000000000000100000000000;// Code for white knight
const uchar W_BISHOP_K = 0b00000000000000000001000000000000;// Code for white bishop
const uchar W_BISHOP_Q = 0b00000000000000000010000000000000;// Code for white bishop
const uchar W_KING     = 0b00000000000000000100000000000000;// Code for white king
const uchar W_QUEEN    = 0b00000000000000001000000000000000;// Code for white queen
const uchar W_PAWN_A   = 0b00000000000000010000000000000000;// Code for white pawn A2
const uchar W_PAWN_B   = 0b00000000000000100000000000000000;// Code for white pawn
const uchar W_PAWN_C   = 0b00000000000001000000000000000000;// Code for white pawn
const uchar W_PAWN_D   = 0b00000000000010000000000000000000;// Code for white pawn
const uchar W_PAWN_E   = 0b00000000000100000000000000000000;// Code for white pawn
const uchar W_PAWN_F   = 0b00000000001000000000000000000000;// Code for white pawn
const uchar W_PAWN_G   = 0b00000000010000000000000000000000;// Code for white pawn
const uchar W_PAWN_H   = 0b00000000100000000000000000000000;// Code for white pawn
const uchar W_ROOK_K   = 0b00000001000000000000000000000000;// Code for white rook
const uchar W_ROOK_Q   = 0b00000010000000000000000000000000;// Code for white rook
const uchar W_KNIGHT_K = 0b00000100000000000000000000000000;// Code for white knight
const uchar W_KNIGHT_Q = 0b00001000000000000000000000000000;// Code for white knight
const uchar W_BISHOP_K = 0b00010000000000000000000000000000;// Code for white bishop
const uchar W_BISHOP_Q = 0b00100000000000000000000000000000;// Code for white bishop
const uchar W_KING     = 0b01000000000000000000000000000000;// Code for white king
const uchar W_QUEEN    = 0b10000000000000000000000000000000;// Code for white queen
const uchar NONE       = 0b00000000000000000000000000000000;// Code for empty square*/

// Define constants for locboard
const uchar W_PAWN   = 0x01;
const uchar B_PAWN   = 0x11;
const uchar W_ROOK   = 0x02;
const uchar B_ROOK   = 0x12;
const uchar W_KNIGHT = 0x03;
const uchar B_KNIGHT = 0x13;
const uchar W_BISHOP = 0x04;
const uchar B_BISHOP = 0x14;
const uchar W_KING   = 0x05;
const uchar B_KING   = 0x15;
const uchar W_QUEEN  = 0x06;
const uchar B_QUEEN  = 0x16;
const uchar EMPTY    = 0x00;

void chess_init();

#endif
