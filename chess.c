/************************************************************************************/
/*Remember... if something is stupid and it works... it's not stupid.               */
/*Code Written by Lance Pan & Griffin Tucker Fall 2017                              */
/*For use in ECE385 Final Project                                                   */
/*The objective is simple... chess.                                                 */
/*The two travelers could not fathom the difficulty of the task laid ahead...       */
/************************************************************************************/


#include <stdlib.h>		//TO DO: check what other libraries we need/can use
#include <stdio.h>


void checkboard_gen_knight(unsigned int locboard[8][8], unsigned int checkboard_knight[8][8], int knight_pos_x, int knight_pos_y, int what_knight)
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
	if (locboard[knight_pos_x][knight_pos_y] <= 0x10)									//case for white piece
	{
		knight_track_y = knight_pos_y - 2;												//first L
		knight_track_x = knight_pos_x - 1;
		if ((knight_track_y >= 0) && (knight_track_y < 8) && (knight_track_x >= 0) && (knight_track_x < 8) && ((locboard[knight_track_x][knight_track_y] > 0x10) || (locboard[knight_track_x][knight_track_y] == 0))) 					//checks whether position is on board
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] | knight_type;
		knight_track_x = knight_pos_x + 1;
		if ((knight_track_y >= 0) && (knight_track_y < 8) && (knight_track_x >= 0) && (knight_track_x < 8) && ((locboard[knight_track_x][knight_track_y] > 0x10) || (locboard[knight_track_x][knight_track_y] == 0)))
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] | knight_type;
		knight_track_y = knight_pos_y + 2;
		if ((knight_track_y >= 0) && (knight_track_y < 8) && (knight_track_x >= 0) && (knight_track_x < 8) && ((locboard[knight_track_x][knight_track_y] > 0x10) || (locboard[knight_track_x][knight_track_y] == 0)))
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] | knight_type;
		knight_track_x = knight_pos_x - 1;
		if ((knight_track_y >= 0) && (knight_track_y < 8) && (knight_track_x >= 0) && (knight_track_x < 8) && ((locboard[knight_track_x][knight_track_y] > 0x10) || (locboard[knight_track_x][knight_track_y] == 0)))
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] | knight_type;
		knight_track_x = knight_pos_x - 2;
		knight_track_y = knight_pos_y + 1;
		if ((knight_track_y >= 0) && (knight_track_y < 8) && (knight_track_x >= 0) && (knight_track_x < 8) && ((locboard[knight_track_x][knight_track_y] > 0x10) || (locboard[knight_track_x][knight_track_y] == 0)))
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] | knight_type;
		knight_track_y = knight_pos_y - 1;
		if ((knight_track_y >= 0) && (knight_track_y < 8) && (knight_track_x >= 0) && (knight_track_x < 8) && ((locboard[knight_track_x][knight_track_y] > 0x10) || (locboard[knight_track_x][knight_track_y] == 0)))
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] | knight_type;
		knight_track_x = knight_pos_x + 2;
		if ((knight_track_y >= 0) && (knight_track_y < 8) && (knight_track_x >= 0) && (knight_track_x < 8) && ((locboard[knight_track_x][knight_track_y] > 0x10) || (locboard[knight_track_x][knight_track_y] == 0)))
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] | knight_type;
		knight_track_y = knight_pos_y + 1;
		if ((knight_track_y >= 0) && (knight_track_y < 8) && (knight_track_x >= 0) && (knight_track_x < 8) && ((locboard[knight_track_x][knight_track_y] > 0x10) || (locboard[knight_track_x][knight_track_y] == 0)))
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] | knight_type;
	}
	else if (locboard[knight_pos_x][knight_pos_y] > 0x10)								//case for black piece
	{
		knight_track_y = knight_pos_y - 2;												//first L
		knight_track_x = knight_pos_x - 1;
		if ((knight_track_y >= 0) && (knight_track_y < 8) && (knight_track_x >= 0) && (knight_track_x < 8) && ((locboard[knight_track_x][knight_track_y] <= 0x10) || (locboard[knight_track_x][knight_track_y] == 0))) 					//checks whether position is on board
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] | knight_type;
		knight_track_x = knight_pos_x + 1;
		if ((knight_track_y >= 0) && (knight_track_y < 8) && (knight_track_x >= 0) && (knight_track_x < 8) && ((locboard[knight_track_x][knight_track_y] <= 0x10) || (locboard[knight_track_x][knight_track_y] == 0)))
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] | knight_type;
		knight_track_y = knight_pos_y + 2;
		if ((knight_track_y >= 0) && (knight_track_y < 8) && (knight_track_x >= 0) && (knight_track_x < 8) && ((locboard[knight_track_x][knight_track_y] <= 0x10) || (locboard[knight_track_x][knight_track_y] == 0)))
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] | knight_type;
		knight_track_x = knight_pos_x - 1;
		if ((knight_track_y >= 0) && (knight_track_y < 8) && (knight_track_x >= 0) && (knight_track_x < 8) && ((locboard[knight_track_x][knight_track_y] <= 0x10) || (locboard[knight_track_x][knight_track_y] == 0)))
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] | knight_type;
		knight_track_x = knight_pos_x - 2;
		knight_track_y = knight_pos_y + 1;
		if ((knight_track_y >= 0) && (knight_track_y < 8) && (knight_track_x >= 0) && (knight_track_x < 8) && ((locboard[knight_track_x][knight_track_y] <= 0x10) || (locboard[knight_track_x][knight_track_y] == 0)))
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] | knight_type;
		knight_track_y = knight_pos_y - 1;
		if ((knight_track_y >= 0) && (knight_track_y < 8) && (knight_track_x >= 0) && (knight_track_x < 8) && ((locboard[knight_track_x][knight_track_y] <= 0x10) || (locboard[knight_track_x][knight_track_y] == 0)))
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] | knight_type;
		knight_track_x = knight_pos_x + 2;
		if ((knight_track_y >= 0) && (knight_track_y < 8) && (knight_track_x >= 0) && (knight_track_x < 8) && ((locboard[knight_track_x][knight_track_y] <= 0x10) || (locboard[knight_track_x][knight_track_y] == 0)))
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] | knight_type;
		knight_track_y = knight_pos_y + 1;
		if ((knight_track_y >= 0) && (knight_track_y < 8) && (knight_track_x >= 0) && (knight_track_x < 8) && ((locboard[knight_track_x][knight_track_y] <= 0x10) || (locboard[knight_track_x][knight_track_y] == 0)))
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] | knight_type;
	}
}

void checkboard_gen_pawn(unsigned int locboard[8][8], unsigned int checkboard_pawn[8][8], int pawn_pos_x, int pawn_pos_y, int what_pawn)
{
	int pawn_track_x;
	int pawn_track_y;
	int jumptracker;
	unsigned int pawn_type;
	int i, j;
	if ((what_pawn > 0) && (what_pawn < 9))
	{
		if (pawn_pos_y == 6)
			jumptracker = 0;
		else
			jumptracker = 1;
	}
	if ((what_pawn > 8) && (what_pawn < 17))
	{
		if (pawn_pos_y == 1)
			jumptracker = 0;
		else
			jumptracker = 1;
	}
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
	if (locboard[pawn_pos_x][pawn_pos_y] <= 0x10)					//case for white piece
	{
		if (jumptracker == 0)		//initial jump has not occured yet
		{
			pawn_track_y = pawn_pos_y - 1;
			if ((pawn_track_y >= 0) && (pawn_track_y < 8) && (locboard[pawn_pos_x][pawn_track_y] == 0))													//includes check for empty space
				checkboard_pawn[pawn_pos_x][pawn_track_y] = checkboard_pawn[pawn_pos_x][pawn_track_y] | pawn_type;
			pawn_track_x = pawn_pos_x + 1;
			if ((pawn_track_y >= 0) && (pawn_track_y < 8) && (pawn_track_x >= 0) && (pawn_track_x < 8) && (locboard[pawn_track_x][pawn_track_y] > 0x10))	//includes check for on board and whether space is occupied by an enemy piece (double check value)
				checkboard_pawn[pawn_track_x][pawn_track_y] = checkboard_pawn[pawn_track_x][pawn_track_y] | pawn_type;
			pawn_track_x = pawn_pos_x - 1;
			if ((pawn_track_y >= 0) && (pawn_track_y < 8) && (pawn_track_x >= 0) && (pawn_track_x < 8) && (locboard[pawn_track_x][pawn_track_y] > 0x10))
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
			if ((pawn_track_y >= 0) && (pawn_track_y < 8) && (pawn_track_x >= 0) && (pawn_track_x < 8) && (locboard[pawn_track_x][pawn_track_y] > 0x10))	//includes check for on board and whether space is occupied by an enemy piece (double check value)
				checkboard_pawn[pawn_track_x][pawn_track_y] = checkboard_pawn[pawn_track_x][pawn_track_y] | pawn_type;
			pawn_track_x = pawn_pos_x - 1;
			if ((pawn_track_y >= 0) && (pawn_track_y < 8) && (pawn_track_x >= 0) && (pawn_track_x < 8) && (locboard[pawn_track_x][pawn_track_y] > 0x10))
				checkboard_pawn[pawn_track_x][pawn_track_y] = checkboard_pawn[pawn_track_x][pawn_track_y] | pawn_type;
		}
	}
	if (locboard[pawn_pos_x][pawn_pos_y] > 0x10)				//case for black piece
	{
		if (jumptracker == 0)		//initial jump has not occured yet
		{
			pawn_track_y = pawn_pos_y + 1;
			if ((pawn_track_y >= 0) && (pawn_track_y < 8) && (locboard[pawn_pos_x][pawn_track_y] == 0))													//includes check for empty space
				checkboard_pawn[pawn_pos_x][pawn_track_y] = checkboard_pawn[pawn_pos_x][pawn_track_y] | pawn_type;
			pawn_track_x = pawn_pos_x + 1;
			if ((pawn_track_y >= 0) && (pawn_track_y < 8) && (pawn_track_x >= 0) && (pawn_track_x < 8) && (locboard[pawn_track_x][pawn_track_y] <= 0x10) && (locboard[pawn_track_x][pawn_track_y] != 0))	//includes check for on board and whether space is occupied by an enemy piece (double check value)
				checkboard_pawn[pawn_track_x][pawn_track_y] = checkboard_pawn[pawn_track_x][pawn_track_y] | pawn_type;
			pawn_track_x = pawn_pos_x - 1;
			if ((pawn_track_y >= 0) && (pawn_track_y < 8) && (pawn_track_x >= 0) && (pawn_track_x < 8) && (locboard[pawn_track_x][pawn_track_y] <= 0x10) && (locboard[pawn_track_x][pawn_track_y] != 0))
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
			if ((pawn_track_y >= 0) && (pawn_track_y < 8) && (pawn_track_x >= 0) && (pawn_track_x < 8) && (locboard[pawn_track_x][pawn_track_y] <= 0x10) && (locboard[pawn_track_x][pawn_track_y] != 0))	//includes check for on board and whether space is occupied by an enemy piece (double check value)
				checkboard_pawn[pawn_track_x][pawn_track_y] = checkboard_pawn[pawn_track_x][pawn_track_y] | pawn_type;
			pawn_track_x = pawn_pos_x - 1;
			if ((pawn_track_y >= 0) && (pawn_track_y < 8) && (pawn_track_x >= 0) && (pawn_track_x < 8) && (locboard[pawn_track_x][pawn_track_y] <= 0x10) && (locboard[pawn_track_x][pawn_track_y] != 0))
				checkboard_pawn[pawn_track_x][pawn_track_y] = checkboard_pawn[pawn_track_x][pawn_track_y] | pawn_type;
		}
	}
}


void checkboard_gen_rook(unsigned int locboard[8][8], unsigned int checkboard_rook[8][8], int rook_pos_x, int rook_pos_y, int what_rook)
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
	if (locboard[rook_pos_x][rook_pos_y] <= 0x10)			//white case
	{
		for (i = rook_pos_x + 1; i < 8; i++)
		{
			if ((locboard[i][rook_pos_y] <= 0x10) && (locboard[i][rook_pos_y] != 0))			//if encountering a friendly piece exit loop
				brk = 1;
			if ((locboard[i][rook_pos_y] > 0x10) && (brk != 1))												//if encountering an enemy piece, write to space and exit loop
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
			if ((locboard[i][rook_pos_y] <= 0x10) && (locboard[i][rook_pos_y] != 0))			//if encountering a friendly piece exit loop
				brk = 1;
			if ((locboard[i][rook_pos_y] > 0x10) && (brk != 1))												//if encountering an enemy piece, write to space and exit loop
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
			if ((locboard[rook_pos_x][i] <= 0x10) && (locboard[rook_pos_x][i] != 0))				//if encountering a friendly piece exit loop
				brk = 1;
			if ((locboard[rook_pos_x][i] > 0x10) && (brk != 1))
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
			if ((locboard[rook_pos_x][i] <= 0x10) && (locboard[rook_pos_x][i] != 0))				//if encountering a friendly piece exit loop
				brk = 1;
			if ((locboard[rook_pos_x][i] > 0x10) && (brk != 1))
			{
				checkboard_rook[rook_pos_x][i] = checkboard_rook[rook_pos_x][i] | rook_type;
				brk = 1;
			}
			if ((locboard[rook_pos_x][i] == 0) && (brk != 1))
				checkboard_rook[rook_pos_x][i] = checkboard_rook[rook_pos_x][i] | rook_type;
		}
		brk = 0;
	}
	if (locboard[rook_pos_x][rook_pos_y] > 0x10)		//black case
	{
		for (i = rook_pos_x + 1; i < 8; i++)
		{
			if (locboard[i][rook_pos_y] > 0x10)			//if encountering a friendly piece exit loop
				brk = 1;
			if ((locboard[i][rook_pos_y] <= 0x10) && (locboard[i][rook_pos_y] != 0x00) && (brk != 1))												//if encountering an enemy piece, write to space and exit loop
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
			if (locboard[i][rook_pos_y] > 0x10)			//if encountering a friendly piece exit loop
				brk = 1;
			if ((locboard[i][rook_pos_y] <= 0x10) && (locboard[i][rook_pos_y] != 0x00) && (brk != 1))												//if encountering an enemy piece, write to space and exit loop
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
			if (locboard[rook_pos_x][i] > 0x10)				//if encountering a friendly piece exit loop
				brk = 1;
			if ((locboard[rook_pos_x][i] <= 0x10) && (locboard[rook_pos_x][i] != 0x00) && (brk != 1))
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
			if (locboard[rook_pos_x][i] > 0x10)				//if encountering a friendly piece exit loop
				brk = 1;
			if ((locboard[rook_pos_x][i] <= 0x10) && (locboard[rook_pos_x][i] != 0x00) && (brk != 1))
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
	if (locboard[bishop_pos_x][bishop_pos_y] <= 0x10)			//white case
	{
		for (i = 1; i < 7; i++)
		{
			if (((locboard[bishop_pos_x + i][bishop_pos_y + i] <= 0x10) && (locboard[bishop_pos_x + i][bishop_pos_y + i] != 0)) || (bishop_pos_x + i > 7) || (bishop_pos_y + i > 7))	//up and to right diagonal
				brk = 1;
			if ((locboard[bishop_pos_x + i][bishop_pos_y + i] > 0x10) && (brk != 1))
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
			if (((locboard[bishop_pos_x - i][bishop_pos_y - i] <= 0x10) && (locboard[bishop_pos_x - i][bishop_pos_y - i] != 0)) || (bishop_pos_x - i < 0) || (bishop_pos_y - i < 0))	//down and left diagonal
				brk = 1;
			if ((locboard[bishop_pos_x - i][bishop_pos_y - i] > 0x10) && (brk != 1))
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
			if (((locboard[bishop_pos_x - i][bishop_pos_y + i] <= 0x10) && (locboard[bishop_pos_x - i][bishop_pos_y + i] != 0)) || (bishop_pos_x - i < 0) || (bishop_pos_y + i > 7))		//up and left diagonal
				brk = 1;
			if ((locboard[bishop_pos_x - i][bishop_pos_y + i] > 0x10) && (brk != 1))
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
			if (((locboard[bishop_pos_x + i][bishop_pos_y - i] <= 0x10) && (locboard[bishop_pos_x + i][bishop_pos_y - i] != 0)) || (bishop_pos_x + i > 7) || (bishop_pos_y - i < 0))		//down and right diagonal
				brk = 1;
			if ((locboard[bishop_pos_x + i][bishop_pos_y - i] > 0x10) && (brk != 1))
			{
				checkboard_bishop[bishop_pos_x + i][bishop_pos_y - i] = checkboard_bishop[bishop_pos_x + i][bishop_pos_y - i] | bishop_type;
				brk = 1;
			}
			if ((locboard[bishop_pos_x + i][bishop_pos_y - i] == 0) && (brk != 1))
				checkboard_bishop[bishop_pos_x + i][bishop_pos_y - i] = checkboard_bishop[bishop_pos_x + i][bishop_pos_y - i] | bishop_type;
		}
		brk = 0;

	}
	else if (locboard[bishop_pos_x][bishop_pos_y] > 0x10)					//BLACK CASE
	{
		for (i = 1; i < 7; i++)
		{
			if ((locboard[bishop_pos_x + i][bishop_pos_y + i] > 0x10) || (bishop_pos_x + i > 7) || (bishop_pos_y + i > 7))	//up and to right diagonal
				brk = 1;
			if ((locboard[bishop_pos_x + i][bishop_pos_y + i] <= 0x10) && (locboard[bishop_pos_x + i][bishop_pos_y + i] != 0x00) && (brk != 1))
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
			if ((locboard[bishop_pos_x - i][bishop_pos_y - i] > 0x10) || (bishop_pos_x - i < 0) || (bishop_pos_y - i < 0))	//down and left diagonal
				brk = 1;
			if ((locboard[bishop_pos_x - i][bishop_pos_y - i] <= 0x10) && (locboard[bishop_pos_x - i][bishop_pos_y - i] != 0x00) && (brk != 1))
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
			if ((locboard[bishop_pos_x - i][bishop_pos_y + i] > 0x10) || (bishop_pos_x - i < 0) || (bishop_pos_y + i > 7))		//up and left diagonal
				brk = 1;
			if ((locboard[bishop_pos_x - i][bishop_pos_y + i] <= 0x10) && (locboard[bishop_pos_x - i][bishop_pos_y + i] != 0x00) && (brk != 1))
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
			if ((locboard[bishop_pos_x + i][bishop_pos_y - i] > 0x10) || (bishop_pos_x + i > 7) || (bishop_pos_y - i < 0))		//down and right diagonal
				brk = 1;
			if ((locboard[bishop_pos_x + i][bishop_pos_y - i] <= 0x10) && (locboard[bishop_pos_x + i][bishop_pos_y - i] != 0x00) && (brk != 1))
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
		if ((king_pos_y != 7) && (checkboard_king[king_pos_x][king_pos_y + 1] < 0x00010000) && ((locboard[king_pos_x][king_pos_y + 1] > 0x10) || (locboard[king_pos_x][king_pos_y + 1] == 0)))
			checkboard_king[king_pos_x][king_pos_y + 1] = checkboard_king[king_pos_x][king_pos_y + 1] | king_type;
		if ((king_pos_y != 0) && (checkboard_king[king_pos_x][king_pos_y - 1] < 0x00010000) && ((locboard[king_pos_x][king_pos_y - 1] > 0x10) || (locboard[king_pos_x][king_pos_y - 1] == 0)))
			checkboard_king[king_pos_x][king_pos_y - 1] = checkboard_king[king_pos_x][king_pos_y - 1] | king_type;
		if ((king_pos_x != 7) && (checkboard_king[king_pos_x + 1][king_pos_y] < 0x00010000) && ((locboard[king_pos_x + 1][king_pos_y] > 0x10) || (locboard[king_pos_x + 1][king_pos_y] == 0)))
			checkboard_king[king_pos_x + 1][king_pos_y] = checkboard_king[king_pos_x + 1][king_pos_y] | king_type;
		if ((king_pos_x != 0) && (checkboard_king[king_pos_x - 1][king_pos_y] < 0x00010000) && ((locboard[king_pos_x - 1][king_pos_y] > 0x10) || (locboard[king_pos_x - 1][king_pos_y] == 0)))
			checkboard_king[king_pos_x - 1][king_pos_y] = checkboard_king[king_pos_x - 1][king_pos_y] | king_type;
		if ((king_pos_x != 7) && (king_pos_y != 7) && (checkboard_king[king_pos_x + 1][king_pos_y + 1] < 0x00010000) && ((locboard[king_pos_x + 1][king_pos_y + 1] > 0x10) || (locboard[king_pos_x + 1][king_pos_y + 1] == 0)))
			checkboard_king[king_pos_x + 1][king_pos_y + 1] = checkboard_king[king_pos_x + 1][king_pos_y + 1] | king_type;
		if ((king_pos_x != 7) && (king_pos_y != 0) && (checkboard_king[king_pos_x + 1][king_pos_y - 1] < 0x00010000) && ((locboard[king_pos_x + 1][king_pos_y - 1] > 0x10) || (locboard[king_pos_x + 1][king_pos_y - 1] == 0)))
			checkboard_king[king_pos_x + 1][king_pos_y - 1] = checkboard_king[king_pos_x + 1][king_pos_y - 1] | king_type;
		if ((king_pos_x != 0) && (king_pos_y != 7) && (checkboard_king[king_pos_x - 1][king_pos_y + 1] < 0x00010000) && ((locboard[king_pos_x - 1][king_pos_y + 1] > 0x10) || (locboard[king_pos_x - 1][king_pos_y + 1] == 0)))
			checkboard_king[king_pos_x - 1][king_pos_y + 1] = checkboard_king[king_pos_x - 1][king_pos_y + 1] | king_type;
		if ((king_pos_x != 0) && (king_pos_y != 0) && (checkboard_king[king_pos_x - 1][king_pos_y - 1] < 0x00010000) && ((locboard[king_pos_x - 1][king_pos_y - 1] > 0x10) || (locboard[king_pos_x - 1][king_pos_y - 1] == 0)))
			checkboard_king[king_pos_x - 1][king_pos_y - 1] = checkboard_king[king_pos_x - 1][king_pos_y - 1] | king_type;
	}
	if (locboard[king_pos_x][king_pos_y] == 0x0B)
	{
		if ((king_pos_y != 7) && ((checkboard_king[king_pos_x][king_pos_y + 1] >= 0x00010000) || (checkboard_king[king_pos_x][king_pos_y + 1] == 0)) && ((locboard[king_pos_x][king_pos_y + 1] <= 0x10) || (locboard[king_pos_x][king_pos_y + 1] == 0)))
			checkboard_king[king_pos_x][king_pos_y + 1] = checkboard_king[king_pos_x][king_pos_y + 1] | king_type;
		if ((king_pos_y != 0) && ((checkboard_king[king_pos_x][king_pos_y - 1] >= 0x00010000) || (checkboard_king[king_pos_x][king_pos_y - 1] == 0)) && ((locboard[king_pos_x][king_pos_y - 1] <= 0x10) || (locboard[king_pos_x][king_pos_y - 1] == 0)))
			checkboard_king[king_pos_x][king_pos_y - 1] = checkboard_king[king_pos_x][king_pos_y - 1] | king_type;
		if ((king_pos_x != 7) && ((checkboard_king[king_pos_x + 1][king_pos_y] >= 0x00010000) || (checkboard_king[king_pos_x + 1][king_pos_y] == 0)) && ((locboard[king_pos_x + 1][king_pos_y] <= 0x10) || (locboard[king_pos_x + 1][king_pos_y] == 0)))
			checkboard_king[king_pos_x + 1][king_pos_y] = checkboard_king[king_pos_x + 1][king_pos_y] | king_type;
		if ((king_pos_x != 0) && ((checkboard_king[king_pos_x - 1][king_pos_y] >= 0x00010000) || (checkboard_king[king_pos_x - 1][king_pos_y] == 0)) && ((locboard[king_pos_x - 1][king_pos_y] <= 0x10) || (locboard[king_pos_x - 1][king_pos_y] == 0)))
			checkboard_king[king_pos_x - 1][king_pos_y] = checkboard_king[king_pos_x - 1][king_pos_y] | king_type;
		if ((king_pos_x != 7) && (king_pos_y != 7) && ((checkboard_king[king_pos_x + 1][king_pos_y + 1] >= 0x00010000) || (checkboard_king[king_pos_x + 1][king_pos_y + 1] == 0)) && ((locboard[king_pos_x + 1][king_pos_y + 1] <= 0x10) || (locboard[king_pos_x + 1][king_pos_y + 1] == 0)))
			checkboard_king[king_pos_x + 1][king_pos_y + 1] = checkboard_king[king_pos_x + 1][king_pos_y + 1] | king_type;
		if ((king_pos_x != 7) && (king_pos_y != 0) && ((checkboard_king[king_pos_x + 1][king_pos_y - 1] >= 0x00010000) || (checkboard_king[king_pos_x + 1][king_pos_y - 1] == 0)) && ((locboard[king_pos_x + 1][king_pos_y - 1] <= 0x10) || (locboard[king_pos_x + 1][king_pos_y - 1] == 0)))
			checkboard_king[king_pos_x + 1][king_pos_y - 1] = checkboard_king[king_pos_x + 1][king_pos_y - 1] | king_type;
		if ((king_pos_x != 0) && (king_pos_y != 7) && ((checkboard_king[king_pos_x - 1][king_pos_y + 1] >= 0x00010000) || (checkboard_king[king_pos_x - 1][king_pos_y + 1] == 0)) && ((locboard[king_pos_x - 1][king_pos_y + 1] <= 0x10) || (locboard[king_pos_x - 1][king_pos_y + 1] == 0)))
			checkboard_king[king_pos_x - 1][king_pos_y + 1] = checkboard_king[king_pos_x - 1][king_pos_y + 1] | king_type;
		if ((king_pos_x != 0) && (king_pos_y != 0) && ((checkboard_king[king_pos_x - 1][king_pos_y - 1] >= 0x00010000) || (checkboard_king[king_pos_x - 1][king_pos_y - 1] == 0)) && ((locboard[king_pos_x - 1][king_pos_y - 1] <= 0x10) || (locboard[king_pos_x - 1][king_pos_y - 1] == 0)))
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

int select_piece(unsigned int locboard[8][8], int x_pos, int y_pos)
{
	int piece;
	if (locboard[x_pos][y_pos] == 0x01)
		piece = 1;
	if (locboard[x_pos][y_pos] == 0x02)
		piece = 1;
	if (locboard[x_pos][y_pos] == 0x03)
		piece = 1;
	if (locboard[x_pos][y_pos] == 0x04)
		piece = 5;
	if (locboard[x_pos][y_pos] == 0x06)
		piece = 2;
	if (locboard[x_pos][y_pos] == 0x07)
		piece = 2;
	if (locboard[x_pos][y_pos] == 0x08)
		piece = 2;
	if (locboard[x_pos][y_pos] == 0x09)
		piece = 1;
	if (locboard[x_pos][y_pos] == 0x0A)
		piece = 2;
	if (locboard[x_pos][y_pos] == 0x0B)
		piece = 3;
	if (locboard[x_pos][y_pos] == 0x0C)
		piece = 4;
	if (locboard[x_pos][y_pos] == 0x0D)
		piece = 5;
	if (locboard[x_pos][y_pos] == 0x0E)
		piece = 6;
	if (locboard[x_pos][y_pos] == 0x0F)
		piece = 7;
	if (locboard[x_pos][y_pos] == 0x10)
		piece = 8;
	if (locboard[x_pos][y_pos] == 0x11)
		piece = 3;
	if (locboard[x_pos][y_pos] == 0x12)
		piece = 3;
	if (locboard[x_pos][y_pos] == 0x13)
		piece = 3;
	if (locboard[x_pos][y_pos] == 0x14)
		piece = 6;
	if (locboard[x_pos][y_pos] == 0x16)
		piece = 4;
	if (locboard[x_pos][y_pos] == 0x17)
		piece = 4;
	if (locboard[x_pos][y_pos] == 0x18)
		piece = 4;
	if (locboard[x_pos][y_pos] == 0x19)
		piece = 9;
	if (locboard[x_pos][y_pos] == 0x1A)
		piece = 10;
	if (locboard[x_pos][y_pos] == 0x1B)
		piece = 11;
	if (locboard[x_pos][y_pos] == 0x1C)
		piece = 12;
	if (locboard[x_pos][y_pos] == 0x1D)
		piece = 13;
	if (locboard[x_pos][y_pos] == 0x1E)
		piece = 14;
	if (locboard[x_pos][y_pos] == 0x1F)
		piece = 15;
	if (locboard[x_pos][y_pos] == 0x20)
		piece = 16;
	return piece;

}

void translate_board(unsigned int locboard[8][8], char realboard[8][8])
{
	int i, j;
	for (i = 0; i < 8; i++)				
	{
		for (j = 0; j < 8; j++)			
		{
			if (locboard[j][i] == 0x00)
				realboard[j][i] = 0;
			if ((locboard[j][i] == 0x01) || (locboard[j][i] == 0x08))
				realboard[j][i] = "WR";
			if ((locboard[j][i] == 0x02) || (locboard[j][i] == 0x07))
				realboard[j][i] = "WK";
			if ((locboard[j][i] == 0x03) || (locboard[j][i] == 0x06))
				realboard[j][i] = "WB";
			if (locboard[j][i] == 0x04)
				realboard[j][i] = "WQ";
			if (locboard[j][i] == 0x05)
				realboard[j][i] = "KW";
			if ((locboard[j][i] >= 0x09) && (locboard[j][i] <= 0x10))
				realboard[j][i] = "WP"; 

			if ((locboard[j][i] == 0x11) || (locboard[j][i] == 0x18))
				realboard[j][i] = "BR";
			if ((locboard[j][i] == 0x12) || (locboard[j][i] == 0x17))
				realboard[j][i] = "BK";
			if ((locboard[j][i] == 0x13) || (locboard[j][i] == 0x16))
				realboard[j][i] = "BB";
			if (locboard[j][i] == 0x14)
				realboard[j][i] = "BQ";
			if (locboard[j][i] == 0x15)
				realboard[j][i] = "KB";
			if ((locboard[j][i] >= 0x19) && (locboard[j][i] <= 0x20))
				realboard[j][i] = "BP";
		}
	}
}

void print_board(unsigned int locboard[8][8])
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (j == 7)
			{
				if (locboard[j][i] == 0x00)
					printf(" 00 \n");
				if ((locboard[j][i] == 0x01) || (locboard[j][i] == 0x08))
					printf(" WR \n");
				if ((locboard[j][i] == 0x02) || (locboard[j][i] == 0x07))
					printf(" WK \n");
				if ((locboard[j][i] == 0x03) || (locboard[j][i] == 0x06))
					printf(" WB \n");
				if (locboard[j][i] == 0x04)
					printf(" WQ \n");
				if (locboard[j][i] == 0x05)
					printf(" KW \n");
				if ((locboard[j][i] >= 0x09) && (locboard[j][i] <= 0x10))
					printf(" WP \n");

				if ((locboard[j][i] == 0x11) || (locboard[j][i] == 0x18))
					printf(" BR \n");
				if ((locboard[j][i] == 0x12) || (locboard[j][i] == 0x17))
					printf(" BK \n");
				if ((locboard[j][i] == 0x13) || (locboard[j][i] == 0x16))
					printf(" BB \n");
				if (locboard[j][i] == 0x14)
					printf(" BQ \n");
				if (locboard[j][i] == 0x15)
					printf(" KB \n");
				if ((locboard[j][i] >= 0x19) && (locboard[j][i] <= 0x20))
					printf(" BP \n");
			}
			else
			{
				if (locboard[j][i] == 0x00)
					printf(" 00 ");
				if ((locboard[j][i] == 0x01) || (locboard[j][i] == 0x08))
					printf(" WR ");
				if ((locboard[j][i] == 0x02) || (locboard[j][i] == 0x07))
					printf(" WK ");
				if ((locboard[j][i] == 0x03) || (locboard[j][i] == 0x06))
					printf(" WB ");
				if (locboard[j][i] == 0x04)
					printf(" WQ ");
				if (locboard[j][i] == 0x05)
					printf(" KW ");
				if ((locboard[j][i] >= 0x09) && (locboard[j][i] <= 0x10))
					printf(" WP ");

				if ((locboard[j][i] == 0x11) || (locboard[j][i] == 0x18))
					printf(" BR ");
				if ((locboard[j][i] == 0x12) || (locboard[j][i] == 0x17))
					printf(" BK ");
				if ((locboard[j][i] == 0x13) || (locboard[j][i] == 0x16))
					printf(" BB ");
				if (locboard[j][i] == 0x14)
					printf(" BQ ");
				if (locboard[j][i] == 0x15)
					printf(" KB ");
				if ((locboard[j][i] >= 0x19) && (locboard[j][i] <= 0x20))
					printf(" BP ");
			}
				
		}
	}
}

int main()
{
	unsigned int locboard[8][8];		//actual game board
	unsigned int checkboard[8][8];		//parallel generated board with hot encoded valid moves
	char realboard[8][8];		//for in console game purposes
	int init_x, init_y, checkmate, check, turn;
	int move_x, move_y, what_piece, valid;
	int WQR_X, WQR_Y, WQK_X, WQK_Y, WQB_X, WQB_Y, WQ_X, WQ_Y, WK_X, WK_Y, WKB_X, WKB_Y, WKK_X, WKK_Y, WKR_X, WKR_Y, WP1_X, WP1_Y, WP2_X, WP2_Y;
	int WP3_X, WP3_Y, WP4_X, WP4_Y, WP5_X, WP5_Y, WP6_X, WP6_Y, WP7_X, WP7_Y, WP8_X, WP8_Y;
	int BQR_X, BQR_Y, BQK_X, BQK_Y, BQB_X, BQB_Y, BQ_X, BQ_Y, BK_X, BK_Y, BKB_X, BKB_Y, BKK_X, BKK_Y, BKR_X, BKR_Y, BP1_X, BP1_Y, BP2_X, BP2_Y;
	int BP3_X, BP3_Y, BP4_X, BP4_Y, BP5_X, BP5_Y, BP6_X, BP6_Y, BP7_X, BP7_Y, BP8_X, BP8_Y;
	WQR_X = 0;									//I didn't know what else to do so BRUTE FORCE IT IS
	WQR_Y = 7;									//keeps track of individual piece positions for the repeated checkboard gen functions
	WQK_X = 1;
	WQK_Y = 7;
	WQB_X = 2;
	WQB_Y = 7;
	WQ_X = 3;
	WQ_Y = 7;
	WK_X = 4;
	WK_Y = 7;
	WKB_X = 5;
	WKB_Y = 7;
	WKK_X = 6;
	WKK_Y = 7;
	WKR_X = 7;
	WKR_Y = 7;
	WP1_X = 0;
	WP1_Y = 6;
	WP2_X = 1;
	WP2_Y = 6;
	WP3_X = 2;
	WP3_Y = 6;
	WP4_X = 3;
	WP4_Y = 6;
	WP5_X = 4;
	WP5_Y = 6;
	WP6_X = 5;
	WP6_Y = 6;
	WP7_X = 6;
	WP7_Y = 6;
	WP8_X = 7;
	WP8_Y = 6;
	BQR_X = 0;
	BQR_Y = 0;
	BQK_X = 1;
	BQK_Y = 0;
	BQB_X = 2;
	BQB_Y = 0;
	BQ_X = 3;
	BQ_Y = 0;
	BK_X = 4;
	BK_Y = 0;
	BKB_X = 5;
	BKB_Y = 0;
	BKK_X = 6;
	BKK_Y = 0;
	BKR_X = 7;
	BKR_Y = 0;
	BP1_X = 0;
	BP1_Y = 1;
	BP2_X = 1;
	BP2_Y = 1;
	BP3_X = 2;
	BP3_Y = 1;
	BP4_X = 3;
	BP4_Y = 1;
	BP5_X = 4;
	BP5_Y = 1;
	BP6_X = 5;
	BP6_Y = 1;
	BP7_X = 6;
	BP7_Y = 1;
	BP8_X = 7;
	BP8_Y = 1;
	int i, j;
	checkmate = 0;
	turn = 0;							//white goes first
	for (i = 0; i < 8; i++)				//y initialization
	{
		for (j = 0; j < 8; j++)			//x initialization
		{
			locboard[j][i] = 0x00;
			checkboard[j][i] = 0x00;
		}
	}
	locboard[0][0] = 0x11;			//locboard initialization
	locboard[1][0] = 0x12;
	locboard[2][0] = 0x13;
	locboard[3][0] = 0x14;
	locboard[4][0] = 0x15;
	locboard[5][0] = 0x16;
	locboard[6][0] = 0x17;
	locboard[7][0] = 0x18;
	locboard[0][1] = 0x19;
	locboard[1][1] = 0x1A;
	locboard[2][1] = 0x1B;
	locboard[3][1] = 0x1C;
	locboard[4][1] = 0x1D;
	locboard[5][1] = 0x1E;
	locboard[6][1] = 0x1F;
	locboard[7][1] = 0x20;
	locboard[0][6] = 0x09;
	locboard[1][6] = 0x0A;
	locboard[2][6] = 0x0B;
	locboard[3][6] = 0x0C;
	locboard[4][6] = 0x0D;
	locboard[5][6] = 0x0E;
	locboard[6][6] = 0x0F;
	locboard[7][6] = 0x10;
	locboard[0][7] = 0x01;
	locboard[1][7] = 0x02;
	locboard[2][7] = 0x03;
	locboard[3][7] = 0x04;
	locboard[4][7] = 0x05;
	locboard[5][7] = 0x06;
	locboard[6][7] = 0x07;
	locboard[7][7] = 0x08;

	print_board(locboard);
/*	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (j == 7)
				printf("%02x \n", locboard[j][i]);
			else
				printf("%02x ", locboard[j][i]);
		}
	}
*/
	checkboard_gen_pawn(locboard, checkboard, WP1_X, WP1_Y, 1);
	checkboard_gen_pawn(locboard, checkboard, WP2_X, WP2_Y, 2);
	checkboard_gen_pawn(locboard, checkboard, WP3_X, WP3_Y, 3);
	checkboard_gen_pawn(locboard, checkboard, WP4_X, WP4_Y, 4);
	checkboard_gen_pawn(locboard, checkboard, WP5_X, WP5_Y, 5);
	checkboard_gen_pawn(locboard, checkboard, WP6_X, WP6_Y, 6);
	checkboard_gen_pawn(locboard, checkboard, WP7_X, WP7_Y, 7);
	checkboard_gen_pawn(locboard, checkboard, WP8_X, WP8_Y, 8);
	checkboard_gen_knight(locboard, checkboard, WQK_X, WQK_Y, 1);
	checkboard_gen_knight(locboard, checkboard, WKK_X, WKK_Y, 2);
	checkboard_gen_rook(locboard, checkboard, WQR_X, WQR_Y, 1);
	checkboard_gen_rook(locboard, checkboard, WKR_X, WKR_Y, 2);
	checkboard_gen_bishop(locboard, checkboard, WQB_X, WQB_Y, 1);
	checkboard_gen_bishop(locboard, checkboard, WKB_X, WKB_Y, 2);
	checkboard_gen_king(locboard, checkboard, WK_X, WK_Y);
	checkboard_gen_queen(locboard, checkboard, WQ_X, WQ_Y, 5);

	checkboard_gen_pawn(locboard, checkboard, BP1_X, BP1_Y, 9);
	checkboard_gen_pawn(locboard, checkboard, BP2_X, BP2_Y, 10);
	checkboard_gen_pawn(locboard, checkboard, BP3_X, BP3_Y, 11);
	checkboard_gen_pawn(locboard, checkboard, BP4_X, BP4_Y, 12);
	checkboard_gen_pawn(locboard, checkboard, BP5_X, BP5_Y, 13);
	checkboard_gen_pawn(locboard, checkboard, BP6_X, BP6_Y, 14);
	checkboard_gen_pawn(locboard, checkboard, BP7_X, BP7_Y, 15);
	checkboard_gen_pawn(locboard, checkboard, BP8_X, BP8_Y, 16);
	checkboard_gen_knight(locboard, checkboard, BQK_X, BQK_Y, 3);
	checkboard_gen_knight(locboard, checkboard, BKK_X, BKK_Y, 4);
	checkboard_gen_rook(locboard, checkboard, BQR_X, BQR_Y, 3);
	checkboard_gen_rook(locboard, checkboard, BKR_X, BKR_Y, 4);
	checkboard_gen_bishop(locboard, checkboard, BQB_X, BQB_Y, 3);
	checkboard_gen_bishop(locboard, checkboard, BKB_X, BKB_Y, 4);
	checkboard_gen_king(locboard, checkboard, BK_X, BK_Y);
	checkboard_gen_queen(locboard, checkboard, BQ_X, BQ_Y, 6);
	while (1 < 2)
	{
		if (turn == 0)
		{
			init_x = 0;
			init_y = 0;
			move_x = 0;
			move_y = 0;
			printf("White Turn: Select Piece and Destination\n");
			scanf("%d %d %d %d", &init_x, &init_y, &move_x, &move_y);
			what_piece = select_piece(locboard, init_x, init_y);
			while ((locboard[init_x][init_y] == 0) || (locboard[init_x][init_y] > 0x10))
			{
				printf("Invalid Selection, Please Try Again!\n");
				scanf("%d %d %d %d", &init_x, &init_y, &move_x, &move_y);
			}
			if ((locboard[init_x][init_y] > 0x08) && (locboard[init_x][init_y] < 0x11))			//white pawn
			{
				valid = move_check_pawn(checkboard, move_x, move_y, what_piece);
				if (valid == 1)
				{
					if (locboard[init_x][init_y] == 0x09)
					{
						WP1_X = move_x;
						WP1_Y = move_y;
					}
					if (locboard[init_x][init_y] == 0x0A)
					{
						WP2_X = move_x;
						WP2_Y = move_y;
					}
					if (locboard[init_x][init_y] == 0x0B)
					{
						WP3_X = move_x;
						WP3_Y = move_y;
					}
					if (locboard[init_x][init_y] == 0x0C)
					{
						WP4_X = move_x;
						WP4_Y = move_y;
					}
					if (locboard[init_x][init_y] == 0x0D)
					{
						WP5_X = move_x;
						WP5_Y = move_y;
					}
					if (locboard[init_x][init_y] == 0x0E)
					{
						WP6_X = move_x;
						WP6_Y = move_y;
					}
					if (locboard[init_x][init_y] == 0x0F)
					{
						WP7_X = move_x;
						WP7_Y = move_y;
					}
					if (locboard[init_x][init_y] == 0x10)
					{
						WP8_X = move_x;
						WP8_Y = move_y;
					}
					locboard[move_x][move_y] = locboard[init_x][init_y];
					locboard[init_x][init_y] = 0x00;
					for (i = 0; i < 8; i++)				//y refresh
					{
						for (j = 0; j < 8; j++)			//x refresh
						{
							checkboard[j][i] = 0x00;
						}
					}
					checkboard_gen_pawn(locboard, checkboard, WP1_X, WP1_Y, 1);
					checkboard_gen_pawn(locboard, checkboard, WP2_X, WP2_Y, 2);
					checkboard_gen_pawn(locboard, checkboard, WP3_X, WP3_Y, 3);
					checkboard_gen_pawn(locboard, checkboard, WP4_X, WP4_Y, 4);
					checkboard_gen_pawn(locboard, checkboard, WP5_X, WP5_Y, 5);
					checkboard_gen_pawn(locboard, checkboard, WP6_X, WP6_Y, 6);
					checkboard_gen_pawn(locboard, checkboard, WP7_X, WP7_Y, 7);
					checkboard_gen_pawn(locboard, checkboard, WP8_X, WP8_Y, 8);
					checkboard_gen_knight(locboard, checkboard, WQK_X, WQK_Y, 1);
					checkboard_gen_knight(locboard, checkboard, WKK_X, WKK_Y, 2);
					checkboard_gen_rook(locboard, checkboard, WQR_X, WQR_Y, 1);
					checkboard_gen_rook(locboard, checkboard, WKR_X, WKR_Y, 2);
					checkboard_gen_bishop(locboard, checkboard, WQB_X, WQB_Y, 1);
					checkboard_gen_bishop(locboard, checkboard, WKB_X, WKB_Y, 2);
					checkboard_gen_king(locboard, checkboard, WK_X, WK_Y);
					checkboard_gen_queen(locboard, checkboard, WQ_X, WQ_Y, 5);

					checkboard_gen_pawn(locboard, checkboard, BP1_X, BP1_Y, 9);
					checkboard_gen_pawn(locboard, checkboard, BP2_X, BP2_Y, 10);
					checkboard_gen_pawn(locboard, checkboard, BP3_X, BP3_Y, 11);
					checkboard_gen_pawn(locboard, checkboard, BP4_X, BP4_Y, 12);
					checkboard_gen_pawn(locboard, checkboard, BP5_X, BP5_Y, 13);
					checkboard_gen_pawn(locboard, checkboard, BP6_X, BP6_Y, 14);
					checkboard_gen_pawn(locboard, checkboard, BP7_X, BP7_Y, 15);
					checkboard_gen_pawn(locboard, checkboard, BP8_X, BP8_Y, 16);
					checkboard_gen_knight(locboard, checkboard, BQK_X, BQK_Y, 3);
					checkboard_gen_knight(locboard, checkboard, BKK_X, BKK_Y, 4);
					checkboard_gen_rook(locboard, checkboard, BQR_X, BQR_Y, 3);
					checkboard_gen_rook(locboard, checkboard, BKR_X, BKR_Y, 4);
					checkboard_gen_bishop(locboard, checkboard, BQB_X, BQB_Y, 3);
					checkboard_gen_bishop(locboard, checkboard, BKB_X, BKB_Y, 4);
					checkboard_gen_king(locboard, checkboard, BK_X, BK_Y);
					checkboard_gen_queen(locboard, checkboard, BQ_X, BQ_Y, 6);
					turn = 1;
				}
				if (valid == 0)
				{
					printf("Invalid Destination, Try Again\n");
					turn = 0;
				}
			}
			if ((locboard[init_x][init_y] == 0x02) || (locboard[init_x][init_y] == 0x07))		//white knight
			{
				valid = move_check_knight(checkboard, move_x, move_y, what_piece);
				if (valid == 1)
				{
					if (locboard[init_x][init_y] == 0x02)
					{
						WQK_X = move_x;
						WQK_Y = move_y;
					}
					if (locboard[init_x][init_y] == 0x07)
					{
						WKK_X = move_x;
						WKK_Y = move_y;
					}
					locboard[move_x][move_y] = locboard[init_x][init_y];
					locboard[init_x][init_y] = 0x00;
					for (i = 0; i < 8; i++)				//y refresh
					{
						for (j = 0; j < 8; j++)			//x refresh
						{
							checkboard[j][i] = 0x00;
						}
					}
					checkboard_gen_pawn(locboard, checkboard, WP1_X, WP1_Y, 1);
					checkboard_gen_pawn(locboard, checkboard, WP2_X, WP2_Y, 2);
					checkboard_gen_pawn(locboard, checkboard, WP3_X, WP3_Y, 3);
					checkboard_gen_pawn(locboard, checkboard, WP4_X, WP4_Y, 4);
					checkboard_gen_pawn(locboard, checkboard, WP5_X, WP5_Y, 5);
					checkboard_gen_pawn(locboard, checkboard, WP6_X, WP6_Y, 6);
					checkboard_gen_pawn(locboard, checkboard, WP7_X, WP7_X, 7);
					checkboard_gen_pawn(locboard, checkboard, WP8_X, WP8_X, 8);
					checkboard_gen_knight(locboard, checkboard, WQK_X, WQK_Y, 1);
					checkboard_gen_knight(locboard, checkboard, WKK_X, WKK_Y, 2);
					checkboard_gen_rook(locboard, checkboard, WQR_X, WQR_Y, 1);
					checkboard_gen_rook(locboard, checkboard, WKR_X, WKR_Y, 2);
					checkboard_gen_bishop(locboard, checkboard, WQB_X, WQB_Y, 1);
					checkboard_gen_bishop(locboard, checkboard, WKB_X, WKB_Y, 2);
					checkboard_gen_king(locboard, checkboard, WK_X, WK_Y);
					checkboard_gen_queen(locboard, checkboard, WQ_X, WQ_Y, 5);

					checkboard_gen_pawn(locboard, checkboard, BP1_X, BP1_Y, 9);
					checkboard_gen_pawn(locboard, checkboard, BP2_X, BP2_Y, 10);
					checkboard_gen_pawn(locboard, checkboard, BP3_X, BP3_Y, 11);
					checkboard_gen_pawn(locboard, checkboard, BP4_X, BP4_Y, 12);
					checkboard_gen_pawn(locboard, checkboard, BP5_X, BP5_Y, 13);
					checkboard_gen_pawn(locboard, checkboard, BP6_X, BP6_Y, 14);
					checkboard_gen_pawn(locboard, checkboard, BP7_X, BP7_Y, 15);
					checkboard_gen_pawn(locboard, checkboard, BP8_X, BP8_Y, 16);
					checkboard_gen_knight(locboard, checkboard, BQK_X, BQK_Y, 3);
					checkboard_gen_knight(locboard, checkboard, BKK_X, BKK_Y, 4);
					checkboard_gen_rook(locboard, checkboard, BQR_X, BQR_Y, 3);
					checkboard_gen_rook(locboard, checkboard, BKR_X, BKR_Y, 4);
					checkboard_gen_bishop(locboard, checkboard, BQB_X, BQB_Y, 3);
					checkboard_gen_bishop(locboard, checkboard, BKB_X, BKB_Y, 4);
					checkboard_gen_king(locboard, checkboard, BK_X, BK_Y);
					checkboard_gen_queen(locboard, checkboard, BQ_X, BQ_Y, 6);
					turn = 1;
				}
				if (valid == 0)
				{
					printf("Invalid Destination, Try Again\n");
					turn = 0;
				}
			}
			if ((locboard[init_x][init_y] == 0x01) || (locboard[init_x][init_y] == 0x08))		//white rook
			{
				valid = move_check_rook(checkboard, move_x, move_y, what_piece);
				if (valid == 1)
				{
					if (locboard[init_x][init_y] == 0x01)
					{
						WQR_X = move_x;
						WQR_Y = move_y;
					}
					if (locboard[init_x][init_y] == 0x08)
					{
						WKR_X = move_x;
						WKR_Y = move_y;
					}
					locboard[move_x][move_y] = locboard[init_x][init_y];
					locboard[init_x][init_y] = 0x00;
					for (i = 0; i < 8; i++)				//y refresh
					{
						for (j = 0; j < 8; j++)			//x refresh
						{
							checkboard[j][i] = 0x00;
						}
					}
					checkboard_gen_pawn(locboard, checkboard, WP1_X, WP1_Y, 1);
					checkboard_gen_pawn(locboard, checkboard, WP2_X, WP2_Y, 2);
					checkboard_gen_pawn(locboard, checkboard, WP3_X, WP3_Y, 3);
					checkboard_gen_pawn(locboard, checkboard, WP4_X, WP4_Y, 4);
					checkboard_gen_pawn(locboard, checkboard, WP5_X, WP5_Y, 5);
					checkboard_gen_pawn(locboard, checkboard, WP6_X, WP6_Y, 6);
					checkboard_gen_pawn(locboard, checkboard, WP7_X, WP7_Y, 7);
					checkboard_gen_pawn(locboard, checkboard, WP8_X, WP8_Y, 8);
					checkboard_gen_knight(locboard, checkboard, WQK_X, WQK_Y, 1);
					checkboard_gen_knight(locboard, checkboard, WKK_X, WKK_Y, 2);
					checkboard_gen_rook(locboard, checkboard, WQR_X, WQR_Y, 1);
					checkboard_gen_rook(locboard, checkboard, WKR_X, WKR_Y, 2);
					checkboard_gen_bishop(locboard, checkboard, WQB_X, WQB_Y, 1);
					checkboard_gen_bishop(locboard, checkboard, WKB_X, WKB_Y, 2);
					checkboard_gen_king(locboard, checkboard, WK_X, WK_Y);
					checkboard_gen_queen(locboard, checkboard, WQ_X, WQ_Y, 5);

					checkboard_gen_pawn(locboard, checkboard, BP1_X, BP1_Y, 9);
					checkboard_gen_pawn(locboard, checkboard, BP2_X, BP2_Y, 10);
					checkboard_gen_pawn(locboard, checkboard, BP3_X, BP3_Y, 11);
					checkboard_gen_pawn(locboard, checkboard, BP4_X, BP4_Y, 12);
					checkboard_gen_pawn(locboard, checkboard, BP5_X, BP5_Y, 13);
					checkboard_gen_pawn(locboard, checkboard, BP6_X, BP6_Y, 14);
					checkboard_gen_pawn(locboard, checkboard, BP7_X, BP7_Y, 15);
					checkboard_gen_pawn(locboard, checkboard, BP8_X, BP8_Y, 16);
					checkboard_gen_knight(locboard, checkboard, BQK_X, BQK_Y, 3);
					checkboard_gen_knight(locboard, checkboard, BKK_X, BKK_Y, 4);
					checkboard_gen_rook(locboard, checkboard, BQR_X, BQR_Y, 3);
					checkboard_gen_rook(locboard, checkboard, BKR_X, BKR_Y, 4);
					checkboard_gen_bishop(locboard, checkboard, BQB_X, BQB_Y, 3);
					checkboard_gen_bishop(locboard, checkboard, BKB_X, BKB_Y, 4);
					checkboard_gen_king(locboard, checkboard, BK_X, BK_Y);
					checkboard_gen_queen(locboard, checkboard, BQ_X, BQ_Y, 6);
					turn = 1;
				}
				if (valid == 0)
				{
					printf("Invalid Destination, Try Again\n");
					turn = 0;
				}
			}
			if ((locboard[init_x][init_y] == 0x03) || (locboard[init_x][init_y] == 0x06))		//white bishop
			{
				valid = move_check_bishop(checkboard, move_x, move_y, what_piece);
				if (valid == 1)
				{
					if (locboard[init_x][init_y] == 0x03)
					{
						WQB_X = move_x;
						WQB_Y = move_y;
					}
					if (locboard[init_x][init_y] == 0x06)
					{
						WKB_X = move_x;
						WKB_Y = move_y;
					}
					locboard[move_x][move_y] = locboard[init_x][init_y];
					locboard[init_x][init_y] = 0x00;
					for (i = 0; i < 8; i++)				//y refresh
					{
						for (j = 0; j < 8; j++)			//x refresh
						{
							checkboard[j][i] = 0x00;
						}
					}
					checkboard_gen_pawn(locboard, checkboard, WP1_X, WP1_Y, 1);
					checkboard_gen_pawn(locboard, checkboard, WP2_X, WP2_Y, 2);
					checkboard_gen_pawn(locboard, checkboard, WP3_X, WP3_Y, 3);
					checkboard_gen_pawn(locboard, checkboard, WP4_X, WP4_Y, 4);
					checkboard_gen_pawn(locboard, checkboard, WP5_X, WP5_Y, 5);
					checkboard_gen_pawn(locboard, checkboard, WP6_X, WP6_Y, 6);
					checkboard_gen_pawn(locboard, checkboard, WP7_X, WP7_Y, 7);
					checkboard_gen_pawn(locboard, checkboard, WP8_X, WP8_Y, 8);
					checkboard_gen_knight(locboard, checkboard, WQK_X, WQK_Y, 1);
					checkboard_gen_knight(locboard, checkboard, WKK_X, WKK_Y, 2);
					checkboard_gen_rook(locboard, checkboard, WQR_X, WQR_Y, 1);
					checkboard_gen_rook(locboard, checkboard, WKR_X, WKR_Y, 2);
					checkboard_gen_bishop(locboard, checkboard, WQB_X, WQB_Y, 1);
					checkboard_gen_bishop(locboard, checkboard, WKB_X, WKB_Y, 2);
					checkboard_gen_king(locboard, checkboard, WK_X, WK_Y);
					checkboard_gen_queen(locboard, checkboard, WQ_X, WQ_Y, 5);

					checkboard_gen_pawn(locboard, checkboard, BP1_X, BP1_Y, 9);
					checkboard_gen_pawn(locboard, checkboard, BP2_X, BP2_Y, 10);
					checkboard_gen_pawn(locboard, checkboard, BP3_X, BP3_Y, 11);
					checkboard_gen_pawn(locboard, checkboard, BP4_X, BP4_Y, 12);
					checkboard_gen_pawn(locboard, checkboard, BP5_X, BP5_Y, 13);
					checkboard_gen_pawn(locboard, checkboard, BP6_X, BP6_Y, 14);
					checkboard_gen_pawn(locboard, checkboard, BP7_X, BP7_Y, 15);
					checkboard_gen_pawn(locboard, checkboard, BP8_X, BP8_Y, 16);
					checkboard_gen_knight(locboard, checkboard, BQK_X, BQK_Y, 3);
					checkboard_gen_knight(locboard, checkboard, BKK_X, BKK_Y, 4);
					checkboard_gen_rook(locboard, checkboard, BQR_X, BQR_Y, 3);
					checkboard_gen_rook(locboard, checkboard, BKR_X, BKR_Y, 4);
					checkboard_gen_bishop(locboard, checkboard, BQB_X, BQB_Y, 3);
					checkboard_gen_bishop(locboard, checkboard, BKB_X, BKB_Y, 4);
					checkboard_gen_king(locboard, checkboard, BK_X, BK_Y);
					checkboard_gen_queen(locboard, checkboard, BQ_X, BQ_Y, 6);
					turn = 1;
				}
				if (valid == 0)
				{
					printf("Invalid Destination, Try Again\n");
					turn = 0;
				}
			}
			if (locboard[init_x][init_y] == 0x04)		//white queen
			{
				valid = move_check_rook(checkboard, move_x, move_y, what_piece);
				if (valid == 1)
				{
					WQ_X = move_x;
					WQ_Y = move_y;
					locboard[move_x][move_y] = locboard[init_x][init_y];
					locboard[init_x][init_y] = 0x00;
					for (i = 0; i < 8; i++)				//y refresh
					{
						for (j = 0; j < 8; j++)			//x refresh
						{
							checkboard[j][i] = 0x00;
						}
					}
					checkboard_gen_pawn(locboard, checkboard, WP1_X, WP1_Y, 1);
					checkboard_gen_pawn(locboard, checkboard, WP2_X, WP2_Y, 2);
					checkboard_gen_pawn(locboard, checkboard, WP3_X, WP3_Y, 3);
					checkboard_gen_pawn(locboard, checkboard, WP4_X, WP4_Y, 4);
					checkboard_gen_pawn(locboard, checkboard, WP5_X, WP5_Y, 5);
					checkboard_gen_pawn(locboard, checkboard, WP6_X, WP6_Y, 6);
					checkboard_gen_pawn(locboard, checkboard, WP7_X, WP7_Y, 7);
					checkboard_gen_pawn(locboard, checkboard, WP8_X, WP8_Y, 8);
					checkboard_gen_knight(locboard, checkboard, WQK_X, WQK_Y, 1);
					checkboard_gen_knight(locboard, checkboard, WKK_X, WKK_Y, 2);
					checkboard_gen_rook(locboard, checkboard, WQR_X, WQR_Y, 1);
					checkboard_gen_rook(locboard, checkboard, WKR_X, WKR_Y, 2);
					checkboard_gen_bishop(locboard, checkboard, WQB_X, WQB_Y, 1);
					checkboard_gen_bishop(locboard, checkboard, WKB_X, WKB_Y, 2);
					checkboard_gen_king(locboard, checkboard, WK_X, WK_Y);
					checkboard_gen_queen(locboard, checkboard, WQ_X, WQ_Y, 5);

					checkboard_gen_pawn(locboard, checkboard, BP1_X, BP1_Y, 9);
					checkboard_gen_pawn(locboard, checkboard, BP2_X, BP2_Y, 10);
					checkboard_gen_pawn(locboard, checkboard, BP3_X, BP3_Y, 11);
					checkboard_gen_pawn(locboard, checkboard, BP4_X, BP4_Y, 12);
					checkboard_gen_pawn(locboard, checkboard, BP5_X, BP5_Y, 13);
					checkboard_gen_pawn(locboard, checkboard, BP6_X, BP6_Y, 14);
					checkboard_gen_pawn(locboard, checkboard, BP7_X, BP7_Y, 15);
					checkboard_gen_pawn(locboard, checkboard, BP8_X, BP8_Y, 16);
					checkboard_gen_knight(locboard, checkboard, BQK_X, BQK_Y, 3);
					checkboard_gen_knight(locboard, checkboard, BKK_X, BKK_Y, 4);
					checkboard_gen_rook(locboard, checkboard, BQR_X, BQR_Y, 3);
					checkboard_gen_rook(locboard, checkboard, BKR_X, BKR_Y, 4);
					checkboard_gen_bishop(locboard, checkboard, BQB_X, BQB_Y, 3);
					checkboard_gen_bishop(locboard, checkboard, BKB_X, BKB_Y, 4);
					checkboard_gen_king(locboard, checkboard, BK_X, BK_Y);
					checkboard_gen_queen(locboard, checkboard, BQ_X, BQ_Y, 6);
					turn = 1;
				}
				if (valid == 0)
				{
					printf("Invalid Destination, Try Again\n");
					turn = 0;
				}
			}
			if (locboard[init_x][init_y] == 0x04)		//white king
			{
				valid = move_check_king(locboard, checkboard, move_x, move_y, WK_X, WK_Y);
				if (valid == 1)
				{
					WK_X = move_x;
					WK_Y = move_y;
					locboard[move_x][move_y] = locboard[init_x][init_y];
					locboard[init_x][init_y] = 0x00;
					for (i = 0; i < 8; i++)				//y refresh
					{
						for (j = 0; j < 8; j++)			//x refresh
						{
							checkboard[j][i] = 0x00;
						}
					}
					checkboard_gen_pawn(locboard, checkboard, WP1_X, WP1_Y, 1);
					checkboard_gen_pawn(locboard, checkboard, WP2_X, WP2_Y, 2);
					checkboard_gen_pawn(locboard, checkboard, WP3_X, WP3_Y, 3);
					checkboard_gen_pawn(locboard, checkboard, WP4_X, WP4_Y, 4);
					checkboard_gen_pawn(locboard, checkboard, WP5_X, WP5_Y, 5);
					checkboard_gen_pawn(locboard, checkboard, WP6_X, WP6_Y, 6);
					checkboard_gen_pawn(locboard, checkboard, WP7_X, WP7_Y, 7);
					checkboard_gen_pawn(locboard, checkboard, WP8_X, WP8_Y, 8);
					checkboard_gen_knight(locboard, checkboard, WQK_X, WQK_Y, 1);
					checkboard_gen_knight(locboard, checkboard, WKK_X, WKK_Y, 2);
					checkboard_gen_rook(locboard, checkboard, WQR_X, WQR_Y, 1);
					checkboard_gen_rook(locboard, checkboard, WKR_X, WKR_Y, 2);
					checkboard_gen_bishop(locboard, checkboard, WQB_X, WQB_Y, 1);
					checkboard_gen_bishop(locboard, checkboard, WKB_X, WKB_Y, 2);
					checkboard_gen_king(locboard, checkboard, WK_X, WK_Y);
					checkboard_gen_queen(locboard, checkboard, WQ_X, WQ_Y, 5);

					checkboard_gen_pawn(locboard, checkboard, BP1_X, BP1_Y, 9);
					checkboard_gen_pawn(locboard, checkboard, BP2_X, BP2_Y, 10);
					checkboard_gen_pawn(locboard, checkboard, BP3_X, BP3_Y, 11);
					checkboard_gen_pawn(locboard, checkboard, BP4_X, BP4_Y, 12);
					checkboard_gen_pawn(locboard, checkboard, BP5_X, BP5_Y, 13);
					checkboard_gen_pawn(locboard, checkboard, BP6_X, BP6_Y, 14);
					checkboard_gen_pawn(locboard, checkboard, BP7_X, BP7_Y, 15);
					checkboard_gen_pawn(locboard, checkboard, BP8_X, BP8_Y, 16);
					checkboard_gen_knight(locboard, checkboard, BQK_X, BQK_Y, 3);
					checkboard_gen_knight(locboard, checkboard, BKK_X, BKK_Y, 4);
					checkboard_gen_rook(locboard, checkboard, BQR_X, BQR_Y, 3);
					checkboard_gen_rook(locboard, checkboard, BKR_X, BKR_Y, 4);
					checkboard_gen_bishop(locboard, checkboard, BQB_X, BQB_Y, 3);
					checkboard_gen_bishop(locboard, checkboard, BKB_X, BKB_Y, 4);
					checkboard_gen_king(locboard, checkboard, BK_X, BK_Y);
					checkboard_gen_queen(locboard, checkboard, BQ_X, BQ_Y, 6);
					turn = 1;
				}
				if (valid == 0)
				{
					printf("Invalid Destination, Try Again\n");
					turn = 0;
				}
			}
			print_board(locboard);
		}
		//Black Turn
		if (turn == 1)
		{
			init_x = 0;
			init_y = 0;
			move_x = 0;
			move_y = 0;
			printf("Black Turn: Select Piece and Destination\n");
			scanf("%d %d %d %d", &init_x, &init_y, &move_x, &move_y);
			what_piece = select_piece(locboard, init_x, init_y);
			while ((locboard[init_x][init_y] == 0) || (locboard[init_x][init_y] < 0x11))
			{
				printf("Invalid Selection, Please Try Again!\n");
				scanf("%d %d %d %d", &init_x, &init_y, &move_x, &move_y);
			}
			if ((locboard[init_x][init_y] > 0x18) && (locboard[init_x][init_y] < 0x21))			//black pawn
			{
				valid = move_check_pawn(checkboard, move_x, move_y, what_piece);
				if (valid == 1)
				{
					if (locboard[init_x][init_y] == 0x19)
					{
						BP1_X = move_x;
						BP1_Y = move_y;
					}
					if (locboard[init_x][init_y] == 0x1A)
					{
						BP2_X = move_x;
						BP2_Y = move_y;
					}
					if (locboard[init_x][init_y] == 0x1B)
					{
						BP3_X = move_x;
						BP3_Y = move_y;
					}
					if (locboard[init_x][init_y] == 0x1C)
					{
						BP4_X = move_x;
						BP4_Y = move_y;
					}
					if (locboard[init_x][init_y] == 0x1D)
					{
						BP5_X = move_x;
						BP5_Y = move_y;
					}
					if (locboard[init_x][init_y] == 0x1E)
					{
						BP6_X = move_x;
						BP6_Y = move_y;
					}
					if (locboard[init_x][init_y] == 0x1F)
					{
						BP7_X = move_x;
						BP7_Y = move_y;
					}
					if (locboard[init_x][init_y] == 0x20)
					{
						BP8_X = move_x;
						BP8_Y = move_y;
					}
					locboard[move_x][move_y] = locboard[init_x][init_y];
					locboard[init_x][init_y] = 0x00;
					turn = 1;
					for (i = 0; i < 8; i++)				//y refresh
					{
						for (j = 0; j < 8; j++)			//x refresh
						{
							checkboard[j][i] = 0x00;
						}
					}
					checkboard_gen_pawn(locboard, checkboard, WP1_X, WP1_Y, 1);
					checkboard_gen_pawn(locboard, checkboard, WP2_X, WP2_Y, 2);
					checkboard_gen_pawn(locboard, checkboard, WP3_X, WP3_Y, 3);
					checkboard_gen_pawn(locboard, checkboard, WP4_X, WP4_Y, 4);
					checkboard_gen_pawn(locboard, checkboard, WP5_X, WP5_Y, 5);
					checkboard_gen_pawn(locboard, checkboard, WP6_X, WP6_Y, 6);
					checkboard_gen_pawn(locboard, checkboard, WP7_X, WP7_Y, 7);
					checkboard_gen_pawn(locboard, checkboard, WP8_X, WP8_Y, 8);
					checkboard_gen_knight(locboard, checkboard, WQK_X, WQK_Y, 1);
					checkboard_gen_knight(locboard, checkboard, WKK_X, WKK_Y, 2);
					checkboard_gen_rook(locboard, checkboard, WQR_X, WQR_Y, 1);
					checkboard_gen_rook(locboard, checkboard, WKR_X, WKR_Y, 2);
					checkboard_gen_bishop(locboard, checkboard, WQB_X, WQB_Y, 1);
					checkboard_gen_bishop(locboard, checkboard, WKB_X, WKB_Y, 2);
					checkboard_gen_king(locboard, checkboard, WK_X, WK_Y);
					checkboard_gen_queen(locboard, checkboard, WQ_X, WQ_Y, 5);

					checkboard_gen_pawn(locboard, checkboard, BP1_X, BP1_Y, 9);
					checkboard_gen_pawn(locboard, checkboard, BP2_X, BP2_Y, 10);
					checkboard_gen_pawn(locboard, checkboard, BP3_X, BP3_Y, 11);
					checkboard_gen_pawn(locboard, checkboard, BP4_X, BP4_Y, 12);
					checkboard_gen_pawn(locboard, checkboard, BP5_X, BP5_Y, 13);
					checkboard_gen_pawn(locboard, checkboard, BP6_X, BP6_Y, 14);
					checkboard_gen_pawn(locboard, checkboard, BP7_X, BP7_Y, 15);
					checkboard_gen_pawn(locboard, checkboard, BP8_X, BP8_Y, 16);
					checkboard_gen_knight(locboard, checkboard, BQK_X, BQK_Y, 3);
					checkboard_gen_knight(locboard, checkboard, BKK_X, BKK_Y, 4);
					checkboard_gen_rook(locboard, checkboard, BQR_X, BQR_Y, 3);
					checkboard_gen_rook(locboard, checkboard, BKR_X, BKR_Y, 4);
					checkboard_gen_bishop(locboard, checkboard, BQB_X, BQB_Y, 3);
					checkboard_gen_bishop(locboard, checkboard, BKB_X, BKB_Y, 4);
					checkboard_gen_king(locboard, checkboard, BK_X, BK_Y);
					checkboard_gen_queen(locboard, checkboard, BQ_X, BQ_Y, 6);
					turn = 0;
				}
				if (valid == 0)
				{
					printf("Invalid Destination, Try Again\n");
					turn = 1;
				}
			}
			if ((locboard[init_x][init_y] == 0x12) || (locboard[init_x][init_y] == 0x17))		//black knight
			{
				valid = move_check_knight(checkboard, move_x, move_y, what_piece);
				if (valid == 1)
				{
					if (locboard[init_x][init_y] == 0x12)
					{
						BQK_X = move_x;
						BQK_Y = move_y;
					}
					if (locboard[init_x][init_y] == 0x17)
					{
						BKK_X = move_x;
						BKK_Y = move_y;
					}
					locboard[move_x][move_y] = locboard[init_x][init_y];
					locboard[init_x][init_y] = 0x00;
					turn = 1;
					for (i = 0; i < 8; i++)				//y refresh
					{
						for (j = 0; j < 8; j++)			//x refresh
						{
							checkboard[j][i] = 0x00;
						}
					}
					checkboard_gen_pawn(locboard, checkboard, WP1_X, WP1_Y, 1);
					checkboard_gen_pawn(locboard, checkboard, WP2_X, WP2_Y, 2);
					checkboard_gen_pawn(locboard, checkboard, WP3_X, WP3_Y, 3);
					checkboard_gen_pawn(locboard, checkboard, WP4_X, WP4_Y, 4);
					checkboard_gen_pawn(locboard, checkboard, WP5_X, WP5_Y, 5);
					checkboard_gen_pawn(locboard, checkboard, WP6_X, WP6_Y, 6);
					checkboard_gen_pawn(locboard, checkboard, WP7_X, WP7_Y, 7);
					checkboard_gen_pawn(locboard, checkboard, WP8_X, WP8_Y, 8);
					checkboard_gen_knight(locboard, checkboard, WQK_X, WQK_Y, 1);
					checkboard_gen_knight(locboard, checkboard, WKK_X, WKK_Y, 2);
					checkboard_gen_rook(locboard, checkboard, WQR_X, WQR_Y, 1);
					checkboard_gen_rook(locboard, checkboard, WKR_X, WKR_Y, 2);
					checkboard_gen_bishop(locboard, checkboard, WQB_X, WQB_Y, 1);
					checkboard_gen_bishop(locboard, checkboard, WKB_X, WKB_Y, 2);
					checkboard_gen_king(locboard, checkboard, WK_X, WK_Y);
					checkboard_gen_queen(locboard, checkboard, WQ_X, WQ_Y, 5);

					checkboard_gen_pawn(locboard, checkboard, BP1_X, BP1_Y, 9);
					checkboard_gen_pawn(locboard, checkboard, BP2_X, BP2_Y, 10);
					checkboard_gen_pawn(locboard, checkboard, BP3_X, BP3_Y, 11);
					checkboard_gen_pawn(locboard, checkboard, BP4_X, BP4_Y, 12);
					checkboard_gen_pawn(locboard, checkboard, BP5_X, BP5_Y, 13);
					checkboard_gen_pawn(locboard, checkboard, BP6_X, BP6_Y, 14);
					checkboard_gen_pawn(locboard, checkboard, BP7_X, BP7_Y, 15);
					checkboard_gen_pawn(locboard, checkboard, BP8_X, BP8_Y, 16);
					checkboard_gen_knight(locboard, checkboard, BQK_X, BQK_Y, 3);
					checkboard_gen_knight(locboard, checkboard, BKK_X, BKK_Y, 4);
					checkboard_gen_rook(locboard, checkboard, BQR_X, BQR_Y, 3);
					checkboard_gen_rook(locboard, checkboard, BKR_X, BKR_Y, 4);
					checkboard_gen_bishop(locboard, checkboard, BQB_X, BQB_Y, 3);
					checkboard_gen_bishop(locboard, checkboard, BKB_X, BKB_Y, 4);
					checkboard_gen_king(locboard, checkboard, BK_X, BK_Y);
					checkboard_gen_queen(locboard, checkboard, BQ_X, BQ_Y, 6);
					turn = 0;
				}
				if (valid == 0)
				{
					printf("Invalid Destination, Try Again\n");
					turn = 1;
				}
			}
			if ((locboard[init_x][init_y] == 0x11) || (locboard[init_x][init_y] == 0x18))		//black rook
			{
				valid = move_check_rook(checkboard, move_x, move_y, what_piece);
				if (valid == 1)
				{
					if (locboard[init_x][init_y] == 0x11)
					{
						BQR_X = move_x;
						BQR_Y = move_y;
					}
					if (locboard[init_x][init_y] == 0x18)
					{
						BKR_X = move_x;
						BKR_Y = move_y;
					}
					locboard[move_x][move_y] = locboard[init_x][init_y];
					locboard[init_x][init_y] = 0x00;
					for (i = 0; i < 8; i++)				//y refresh
					{
						for (j = 0; j < 8; j++)			//x refresh
						{
							checkboard[j][i] = 0x00;
						}
					}
					checkboard_gen_pawn(locboard, checkboard, WP1_X, WP1_Y, 1);
					checkboard_gen_pawn(locboard, checkboard, WP2_X, WP2_Y, 2);
					checkboard_gen_pawn(locboard, checkboard, WP3_X, WP3_Y, 3);
					checkboard_gen_pawn(locboard, checkboard, WP4_X, WP4_Y, 4);
					checkboard_gen_pawn(locboard, checkboard, WP5_X, WP5_Y, 5);
					checkboard_gen_pawn(locboard, checkboard, WP6_X, WP6_Y, 6);
					checkboard_gen_pawn(locboard, checkboard, WP7_X, WP7_X, 7);
					checkboard_gen_pawn(locboard, checkboard, WP8_X, WP8_X, 8);
					checkboard_gen_knight(locboard, checkboard, WQK_X, WQK_Y, 1);
					checkboard_gen_knight(locboard, checkboard, WKK_X, WKK_Y, 2);
					checkboard_gen_rook(locboard, checkboard, WQR_X, WQR_Y, 1);
					checkboard_gen_rook(locboard, checkboard, WKR_X, WKR_Y, 2);
					checkboard_gen_bishop(locboard, checkboard, WQB_X, WQB_Y, 1);
					checkboard_gen_bishop(locboard, checkboard, WKB_X, WKB_Y, 2);
					checkboard_gen_king(locboard, checkboard, WK_X, WK_Y);
					checkboard_gen_queen(locboard, checkboard, WQ_X, WQ_Y, 5);

					checkboard_gen_pawn(locboard, checkboard, BP1_X, BP1_Y, 9);
					checkboard_gen_pawn(locboard, checkboard, BP2_X, BP2_Y, 10);
					checkboard_gen_pawn(locboard, checkboard, BP3_X, BP3_Y, 11);
					checkboard_gen_pawn(locboard, checkboard, BP4_X, BP4_Y, 12);
					checkboard_gen_pawn(locboard, checkboard, BP5_X, BP5_Y, 13);
					checkboard_gen_pawn(locboard, checkboard, BP6_X, BP6_Y, 14);
					checkboard_gen_pawn(locboard, checkboard, BP7_X, BP7_Y, 15);
					checkboard_gen_pawn(locboard, checkboard, BP8_X, BP8_Y, 16);
					checkboard_gen_knight(locboard, checkboard, BQK_X, BQK_Y, 3);
					checkboard_gen_knight(locboard, checkboard, BKK_X, BKK_Y, 4);
					checkboard_gen_rook(locboard, checkboard, BQR_X, BQR_Y, 3);
					checkboard_gen_rook(locboard, checkboard, BKR_X, BKR_Y, 4);
					checkboard_gen_bishop(locboard, checkboard, BQB_X, BQB_Y, 3);
					checkboard_gen_bishop(locboard, checkboard, BKB_X, BKB_Y, 4);
					checkboard_gen_king(locboard, checkboard, BK_X, BK_Y);
					checkboard_gen_queen(locboard, checkboard, BQ_X, BQ_Y, 6);
					turn = 0;
				}
				if (valid == 0)
				{
					printf("Invalid Destination, Try Again\n");
					turn = 1;
				}
			}
			if ((locboard[init_x][init_y] == 0x13) || (locboard[init_x][init_y] == 0x16))		//black bishop
			{
				valid = move_check_bishop(checkboard, move_x, move_y, what_piece);
				if (valid == 1)
				{
					if (locboard[init_x][init_y] == 0x13)
					{
						BQB_X = move_x;
						BQB_Y = move_y;
					}
					if (locboard[init_x][init_y] == 0x16)
					{
						BKB_X = move_x;
						BKB_Y = move_y;
					}
					locboard[move_x][move_y] = locboard[init_x][init_y];
					locboard[init_x][init_y] = 0x00;
					for (i = 0; i < 8; i++)				//y refresh
					{
						for (j = 0; j < 8; j++)			//x refresh
						{
							checkboard[j][i] = 0x00;
						}
					}
					checkboard_gen_pawn(locboard, checkboard, WP1_X, WP1_Y, 1);
					checkboard_gen_pawn(locboard, checkboard, WP2_X, WP2_Y, 2);
					checkboard_gen_pawn(locboard, checkboard, WP3_X, WP3_Y, 3);
					checkboard_gen_pawn(locboard, checkboard, WP4_X, WP4_Y, 4);
					checkboard_gen_pawn(locboard, checkboard, WP5_X, WP5_Y, 5);
					checkboard_gen_pawn(locboard, checkboard, WP6_X, WP6_Y, 6);
					checkboard_gen_pawn(locboard, checkboard, WP7_X, WP7_X, 7);
					checkboard_gen_pawn(locboard, checkboard, WP8_X, WP8_X, 8);
					checkboard_gen_knight(locboard, checkboard, WQK_X, WQK_Y, 1);
					checkboard_gen_knight(locboard, checkboard, WKK_X, WKK_Y, 2);
					checkboard_gen_rook(locboard, checkboard, WQR_X, WQR_Y, 1);
					checkboard_gen_rook(locboard, checkboard, WKR_X, WKR_Y, 2);
					checkboard_gen_bishop(locboard, checkboard, WQB_X, WQB_Y, 1);
					checkboard_gen_bishop(locboard, checkboard, WKB_X, WKB_Y, 2);
					checkboard_gen_king(locboard, checkboard, WK_X, WK_Y);
					checkboard_gen_queen(locboard, checkboard, WQ_X, WQ_Y, 5);

					checkboard_gen_pawn(locboard, checkboard, BP1_X, BP1_Y, 9);
					checkboard_gen_pawn(locboard, checkboard, BP2_X, BP2_Y, 10);
					checkboard_gen_pawn(locboard, checkboard, BP3_X, BP3_Y, 11);
					checkboard_gen_pawn(locboard, checkboard, BP4_X, BP4_Y, 12);
					checkboard_gen_pawn(locboard, checkboard, BP5_X, BP5_Y, 13);
					checkboard_gen_pawn(locboard, checkboard, BP6_X, BP6_Y, 14);
					checkboard_gen_pawn(locboard, checkboard, BP7_X, BP7_Y, 15);
					checkboard_gen_pawn(locboard, checkboard, BP8_X, BP8_Y, 16);
					checkboard_gen_knight(locboard, checkboard, BQK_X, BQK_Y, 3);
					checkboard_gen_knight(locboard, checkboard, BKK_X, BKK_Y, 4);
					checkboard_gen_rook(locboard, checkboard, BQR_X, BQR_Y, 3);
					checkboard_gen_rook(locboard, checkboard, BKR_X, BKR_Y, 4);
					checkboard_gen_bishop(locboard, checkboard, BQB_X, BQB_Y, 3);
					checkboard_gen_bishop(locboard, checkboard, BKB_X, BKB_Y, 4);
					checkboard_gen_king(locboard, checkboard, BK_X, BK_Y);
					checkboard_gen_queen(locboard, checkboard, BQ_X, BQ_Y, 6);
					turn = 0;
				}
				if (valid == 0)
				{
					printf("Invalid Destination, Try Again\n");
					turn = 1;
				}
			}
			if (locboard[init_x][init_y] == 0x14)		//black queen
			{
				valid = move_check_queen(checkboard, move_x, move_y, what_piece);
				if (valid == 1)
				{
					BQ_X = move_x;
					BQ_Y = move_y;
					locboard[move_x][move_y] = locboard[init_x][init_y];
					locboard[init_x][init_y] = 0x00;
					for (i = 0; i < 8; i++)				//y refresh
					{
						for (j = 0; j < 8; j++)			//x refresh
						{
							checkboard[j][i] = 0x00;
						}
					}
					checkboard_gen_pawn(locboard, checkboard, WP1_X, WP1_Y, 1);
					checkboard_gen_pawn(locboard, checkboard, WP2_X, WP2_Y, 2);
					checkboard_gen_pawn(locboard, checkboard, WP3_X, WP3_Y, 3);
					checkboard_gen_pawn(locboard, checkboard, WP4_X, WP4_Y, 4);
					checkboard_gen_pawn(locboard, checkboard, WP5_X, WP5_Y, 5);
					checkboard_gen_pawn(locboard, checkboard, WP6_X, WP6_Y, 6);
					checkboard_gen_pawn(locboard, checkboard, WP7_X, WP7_X, 7);
					checkboard_gen_pawn(locboard, checkboard, WP8_X, WP8_X, 8);
					checkboard_gen_knight(locboard, checkboard, WQK_X, WQK_Y, 1);
					checkboard_gen_knight(locboard, checkboard, WKK_X, WKK_Y, 2);
					checkboard_gen_rook(locboard, checkboard, WQR_X, WQR_Y, 1);
					checkboard_gen_rook(locboard, checkboard, WKR_X, WKR_Y, 2);
					checkboard_gen_bishop(locboard, checkboard, WQB_X, WQB_Y, 1);
					checkboard_gen_bishop(locboard, checkboard, WKB_X, WKB_Y, 2);
					checkboard_gen_king(locboard, checkboard, WK_X, WK_Y);
					checkboard_gen_queen(locboard, checkboard, WQ_X, WQ_Y, 5);

					checkboard_gen_pawn(locboard, checkboard, BP1_X, BP1_Y, 9);
					checkboard_gen_pawn(locboard, checkboard, BP2_X, BP2_Y, 10);
					checkboard_gen_pawn(locboard, checkboard, BP3_X, BP3_Y, 11);
					checkboard_gen_pawn(locboard, checkboard, BP4_X, BP4_Y, 12);
					checkboard_gen_pawn(locboard, checkboard, BP5_X, BP5_Y, 13);
					checkboard_gen_pawn(locboard, checkboard, BP6_X, BP6_Y, 14);
					checkboard_gen_pawn(locboard, checkboard, BP7_X, BP7_Y, 15);
					checkboard_gen_pawn(locboard, checkboard, BP8_X, BP8_Y, 16);
					checkboard_gen_knight(locboard, checkboard, BQK_X, BQK_Y, 3);
					checkboard_gen_knight(locboard, checkboard, BKK_X, BKK_Y, 4);
					checkboard_gen_rook(locboard, checkboard, BQR_X, BQR_Y, 3);
					checkboard_gen_rook(locboard, checkboard, BKR_X, BKR_Y, 4);
					checkboard_gen_bishop(locboard, checkboard, BQB_X, BQB_Y, 3);
					checkboard_gen_bishop(locboard, checkboard, BKB_X, BKB_Y, 4);
					checkboard_gen_king(locboard, checkboard, BK_X, BK_Y);
					checkboard_gen_queen(locboard, checkboard, BQ_X, BQ_Y, 6);
					turn = 0;
				}
				if (valid == 0)
				{
					printf("Invalid Destination, Try Again\n");
					turn = 1;
				}
			}
			if (locboard[init_x][init_y] == 0x15)		//black king
			{
				valid = move_check_king(locboard, checkboard, move_x, move_y, BK_X, BK_Y);
				if (valid == 1)
				{
					BK_X = move_x;
					BK_Y = move_y;
					locboard[move_x][move_y] = locboard[init_x][init_y];
					locboard[init_x][init_y] = 0x00;
					for (i = 0; i < 8; i++)				//y refresh
					{
						for (j = 0; j < 8; j++)			//x refresh
						{
							checkboard[j][i] = 0x00;
						}
					}
					checkboard_gen_pawn(locboard, checkboard, WP1_X, WP1_Y, 1);
					checkboard_gen_pawn(locboard, checkboard, WP2_X, WP2_Y, 2);
					checkboard_gen_pawn(locboard, checkboard, WP3_X, WP3_Y, 3);
					checkboard_gen_pawn(locboard, checkboard, WP4_X, WP4_Y, 4);
					checkboard_gen_pawn(locboard, checkboard, WP5_X, WP5_Y, 5);
					checkboard_gen_pawn(locboard, checkboard, WP6_X, WP6_Y, 6);
					checkboard_gen_pawn(locboard, checkboard, WP7_X, WP7_X, 7);
					checkboard_gen_pawn(locboard, checkboard, WP8_X, WP8_X, 8);
					checkboard_gen_knight(locboard, checkboard, WQK_X, WQK_Y, 1);
					checkboard_gen_knight(locboard, checkboard, WKK_X, WKK_Y, 2);
					checkboard_gen_rook(locboard, checkboard, WQR_X, WQR_Y, 1);
					checkboard_gen_rook(locboard, checkboard, WKR_X, WKR_Y, 2);
					checkboard_gen_bishop(locboard, checkboard, WQB_X, WQB_Y, 1);
					checkboard_gen_bishop(locboard, checkboard, WKB_X, WKB_Y, 2);
					checkboard_gen_king(locboard, checkboard, WK_X, WK_Y);
					checkboard_gen_queen(locboard, checkboard, WQ_X, WQ_Y, 5);

					checkboard_gen_pawn(locboard, checkboard, BP1_X, BP1_Y, 9);
					checkboard_gen_pawn(locboard, checkboard, BP2_X, BP2_Y, 10);
					checkboard_gen_pawn(locboard, checkboard, BP3_X, BP3_Y, 11);
					checkboard_gen_pawn(locboard, checkboard, BP4_X, BP4_Y, 12);
					checkboard_gen_pawn(locboard, checkboard, BP5_X, BP5_Y, 13);
					checkboard_gen_pawn(locboard, checkboard, BP6_X, BP6_Y, 14);
					checkboard_gen_pawn(locboard, checkboard, BP7_X, BP7_Y, 15);
					checkboard_gen_pawn(locboard, checkboard, BP8_X, BP8_Y, 16);
					checkboard_gen_knight(locboard, checkboard, BQK_X, BQK_Y, 3);
					checkboard_gen_knight(locboard, checkboard, BKK_X, BKK_Y, 4);
					checkboard_gen_rook(locboard, checkboard, BQR_X, BQR_Y, 3);
					checkboard_gen_rook(locboard, checkboard, BKR_X, BKR_Y, 4);
					checkboard_gen_bishop(locboard, checkboard, BQB_X, BQB_Y, 3);
					checkboard_gen_bishop(locboard, checkboard, BKB_X, BKB_Y, 4);
					checkboard_gen_king(locboard, checkboard, BK_X, BK_Y);
					checkboard_gen_queen(locboard, checkboard, BQ_X, BQ_Y, 6);
					turn = 0;
				}
				if (valid == 0)
				{
					printf("Invalid Destination, Try Again\n");
					turn = 1;
				}
			}
			print_board(locboard);
		}
	}
	return 0;
}
