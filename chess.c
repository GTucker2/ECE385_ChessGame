/************************************************************************************/
/*Remember... if something is stupid and it works... it's not stupid.               */
/*Code Written by Lance Pan & Griffin Tucker Fall 2017                              */
/*For use in ECE385 Final Project                                                   */
/*The objective is simple... chess.                                                 */
/*The two travelers could not fathom the difficulty of the task laid ahead...       */
/************************************************************************************/


#include <stdlib.h>		//TO DO: check what other libraries we need/can use
#include <stdio.h>


void checkboard_gen_knight(unsigned int locboard[8][8], unsigned int checkboard_knight[8][8], unsigned int knight_pos_x, unsigned int knight_pos_y, int what_knight)
{
	int knight_track_x;															//local position tracker
	int knight_track_y;
	int knight_type;
	int i, j;
	if (what_knight == 1)					//White Queen Knight
		knight_type = 0x00000002;
	if (what_knight == 2)					//White King Knight
		knight_type = 0x00000040;
	if (what_knight == 3)					//Black Queen Knight
		knight_type = 0x00020000;
	if (what_knight == 4)					//Black King Knight
		knight_type = 0x00400000;
	//	locboard[3][2] = 5;
	if (locboard[knight_pos_x][knight_pos_y] <= 0x06)									//case for white piece
	{
		knight_track_y = knight_pos_y - 2;												//first L 
		knight_track_x = knight_pos_x - 1;
		if ((knight_track_y >= 0) && (knight_track_y < 8) && (knight_track_x >= 0) && (knight_track_x < 8) && ((locboard[knight_track_x][knight_track_y] > 0x06) || (locboard[knight_track_x][knight_track_y] == 0))) 					//checks whether position is on board
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] | knight_type;
		knight_track_x = knight_pos_x + 1;
		if ((knight_track_y >= 0) && (knight_track_y < 8) && (knight_track_x >= 0) && (knight_track_x < 8) && ((locboard[knight_track_x][knight_track_y] > 0x06) || (locboard[knight_track_x][knight_track_y] == 0)))
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] | knight_type;
		knight_track_y = knight_pos_y + 2;
		if ((knight_track_y >= 0) && (knight_track_y < 8) && (knight_track_x >= 0) && (knight_track_x < 8) && ((locboard[knight_track_x][knight_track_y] > 0x06) || (locboard[knight_track_x][knight_track_y] == 0)))
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] | knight_type;
		knight_track_x = knight_pos_x - 1;
		if ((knight_track_y >= 0) && (knight_track_y < 8) && (knight_track_x >= 0) && (knight_track_x < 8) && ((locboard[knight_track_x][knight_track_y] > 0x06) || (locboard[knight_track_x][knight_track_y] == 0)))
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] | knight_type;
		knight_track_x = knight_pos_x - 2;
		knight_track_y = knight_pos_y + 1;
		if ((knight_track_y >= 0) && (knight_track_y < 8) && (knight_track_x >= 0) && (knight_track_x < 8) && ((locboard[knight_track_x][knight_track_y] > 0x06) || (locboard[knight_track_x][knight_track_y] == 0)))
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] | knight_type;
		knight_track_y = knight_pos_y - 1;
		if ((knight_track_y >= 0) && (knight_track_y < 8) && (knight_track_x >= 0) && (knight_track_x < 8) && ((locboard[knight_track_x][knight_track_y] > 0x06) || (locboard[knight_track_x][knight_track_y] == 0)))
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] | knight_type;
		knight_track_x = knight_pos_x + 2;
		if ((knight_track_y >= 0) && (knight_track_y < 8) && (knight_track_x >= 0) && (knight_track_x < 8) && ((locboard[knight_track_x][knight_track_y] > 0x06) || (locboard[knight_track_x][knight_track_y] == 0)))
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] | knight_type;
		knight_track_y = knight_pos_y + 1;
		if ((knight_track_y >= 0) && (knight_track_y < 8) && (knight_track_x >= 0) && (knight_track_x < 8) && ((locboard[knight_track_x][knight_track_y] > 0x06) || (locboard[knight_track_x][knight_track_y] == 0)))
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] | knight_type;
	}
	else if (locboard[knight_pos_x][knight_pos_y] > 0x06)								//case for black piece
	{
		if ((knight_track_y >= 0) && (knight_track_y < 8) && (knight_track_x >= 0) && (knight_track_x < 8) && ((locboard[knight_track_x][knight_track_y] <= 0x06) || (locboard[knight_track_x][knight_track_y] == 0))) 					//checks whether position is on board
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] | knight_type;
		knight_track_x = knight_pos_x + 1;
		if ((knight_track_y >= 0) && (knight_track_y < 8) && (knight_track_x >= 0) && (knight_track_x < 8) && ((locboard[knight_track_x][knight_track_y] <= 0x06) || (locboard[knight_track_x][knight_track_y] == 0)))
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] | knight_type;
		knight_track_y = knight_pos_y + 2;
		if ((knight_track_y >= 0) && (knight_track_y < 8) && (knight_track_x >= 0) && (knight_track_x < 8) && ((locboard[knight_track_x][knight_track_y] <= 0x06) || (locboard[knight_track_x][knight_track_y] == 0)))
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] | knight_type;
		knight_track_x = knight_pos_x - 1;
		if ((knight_track_y >= 0) && (knight_track_y < 8) && (knight_track_x >= 0) && (knight_track_x < 8) && ((locboard[knight_track_x][knight_track_y] <= 0x06) || (locboard[knight_track_x][knight_track_y] == 0)))
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] | knight_type;
		knight_track_x = knight_pos_x - 2;
		knight_track_y = knight_pos_y + 1;
		if ((knight_track_y >= 0) && (knight_track_y < 8) && (knight_track_x >= 0) && (knight_track_x < 8) && ((locboard[knight_track_x][knight_track_y] <= 0x06) || (locboard[knight_track_x][knight_track_y] == 0)))
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] | knight_type;
		knight_track_y = knight_pos_y - 1;
		if ((knight_track_y >= 0) && (knight_track_y < 8) && (knight_track_x >= 0) && (knight_track_x < 8) && ((locboard[knight_track_x][knight_track_y] <= 0x06) || (locboard[knight_track_x][knight_track_y] == 0)))
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] | knight_type;
		knight_track_x = knight_pos_x + 2;
		if ((knight_track_y >= 0) && (knight_track_y < 8) && (knight_track_x >= 0) && (knight_track_x < 8) && ((locboard[knight_track_x][knight_track_y] <= 0x06) || (locboard[knight_track_x][knight_track_y] == 0)))
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] | knight_type;
		knight_track_y = knight_pos_y + 1;
		if ((knight_track_y >= 0) && (knight_track_y < 8) && (knight_track_x >= 0) && (knight_track_x < 8) && ((locboard[knight_track_x][knight_track_y] <= 0x06) || (locboard[knight_track_x][knight_track_y] == 0)))
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] | knight_type;
	}
}

void checkboard_gen_pawn(unsigned int locboard[8][8], unsigned int checkboard_pawn[8][8], int pawn_pos_x, int pawn_pos_y, int what_pawn, int jumptracker)
{
	unsigned long pawn_track_x;
	unsigned long pawn_track_y;
	unsigned int pawn_type;
	int i, j;
	if (what_pawn == 1)				//White Pawn 1
		pawn_type = 0x100;
	if (what_pawn == 2)				//White Pawn 2
		pawn_type = 0x200;
	if (what_pawn == 3)				//White Pawn 3
		pawn_type = 0x400;
	if (what_pawn == 4)				//White Pawn 4
		pawn_type = 0x800;
	if (what_pawn == 5)				//White Pawn 5
		pawn_type = 0x1000;
	if (what_pawn == 6)				//White Pawn 6
		pawn_type = 0x2000;
	if (what_pawn == 7)				//White Pawn 7
		pawn_type = 0x4000;
	if (what_pawn == 8)				//White Pawn 8 
		pawn_type = 0x8000;
	if (what_pawn == 9)				//Black Pawn 1
		pawn_type = 0x1000000;
	if (what_pawn == 10)			//Black Pawn 2
		pawn_type = 0x2000000;
	if (what_pawn == 11)			//Black Pawn 3
		pawn_type = 0x4000000;
	if (what_pawn == 12)			//Black Pawn 4
		pawn_type = 0x8000000;
	if (what_pawn == 13)			//Black Pawn 5
		pawn_type = 0x10000000;
	if (what_pawn == 14)			//Black Pawn 6
		pawn_type = 0x20000000;
	if (what_pawn == 15)			//Black Pawn 7
		pawn_type = 0x40000000;
	if (what_pawn == 16)			//Black Pawn 8
		pawn_type = 0x80000000;
	if (locboard[pawn_pos_x][pawn_pos_y] <= 0x06)					//case for white piece
	{
		if (jumptracker == 0)		//initial jump has not occured yet
		{
			pawn_track_y = pawn_pos_y - 1;
			if ((pawn_track_y >= 0) && (pawn_track_y < 8) && (locboard[pawn_pos_x][pawn_track_y] == 0))													//includes check for empty space 
				checkboard_pawn[pawn_pos_x][pawn_track_y] = checkboard_pawn[pawn_pos_x][pawn_track_y] | pawn_type;
			pawn_track_x = pawn_pos_x + 1;
			if ((pawn_track_y >= 0) && (pawn_track_y < 8) && (pawn_track_x >= 0) && (pawn_track_x < 8) && (locboard[pawn_track_x][pawn_track_y] > 0x06))	//includes check for on board and whether space is occupied by an enemy piece (double check value)
				checkboard_pawn[pawn_track_x][pawn_track_y] = checkboard_pawn[pawn_track_x][pawn_track_y] | pawn_type;
			pawn_track_x = pawn_pos_x - 1;
			if ((pawn_track_y >= 0) && (pawn_track_y < 8) && (pawn_track_x >= 0) && (pawn_track_x < 8) && (locboard[pawn_track_x][pawn_track_y] > 0x06))
				checkboard_pawn[pawn_track_x][pawn_track_y] = checkboard_pawn[pawn_track_x][pawn_track_y] | pawn_type;
			pawn_track_y = pawn_pos_y - 2;
			if ((pawn_track_y >= 0) && (pawn_track_y < 8) && (locboard[pawn_pos_x][pawn_track_y] == 0))
				checkboard_pawn[pawn_pos_x][pawn_track_y] = checkboard_pawn[pawn_pos_x][pawn_track_y] | pawn_type;
		}
		else if (jumptracker == 1)
		{
			pawn_track_y = pawn_pos_y - 1;
			if ((pawn_track_y >= 0) && (pawn_track_y < 8) && (locboard[pawn_pos_x][pawn_track_y] == 0))													//includes check for empty space 
				checkboard_pawn[pawn_pos_x][pawn_track_y] = checkboard_pawn[pawn_pos_x][pawn_track_y] | pawn_type;
			pawn_track_x = pawn_pos_x + 1;
			if ((pawn_track_y >= 0) && (pawn_track_y < 8) && (pawn_track_x >= 0) && (pawn_track_x < 8) && (locboard[pawn_track_x][pawn_track_y] > 0x06))	//includes check for on board and whether space is occupied by an enemy piece (double check value)
				checkboard_pawn[pawn_track_x][pawn_track_y] = checkboard_pawn[pawn_track_x][pawn_track_y] | pawn_type;
			pawn_track_x = pawn_pos_x - 1;
			if ((pawn_track_y >= 0) && (pawn_track_y < 8) && (pawn_track_x >= 0) && (pawn_track_x < 8) && (locboard[pawn_track_x][pawn_track_y] > 0x06))
				checkboard_pawn[pawn_track_x][pawn_track_y] = checkboard_pawn[pawn_track_x][pawn_track_y] | pawn_type;
		}
	}
	if (locboard[pawn_pos_x][pawn_pos_y] > 0x06)				//case for black piece
	{
		if (jumptracker == 0)		//initial jump has not occured yet
		{
			pawn_track_y = pawn_pos_y + 1;
			if ((pawn_track_y >= 0) && (pawn_track_y < 8) && (locboard[pawn_pos_x][pawn_track_y] == 0))													//includes check for empty space 
				checkboard_pawn[pawn_pos_x][pawn_track_y] = checkboard_pawn[pawn_pos_x][pawn_track_y] | pawn_type;
			pawn_track_x = pawn_pos_x + 1;
			if ((pawn_track_y >= 0) && (pawn_track_y < 8) && (pawn_track_x >= 0) && (pawn_track_x < 8) && (locboard[pawn_track_x][pawn_track_y] <= 0x06) && (locboard[pawn_track_x][pawn_track_y] != 0))	//includes check for on board and whether space is occupied by an enemy piece (double check value)
				checkboard_pawn[pawn_track_x][pawn_track_y] = checkboard_pawn[pawn_track_x][pawn_track_y] | pawn_type;
			pawn_track_x = pawn_pos_x - 1;
			if ((pawn_track_y >= 0) && (pawn_track_y < 8) && (pawn_track_x >= 0) && (pawn_track_x < 8) && (locboard[pawn_track_x][pawn_track_y] <= 0x06) && (locboard[pawn_track_x][pawn_track_y] != 0))
				checkboard_pawn[pawn_track_x][pawn_track_y] = checkboard_pawn[pawn_track_x][pawn_track_y] | pawn_type;
			pawn_track_y = pawn_pos_y + 2;
			if ((pawn_track_y >= 0) && (pawn_track_y < 8) && (locboard[pawn_pos_x][pawn_track_y] == 0))
				checkboard_pawn[pawn_pos_x][pawn_track_y] = checkboard_pawn[pawn_pos_x][pawn_track_y] | pawn_type;
		}
		else if (jumptracker == 1)
		{
			pawn_track_y = pawn_pos_y + 1;
			if ((pawn_track_y >= 0) && (pawn_track_y < 8) && (locboard[pawn_pos_x][pawn_track_y] == 0))													//includes check for empty space 
				checkboard_pawn[pawn_pos_x][pawn_track_y] = checkboard_pawn[pawn_pos_x][pawn_track_y] | pawn_type;
			pawn_track_x = pawn_pos_x + 1;
			if ((pawn_track_y >= 0) && (pawn_track_y < 8) && (pawn_track_x >= 0) && (pawn_track_x < 8) && (locboard[pawn_track_x][pawn_track_y] <= 0x06) && (locboard[pawn_track_x][pawn_track_y] != 0))	//includes check for on board and whether space is occupied by an enemy piece (double check value)
				checkboard_pawn[pawn_track_x][pawn_track_y] = checkboard_pawn[pawn_track_x][pawn_track_y] | pawn_type;
			pawn_track_x = pawn_pos_x - 1;
			if ((pawn_track_y >= 0) && (pawn_track_y < 8) && (pawn_track_x >= 0) && (pawn_track_x < 8) && (locboard[pawn_track_x][pawn_track_y] <= 0x06) && (locboard[pawn_track_x][pawn_track_y] != 0))
				checkboard_pawn[pawn_track_x][pawn_track_y] = checkboard_pawn[pawn_track_x][pawn_track_y] | pawn_type;
		}
	}
}

void checkboard_gen_rook(unsigned int locboard[8][8], unsigned int checkboard_rook[8][8], unsigned int rook_pos_x, unsigned int rook_pos_y, int what_rook)
{
	int brk;
	unsigned int rook_type;
	int i, j;
	if (what_rook == 1)					//White Queen Rook
		rook_type = 0x00000001;
	if (what_rook == 2)					//White King Rook
		rook_type = 0x00000080;
	if (what_rook == 3)					//Black Queen Rook
		rook_type = 0x00010000;
	if (what_rook == 4)					//Black King Rook
		rook_type = 0x00800000;
	if (what_rook == 5)			//White Queen
		rook_type = 0x00000008;
	if (what_rook == 6)			//Black Queen
		rook_type = 0x00080000;
	brk = 0;
	if (locboard[rook_pos_x][rook_pos_y] <= 0x06)			//white case
	{
		for (i = rook_pos_x + 1; i < 8; i++)
		{
			if ((locboard[i][rook_pos_y] <= 0x06) && (locboard[i][rook_pos_y] != 0))			//if encountering a friendly piece exit loop
				brk = 1;
			if ((locboard[i][rook_pos_y] > 0x06) && (brk != 1))												//if encountering an enemy piece, write to space and exit loop
			{
				checkboard_rook[i][rook_pos_y] = checkboard_rook[i][rook_pos_y] | rook_type;
				brk = 1;
			}
			if ((locboard[i][rook_pos_y] == 0) && (brk != 1))										//if encountering empty space, write to space and continue with loop
				checkboard_rook[i][rook_pos_y] = checkboard_rook[i][rook_pos_y] | rook_type;
		}
		brk = 0;
		for (i = rook_pos_x - 1; i >= 0; i--)
		{
			if ((locboard[i][rook_pos_y] <= 0x06) && (locboard[i][rook_pos_y] != 0))			//if encountering a friendly piece exit loop
				brk = 1;
			if ((locboard[i][rook_pos_y] > 0x06) && (brk != 1))												//if encountering an enemy piece, write to space and exit loop
			{
				checkboard_rook[i][rook_pos_y] = checkboard_rook[i][rook_pos_y] | rook_type;
				brk = 1;
			}
			if ((locboard[i][rook_pos_y] == 0) && (brk != 1))										//if encountering empty space, write to space and continue with loop
				checkboard_rook[i][rook_pos_y] = checkboard_rook[i][rook_pos_y] | rook_type;
		}
		brk = 0;
		for (i = rook_pos_y + 1; i < 8; i++)
		{
			if ((locboard[rook_pos_x][i] <= 0x06) && (locboard[rook_pos_x][i] != 0))				//if encountering a friendly piece exit loop
				brk = 1;
			if ((locboard[rook_pos_x][i] > 0x06) && (brk != 1))
			{
				checkboard_rook[rook_pos_x][i] = checkboard_rook[rook_pos_x][i] | rook_type;
				brk = 1;
			}
			if ((locboard[rook_pos_x][i] == 0) && (brk != 1))
				checkboard_rook[rook_pos_x][i] = checkboard_rook[rook_pos_x][i] | rook_type;
		}
		brk = 0;
		for (i = rook_pos_y - 1; i >= 0; i--)
		{
			if ((locboard[rook_pos_x][i] <= 0x06) && (locboard[rook_pos_x][i] != 0))				//if encountering a friendly piece exit loop
				brk = 1;
			if ((locboard[rook_pos_x][i] > 0x06) && (brk != 1))
			{
				checkboard_rook[rook_pos_x][i] = checkboard_rook[rook_pos_x][i] | rook_type;
				brk = 1;
			}
			if ((locboard[rook_pos_x][i] == 0) && (brk != 1))
				checkboard_rook[rook_pos_x][i] = checkboard_rook[rook_pos_x][i] | rook_type;
		}
		brk = 0;
	}
	else if (locboard[rook_pos_x][rook_pos_y] > 0x06)		//black case
	{
		for (i = rook_pos_x + 1; i < 8; i++)
		{
			if ((locboard[i][rook_pos_y] > 0x06) && (locboard[i][rook_pos_y] != 0))			//if encountering a friendly piece exit loop
				brk = 1;
			if ((locboard[i][rook_pos_y] <= 0x06) && (brk != 1))												//if encountering an enemy piece, write to space and exit loop
			{
				checkboard_rook[i][rook_pos_y] = checkboard_rook[i][rook_pos_y] | rook_type;
				brk = 1;
			}
			if ((locboard[i][rook_pos_y] == 0) && (brk != 1))										//if encountering empty space, write to space and continue with loop
				checkboard_rook[i][rook_pos_y] = checkboard_rook[i][rook_pos_y] | rook_type;
		}
		brk = 0;
		for (i = rook_pos_x - 1; i >= 0; i--)
		{
			if ((locboard[i][rook_pos_y] > 0x06) && (locboard[i][rook_pos_y] != 0))			//if encountering a friendly piece exit loop
				brk = 1;
			if ((locboard[i][rook_pos_y] <= 0x06) && (brk != 1))												//if encountering an enemy piece, write to space and exit loop
			{
				checkboard_rook[i][rook_pos_y] = checkboard_rook[i][rook_pos_y] | rook_type;
				brk = 1;
			}
			if ((locboard[i][rook_pos_y] == 0) && (brk != 1))										//if encountering empty space, write to space and continue with loop
				checkboard_rook[i][rook_pos_y] = checkboard_rook[i][rook_pos_y] | rook_type;
		}
		brk = 0;
		for (i = rook_pos_y + 1; i < 8; i++)
		{
			if ((locboard[rook_pos_x][i] > 0x06) && (locboard[rook_pos_x][i] != 0))				//if encountering a friendly piece exit loop
				brk = 1;
			if ((locboard[rook_pos_x][i] <= 0x06) && (brk != 1))
			{
				checkboard_rook[rook_pos_x][i] = checkboard_rook[rook_pos_x][i] | rook_type;
				brk = 1;
			}
			if ((locboard[rook_pos_x][i] == 0) && (brk != 1))
				checkboard_rook[rook_pos_x][i] = checkboard_rook[rook_pos_x][i] | rook_type;
		}
		brk = 0;
		for (i = rook_pos_y - 1; i >= 0; i--)
		{
			if ((locboard[rook_pos_x][i] > 0x06) && (locboard[rook_pos_x][i] != 0))				//if encountering a friendly piece exit loop
				brk = 1;
			if ((locboard[rook_pos_x][i] <= 0x06) && (brk != 1))
			{
				checkboard_rook[rook_pos_x][i] = checkboard_rook[rook_pos_x][i] | rook_type;
				brk = 1;
			}
			if ((locboard[rook_pos_x][i] == 0) && (brk != 1))
				checkboard_rook[rook_pos_x][i] = checkboard_rook[rook_pos_x][i] | rook_type;
		}
		brk = 0;
	}
}

void checkboard_gen_bishop(unsigned int locboard[8][8], unsigned int checkboard_bishop[8][8], int bishop_pos_x, int bishop_pos_y, int what_bishop)
{
	int brk;
	unsigned int bishop_type;
	int i, j;
	if (what_bishop == 1)			//White Queen Bishop
		bishop_type = 0x00000004;
	if (what_bishop == 2)			//White King Bishop
		bishop_type = 0x00000020;
	if (what_bishop == 3)			//Black Queen Bishop
		bishop_type = 0x00040000;
	if (what_bishop == 4)			//Black King Bishop
		bishop_type = 0x00200000;
	if (what_bishop == 5)			//White Queen
		bishop_type = 0x00000008;
	if (what_bishop == 6)			//Black Queen
		bishop_type = 0x00080000;
	brk = 0;
	if (locboard[bishop_pos_x][bishop_pos_y] <= 0x06)			//white case
	{
		for (i = 1; i < 7; i++)
		{
			if (((locboard[bishop_pos_x + i][bishop_pos_y + i] <= 0x06) && (locboard[bishop_pos_x + i][bishop_pos_y + i] != 0)) || (bishop_pos_x + i > 7) || (bishop_pos_y + i > 7))	//up and to right diagonal
				brk = 1;
			if ((locboard[bishop_pos_x + i][bishop_pos_y + i] > 0x06) && (brk != 1))
			{
				checkboard_bishop[bishop_pos_x + i][bishop_pos_y + i] = checkboard_bishop[bishop_pos_x + i][bishop_pos_y + i] | bishop_type;
				brk = 1;
			}
			if ((locboard[bishop_pos_x + i][bishop_pos_y + i] == 0) && (brk != 1))
				checkboard_bishop[bishop_pos_x + i][bishop_pos_y + i] = checkboard_bishop[bishop_pos_x + i][bishop_pos_y + i] | bishop_type;
		}
		brk = 0;
		for (i = 1; i < 7; i++)
		{
			if (((locboard[bishop_pos_x - i][bishop_pos_y - i] <= 0x06) && (locboard[bishop_pos_x - i][bishop_pos_y - i] != 0)) || (bishop_pos_x - i < 0) || (bishop_pos_y - i < 0))	//down and left diagonal
				brk = 1;
			if ((locboard[bishop_pos_x - i][bishop_pos_y - i] > 0x06) && (brk != 1))
			{
				checkboard_bishop[bishop_pos_x - i][bishop_pos_y - i] = checkboard_bishop[bishop_pos_x - i][bishop_pos_y - i] | bishop_type;
				brk = 1;
			}
			if ((locboard[bishop_pos_x - i][bishop_pos_y - i] == 0) && (brk != 1))
				checkboard_bishop[bishop_pos_x - i][bishop_pos_y - i] = checkboard_bishop[bishop_pos_x - i][bishop_pos_y - i] | bishop_type;
		}
		brk = 0;
		for (i = 1; i < 7; i++)
		{
			if (((locboard[bishop_pos_x - i][bishop_pos_y + i] <= 0x06) && (locboard[bishop_pos_x - i][bishop_pos_y + i] != 0)) || (bishop_pos_x - i < 0) || (bishop_pos_y + i > 7))		//up and left diagonal
				brk = 1;
			if ((locboard[bishop_pos_x - i][bishop_pos_y + i] > 0x06) && (brk != 1))
			{
				checkboard_bishop[bishop_pos_x - i][bishop_pos_y + i] = checkboard_bishop[bishop_pos_x - i][bishop_pos_y + i] | bishop_type;
				brk = 1;
			}
			if ((locboard[bishop_pos_x - i][bishop_pos_y + i] == 0) && (brk != 1))
				checkboard_bishop[bishop_pos_x - i][bishop_pos_y + i] = checkboard_bishop[bishop_pos_x - i][bishop_pos_y + i] | bishop_type;
		}
		brk = 0;
		for (i = 1; i < 7; i++)
		{
			if (((locboard[bishop_pos_x + i][bishop_pos_y - i] <= 0x06) && (locboard[bishop_pos_x + i][bishop_pos_y - i] != 0)) || (bishop_pos_x + i > 7) || (bishop_pos_y - i < 0))		//down and right diagonal
				brk = 1;
			if ((locboard[bishop_pos_x + i][bishop_pos_y - i] > 0x06) && (brk != 1))
			{
				checkboard_bishop[bishop_pos_x + i][bishop_pos_y - i] = checkboard_bishop[bishop_pos_x + i][bishop_pos_y - i] | bishop_type;
				brk = 1;
			}
			if ((locboard[bishop_pos_x + i][bishop_pos_y - i] == 0) && (brk != 1))
				checkboard_bishop[bishop_pos_x + i][bishop_pos_y - i] = checkboard_bishop[bishop_pos_x + i][bishop_pos_y - i] | bishop_type;
		}
		brk = 0;

	}
	else if (locboard[bishop_pos_x][bishop_pos_y] > 0x06)					//BLACK CASE
	{
		for (i = 1; i < 7; i++)
		{
			if (((locboard[bishop_pos_x + i][bishop_pos_y + i] > 0x06) && (locboard[bishop_pos_x + i][bishop_pos_y + i] != 0)) || (bishop_pos_x + i > 7) || (bishop_pos_y + i > 7))	//up and to right diagonal
				brk = 1;
			if ((locboard[bishop_pos_x + i][bishop_pos_y + i] <= 0x06) && (brk != 1))
			{
				checkboard_bishop[bishop_pos_x + i][bishop_pos_y + i] = checkboard_bishop[bishop_pos_x + i][bishop_pos_y + i] | bishop_type;
				brk = 1;
			}
			if ((locboard[bishop_pos_x + i][bishop_pos_y + i] == 0) && (brk != 1))
				checkboard_bishop[bishop_pos_x + i][bishop_pos_y + i] = checkboard_bishop[bishop_pos_x + i][bishop_pos_y + i] | bishop_type;
		}
		brk = 0;
		for (i = 1; i < 7; i++)
		{
			if (((locboard[bishop_pos_x - i][bishop_pos_y - i] > 0x06) && (locboard[bishop_pos_x - i][bishop_pos_y - i] != 0)) || (bishop_pos_x - i < 0) || (bishop_pos_y - i < 0))	//down and left diagonal
				brk = 1;
			if ((locboard[bishop_pos_x - i][bishop_pos_y - i] <= 0x06) && (brk != 1))
			{
				checkboard_bishop[bishop_pos_x - i][bishop_pos_y - i] = checkboard_bishop[bishop_pos_x - i][bishop_pos_y - i] | bishop_type;
				brk = 1;
			}
			if ((locboard[bishop_pos_x - i][bishop_pos_y - i] == 0) && (brk != 1))
				checkboard_bishop[bishop_pos_x - i][bishop_pos_y - i] = checkboard_bishop[bishop_pos_x - i][bishop_pos_y - i] | bishop_type;
		}
		brk = 0;
		for (i = 1; i < 7; i++)
		{
			if (((locboard[bishop_pos_x - i][bishop_pos_y + i] > 0x06) && (locboard[bishop_pos_x - i][bishop_pos_y + i] != 0)) || (bishop_pos_x - i < 0) || (bishop_pos_y + i > 7))		//up and left diagonal
				brk = 1;
			if ((locboard[bishop_pos_x - i][bishop_pos_y + i] <= 0x06) && (brk != 1))
			{
				checkboard_bishop[bishop_pos_x - i][bishop_pos_y + i] = checkboard_bishop[bishop_pos_x - i][bishop_pos_y + i] | bishop_type;
				brk = 1;
			}
			if ((locboard[bishop_pos_x - i][bishop_pos_y + i] == 0) && (brk != 1))
				checkboard_bishop[bishop_pos_x - i][bishop_pos_y + i] = checkboard_bishop[bishop_pos_x - i][bishop_pos_y + i] | bishop_type;
		}
		brk = 0;
		for (i = 1; i < 7; i++)
		{
			if (((locboard[bishop_pos_x + i][bishop_pos_y - i] > 0x06) && (locboard[bishop_pos_x + i][bishop_pos_y - i] != 0)) || (bishop_pos_x + i > 7) || (bishop_pos_y - i < 0))		//down and right diagonal
				brk = 1;
			if ((locboard[bishop_pos_x + i][bishop_pos_y - i] <= 0x06) && (brk != 1))
			{
				checkboard_bishop[bishop_pos_x + i][bishop_pos_y - i] = checkboard_bishop[bishop_pos_x + i][bishop_pos_y - i] | bishop_type;
				brk = 1;
			}
			if ((locboard[bishop_pos_x + i][bishop_pos_y - i] == 0) && (brk != 1))
				checkboard_bishop[bishop_pos_x + i][bishop_pos_y - i] = checkboard_bishop[bishop_pos_x + i][bishop_pos_y - i] | bishop_type;
		}
		brk = 0;
	}
}
void checkboard_gen_queen(unsigned int locboard[8][8], unsigned int checkboard[8][8], int queen_pos_x, int queen_pos_y, int what_queen)
{
	checkboard_gen_rook(locboard, checkboard, queen_pos_x, queen_pos_y, what_queen);
	checkboard_gen_bishop(locboard, checkboard, queen_pos_x, queen_pos_y, what_queen);
}


void checkboard_gen_king(unsigned int locboard[8][8], unsigned int checkboard_king[8][8], int king_pos_x, int king_pos_y)
{
	unsigned int king_type;
	if (locboard[king_pos_x][king_pos_y] == 0x05)				//White King
		king_type = 0x00000010;
	if (locboard[king_pos_x][king_pos_y] == 0x0B)				//Black King
		king_type = 0x00100000;
	if (locboard[king_pos_x][king_pos_y] == 0x05)
	{
		if ((king_pos_y != 7) && (checkboard_king[king_pos_x][king_pos_y + 1] < 0x00010000) && ((locboard[king_pos_x][king_pos_y + 1] > 0x06) || (locboard[king_pos_x][king_pos_y + 1] == 0)))
			checkboard_king[king_pos_x][king_pos_y + 1] = checkboard_king[king_pos_x][king_pos_y + 1] | king_type;
		if ((king_pos_y != 0) && (checkboard_king[king_pos_x][king_pos_y - 1] < 0x00010000) && ((locboard[king_pos_x][king_pos_y - 1] > 0x06) || (locboard[king_pos_x][king_pos_y - 1] == 0)))
			checkboard_king[king_pos_x][king_pos_y - 1] = checkboard_king[king_pos_x][king_pos_y - 1] | king_type;
		if ((king_pos_x != 7) && (checkboard_king[king_pos_x + 1][king_pos_y] < 0x00010000) && ((locboard[king_pos_x + 1][king_pos_y] > 0x06) || (locboard[king_pos_x + 1][king_pos_y] == 0)))
			checkboard_king[king_pos_x + 1][king_pos_y] = checkboard_king[king_pos_x + 1][king_pos_y] | king_type;
		if ((king_pos_x != 0) && (checkboard_king[king_pos_x - 1][king_pos_y] < 0x00010000) && ((locboard[king_pos_x - 1][king_pos_y] > 0x06) || (locboard[king_pos_x - 1][king_pos_y] == 0)))
			checkboard_king[king_pos_x - 1][king_pos_y] = checkboard_king[king_pos_x - 1][king_pos_y] | king_type;
		if ((king_pos_x != 7) && (king_pos_y != 7) && (checkboard_king[king_pos_x + 1][king_pos_y + 1] < 0x00010000) && ((locboard[king_pos_x + 1][king_pos_y + 1] > 0x06) || (locboard[king_pos_x + 1][king_pos_y + 1] == 0)))
			checkboard_king[king_pos_x + 1][king_pos_y + 1] = checkboard_king[king_pos_x + 1][king_pos_y + 1] | king_type;
		if ((king_pos_x != 7) && (king_pos_y != 0) && (checkboard_king[king_pos_x + 1][king_pos_y - 1] < 0x00010000) && ((locboard[king_pos_x + 1][king_pos_y - 1] > 0x06) || (locboard[king_pos_x + 1][king_pos_y - 1] == 0)))
			checkboard_king[king_pos_x + 1][king_pos_y - 1] = checkboard_king[king_pos_x + 1][king_pos_y - 1] | king_type;
		if ((king_pos_x != 0) && (king_pos_y != 7) && (checkboard_king[king_pos_x - 1][king_pos_y + 1] < 0x00010000) && ((locboard[king_pos_x - 1][king_pos_y + 1] > 0x06) || (locboard[king_pos_x - 1][king_pos_y + 1] == 0)))
			checkboard_king[king_pos_x - 1][king_pos_y + 1] = checkboard_king[king_pos_x - 1][king_pos_y + 1] | king_type;
		if ((king_pos_x != 0) && (king_pos_y != 0) && (checkboard_king[king_pos_x - 1][king_pos_y - 1] < 0x00010000) && ((locboard[king_pos_x - 1][king_pos_y - 1] > 0x06) || (locboard[king_pos_x - 1][king_pos_y - 1] == 0)))
			checkboard_king[king_pos_x - 1][king_pos_y - 1] = checkboard_king[king_pos_x - 1][king_pos_y - 1] | king_type;
	}
	if (locboard[king_pos_x][king_pos_y] == 0x0B)
	{
		if ((king_pos_y != 7) && ((checkboard_king[king_pos_x][king_pos_y + 1] >= 0x00010000) || (checkboard_king[king_pos_x][king_pos_y + 1] == 0)) && ((locboard[king_pos_x][king_pos_y + 1] <= 0x06) || (locboard[king_pos_x][king_pos_y + 1] == 0)))
			checkboard_king[king_pos_x][king_pos_y + 1] = checkboard_king[king_pos_x][king_pos_y + 1] | king_type;
		if ((king_pos_y != 0) && ((checkboard_king[king_pos_x][king_pos_y - 1] >= 0x00010000) || (checkboard_king[king_pos_x][king_pos_y - 1] == 0)) && ((locboard[king_pos_x][king_pos_y - 1] <= 0x06) || (locboard[king_pos_x][king_pos_y - 1] == 0)))
			checkboard_king[king_pos_x][king_pos_y - 1] = checkboard_king[king_pos_x][king_pos_y - 1] | king_type;
		if ((king_pos_x != 7) && ((checkboard_king[king_pos_x + 1][king_pos_y] >= 0x00010000) || (checkboard_king[king_pos_x + 1][king_pos_y] == 0)) && ((locboard[king_pos_x + 1][king_pos_y] <= 0x06) || (locboard[king_pos_x + 1][king_pos_y] == 0)))
			checkboard_king[king_pos_x + 1][king_pos_y] = checkboard_king[king_pos_x + 1][king_pos_y] | king_type;
		if ((king_pos_x != 0) && ((checkboard_king[king_pos_x - 1][king_pos_y] >= 0x00010000) || (checkboard_king[king_pos_x - 1][king_pos_y] == 0)) && ((locboard[king_pos_x - 1][king_pos_y] <= 0x06) || (locboard[king_pos_x - 1][king_pos_y] == 0)))
			checkboard_king[king_pos_x - 1][king_pos_y] = checkboard_king[king_pos_x - 1][king_pos_y] | king_type;
		if ((king_pos_x != 7) && (king_pos_y != 7) && ((checkboard_king[king_pos_x + 1][king_pos_y + 1] >= 0x00010000) || (checkboard_king[king_pos_x + 1][king_pos_y + 1] == 0)) && ((locboard[king_pos_x + 1][king_pos_y + 1] <= 0x06) || (locboard[king_pos_x + 1][king_pos_y + 1] == 0)))
			checkboard_king[king_pos_x + 1][king_pos_y + 1] = checkboard_king[king_pos_x + 1][king_pos_y + 1] | king_type;
		if ((king_pos_x != 7) && (king_pos_y != 0) && ((checkboard_king[king_pos_x + 1][king_pos_y - 1] >= 0x00010000) || (checkboard_king[king_pos_x + 1][king_pos_y - 1] == 0)) && ((locboard[king_pos_x + 1][king_pos_y - 1] <= 0x06) || (locboard[king_pos_x + 1][king_pos_y - 1] == 0)))
			checkboard_king[king_pos_x + 1][king_pos_y - 1] = checkboard_king[king_pos_x + 1][king_pos_y - 1] | king_type;
		if ((king_pos_x != 0) && (king_pos_y != 7) && ((checkboard_king[king_pos_x - 1][king_pos_y + 1] >= 0x00010000) || (checkboard_king[king_pos_x - 1][king_pos_y + 1] == 0)) && ((locboard[king_pos_x - 1][king_pos_y + 1] <= 0x06) || (locboard[king_pos_x - 1][king_pos_y + 1] == 0)))
			checkboard_king[king_pos_x - 1][king_pos_y + 1] = checkboard_king[king_pos_x - 1][king_pos_y + 1] | king_type;
		if ((king_pos_x != 0) && (king_pos_y != 0) && ((checkboard_king[king_pos_x - 1][king_pos_y - 1] >= 0x00010000) || (checkboard_king[king_pos_x - 1][king_pos_y - 1] == 0)) && ((locboard[king_pos_x - 1][king_pos_y - 1] <= 0x06) || (locboard[king_pos_x - 1][king_pos_y - 1] == 0)))
			checkboard_king[king_pos_x - 1][king_pos_y - 1] = checkboard_king[king_pos_x - 1][king_pos_y - 1] | king_type;
	}
}

int move_check_pawn(unsigned int checkboard[8][8], int x_pos, int y_pos, int what_pawn)
{
	unsigned int pawn_type;
	unsigned int test;
	if (what_pawn == 1)				//White Pawn 1
		pawn_type = 0x100;
	if (what_pawn == 2)				//White Pawn 2
		pawn_type = 0x200;
	if (what_pawn == 3)				//White Pawn 3
		pawn_type = 0x400;
	if (what_pawn == 4)				//White Pawn 4
		pawn_type = 0x800;
	if (what_pawn == 5)				//White Pawn 5
		pawn_type = 0x1000;
	if (what_pawn == 6)				//White Pawn 6
		pawn_type = 0x2000;
	if (what_pawn == 7)				//White Pawn 7
		pawn_type = 0x4000;
	if (what_pawn == 8)				//White Pawn 8 
		pawn_type = 0x8000;
	if (what_pawn == 9)				//Black Pawn 1
		pawn_type = 0x1000000;
	if (what_pawn == 10)			//Black Pawn 2
		pawn_type = 0x2000000;
	if (what_pawn == 11)			//Black Pawn 3
		pawn_type = 0x4000000;
	if (what_pawn == 12)			//Black Pawn 4
		pawn_type = 0x8000000;
	if (what_pawn == 13)			//Black Pawn 5
		pawn_type = 0x10000000;
	if (what_pawn == 14)			//Black Pawn 6
		pawn_type = 0x20000000;
	if (what_pawn == 15)			//Black Pawn 7
		pawn_type = 0x40000000;
	if (what_pawn == 16)			//Black Pawn 8
		pawn_type = 0x80000000;
	test = checkboard[x_pos][y_pos] & pawn_type;
	if (test != 0)
		return 1;
	if (test == 0)
		return 0;
}

int move_check_knight(unsigned int checkboard[8][8], int x_pos, int y_pos, int what_knight)
{
	unsigned int knight_type, test;
	if (what_knight == 1)					//White Queen Knight
		knight_type = 0x00000002;
	if (what_knight == 2)					//White King Knight
		knight_type = 0x00000040;
	if (what_knight == 3)					//Black Queen Knight
		knight_type = 0x00020000;
	if (what_knight == 4)					//Black King Knight
		knight_type = 0x00400000;
	test = checkboard[x_pos][y_pos] & knight_type;
	if (test != 0)
		return 1;
	if (test == 0)
		return 0;
}

int move_check_rook(unsigned int checkboard[8][8], int x_pos, int y_pos, int what_rook)
{
	unsigned int rook_type, test;
	if (what_rook == 1)					//White Queen Rook
		rook_type = 0x00000001;
	if (what_rook == 2)					//White King Rook
		rook_type = 0x00000080;
	if (what_rook == 3)					//Black Queen Rook
		rook_type = 0x00010000;
	if (what_rook == 4)					//Black King Rook
		rook_type = 0x00800000;
	if (what_rook == 5)					//White Queen
		rook_type = 0x00000008;
	if (what_rook == 6)					//Black Queen
		rook_type = 0x00080000;
	test = checkboard[x_pos][y_pos] & rook_type;
	if (test != 0)
		return 1;
	if (test == 0)
		return 0;
}

int move_check_bishop(unsigned int checkboard[8][8], int x_pos, int y_pos, int what_bishop)
{
	unsigned int bishop_type, test;
	if (what_bishop == 1)			//White Queen Bishop
		bishop_type = 0x00000004;
	if (what_bishop == 2)			//White King Bishop
		bishop_type = 0x00000020;
	if (what_bishop == 3)			//Black Queen Bishop
		bishop_type = 0x00040000;
	if (what_bishop == 4)			//Black King Bishop
		bishop_type = 0x00200000;
	if (what_bishop == 5)			//White Queen
		bishop_type = 0x00000008;
	if (what_bishop == 6)			//Black Queen
		bishop_type = 0x00080000;
	test = checkboard[x_pos][y_pos] & bishop_type;
	if (test != 0)
		return 1;
	if (test == 0)
		return 0;
}

int move_check_queen(unsigned int checkboard[8][8], int x_pos, int y_pos, int what_queen)
{
	unsigned int queen_type, test;
	if (what_queen == 5)			//White Queen
		queen_type = 0x00000008;
	if (what_queen == 6)			//Black Queen
		queen_type = 0x00080000;
	test = checkboard[x_pos][y_pos] & queen_type;
	if (test != 0)
		return 1;
	if (test == 0)
		return 0;
}

int move_check_king(unsigned int locboard[8][8], unsigned int checkboard[8][8], int x_pos, int y_pos, int king_x, int king_y)
{
	unsigned int king_type, test;
	if (locboard[king_x][king_y] == 0x05)				//White King
		king_type = 0x00000010;
	if (locboard[king_x][king_y] == 0x0B)				//Black King
		king_type = 0x00100000;
	test = checkboard[x_pos][y_pos] & king_type;
	if (test != 0)
		return 1;
	if (test == 0)
		return 0;
}

int main()
{
	unsigned int locboard[8][8];		//actual game board
	unsigned int checkboard[8][8];		//parallel generated board with hot encoded valid moves
	unsigned char piece_tracker[32];	//tracks positions of each individual piece  
	int i, j;
	for (i = 0; i < 8; i++)				//y initialization
	{
		for (j = 0; j < 8; j++)			//x initialization
		{
			locboard[j][i] = 0x00;
			checkboard[j][i] = 0x00;
		}
	}
	locboard[0][0] = 0x07;
	locboard[1][0] = 0x08;
	locboard[2][0] = 0x09;
	locboard[3][0] = 0x0A;
	locboard[4][0] = 0x0B;
	locboard[5][0] = 0x09;
	locboard[6][0] = 0x08;
	locboard[7][0] = 0x07;
	locboard[0][1] = 0x0C;
	locboard[1][1] = 0x0C;
	locboard[2][1] = 0x0C;
	locboard[3][1] = 0x0C;
	locboard[4][1] = 0x0C;
	locboard[5][1] = 0x0C;
	locboard[6][1] = 0x0C;
	locboard[7][1] = 0x0C;
	locboard[0][6] = 0x06;
	locboard[1][6] = 0x06;
	locboard[2][6] = 0x06;
	locboard[3][6] = 0x06;
	locboard[4][6] = 0x06;
	locboard[5][6] = 0x06;
	locboard[6][6] = 0x06;
	locboard[7][6] = 0x06;
	locboard[0][7] = 0x01;
	locboard[1][7] = 0x02;
	locboard[2][7] = 0x03;
	locboard[3][7] = 0x04;
	locboard[4][7] = 0x05;
	locboard[5][7] = 0x03;
	locboard[6][7] = 0x02;
	locboard[7][7] = 0x01;

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (j == 7)
				printf("%02x \n", locboard[j][i]);
			else
				printf("%02x ", locboard[j][i]);
		}
	}
	printf("\n");
	printf("Checkboard:\n");
	checkboard_gen_pawn(locboard, checkboard, 0, 6, 1, 0);
	checkboard_gen_pawn(locboard, checkboard, 1, 6, 2, 0);
	checkboard_gen_pawn(locboard, checkboard, 2, 6, 3, 0);
	checkboard_gen_pawn(locboard, checkboard, 3, 6, 4, 0);
	checkboard_gen_pawn(locboard, checkboard, 4, 6, 5, 0);
	checkboard_gen_pawn(locboard, checkboard, 5, 6, 6, 0);
	checkboard_gen_pawn(locboard, checkboard, 6, 6, 7, 0);
	checkboard_gen_pawn(locboard, checkboard, 7, 6, 8, 0);
	checkboard_gen_knight(locboard, checkboard, 1, 7, 1);
	checkboard_gen_knight(locboard, checkboard, 6, 7, 2);
	checkboard_gen_rook(locboard, checkboard, 0, 7, 1);
	checkboard_gen_rook(locboard, checkboard, 7, 7, 2);
	checkboard_gen_bishop(locboard, checkboard, 2, 7, 1);
	checkboard_gen_bishop(locboard, checkboard, 5, 7, 2);
	checkboard_gen_king(locboard, checkboard, 4, 7);
	checkboard_gen_queen(locboard, checkboard, 3, 7, 5);

	checkboard_gen_pawn(locboard, checkboard, 0, 1, 9, 0);
	checkboard_gen_pawn(locboard, checkboard, 1, 1, 10, 0);
	checkboard_gen_pawn(locboard, checkboard, 2, 1, 11, 0);
	checkboard_gen_pawn(locboard, checkboard, 3, 1, 12, 0);
	checkboard_gen_pawn(locboard, checkboard, 4, 1, 13, 0);
	checkboard_gen_pawn(locboard, checkboard, 5, 1, 14, 0);
	checkboard_gen_pawn(locboard, checkboard, 6, 1, 15, 0);
	checkboard_gen_pawn(locboard, checkboard, 7, 1, 16, 0);
	checkboard_gen_knight(locboard, checkboard, 1, 0, 3);
	checkboard_gen_knight(locboard, checkboard, 6, 0, 4);
	checkboard_gen_rook(locboard, checkboard, 0, 0, 3);
	checkboard_gen_rook(locboard, checkboard, 7, 0, 4);
	checkboard_gen_bishop(locboard, checkboard, 2, 0, 3);
	checkboard_gen_bishop(locboard, checkboard, 5, 0, 4);
	checkboard_gen_king(locboard, checkboard, 4, 0);
	checkboard_gen_queen(locboard, checkboard, 3, 0, 6);

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (j == 7)
				printf("%08x \n", checkboard[j][i]);
			else
				printf("%08x ", checkboard[j][i]);
		}
	}
	if (move_check_queen(checkboard, 3, 2, 5))
		printf("valid move\n");
	else
		printf("invalid move\n"); 
	return 0;
}
