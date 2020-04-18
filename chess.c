/*Classic Game of Chess*/

#include<stdio.h>
#include<stdlib.h>
#include"piece.h"

struct tile **initboard();
struct tile **move_piece(struct tile ** board, int xi, int yi, int xf, int yf);
void print_board(struct tile ** board);


void main(){


	struct tile ** board = initboard();
	print_board(board);
	board = move_piece(board, 0, 1, 0, 3);
	print_board(board);
	/*
	int move = board[0][0].valid_moves[0][0];*/	
}


struct tile **initboard() {


	struct tile ** board = malloc(8 * sizeof(struct tile*));

	for (int i = 0; i <= 7; i++){

		board[i] = malloc(8 * sizeof(struct tile));
	}

	int init_colors[8][8] = {
		{1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{2, 2, 2, 2, 2, 2, 2, 2},
		{2, 2, 2, 2, 2, 2, 2, 2}};

	int init_pieces[8][8] = {
		{1, 2, 3, 4, 5, 3, 2, 1},
		{6, 6, 6, 6, 6, 6, 6, 6},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 0, 0, 0, 0, 0, 0}, 
		{6, 6, 6, 6, 6, 6, 6, 6},
		{1, 2, 3, 5, 4, 3, 2, 1}};
	
	int i;
	int j;
	for (i=0; i<=7; i++){
		
		for (j=0; j<=7; j++){

			switch(init_colors[i][j]){

				case 0:
					board[i][j].color = clear;
					break;
				case 1:
					board[i][j].color = white;
					break;
				case 2:
					board[i][j].color = black;
					break;
				default:

					printf("Color Switch Case: No Case Satisfied; Defaulting");

			}

			switch(init_pieces[i][j]){

				case 0:
					board[i][j].piece = none;
					break;
				case 1:
					board[i][j].piece = rook;
					break;
				case 2:
					board[i][j].piece = knight;
					break;
				case 3:
					board[i][j].piece = bishop;
					break;
				case 4:
					board[i][j].piece = king;
					break;
				case 5:
					board[i][j].piece = queen;
					break;
				case 6:
					board[i][j].piece = pawn;
					break;
				default:
					printf("Piece Switch Case: No Case Satisfied; Defaulting");

			}
			/*
			int valid_moves[8][8] = {
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0, 0, 0, 0},	
				{0, 0, 0, 0, 0, 0, 0, 0},	
				{0, 0, 0, 0, 0, 0, 0, 0},	
				{0, 0, 0, 0, 0, 0, 0, 0},	
				{0, 0, 0, 0, 0, 0, 0, 0},	
				{0, 0, 0, 0, 0, 0, 0, 0}};


			
			board[i][j].moves = &valid_moves;*/

		}
	}

	return board;

}

/*
struct tile ** define_moves(struct tile ** board){

	return board;
}
*/

void print_board(struct tile **board){

	for(int i = 0; i<=7; i++){

		printf("\n-------------------------------------------------\n");

		for(int j = 0; j<=7; j++){

			printf("| ");
		
			switch(board[i][j].color){

				case 0:
					printf("  ");
					break;	
				case 1:
					printf("W");
					break;
				case 2:
					printf("B");
					break;
			}

			switch(board[i][j].piece){

				case 0:
					break;
				case 1:
					printf("R");
					break;
				case 2:
					printf("N");
					break;
				case 3:
					printf("B");
					break;
				case 4:
					printf("K");
					break;
				case 5:
					printf("Q");
					break;
				case 6:
					printf("P");
					break;
				default:
					printf("Print Board Piece Switch Case: No Case Satisfied; Defaulting");
			}

			printf(" |");
		}
	}
	printf("\n-------------------------------------------------\n");
}


struct tile ** move_piece(struct tile ** board, int yi, int xi, int yf, int xf){

	board[xf][yf].color = board[xi][yi].color;
	board[xf][yf].piece = board[xi][yi].piece;
	board[xi][yi].color = clear;
	board[xi][yi].piece = none;

	return board;
}

