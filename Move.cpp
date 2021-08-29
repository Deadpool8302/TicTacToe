#include"Move.hpp"
#include<iostream>
#include"consolehandle.hpp"

Move::Move()
{
	x = 0;
	y = 0;
	displayMove = 'N';
}

void Move::movexy(int a, int b) {
	x = a;
	y = b;
}

void Move::showpos()
{
	std::cout << x << ',' << y << std::endl;
	std::cout << displayMove;
}

int Move::getposx()
{
	return x;
}

int Move::getposy()
{
	return y;
}

void Move::setMove(int i)
{
		if (i % 2 == 0) {
			displayMove = 'O';
		}
		else {
			displayMove = 'X';
		}
}

char Move::getMove()
{
	return displayMove;
}

void Move::clearMoves()
{
	displayMove = 'N';
}
