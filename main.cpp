#include"consolehandle.hpp"
#include"Move.hpp"
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<conio.h>
#include<math.h>

using namespace std;

void display(int x, int y);
char checkMove(int a, int b, int c, Move* ptr);

int main() {

	char win = 'N';
	int x = 12;
	int y = 3;
	int z = 0;
	int i = 0;

	Move arr[9];

	int k = 0;
	for (int j = 3; j <= 9; j += 3) {
		for (int i = 13; i <= 30; i += 8) {
			arr[k].movexy(i, j);
			k++;
		}
	}

	int type = 0;

	while (true) {
		clrscr();

		display(x, y);

		for (int j = 0; j < 9; j++) {
			if (arr[j].getMove() != 'N') {
				gotoxy(arr[j].getposx(), arr[j].getposy());
				cout << arr[j].getMove();
			}
		}

		win = checkMove(0, 1, 2, arr);
		if (win != 'N') break;
		win = checkMove(3, 4, 5, arr);
		if (win != 'N') break;
		win = checkMove(6, 7, 8, arr);
		if (win != 'N') break;
		win = checkMove(0, 3, 6, arr);
		if (win != 'N') break;
		win = checkMove(1, 4, 7, arr);
		if (win != 'N') break;
		win = checkMove(2, 5, 8, arr);
		if (win != 'N') break;
		win = checkMove(0, 4, 8, arr);
		if (win != 'N') break;
		win = checkMove(2, 4, 6, arr);
		if (win != 'N') break;

		if (type == 9) {
			gotoxy(x, y);cout << ' ';
			gotoxy(x + 2, y);cout << ' ';
			break;
		}

		gotoxy(10, 20);
		int input = _getch();

		if (input == 'w') y -= 3;
		if (input == 'a') x -= 8;
		if (input == 's') y += 3;
		if (input == 'd') x += 8;

		if (x == 36) x = 12;
		if (x == 4) x = 28;
		if (y == 12) y = 3;
		if (y == 0) y = 9;

		i = (x / 8) + y - (9 / 2);

		if (input == 13) {
			if (arr[i].getMove() == 'N') {
				arr[i].setMove(type);
				type++;
			}
		}



	}


	//for (int i = 0; i < 9; i++) {
	//	arr[i].showpos(); cout << endl;
	//}

	if (win == 'X') {
		gotoxy(40, 6); cout << "PLAYER 2 WINS!!";
	}

	else if (win == 'O') {
		gotoxy(40, 6); cout << "PLAYER 1 WINS!!";
	}

	else {
		gotoxy(40, 6); cout << "DRAW!!";
	}

	gotoxy(11, 15);
	cout << "press any key to exit."; 
	_getch();
	return 0;
}

void display(int x, int y) {
	gotoxy(x, y);    cout << "[";
	gotoxy(x+2, y);    cout << "]";

	gotoxy(17, 2);   cout << "|"; gotoxy(25, 2); cout << "|\n";
	gotoxy(17, 3);   cout << "|"; gotoxy(25, 3); cout << "|\n";
	gotoxy(10, 4);   cout << "_______|_______|_______\n";
	gotoxy(17, 5);   cout << "|"; gotoxy(25, 5); cout << "|\n";
	gotoxy(17, 6);   cout << "|"; gotoxy(25, 6); cout << "|\n";
	gotoxy(10, 7);   cout << "_______|_______|_______\n";
	gotoxy(10, 8);   cout << "       |       |       \n";
	gotoxy(17, 9);   cout << "|"; gotoxy(25, 9); cout << "|\n";
	gotoxy(17, 10);  cout << "|"; gotoxy(25, 10); cout << "|";

}

char checkMove(int a, int b, int c, Move* ptr) {
	if (ptr[a].getMove() == ptr[b].getMove() && ptr[b].getMove() == ptr[c].getMove()) {
		if (ptr[a].getMove() == 'O') {
			return 'O';
		}
		else if (ptr[a].getMove() == 'X') {
			return 'X';
		}
	}
	else return 'N';
}