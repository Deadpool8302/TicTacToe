#pragma once
#include"consolehandle.hpp"
#include"Move.hpp"
#include<unordered_map>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<conio.h>
#include<math.h>

using namespace std;

enum CellType { CORNER, EDGE, CENTER };

class WelcomeScreen {
public:
	void displayChoice();
	void playerVSplayer();
	void playerVScomp();

private:
	void display(int x, int y);
	char checkMove(int a, int b, int c, Move* ptr);

	int checkWin0(int* ptr);
	int checkWinx(int* ptr);
	CellType isCornerOrEdge(int i);
	int getRandomCell(CellType type);
};