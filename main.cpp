#include"consolehandle.hpp"
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<conio.h>
#include<math.h>
#include<unordered_map>

using namespace std;

void display(int x, int y);
int checkWin0(int* ptr);
int checkWinx(int* ptr);

int main() {
	unordered_map<int, char> type;
	type[1] = 'O';
	type[3] = 'X';

	int x = 12;
	int y = 3;
	int i = 0;

	int arr[9] = { 0 };

	vector<int> corner{ 0, 2, 6, 8 };
	vector<int> edge{ 1, 3, 5, 7 };
	int move = 0;

	while (true) {
		clrscr();

		display(x, y);

		for (int j = 0; j < 9; j++) {
			if (arr[j] != 0) {
				gotoxy(8 * (j % 3) + 13, 3 * (j / 3 + 1)); cout << type[arr[j]];
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
				if (i == 4) { arr[i] = 1; arr[8] = 3; }
				else { arr[i] = 1; arr[4] = 3; }
				move++;
			}
			else if (move == 1) {
				if (arr[i] != 0);
				else {
					arr[i] = 1;
					if (arr[0] + arr[4] + arr[8] == 5 || arr[2] + arr[4] + arr[6] == 5) {
						if ((arr[0] == arr[8] && arr[8] == 1) || (arr[2] == arr[6] && arr[6] == 1)) arr[1] = 3;
						else arr[2] = 3;
					}
					else {
						c = checkWin0(arr);
						if (c < 9) arr[c] = 3;
						else {
							if ((arr[3] != 0 && arr[5] != 0) || (arr[1] != 0 && arr[7] != 0)) arr[0] = 3;
							else if (arr[0] == arr[8] && arr[8] == 0) {
								if ((arr[1] != 0 && arr[6] != 0) || (arr[2] != 0 && arr[3] != 0))arr[0] = 3;
								else if ((arr[7] != 0 && arr[2] != 0) || (arr[5] != 0 && arr[6] != 0))arr[8] = 3;
							}
							else if (arr[2] == arr[6] && arr[6] == 0) {
								if ((arr[1] != 0 && arr[8] != 0) || (arr[0] != 0 && arr[5] != 0))arr[2] = 3;
								else if ((arr[0] != 0 && arr[7] != 0) || (arr[8] != 0 && arr[3] != 0))arr[6] = 3;
							}
						}
					}
					move++;
				}
				
			}
			else {
				if (arr[i] != 0);
				else {
					arr[i] = 1;
					c = checkWin0(arr);
					d = checkWinx(arr);
					if (d < 9) {
						arr[d] = 3;
						gotoxy(8 * (d % 3) + 13, 3 * (d / 3 + 1)); cout << type[arr[d]];
						gotoxy(8 * (i % 3) + 13, 3 * (i / 3 + 1)); cout << type[arr[i]];
						gotoxy(50, 7);  cout << "You Lost"; gotoxy(0, 20);
						break;
					}
					else if (c < 9) arr[c] = 3; 
					else {
						bool cont = false;
						for (int k = 0; k < 9; k++) {
							if (arr[k] == 0) {
								arr[k] = 3;
								cont = true;
								break;
							}
						}
						if (cont) continue;
						gotoxy(8 * (i % 3) + 13, 3 * (i / 3 + 1)); cout << type[arr[i]];
						gotoxy(8 * (i % 3) + 13, 3 * (i / 3 + 1)); cout << type[arr[i]];
						gotoxy(50, 7);  cout << "draw"; gotoxy(0, 20);
						break;
					}
					move++;
				}
			}
		}
		
	}
	cout << "Press enter to exit"; cin.get();
}


void display(int x, int y) {
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

}

int checkWin0(int* ptr) {

	int diag1 = 0, diag2 = 0;
	for (int i = 0, j = 0; i < 3; i++, j += 3 ) {
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

int checkWinx(int* ptr) {

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


