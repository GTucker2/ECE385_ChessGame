/************************************************************************************/
/*Remember... if something is stupid and it works... it's not stupid                */
/*Code Written by Lance Pan & Griffin Tucker Fall 2017                              */
/*For use in ECE385 Final Project                                                   */
/*The objective is simple: chess.                                                   */
/*The two travelers could not fathom the difficulty of the task laid ahead...       */
/************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "chess.h"

// Pointer to base address of chess module, make sure it matches Qsys
//volatile unsigned int * CHESS_PTR = (unsigned int *) 0x00000040;

// A board which contains all of the present locations of the board pieces
uchar locboard[BOARD_WIDTH][BOARD_WIDTH];

void chess_init()
{
	// Declare local variables
	alt_u8 cur_row;												// Iterator for board squares
	alt_u8 cur_col;
	alt_u8 cur_square;

	// Initialize the pieces on the board squares
	for(cur_col = 0, cur_square = 0; cur_col < BOARD_WIDTH; cur_col++)
		for(cur_row = 0; cur_row < BOARD_WIDTH; cur_row++, cur_square++)
		{
			if(cur_row == 1) locboard[cur_col][cur_row] = W_PAWN;
			else if(cur_row == 6) locboard[cur_col][cur_row] = B_PAWN;
			else if(cur_square == 0  || cur_square == 56) locboard[cur_col][cur_row] = W_ROOK;
			else if(cur_square == 7  || cur_square == 63) locboard[cur_col][cur_row] = B_ROOK;
			else if(cur_square == 8  || cur_square == 48) locboard[cur_col][cur_row] = W_KNIGHT;
			else if(cur_square == 15 || cur_square == 55) locboard[cur_col][cur_row] = B_KNIGHT;
			else if(cur_square == 16 || cur_square == 54) locboard[cur_col][cur_row] = W_BISHOP;
			else if(cur_square == 23 || cur_square == 47) locboard[cur_col][cur_row] = B_BISHOP;
			else if(cur_square == 46) locboard[cur_col][cur_row] = W_KING;
			else if(cur_square == 53) locboard[cur_col][cur_row] = B_KING;
			else if(cur_square == 24) locboard[cur_col][cur_row] = W_QUEEN;
			else if(cur_square == 31) locboard[cur_col][cur_row] = B_QUEEN;
			else locboard[cur_col][cur_row] = EMPTY;
			CHESS_PTR[cur_square] = locboard[cur_col][cur_row];
		}
}

/*
void checkboard_gen_rook(unsigned long* locboard, unsigned long * checkboard_rook, unsigned long rook_pos_x, unsigned long rook_pos_y, unsigned long what_rook)
{
	// Declare local variables
	int rook_track_x;									//local position tracker
	int rook_track_y;
	int rook_type;										//need to keep track of which rook so we know which bit to hotencode

	if (what_rook = 0)rook_type = 0;					//case for white QK (figure out value needed for hot encoding)
	else if (what_rook = 1)rook_type = 1;				//case for white KK
	else if (what_rook = 2)rook_type = 2;				//case for black QK
	else if (what_rook = 3)rook_type = 3;				//case for black KK
	rook_track_y = rook_pos_y - 2;						//first L
	rook_track_x = rook_pos_x - 1;
	if (locboard[rook_pos_x][rook_pos_y] <= 16)			//case for white piece
	{
		if (rook_track_y >= 0) && (rook_track_y < 9) && (rook_track_x >= 0) && (rook_track_x < 9) && ((locboard[rook_track_x][rook_track_y] > 16) || (locboard[rook_track_x][rook_track_y] == 0)) 					//checks whether position is on board
			checkboard_rook[rook_track_x][rook_track_y] = checkboard_rook[rook_track_x][rook_track_y] + rook_type;
		rook_track_x = rook_pos_x + 1;
		if (rook_track_y >= 0) && (rook_track_y < 9) && (rook_track_x >= 0) && (rook_track_x < 9) && ((locboard[rook_track_x][rook_track_y] > 16) || (locboard[rook_track_x][rook_track_y] == 0))
			checkboard_rook[rook_track_x][rook_track_y] = checkboard_rook[rook_track_x][rook_track_y] + rook_type;
		rook_track_y = rook_pos_y + 2;
		if (rook_track_y >= 0) && (rook_track_y < 9) && (rook_track_x >= 0) && (rook_track_x < 9) && ((locboard[rook_track_x][rook_track_y] > 16) || (locboard[rook_track_x][rook_track_y] == 0))
			checkboard_rook[rook_track_x][rook_track_y] = checkboard_rook[rook_track_x][rook_track_y] + rook_type;
		rook_track_x = rook_pos_x - 1;
		if (rook_track_y >= 0) && (rook_track_y < 9) && (rook_track_x >= 0) && (rook_track_x < 9) && ((locboard[rook_track_x][rook_track_y] > 16) || (locboard[rook_track_x][rook_track_y] == 0))
			checkboard_rook[rook_track_x][rook_track_y] = checkboard_rook[rook_track_x][rook_track_y] + rook_type;
		rook_track_x = rook_pos_x - 2;
		rook_track_y = rook_pos_y + 1;
		if (rook_track_y >= 0) && (rook_track_y < 9) && (rook_track_x >= 0) && (rook_track_x < 9) && ((locboard[rook_track_x][rook_track_y] > 16) || (locboard[rook_track_x][rook_track_y] == 0))
			checkboard_rook[rook_track_x][rook_track_y] = checkboard_rook[rook_track_x][rook_track_y] + rook_type;
		rook_track_y = rook_pos_y - 1;
		if (rook_track_y >= 0) && (rook_track_y < 9) && (rook_track_x >= 0) && (rook_track_x < 9) && ((locboard[rook_track_x][rook_track_y] > 16) || (locboard[rook_track_x][rook_track_y] == 0))
			checkboard_rook[rook_track_x][rook_track_y] = checkboard_rook[rook_track_x][rook_track_y] + rook_type;
		rook_track_x = rook_pos_x + 2;
		if (rook_track_y >= 0) && (rook_track_y < 9) && (rook_track_x >= 0) && (rook_track_x < 9) && ((locboard[rook_track_x][rook_track_y] > 16) || (locboard[rook_track_x][rook_track_y] == 0))
			checkboard_rook[rook_track_x][rook_track_y] = checkboard_rook[rook_track_x][rook_track_y] + rook_type;
		rook_track_y = rook_pos_y + 1;
		if (rook_track_y >= 0) && (rook_track_y < 9) && (rook_track_x >= 0) && (rook_track_x < 9) && ((locboard[rook_track_x][rook_track_y] > 16) || (locboard[rook_track_x][rook_track_y] == 0))
			checkboard_rook[rook_track_x][rook_track_y] = checkboard_rook[rook_track_x][rook_track_y] + rook_type;
	}
	else if (locboard[rook_pos_x][rook_pos_y] > 16)								//case for black piece
	{
		if (rook_track_y >= 0) && (rook_track_y < 9) && (rook_track_x >= 0) && (rook_track_x < 9) && ((locboard[rook_track_x][rook_track_y] <= 16) || (locboard[rook_track_x][rook_track_y] == 0)) 					//checks whether position is on board
			checkboard_rook[rook_track_x][rook_track_y] = checkboard_rook[rook_track_x][rook_track_y] + rook_type;
		rook_track_x = rook_pos_x + 1;
		if (rook_track_y >= 0) && (rook_track_y < 9) && (rook_track_x >= 0) && (rook_track_x < 9) && ((locboard[rook_track_x][rook_track_y] <= 16) || (locboard[rook_track_x][rook_track_y] == 0))
			checkboard_rook[rook_track_x][rook_track_y] = checkboard_rook[rook_track_x][rook_track_y] + rook_type;
		rook_track_y = rook_pos_y + 2;
		if (rook_track_y >= 0) && (rook_track_y < 9) && (rook_track_x >= 0) && (rook_track_x < 9) && ((locboard[rook_track_x][rook_track_y] <= 16) || (locboard[rook_track_x][rook_track_y] == 0))
			checkboard_rook[rook_track_x][rook_track_y] = checkboard_rook[rook_track_x][rook_track_y] + rook_type;
		rook_track_x = rook_pos_x - 1;
		if (rook_track_y >= 0) && (rook_track_y < 9) && (rook_track_x >= 0) && (rook_track_x < 9) && ((locboard[rook_track_x][rook_track_y] <= 16) || (locboard[rook_track_x][rook_track_y] == 0))
			checkboard_rook[rook_track_x][rook_track_y] = checkboard_rook[rook_track_x][rook_track_y] + rook_type;
		rook_track_x = rook_pos_x - 2;
		rook_track_y = rook_pos_y + 1;
		if (rook_track_y >= 0) && (rook_track_y < 9) && (rook_track_x >= 0) && (rook_track_x < 9) && ((locboard[rook_track_x][rook_track_y] <= 16) || (locboard[rook_track_x][rook_track_y] == 0))
			checkboard_rook[rook_track_x][rook_track_y] = checkboard_rook[rook_track_x][rook_track_y] + rook_type;
		rook_track_y = rook_pos_y - 1;
		if (rook_track_y >= 0) && (rook_track_y < 9) && (rook_track_x >= 0) && (rook_track_x < 9) && ((locboard[rook_track_x][rook_track_y] <= 16) || (locboard[rook_track_x][rook_track_y] == 0))
			checkboard_rook[rook_track_x][rook_track_y] = checkboard_rook[rook_track_x][rook_track_y] + rook_type;
		rook_track_x = rook_pos_x + 2;
		if (rook_track_y >= 0) && (rook_track_y < 9) && (rook_track_x >= 0) && (rook_track_x < 9) && ((locboard[rook_track_x][rook_track_y] <= 16) || (locboard[rook_track_x][rook_track_y] == 0))
			checkboard_rook[rook_track_x][rook_track_y] = checkboard_rook[rook_track_x][rook_track_y] + rook_type;
		rook_track_y = rook_pos_y + 1;
		if (rook_track_y >= 0) && (rook_track_y < 9) && (rook_track_x >= 0) && (rook_track_x < 9) && ((locboard[rook_track_x][rook_track_y] <= 16) || (locboard[rook_track_x][rook_track_y] == 0))
			checkboard_rook[rook_track_x][rook_track_y] = checkboard_rook[rook_track_x][rook_track_y] + rook_type;
	}
}

void checkboard_gen_pawn(unsigned long * locboard, unsigned long * checkboard_pawn, unsigned long pawn_pos_x, unsigned long pawn_pos_y, unsigned long what_pawn, int jumptracker)
{
	int pawn_track_x;
	int pawn_track_y;
	int pawn_type;
	if (locboard[pawn_pos_x][pawn_pos_y] <= 16)					//case for white piece
	{
		if (jumptracker = 0)		//initial jump has not occured yet
		{
			pawn_track_y = pawn_pos_y + 1;
			if (pawn_track_y >= 0) && (pawn_track_y < 9) && (locboard[pawn_track_y][pawn_pos_x] == 0)													//includes check for empty space
				checkboard_pawn[pawn_track_x][pawn_track_y] = checkboard_pawn[pawn_track_x][pawn_track_y] + pawn_type;
			pawn_track_x = pawn_pos_x + 1;
			if (pawn_track_y >= 0) && (pawn_track_y < 9) && (pawn_track_x >= 0) && (pawn_track_x < 9) && (locboard[pawn_track_x][pawn_track_y] > 16)	//includes check for on board and whether space is occupied by an enemy piece (double check value)
				checkboard_pawn[pawn_track_x][pawn_track_y] = checkboard_pawn[pawn_track_x][pawn_track_y] + pawn_type;
			pawn_track_x = pawn_pos_x - 1;
			if (pawn_track_y >= 0) && (pawn_track_y < 9) && (pawn_track_x >= 0) && (pawn_track_x < 9) && (locboard[pawn_track_x][pawn_track_y] > 16)
				checkboard_pawn[pawn_track_x][pawn_track_y] = checkboard_pawn[pawn_track_x][pawn_track_y] + pawn_type;
			pawn_track_y = pawn_pos_y + 2;
			if (pawn_track_y >= 0) && (pawn_track_y < 9) && (locboard[pawn_track_y][pawn_pos_x] == 0)
				checkboard_pawn[pawn_pos_x][pawn_track_y] = checkboard_pawn[pawn_pos_x][pawn_track_y] + pawn_type;

		}
		else if (jumptracker = 1)
		{
			pawn_track_y = pawn_pos_y + 1;
			if (pawn_track_y >= 0) && (pawn_track_y < 9) && (locboard[pawn_track_y][pawn_pos_x] == 0)													//includes check for empty space
				checkboard_pawn[pawn_track_x][pawn_track_y] = checkboard_pawn[pawn_track_x][pawn_track_y] + pawn_type;
			pawn_track_x = pawn_pos_x + 1;
			if (pawn_track_y >= 0) && (pawn_track_y < 9) && (pawn_track_x >= 0) && (pawn_track_x < 9) && (locboard[pawn_track_x][pawn_track_y] > 16)	//includes check for on board and whether space is occupied by an enemy piece (double check value)
				checkboard_pawn[pawn_track_x][pawn_track_y] = checkboard_pawn[pawn_track_x][pawn_track_y] + pawn_type;
			pawn_track_x = pawn_pos_x - 1;
			if (pawn_track_y >= 0) && (pawn_track_y < 9) && (pawn_track_x >= 0) && (pawn_track_x < 9) && (locboard[pawn_track_x][pawn_track_y] > 16)
				checkboard_pawn[pawn_track_x][pawn_track_y] = checkboard_pawn[pawn_track_x][pawn_track_y] + pawn_type;
		}
	}
	if (locboard[pawn_pos_x][pawn_pos_y] > 16)				//case for black piece
	{
		if (jumptracker = 0)		//initial jump has not occured yet
		{
			pawn_track_y = pawn_pos_y + 1;
			if (pawn_track_y >= 0) && (pawn_track_y < 9) && (locboard[pawn_track_y][pawn_pos_x] == 0)													//includes check for empty space
				checkboard_pawn[pawn_track_x][pawn_track_y] = checkboard_pawn[pawn_track_x][pawn_track_y] + pawn_type;
			pawn_track_x = pawn_pos_x + 1;
			if (pawn_track_y >= 0) && (pawn_track_y < 9) && (pawn_track_x >= 0) && (pawn_track_x < 9) && (locboard[pawn_track_x][pawn_track_y] <= 16)	//includes check for on board and whether space is occupied by an enemy piece (double check value)
				checkboard_pawn[pawn_track_x][pawn_track_y] = checkboard_pawn[pawn_track_x][pawn_track_y] + pawn_type;
			pawn_track_x = pawn_pos_x - 1;
			if (pawn_track_y >= 0) && (pawn_track_y < 9) && (pawn_track_x >= 0) && (pawn_track_x < 9) && (locboard[pawn_track_x][pawn_track_y] <= 16)
				checkboard_pawn[pawn_track_x][pawn_track_y] = checkboard_pawn[pawn_track_x][pawn_track_y] + pawn_type;
			pawn_track_y = pawn_pos_y + 2;
			if (pawn_track_y >= 0) && (pawn_track_y < 9) && (locboard[pawn_track_y][pawn_pos_x] == 0)
				checkboard_pawn[pawn_pos_x][pawn_track_y] = checkboard_pawn[pawn_pos_x][pawn_track_y] + pawn_type;

		}
		else if (jumptracker = 1)
		{
			pawn_track_y = pawn_pos_y + 1;
			if (pawn_track_y >= 0) && (pawn_track_y < 9) && (locboard[pawn_track_y][pawn_pos_x] == 0)													//includes check for empty space
				checkboard_pawn[pawn_track_x][pawn_track_y] = checkboard_pawn[pawn_track_x][pawn_track_y] + pawn_type;
			pawn_track_x = pawn_pos_x + 1;
			if (pawn_track_y >= 0) && (pawn_track_y < 9) && (pawn_track_x >= 0) && (pawn_track_x < 9) && (locboard[pawn_track_x][pawn_track_y] <= 16)	//includes check for on board and whether space is occupied by an enemy piece (double check value)
				checkboard_pawn[pawn_track_x][pawn_track_y] = checkboard_pawn[pawn_track_x][pawn_track_y] + pawn_type;
			pawn_track_x = pawn_pos_x - 1;
			if (pawn_track_y >= 0) && (pawn_track_y < 9) && (pawn_track_x >= 0) && (pawn_track_x < 9) && (locboard[pawn_track_x][pawn_track_y] <= 16)
				checkboard_pawn[pawn_track_x][pawn_track_y] = checkboard_pawn[pawn_track_x][pawn_track_y] + pawn_type;
		}
	}

}

void checkboard_gen_rook(unsigned long * locboard, unsigned long * checkboard_rook, int rook_pos_x, int rook_pos_y, int what_rook)
int fill_track_x, fill_track_y, i, rook_type;
	if (locboard[rook_pos_x][rook_pos_y] <= 16)			//white case
	{
		for (i = rook_pos_x + 1; i < 9; i++)
		{
			if (locboard[rook_pos_x][i] <= 16)			//if encountering a friendly piece exit loop
				break;
			else if (locboard[rook_pos_x][i] > 16)												//if encountering an enemy piece, write to space and exit loop
				checkboard_rook[rook_pos_x][i] = checkboard_rook[rook_pos_x][i] + rook_type;
			break;
				else if (locboard[rook_pos_y][i] == 0)											//if encountering empty space, write to space and continue with loop
				checkboard_rook[rook_pos_x][i] = checkboard_rook[rook_pos_x][i] + rook_type;
		}
		for (i = rook_pos_y + 1; i < 9; i++)
		{
			if (locboard[rook_pos_x][i] <= 16)			//if encountering a friendly piece exit loop
				break;
			else if (locboard[rook_pos_x][i] > 16)
				checkboard_rook[rook_pos_x][i] = checkboard_rook[rook_pos_x][i] + rook_type;
				break;
			else if (locboard[rook_pos_x][i] == 0)
				checkboard_rook[rook_pos_x][i] = checkboard_rook[rook_pos_x][i] + rook_type;
		}
	}
	else if (locboard[rook_pos_x][rook_pos_y] > 16)		//black case
	{
		for (i = rook_pos_x + 1; i < 9; i++)
		{
			if (locboard[rook_pos_x][i] > 16)			//if encountering a friendly piece exit loop
				break;
			else if (locboard[rook_pos_x][i] <= 16)
				checkboard_rook[rook_pos_x][i] = checkboard_rook[rook_pos_x][i] + rook_type;
				break;
			else if (locboard[rook_pos_y][i] == 0)
				checkboard_rook[rook_pos_x][i] = checkboard_rook[rook_pos_x][i] + rook_type;
		}
		for (i = rook_pos_y + 1; i < 9; i++)
		{
			if (locboard[rook_pos_x][i] > 16)			//if encountering a friendly piece exit loop
				break;
			else if (locboard[rook_pos_x][i] <= 16)
				checkboard_rook[rook_pos_x][i] = checkboard_rook[rook_pos_x][i] + rook_type;
				break;
			else if (locboard[rook_pos_x][i] == 0)
				checkboard_rook[rook_pos_x][i] = checkboard_rook[rook_pos_x][i] + rook_type;
		}
	}

void board(unsigned char * cmd_ascii, unsigned long * gameboard)
{
	unsigned long locboard[8][8];		//actual game board
	unsigned long checkboard[8][8];		//parallel generated board with hot encoded valid moves
	unsigned long piece_tracker[32];	//tracks positions of each individual piece

}
*/
