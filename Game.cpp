#include "Game.hpp"

void WelcomeScreen::displayChoice()
{
	gotoxy(42, 4); cout << "|-----------------------------------|";
	gotoxy(42, 5); cout << "|      Welcome to Tic Tac Toe!      |";
	gotoxy(42, 6); cout << "|                                   |";
	gotoxy(42, 7); cout << "|    Enter 1 to play vs computer    |";
	gotoxy(42, 8); cout << "|   Enter 2 to play with a friend   |";
	gotoxy(42, 9); cout << "|                                   |";
	gotoxy(42, 10);cout << "|     Press E to Exit the Game      |";
	gotoxy(42, 11);cout << "|-----------------------------------|";
}

void WelcomeScreen::playerVSplayer()
{
restart:
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
			gotoxy(x, y); cout << ' ';
			gotoxy(x + 2, y); cout << ' ';
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

		else if (input == 114) {
			for (int k = 0; k < 9; k++) arr[k].clearMoves();
			type = 0;
			continue;
		}

	}

	if (win == 'X') {
		gotoxy(50, 6); cout << "X WINS!!";
		gotoxy(50, 7); cout << "                                          ";
		gotoxy(50, 8); cout << "                                          ";
	}

	else if (win == 'O') {
		gotoxy(50, 6); cout << "O WINS!!";
		gotoxy(50, 7); cout << "                                          ";
		gotoxy(50, 8); cout << "                                          ";
	}

	else {
		gotoxy(50, 6); cout << "DRAW!!";
		gotoxy(50, 7); cout << "                                          ";
		gotoxy(50, 8); cout << "                                          ";
	}

	gotoxy(11, 15);
	gotoxy(50, 8); cout << "Press R to restart or any other key to return to Main Screen";
	int temp = _getch();
	if (temp == 114) goto restart;
}

void WelcomeScreen::playerVScomp()
{
	unordered_map<int, char> type;
	type[1] = 'O';
	type[3] = 'X';

	int x = 12;
	int y = 3;
	int i = 0;

	vector<int> halfCor1{ 2,6 };
	vector<int> halfCor2{ 0,8 };

restart:

	int move = 0;
	int cells[9] = { 0 };
	srand(time(0));
	while (true) {
		clrscr();

		display(x, y);

		for (int j = 0; j < 9; j++) {
			if (cells[j] != 0) {
				gotoxy(8 * (j % 3) + 13, 3 * (j / 3 + 1)); cout << type[cells[j]];
			}
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

		//if (input == 13) { cout << i; cin.get(); }

		if (input == 13) {
			int c, d;
			if (move == 0) {
				if (i == 4) {
					cells[i] = 1;
					cells[getRandomCell(CORNER)] = 3;
				}
				else {
					cells[i] = 1;
					if (isCornerOrEdge(i) == 0) cells[4] = 3;
					else {
						int ed[2] = { 4, 8 - i };
						cells[ed[rand() % 2]] = 3;
					}
				}
				move++;
			}
			else if (move == 1) {
				if (cells[i] != 0);
				else {
					cells[i] = 1;
					if (cells[0] + cells[4] + cells[8] == 5 || cells[2] + cells[4] + cells[6] == 5) {
						if ((cells[0] == cells[8] && cells[8] == 1) || (cells[2] == cells[6] && cells[6] == 1)) {
							cells[getRandomCell(EDGE)] = 3;
						}
						else {
							if (cells[0] != 0) {
								cells[halfCor1[rand() % halfCor1.size()]] = 3;
							}
							else {
								cells[halfCor2[rand() % halfCor2.size()]] = 3;
							}
						}
					}
					else {
						c = checkWin0(cells);
						if (c < 9) cells[c] = 3;
						else {
							if ((cells[3] != 0 && cells[5] != 0) || (cells[1] != 0 && cells[7] != 0)) {
								cells[getRandomCell(CORNER)] = 3;
							}
							else if (cells[0] == cells[8] && cells[2] == cells[6] && cells[6] == 0) {
								if ((cells[1] != 0 && cells[3] != 0)) cells[0] = 3;
								else if ((cells[1] != 0 && cells[5] != 0)) cells[2] = 3;
								else if ((cells[3] != 0 && cells[7] != 0)) cells[6] = 3;
								else if ((cells[7] != 0 && cells[5] != 0)) cells[8] = 3;

							}
							else if (cells[0] == cells[8] && cells[8] == 0) {
								if ((cells[1] != 0 && cells[6] != 0) || (cells[2] != 0 && cells[3] != 0))cells[0] = 3;
								else if ((cells[7] != 0 && cells[2] != 0) || (cells[5] != 0 && cells[6] != 0))cells[8] = 3;
							}
							else if (cells[2] == cells[6] && cells[6] == 0) {
								if ((cells[1] != 0 && cells[8] != 0) || (cells[0] != 0 && cells[5] != 0))cells[2] = 3;
								else if ((cells[0] != 0 && cells[7] != 0) || (cells[8] != 0 && cells[3] != 0))cells[6] = 3;
							}
						}
					}
					move++;
				}

			}
			else {
				if (cells[i] != 0);
				else {
					cells[i] = 1;
					c = checkWin0(cells);
					d = checkWinx(cells);
					if (d < 9) {
						cells[d] = 3;
						gotoxy(8 * (d % 3) + 13, 3 * (d / 3 + 1)); cout << type[cells[d]];
						gotoxy(8 * (i % 3) + 13, 3 * (i / 3 + 1)); cout << type[cells[i]];
						gotoxy(50, 6);  cout << "X WINS!!"; 
						gotoxy(50, 7); cout << "                                          ";
						gotoxy(50, 8); cout << "                                          ";
						break;
					}
					else if (c < 9) cells[c] = 3;
					else {
						vector<int> vac;
						for (int k = 0; k < 9; k++) {
							if (cells[k] == 0) vac.push_back(k);
						}
						if (vac.size() != 0) {
							cells[vac[rand() % vac.size()]] = 3;
							continue;
						}
						gotoxy(8 * (i % 3) + 13, 3 * (i / 3 + 1)); cout << type[cells[i]];
						gotoxy(8 * (i % 3) + 13, 3 * (i / 3 + 1)); cout << type[cells[i]];
						gotoxy(50, 6);  cout << "DRAW!!";
						gotoxy(50, 7); cout << "                                          ";
						gotoxy(50, 8); cout << "                                          ";
						break;
					}
					move++;
				}
			}
		}

		else if (input == 114) {
			for (int l = 0; l < 9; l++) cells[l] = 0;
			move = 0;
			continue;
		}

	}
	gotoxy(50, 8); cout << "Press R to restart or any other key to return to Main Screen";
	int input2 = _getch();
	if (input2 == 114) goto restart;
}

void WelcomeScreen::display(int x, int y) {
	gotoxy(x, y);    cout << "[";
	gotoxy(x + 2, y);    cout << "]";

	gotoxy(17, 2);   cout << "|"; gotoxy(25, 2); cout << "|\n";
	gotoxy(17, 3);   cout << "|"; gotoxy(25, 3); cout << "|\n";
	gotoxy(10, 4);   cout << "_______|_______|_______\n";
	gotoxy(17, 5);   cout << "|"; gotoxy(25, 5); cout << "|\n";
	gotoxy(17, 6);   cout << "|"; gotoxy(25, 6); cout << "|\n";
	gotoxy(10, 7);   cout << "_______|_______|_______\n";
	gotoxy(10, 8);   cout << "       |       |       \n";
	gotoxy(17, 9);   cout << "|"; gotoxy(25, 9); cout << "|\n";
	gotoxy(17, 10);  cout << "|"; gotoxy(25, 10); cout << "|";

	gotoxy(50, 7); cout << "Use W, A, S, D keys to move the cursor";
	gotoxy(50, 8); cout << "         Press R to restart";

}

char WelcomeScreen::checkMove(int a, int b, int c, Move* ptr) {
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

int WelcomeScreen::checkWin0(int* ptr) {

	int diag1 = 0, diag2 = 0;
	for (int i = 0, j = 0; i < 3; i++, j += 3) {
		if (ptr[j] + ptr[j + 1] + ptr[j + 2] == 2) {
			if (ptr[j] == 0) return j;
			else if (ptr[j + 1] == 0) return j + 1;
			else if (ptr[j + 2] == 0) return j + 2;
		}
		if (ptr[i] + ptr[i + 3] + ptr[i + 6] == 2) {
			if (ptr[i] == 0) return i;
			else if (ptr[i + 3] == 0) return i + 3;
			else if (ptr[i + 6] == 0) return i + 6;
		}
		diag1 += ptr[i + j];
		diag2 += ptr[j - i + 2];
	}

	if (diag1 == 2) {
		if (ptr[0] == 0) return 0;
		else if (ptr[4] == 0) return 4;
		else if (ptr[8] == 0) return 8;
	}

	if (diag2 == 2) {
		if (ptr[2] == 0) return 2;
		else if (ptr[4] == 0) return 4;
		else if (ptr[6] == 0) return 6;
	}

	return 10;
}

int WelcomeScreen::checkWinx(int* ptr) {

	int diag1 = 0, diag2 = 0;
	for (int i = 0, j = 0; i < 3; i++, j += 3) {
		if (ptr[j] + ptr[j + 1] + ptr[j + 2] == 6) {
			if (ptr[j] == 0) return j;
			else if (ptr[j + 1] == 0) return j + 1;
			else if (ptr[j + 2] == 0) return j + 2;
		}
		if (ptr[i] + ptr[i + 3] + ptr[i + 6] == 6) {
			if (ptr[i] == 0) return i;
			else if (ptr[i + 3] == 0) return i + 3;
			else if (ptr[i + 6] == 0) return i + 6;
		}
		diag1 += ptr[i + j];
		diag2 += ptr[j - i + 2];
	}

	if (diag1 == 6) {
		if (ptr[0] == 0) return 0;
		else if (ptr[4] == 0) return 4;
		else if (ptr[8] == 0) return 8;
	}

	if (diag2 == 6) {
		if (ptr[2] == 0) return 2;
		else if (ptr[4] == 0) return 4;
		else if (ptr[6] == 0) return 6;
	}

	return 10;
}

CellType WelcomeScreen::isCornerOrEdge(int i)
{
	if (i == 4) return CENTER;
	return CellType(i % 2);
}

int WelcomeScreen::getRandomCell(CellType type)
{
	int r = (rand() % 4);
	if (type == CORNER) return (r + r / 2) * 2;
	if (type == EDGE) return 2 * r + 1;
	return 4;
}