/************************************************************************************/
/*Remember... if something is stupid and it works... it's not stupid.                */
/*Code Written by Lance Pan & Griffin Tucker Fall 2017                              */
/*For use in ECE385 Final Project                                                   */
/*The objective is simple... chess.                                                 */
/*The two travelers could not fathom the difficulty of the task laid ahead...       */
/************************************************************************************/


#include <stdlib.h>		//TO DO: check what other libraries we need/can use
#include <stdio.h>


void checkboard_gen_knight(unsigned char ** locboard_temp, unsigned char ** checkboard_rook_temp, unsigned long knight_pos_x, unsigned long knight_pos_y, unsigned long what_knight)
{
	int knight_track_x;															//local position tracker
	int knight_track_y;
	int knight_type;
	unsigned char checkboard_knight[8][8];
	unsigned char locboard[8][8];
	int i, j;
	for (i = 0; i < 8; i++)				//y initialization
	{
		for (j = 0; j < 8; j++)			//x initialization
		{
			locboard[j][i] = 0x00;
			checkboard_knight[j][i] = 0x00;
		}
	}
	knight_type = 1;
	//	locboard[3][2] = 5;
	if (locboard[knight_pos_x][knight_pos_y] <= 16)									//case for white piece
	{
		knight_track_y = knight_pos_y - 2;												//first L 
		knight_track_x = knight_pos_x - 1;
		if ((knight_track_y >= 0) && (knight_track_y < 9) && (knight_track_x >= 0) && (knight_track_x < 9) && ((locboard[knight_track_x][knight_track_y] > 16) || (locboard[knight_track_x][knight_track_y] == 0))) 					//checks whether position is on board
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] + knight_type;
		knight_track_x = knight_pos_x + 1;
		if ((knight_track_y >= 0) && (knight_track_y < 9) && (knight_track_x >= 0) && (knight_track_x < 9) && ((locboard[knight_track_x][knight_track_y] > 16) || (locboard[knight_track_x][knight_track_y] == 0)))
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] + knight_type;
		knight_track_y = knight_pos_y + 2;
		if ((knight_track_y >= 0) && (knight_track_y < 9) && (knight_track_x >= 0) && (knight_track_x < 9) && ((locboard[knight_track_x][knight_track_y] > 16) || (locboard[knight_track_x][knight_track_y] == 0)))
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] + knight_type;
		knight_track_x = knight_pos_x - 1;
		if ((knight_track_y >= 0) && (knight_track_y < 9) && (knight_track_x >= 0) && (knight_track_x < 9) && ((locboard[knight_track_x][knight_track_y] > 16) || (locboard[knight_track_x][knight_track_y] == 0)))
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] + knight_type;
		knight_track_x = knight_pos_x - 2;
		knight_track_y = knight_pos_y + 1;
		if ((knight_track_y >= 0) && (knight_track_y < 9) && (knight_track_x >= 0) && (knight_track_x < 9) && ((locboard[knight_track_x][knight_track_y] > 16) || (locboard[knight_track_x][knight_track_y] == 0)))
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] + knight_type;
		knight_track_y = knight_pos_y - 1;
		if ((knight_track_y >= 0) && (knight_track_y < 9) && (knight_track_x >= 0) && (knight_track_x < 9) && ((locboard[knight_track_x][knight_track_y] > 16) || (locboard[knight_track_x][knight_track_y] == 0)))
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] + knight_type;
		knight_track_x = knight_pos_x + 2;
		if ((knight_track_y >= 0) && (knight_track_y < 9) && (knight_track_x >= 0) && (knight_track_x < 9) && ((locboard[knight_track_x][knight_track_y] > 16) || (locboard[knight_track_x][knight_track_y] == 0)))
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] + knight_type;
		knight_track_y = knight_pos_y + 1;
		if ((knight_track_y >= 0) && (knight_track_y < 9) && (knight_track_x >= 0) && (knight_track_x < 9) && ((locboard[knight_track_x][knight_track_y] > 16) || (locboard[knight_track_x][knight_track_y] == 0)))
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] + knight_type;
	}
	else if (locboard[knight_pos_x][knight_pos_y] > 16)								//case for black piece
	{
		if ((knight_track_y >= 0) && (knight_track_y < 9) && (knight_track_x >= 0) && (knight_track_x < 9) && ((locboard[knight_track_x][knight_track_y] <= 16) || (locboard[knight_track_x][knight_track_y] == 0))) 					//checks whether position is on board
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] + knight_type;
		knight_track_x = knight_pos_x + 1;
		if ((knight_track_y >= 0) && (knight_track_y < 9) && (knight_track_x >= 0) && (knight_track_x < 9) && ((locboard[knight_track_x][knight_track_y] <= 16) || (locboard[knight_track_x][knight_track_y] == 0)))
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] + knight_type;
		knight_track_y = knight_pos_y + 2;
		if ((knight_track_y >= 0) && (knight_track_y < 9) && (knight_track_x >= 0) && (knight_track_x < 9) && ((locboard[knight_track_x][knight_track_y] <= 16) || (locboard[knight_track_x][knight_track_y] == 0)))
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] + knight_type;
		knight_track_x = knight_pos_x - 1;
		if ((knight_track_y >= 0) && (knight_track_y < 9) && (knight_track_x >= 0) && (knight_track_x < 9) && ((locboard[knight_track_x][knight_track_y] <= 16) || (locboard[knight_track_x][knight_track_y] == 0)))
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] + knight_type;
		knight_track_x = knight_pos_x - 2;
		knight_track_y = knight_pos_y + 1;
		if ((knight_track_y >= 0) && (knight_track_y < 9) && (knight_track_x >= 0) && (knight_track_x < 9) && ((locboard[knight_track_x][knight_track_y] <= 16) || (locboard[knight_track_x][knight_track_y] == 0)))
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] + knight_type;
		knight_track_y = knight_pos_y - 1;
		if ((knight_track_y >= 0) && (knight_track_y < 9) && (knight_track_x >= 0) && (knight_track_x < 9) && ((locboard[knight_track_x][knight_track_y] <= 16) || (locboard[knight_track_x][knight_track_y] == 0)))
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] + knight_type;
		knight_track_x = knight_pos_x + 2;
		if ((knight_track_y >= 0) && (knight_track_y < 9) && (knight_track_x >= 0) && (knight_track_x < 9) && ((locboard[knight_track_x][knight_track_y] <= 16) || (locboard[knight_track_x][knight_track_y] == 0)))
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] + knight_type;
		knight_track_y = knight_pos_y + 1;
		if ((knight_track_y >= 0) && (knight_track_y < 9) && (knight_track_x >= 0) && (knight_track_x < 9) && ((locboard[knight_track_x][knight_track_y] <= 16) || (locboard[knight_track_x][knight_track_y] == 0)))
			checkboard_knight[knight_track_x][knight_track_y] = checkboard_knight[knight_track_x][knight_track_y] + knight_type;
	}
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (j == 7)
				printf("%x \n", checkboard_knight[j][i]);
			else
				printf("%x ", checkboard_knight[j][i]);
		}
	}
}

void checkboard_gen_pawn(unsigned char ** locboard_temp, unsigned char ** checkboard, int pawn_pos_x, int pawn_pos_y, int what_pawn, int jumptracker)
{
	unsigned long pawn_track_x;
	unsigned long pawn_track_y;
	unsigned long pawn_type;
	unsigned char checkboard_pawn[8][8];
	unsigned char locboard[8][8];
	int i, j;
	for (i = 0; i < 8; i++)				//y initialization
	{
		for (j = 0; j < 8; j++)			//x initialization
		{
			locboard[j][i] = 0x00;
			checkboard_pawn[j][i] = 0x00;
		}
	}
	pawn_type = 0x01;
	if (locboard[pawn_pos_x][pawn_pos_y] <= 16)					//case for white piece
	{
		if (jumptracker == 0)		//initial jump has not occured yet
		{
			pawn_track_y = pawn_pos_y + 1;
			if ((pawn_track_y >= 0) && (pawn_track_y < 9) && (locboard[pawn_track_y][pawn_pos_x] == 0))													//includes check for empty space 
				checkboard_pawn[pawn_pos_x][pawn_track_y] = checkboard_pawn[pawn_pos_x][pawn_track_y] + pawn_type;
			pawn_track_x = pawn_pos_x + 1;
			if ((pawn_track_y >= 0) && (pawn_track_y < 9) && (pawn_track_x >= 0) && (pawn_track_x < 9) && (locboard[pawn_track_x][pawn_track_y] > 16))	//includes check for on board and whether space is occupied by an enemy piece (double check value)
				checkboard_pawn[pawn_track_x][pawn_track_y] = checkboard_pawn[pawn_track_x][pawn_track_y] + pawn_type;
			pawn_track_x = pawn_pos_x - 1;
			if ((pawn_track_y >= 0) && (pawn_track_y < 9) && (pawn_track_x >= 0) && (pawn_track_x < 9) && (locboard[pawn_track_x][pawn_track_y] > 16))
				checkboard_pawn[pawn_track_x][pawn_track_y] = checkboard_pawn[pawn_track_x][pawn_track_y] + pawn_type;
			pawn_track_y = pawn_pos_y + 2;
			if ((pawn_track_y >= 0) && (pawn_track_y < 9) && (locboard[pawn_track_x][pawn_pos_y] == 0))
				checkboard_pawn[pawn_pos_x][pawn_track_y] = checkboard_pawn[pawn_pos_x][pawn_track_y] + pawn_type;
		}
		else if (jumptracker = 1)
		{
			pawn_track_y = pawn_pos_y + 1;
			if ((pawn_track_y >= 0) && (pawn_track_y < 9) && (locboard[pawn_track_y][pawn_pos_x] == 0))													//includes check for empty space 
				checkboard_pawn[pawn_track_x][pawn_track_y] = checkboard_pawn[pawn_track_x][pawn_track_y] + pawn_type;
			printf("still working 3");
			pawn_track_x = pawn_pos_x + 1;
			if ((pawn_track_y >= 0) && (pawn_track_y < 9) && (pawn_track_x >= 0) && (pawn_track_x < 9) && (locboard[pawn_track_x][pawn_track_y] > 16))	//includes check for on board and whether space is occupied by an enemy piece (double check value)
				checkboard_pawn[pawn_track_x][pawn_track_y] = checkboard_pawn[pawn_track_x][pawn_track_y] + pawn_type;
			pawn_track_x = pawn_pos_x - 1;
			if ((pawn_track_y >= 0) && (pawn_track_y < 9) && (pawn_track_x >= 0) && (pawn_track_x < 9) && (locboard[pawn_track_x][pawn_track_y] > 16))
				checkboard_pawn[pawn_track_x][pawn_track_y] = checkboard_pawn[pawn_track_x][pawn_track_y] + pawn_type;
		}
	}
	if (locboard[pawn_pos_x][pawn_pos_y] > 16)				//case for black piece
	{
		if (jumptracker = 0)		//initial jump has not occured yet
		{
			pawn_track_y = pawn_pos_y - 1;
			if ((pawn_track_y >= 0) && (pawn_track_y < 9) && (locboard[pawn_track_y][pawn_pos_x] == 0))													//includes check for empty space 
				checkboard_pawn[pawn_track_x][pawn_track_y] = checkboard_pawn[pawn_track_x][pawn_track_y] + pawn_type;
			pawn_track_x = pawn_pos_x + 1;
			if ((pawn_track_y >= 0) && (pawn_track_y < 9) && (pawn_track_x >= 0) && (pawn_track_x < 9) && (locboard[pawn_track_x][pawn_track_y] <= 16))	//includes check for on board and whether space is occupied by an enemy piece (double check value)
				checkboard_pawn[pawn_track_x][pawn_track_y] = checkboard_pawn[pawn_track_x][pawn_track_y] + pawn_type;
			pawn_track_x = pawn_pos_x - 1;
			if ((pawn_track_y >= 0) && (pawn_track_y < 9) && (pawn_track_x >= 0) && (pawn_track_x < 9) && (locboard[pawn_track_x][pawn_track_y] <= 16))
				checkboard_pawn[pawn_track_x][pawn_track_y] = checkboard_pawn[pawn_track_x][pawn_track_y] + pawn_type;
			pawn_track_y = pawn_pos_y - 2;
			if ((pawn_track_y >= 0) && (pawn_track_y < 9) && (locboard[pawn_track_y][pawn_pos_x] == 0))
				checkboard_pawn[pawn_pos_x][pawn_track_y] = checkboard_pawn[pawn_pos_x][pawn_track_y] + pawn_type;
		}
		else if (jumptracker = 1)
		{
			pawn_track_y = pawn_pos_y - 1;
			if ((pawn_track_y >= 0) && (pawn_track_y < 9) && (locboard[pawn_track_y][pawn_pos_x] == 0))													//includes check for empty space 
				checkboard_pawn[pawn_track_x][pawn_track_y] = checkboard_pawn[pawn_track_x][pawn_track_y] + pawn_type;
			pawn_track_x = pawn_pos_x + 1;
			if ((pawn_track_y >= 0) && (pawn_track_y < 9) && (pawn_track_x >= 0) && (pawn_track_x < 9) && (locboard[pawn_track_x][pawn_track_y] <= 16))	//includes check for on board and whether space is occupied by an enemy piece (double check value)
				checkboard_pawn[pawn_track_x][pawn_track_y] = checkboard_pawn[pawn_track_x][pawn_track_y] + pawn_type;
			pawn_track_x = pawn_pos_x - 1;
			if ((pawn_track_y >= 0) && (pawn_track_y < 9) && (pawn_track_x >= 0) && (pawn_track_x < 9) && (locboard[pawn_track_x][pawn_track_y] <= 16))
				checkboard_pawn[pawn_track_x][pawn_track_y] = checkboard_pawn[pawn_track_x][pawn_track_y] + pawn_type;
		}
	}
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (j == 7)
				printf("%x \n", checkboard_pawn[j][i]);
			else
				printf("%x ", checkboard_pawn[j][i]);
		}
	}
}

void checkboard_gen_rook(unsigned long ** locboard_temp, unsigned long ** checkboard_rook_temp, int rook_pos_x, int rook_pos_y, int what_rook)
{
	int fill_track_x, fill_track_y, rook_type, brk;
	unsigned char checkboard_rook[8][8];
	unsigned char locboard[8][8];
	int i, j;
	for (i = 0; i < 8; i++)				//y initialization
	{
		for (j = 0; j < 8; j++)			//x initialization
		{
			locboard[j][i] = 0x00;
			checkboard_rook[j][i] = 0x00;
		}
	}
	rook_type = 1;
	brk = 0;
	if (locboard[rook_pos_x][rook_pos_y] <= 16)			//white case
	{
		for (i = rook_pos_x + 1; i < 8; i++)
		{
			if ((locboard[i][rook_pos_y] <= 16) && (locboard[i][rook_pos_y] != 0))			//if encountering a friendly piece exit loop
				brk = 1;
			if ((locboard[i][rook_pos_y] > 16) && (brk != 1))												//if encountering an enemy piece, write to space and exit loop
			{
				checkboard_rook[i][rook_pos_y] = checkboard_rook[i][rook_pos_y] + rook_type;
				brk = 1;
			}
			if ((locboard[i][rook_pos_y] == 0) && (brk != 1))										//if encountering empty space, write to space and continue with loop
				checkboard_rook[i][rook_pos_y] = checkboard_rook[i][rook_pos_y] + rook_type;
		}
		brk = 0;
		for (i = rook_pos_x - 1; i >= 0; i--)
		{
			if ((locboard[i][rook_pos_y] <= 16) && (locboard[i][rook_pos_y] != 0))			//if encountering a friendly piece exit loop
				brk = 1;
			if ((locboard[i][rook_pos_y] > 16) && (brk != 1))												//if encountering an enemy piece, write to space and exit loop
			{
				checkboard_rook[i][rook_pos_y] = checkboard_rook[i][rook_pos_y] + rook_type;
				brk = 1;
			}
			if ((locboard[i][rook_pos_y] == 0) && (brk != 1))										//if encountering empty space, write to space and continue with loop
				checkboard_rook[i][rook_pos_y] = checkboard_rook[i][rook_pos_y] + rook_type;
		}
		brk = 0;
		for (i = rook_pos_y + 1; i < 8; i++)
		{
			if ((locboard[rook_pos_x][i] <= 16) && (locboard[rook_pos_x][i] != 0))				//if encountering a friendly piece exit loop
				brk = 1;
			if ((locboard[rook_pos_x][i] > 16) && (brk != 1))
			{
				checkboard_rook[rook_pos_x][i] = checkboard_rook[rook_pos_x][i] + rook_type;
				brk = 1;
			}
			if ((locboard[rook_pos_x][i] == 0) && (brk != 1))
				checkboard_rook[rook_pos_x][i] = checkboard_rook[rook_pos_x][i] + rook_type;
		}
		brk = 0;
		for (i = rook_pos_y - 1; i >= 0; i--)
		{
			if ((locboard[rook_pos_x][i] <= 16) && (locboard[rook_pos_x][i] != 0))				//if encountering a friendly piece exit loop
				brk = 1;
			if ((locboard[rook_pos_x][i] > 16) && (brk != 1))
			{
				checkboard_rook[rook_pos_x][i] = checkboard_rook[rook_pos_x][i] + rook_type;
				brk = 1;
			}
			if ((locboard[rook_pos_x][i] == 0) && (brk != 1))
				checkboard_rook[rook_pos_x][i] = checkboard_rook[rook_pos_x][i] + rook_type;
		}
		brk = 0;
	}
	else if (locboard[rook_pos_x][rook_pos_y] > 16)		//black case
	{
		for (i = rook_pos_x + 1; i < 8; i++)
		{
			if ((locboard[i][rook_pos_y] > 16) && (locboard[i][rook_pos_y] != 0))			//if encountering a friendly piece exit loop
				brk = 1;
			if ((locboard[i][rook_pos_y] <= 16) && (brk != 1))												//if encountering an enemy piece, write to space and exit loop
			{
				checkboard_rook[i][rook_pos_y] = checkboard_rook[i][rook_pos_y] + rook_type;
				brk = 1;
			}
			if ((locboard[i][rook_pos_y] == 0) && (brk != 1))										//if encountering empty space, write to space and continue with loop
				checkboard_rook[i][rook_pos_y] = checkboard_rook[i][rook_pos_y] + rook_type;
		}
		brk = 0;
		for (i = rook_pos_x - 1; i >= 0; i--)
		{
			if ((locboard[i][rook_pos_y] > 16) && (locboard[i][rook_pos_y] != 0))			//if encountering a friendly piece exit loop
				brk = 1;
			if ((locboard[i][rook_pos_y] <= 16) && (brk != 1))												//if encountering an enemy piece, write to space and exit loop
			{
				checkboard_rook[i][rook_pos_y] = checkboard_rook[i][rook_pos_y] + rook_type;
				brk = 1;
			}
			if ((locboard[i][rook_pos_y] == 0) && (brk != 1))										//if encountering empty space, write to space and continue with loop
				checkboard_rook[i][rook_pos_y] = checkboard_rook[i][rook_pos_y] + rook_type;
		}
		brk = 0;
		for (i = rook_pos_y + 1; i < 8; i++)
		{
			if ((locboard[rook_pos_x][i] > 16) && (locboard[rook_pos_x][i] != 0))				//if encountering a friendly piece exit loop
				brk = 1;
			if ((locboard[rook_pos_x][i] <= 16) && (brk != 1))
			{
				checkboard_rook[rook_pos_x][i] = checkboard_rook[rook_pos_x][i] + rook_type;
				brk = 1;
			}
			if ((locboard[rook_pos_x][i] == 0) && (brk != 1))
				checkboard_rook[rook_pos_x][i] = checkboard_rook[rook_pos_x][i] + rook_type;
		}
		brk = 0;
		for (i = rook_pos_y - 1; i >= 0; i--)
		{
			if ((locboard[rook_pos_x][i] > 16) && (locboard[rook_pos_x][i] != 0))				//if encountering a friendly piece exit loop
				brk = 1;
			if ((locboard[rook_pos_x][i] <= 16) && (brk != 1))
			{
				checkboard_rook[rook_pos_x][i] = checkboard_rook[rook_pos_x][i] + rook_type;
				brk = 1;
			}
			if ((locboard[rook_pos_x][i] == 0) && (brk != 1))
				checkboard_rook[rook_pos_x][i] = checkboard_rook[rook_pos_x][i] + rook_type;
		}
		brk = 0;
	}
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (j == 7)
				printf("%x \n", checkboard_rook[j][i]);
			else
				printf("%x ", checkboard_rook[j][i]);
		}
	}
}

void checkboard_gen_bishop(unsigned long ** locboard_temp, unsigned long ** checkboard_bishop_temp, int bishop_pos_x, int bishop_pos_y, int what_bishop)
{
	int fill_track_x, fill_track_y, bishop_type, brk;
	unsigned char checkboard_bishop[8][8];
	unsigned char locboard[8][8];
	int i, j;
	for (i = 0; i < 8; i++)				//y initialization
	{
		for (j = 0; j < 8; j++)			//x initialization
		{
			locboard[j][i] = 0x00;
			checkboard_bishop[j][i] = 0x00;
		}
	}
	bishop_type = 1;
	brk = 0;
	locboard[2][2] = 5;
	if (locboard[bishop_pos_x][bishop_pos_y] <= 16)			//white case
	{
		for (i = 1; i < 8; i++)
		{
			if (((locboard[bishop_pos_x + i][bishop_pos_y + i] <= 16) && (locboard[bishop_pos_x + i][bishop_pos_y + i] != 0)) || (bishop_pos_x + i > 8) || (bishop_pos_y + i > 8))	//up and to right diagonal
				brk = 1;
			if ((locboard[bishop_pos_x + i][bishop_pos_y + i] > 16) && (brk != 1))
			{
				checkboard_bishop[bishop_pos_x + i][bishop_pos_y + i] = checkboard_bishop[bishop_pos_x + i][bishop_pos_y + i] + bishop_type;
				brk = 1;
			}
			if ((locboard[bishop_pos_x + i][bishop_pos_y + i] == 0) && (brk != 1))
				checkboard_bishop[bishop_pos_x + i][bishop_pos_y + i] = checkboard_bishop[bishop_pos_x + i][bishop_pos_y + i] + bishop_type;
		}
		brk = 0;
		for (i = 1; i < 8; i++)
		{
			if (((locboard[bishop_pos_x - i][bishop_pos_y - i] <= 16) && (locboard[bishop_pos_x - i][bishop_pos_y - i] != 0)) || (bishop_pos_x - i < 0) || (bishop_pos_y - i < 0))	//down and left diagonal
				brk = 1;
			if ((locboard[bishop_pos_x - i][bishop_pos_y - i] > 16) && (brk != 1))
			{
				checkboard_bishop[bishop_pos_x - i][bishop_pos_y - i] = checkboard_bishop[bishop_pos_x - i][bishop_pos_y - i] + bishop_type;
				brk = 1;
			}
			if ((locboard[bishop_pos_x - i][bishop_pos_y - i] == 0) && (brk != 1))
				checkboard_bishop[bishop_pos_x - i][bishop_pos_y - i] = checkboard_bishop[bishop_pos_x - i][bishop_pos_y - i] + bishop_type;
		}
		brk = 0;
		for (i = 1; i < 8; i++)
		{
			if (((locboard[bishop_pos_x - i][bishop_pos_y + i] <= 16) && (locboard[bishop_pos_x - i][bishop_pos_y + i] != 0)) || (bishop_pos_x - i < 0) || (bishop_pos_y + i > 8))		//up and left diagonal
				brk = 1;
			if ((locboard[bishop_pos_x - i][bishop_pos_y + i] > 16) && (brk != 1))
			{
				checkboard_bishop[bishop_pos_x - i][bishop_pos_y + i] = checkboard_bishop[bishop_pos_x - i][bishop_pos_y + i] + bishop_type;
				brk = 1;
			}
			if ((locboard[bishop_pos_x - i][bishop_pos_y + i] == 0) && (brk != 1))
				checkboard_bishop[bishop_pos_x - i][bishop_pos_y + i] = checkboard_bishop[bishop_pos_x - i][bishop_pos_y + i] + bishop_type;
		}
		brk = 0;
		for (i = 1; i < 8; i++)
		{
			if (((locboard[bishop_pos_x + i][bishop_pos_y - i] <= 16) && (locboard[bishop_pos_x + i][bishop_pos_y - i] != 0)) || (bishop_pos_x + i > 8) || (bishop_pos_y - i < 0))		//down and right diagonal
				brk = 1;
			if ((locboard[bishop_pos_x + i][bishop_pos_y - i] > 16) && (brk != 1))
			{
				checkboard_bishop[bishop_pos_x + i][bishop_pos_y - i] = checkboard_bishop[bishop_pos_x + i][bishop_pos_y - i] + bishop_type;
				brk = 1;
			}
			if ((locboard[bishop_pos_x + i][bishop_pos_y - i] == 0) && (brk != 1))
				checkboard_bishop[bishop_pos_x + i][bishop_pos_y - i] = checkboard_bishop[bishop_pos_x + i][bishop_pos_y - i] + bishop_type;
		}
		
	}
	else if (locboard[bishop_pos_x][bishop_pos_y] > 16)					//BLACK CASE
	{
		for (i = 1; i < 8; i++)
		{
			if (((locboard[bishop_pos_x + i][bishop_pos_y + i] > 16) && (locboard[bishop_pos_x + i][bishop_pos_y + i] != 0)) || (bishop_pos_x + i > 8) || (bishop_pos_y + i > 8))	//up and to right diagonal
				brk = 1;
			if ((locboard[bishop_pos_x + i][bishop_pos_y + i] <= 16) && (brk != 1))
			{
				checkboard_bishop[bishop_pos_x + i][bishop_pos_y + i] = checkboard_bishop[bishop_pos_x + i][bishop_pos_y + i] + bishop_type;
				brk = 1;
			}
			if ((locboard[bishop_pos_x + i][bishop_pos_y + i] == 0) && (brk != 1))
				checkboard_bishop[bishop_pos_x + i][bishop_pos_y + i] = checkboard_bishop[bishop_pos_x + i][bishop_pos_y + i] + bishop_type;
		}
		brk = 0;
		for (i = 1; i < 8; i++)
		{
			if (((locboard[bishop_pos_x - i][bishop_pos_y - i] > 16) && (locboard[bishop_pos_x - i][bishop_pos_y - i] != 0)) || (bishop_pos_x - i < 0) || (bishop_pos_y - i < 0))	//down and left diagonal
				brk = 1;
			if ((locboard[bishop_pos_x - i][bishop_pos_y - i] <= 16) && (brk != 1))
			{
				checkboard_bishop[bishop_pos_x - i][bishop_pos_y - i] = checkboard_bishop[bishop_pos_x - i][bishop_pos_y - i] + bishop_type;
				brk = 1;
			}
			if ((locboard[bishop_pos_x - i][bishop_pos_y - i] == 0) && (brk != 1))
				checkboard_bishop[bishop_pos_x - i][bishop_pos_y - i] = checkboard_bishop[bishop_pos_x - i][bishop_pos_y - i] + bishop_type;
		}
		brk = 0;
		for (i = 1; i < 8; i++)
		{
			if (((locboard[bishop_pos_x - i][bishop_pos_y + i] > 16) && (locboard[bishop_pos_x - i][bishop_pos_y + i] != 0)) || (bishop_pos_x - i < 0) || (bishop_pos_y + i > 8))		//up and left diagonal
				brk = 1;
			if ((locboard[bishop_pos_x - i][bishop_pos_y + i] <= 16) && (brk != 1))
			{
				checkboard_bishop[bishop_pos_x - i][bishop_pos_y + i] = checkboard_bishop[bishop_pos_x - i][bishop_pos_y + i] + bishop_type;
				brk = 1;
			}
			if ((locboard[bishop_pos_x - i][bishop_pos_y + i] == 0) && (brk != 1))
				checkboard_bishop[bishop_pos_x - i][bishop_pos_y + i] = checkboard_bishop[bishop_pos_x - i][bishop_pos_y + i] + bishop_type;
		}
		brk = 0;
		for (i = 1; i < 8; i++)
		{
			if (((locboard[bishop_pos_x + i][bishop_pos_y - i] > 16) && (locboard[bishop_pos_x + i][bishop_pos_y - i] != 0)) || (bishop_pos_x + i > 8) || (bishop_pos_y - i < 0))		//down and right diagonal
				brk = 1;
			if ((locboard[bishop_pos_x + i][bishop_pos_y - i] <= 16) && (brk != 1))
			{
				checkboard_bishop[bishop_pos_x + i][bishop_pos_y - i] = checkboard_bishop[bishop_pos_x + i][bishop_pos_y - i] + bishop_type;
				brk = 1;
			}
			if ((locboard[bishop_pos_x + i][bishop_pos_y - i] == 0) && (brk != 1))
				checkboard_bishop[bishop_pos_x + i][bishop_pos_y - i] = checkboard_bishop[bishop_pos_x + i][bishop_pos_y - i] + bishop_type;
		}
	}
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (j == 7)
				printf("%x \n", checkboard_bishop[j][i]);
			else
				printf("%x ", checkboard_bishop[j][i]);
		}
	}
}

int main()
{
	unsigned char locboard[8][8];		//actual game board
	unsigned char checkboard[8][8];		//parallel generated board with hot encoded valid moves
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
	printf("Checkboard for Pawn:\n");
	checkboard_gen_pawn(locboard, checkboard, 0, 0, 0, 0);
	printf("Checkboard for Knight:\n");
	checkboard_gen_knight(locboard, checkboard, 4, 4, 0);
	printf("Checkboard for Rook:\n");
	checkboard_gen_rook(locboard, checkboard, 3, 3, 0);
	printf("Checkboard for Bishop:\n");
	checkboard_gen_bishop(locboard, checkboard, 3, 3, 0);
	return 0;
}
