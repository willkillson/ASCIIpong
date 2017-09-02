#include <iostream>
#include "functions.h"
#include <windows.h>

#include <iostream>
using namespace std;




int main() {




	int i = 0;
	int j = 0;
	int k = 0;

	int clock = 0;
	
	window x;
	x.create_board();
	x.setstate_board();


	// main game loop
	while (1) {

		if (clock % 2 == 0) {
			x.move_ballMASTER();
		}
		x.print_board();


		//Sleep(135);
		if (GetAsyncKeyState('W') & 0x8000) {
			x.move_player1(1);
		}
		if (GetAsyncKeyState('S') & 0x8000) {
			x.move_player1(2);
		}
		if (GetAsyncKeyState(VK_UP) & 0x8000) {
			x.move_player2(1);
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			x.move_player2(2);
		}
		clock++;
	}

}