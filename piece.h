/* Initialize board resources including enums, pieces, and colors*/
#ifndef PIECE_H
#define PIECE_H

typedef enum {none, rook, knight, bishop, king, queen, pawn} pieces;
typedef enum {clear, white, black} colors;


struct tile {

	pieces piece;
	colors color;
	/*int moves;*/
};
#endif

