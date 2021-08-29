#pragma once

class Move {
	int x, y;
	char displayMove;

public:

	Move();
	void movexy(int, int);

	void showpos();
	int getposx();
	int getposy();
	void setMove(int);
	char getMove();
	void clearMoves();

};