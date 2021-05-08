/*Dor And the Mighty Idan Q1 Bitch*/
#define _CRT_SECURE_NO_WARNINGS
#include "Q1.h"

/*Q1*/
chessPosArray*** validKnightMoves() {

	int rows, cols;
	Coords CoordTable[MAX_MOVES] = { {-2 , 1},{-2 , -1},
									 {2 , 1} , {2 , -1},
									 {1 , 2} , {1 , -2},
									 {-1 , 2},{-1 , -2} };/*TODO NOTES*/

	chessPosArray*** board = initiateChessBoard();

	for (rows = 0; rows < BOARD_SIZE; rows++) {
		for (cols = 0; cols < BOARD_SIZE; cols++) {
			//(board[rows][cols].size) = 0;
			board[rows][cols]->positions = validSquareMoves(rows, cols, CoordTable, &(board[rows][cols]->size));
		}
	}
	return board;
}

chessPos* validSquareMoves(int rows, int cols, Coords scanCoords[], unsigned int* size) {

	int i, counter = 0;
	int tempRows, tempCols;
	chessPos* chessPosRes = (chessPos*)malloc(MAX_MOVES * sizeof(chessPos));
	checkAlloc(chessPosRes, "failed to malloc chessPosRes");
	/*TODO CHEECK ALLOC*/

	/*TODO smart way to scan moves around the Knight*/
	for (i = 0; i < MAX_MOVES; i++) {
		tempRows = rows + scanCoords[i][0];
		tempCols = cols + scanCoords[i][1];

		if (isInBoard(tempRows, tempCols)) { /*TODO check chessPosRes[i] = chessPos Temp[0]*/
			chessPosRes[counter][0] = IntToCharLetter(tempRows);
			chessPosRes[counter][1] = IntToCharNum(tempCols);
			counter++;
		}
	}

	chessPosRes = (chessPos*)realloc(chessPosRes, counter * sizeof(chessPos));
	checkAlloc(chessPosRes, "cant realloc chessPosRes");

	*size = counter;
	return chessPosRes;
}

chessPosArray*** initiateChessBoard() {/*TODO change the name*/
	int i,j;
	chessPosArray*** board;
	board = (chessPosArray***)malloc(BOARD_SIZE * sizeof(chessPosArray**));
	for (i = 0; i < BOARD_SIZE; i++) {
		
		board[i] = (chessPosArray**)malloc(BOARD_SIZE * sizeof(chessPosArray*));
		checkAlloc(board[i], "failed to alloc board[i]");

		for  (j = 0; j < BOARD_SIZE; j++) {
			board[i][j] = (chessPosArray*)malloc(sizeof(chessPosArray));
			checkAlloc(board[i][j], "failed to alloc board[i][j]");
		}
	}
	return board;
}

bool isInBoard(int rows, int cols) {
	return ((rows >= 0 && rows <= (BOARD_SIZE-1)) && (cols >= 0 && cols <= (BOARD_SIZE - 1)));
}
