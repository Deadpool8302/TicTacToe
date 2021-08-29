#include"consolehandle.hpp"
#include"Game.hpp"

using namespace std;

WelcomeScreen game;

int main() {
	while (true) {
		clrscr();
		game.displayChoice();
		int input = _getch();
		if (input == 50) game.playerVSplayer();
		else if (input == 49) game.playerVScomp();
		else if (input == 'e') break;
		else continue;
	}
}


