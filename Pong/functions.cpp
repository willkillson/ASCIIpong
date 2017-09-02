#include <iostream>
#include <Windows.h>
#include "functions.h"

using namespace std;



void window::gotoXY(int x, int y) {

	HANDLE hOut;
	COORD Position;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	Position.X = x;
	Position.Y = y;
	SetConsoleCursorPosition(hOut, Position);


	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void window::setstate_board() {

	size_paddle_playr1 = 1;
	size_paddle_playr2 = 1;
	window::create_player1();
	window::create_player2();
	window::create_ball();

	ballvecXPLUS = 0;
	ballvecXMINUS = 8;
	ballvecYPLUS = 2;
	ballvecYMINUS = 0;

	scorep1 = 0;
	scorep2 = 0;

	ballmovX = 0;
	ballmovY = 0;

}




void window::print_board() {
	int i = 0;
	int j = 0;

	window::gotoXY(0, 0);
	for (i = 0; i < MAXHEIGHT; i++) {
		for (j = 0; j < MAXWIDTH; j++) {

			if (board[i][j] == 0) {
				cout << space;
			}
			if (board[i][j] == 1) {
				cout << boarder;
			}
			if (board[i][j] == 2) {
				cout << player;
			}
			if (board[i][j] == 3) {
				cout << ball;
			}
			if (board[i][j] == 4) {
				cout << missile;
			}

		}
		cout << "\n";
	}
	window::gotoXY(81, 0);
	printf("Score");
	window::gotoXY(81, 1);
	printf("Player 1  %d", scorep1);
	window::gotoXY(81, 2);
	printf("Player 2  %d", scorep2);
}

void window::create_board() {
	int i = 0;
	int j = 0;

	for (i = 0; i < MAXHEIGHT; i++) {
		for (j = 0; j < MAXWIDTH; j++) {
			//set everything to zero
			board[i][j] = 0;
		}
	}

	for (i = 0; i < MAXHEIGHT; i++) {
		for (j = 0; j < MAXWIDTH; j++) {
			//if on border set it to 1
			if (i == 0) {
				board[i][j] = 1;
			}
			if (j == 0) {
				board[i][j] = 1;
			}
			if (j == MAXWIDTH - 1) {
				board[i][j] = 1;
			}
			if (i == MAXHEIGHT - 1) {
				board[i][j] = 1;
			}
		}
	}

}
void window::create_player1() {
	int i = size_paddle_playr1;

	board[MAXHEIGHT / 2][MAXWIDTH - MAXWIDTH + 2] = 2;
	board[(MAXHEIGHT / 2) + i][MAXWIDTH - MAXWIDTH + 2] = 2;
	board[(MAXHEIGHT / 2) - i][MAXWIDTH - MAXWIDTH + 2] = 2;

}
void window::create_player2() {
	int i =size_paddle_playr2;

	board[MAXHEIGHT / 2][MAXWIDTH - 3] = 2;
	board[(MAXHEIGHT / 2) + i][MAXWIDTH - 3] = 2;
	board[(MAXHEIGHT / 2) - i][MAXWIDTH - 3] = 2;
}
void window::create_ball() {

	board[MAXHEIGHT / 2][MAXWIDTH/2] = 3;


}


void window::move_player1(int y) {

	for (int i = 0; i < MAXHEIGHT; i++) {

		if ((y == 1) && (board[i][MAXWIDTH - MAXWIDTH + 2] == 2)) {
			if (board[1][MAXWIDTH - MAXWIDTH + 2] == 2) {
				break;
			}
			board[i - 1][MAXWIDTH - MAXWIDTH + 2] = 2;
			board[i + 2][MAXWIDTH - MAXWIDTH + 2] = 0;
			break;
		}
		if ((y == 2) && (board[i][MAXWIDTH - MAXWIDTH + 2] == 2)) {
			if (board[MAXHEIGHT - 2][MAXWIDTH - MAXWIDTH + 2] == 2) {
				break;
			}
			board[i][MAXWIDTH - MAXWIDTH + 2] = 0;
			board[i + 3][MAXWIDTH - MAXWIDTH + 2] = 2;
			break;
		}

	}


}
void window::move_player2(int y) {

	for (int i = 0; i < MAXHEIGHT; i++) {


		if ((y == 1) && (board[i][MAXWIDTH - 3] == 2)) {
			if (board[1][MAXWIDTH - 3] == 2) {
				break;
			}
			board[i - 1][MAXWIDTH - 3] = 2;
			board[i + 2][MAXWIDTH - 3] = 0;
			break;
		}
		if ((y == 2) && (board[i][MAXWIDTH - 3] == 2)) {
			if (board[MAXHEIGHT - 2][MAXWIDTH - 3] == 2) {
				break;
			}
			board[i][MAXWIDTH - 3] = 0;
			board[i + 3][MAXWIDTH - 3] = 2;
			break;
		}

	}


}


void window::move_ballMASTER() {



	ballmovX = ballmovX + ballvecXPLUS + ballvecXMINUS;
	ballmovY = ballmovY + ballvecYPLUS + ballvecYMINUS;

	if (ballmovY >= 5) {
		if (ballvecYPLUS > ballvecYMINUS) {
			move_ballUP();
			ballmovY = 0;
		}
		else {
			move_ballDOWN();
			//return;
			ballmovY = 0;
		}
		return;

	}
	if (ballmovX >= 5) {
		if (ballvecXMINUS > ballvecXPLUS) {
			move_ballLEFT();
			ballmovX = 0;
			//return;
		}
		else {
			move_ballRIGHT();
			ballmovX = 0;
			//return;
		}
		return;
	}

}
void window::move_ballUP() {

	int i = 0;
	int j = 0;


		for (i = 0; i < MAXHEIGHT; i++) {
			for (j = 0; j < MAXWIDTH; j++) {
				if ((board[i][j] == 3) && (i == 1)) {
					window::gotoXY(0, 29);
					printf("Bounce off top      ");
					ballvecYMINUS = ballvecYPLUS;
					ballvecYPLUS = 0;
					return;

				}
				else if (board[i][j] == 3) {
					board[i][j] = 0;
					board[i - 1][j] = 3;
					return;
				}

			}

		}


}
void window::move_ballDOWN() {
	int i = 0;
	int j = 0;

		for (i = 0; i < MAXHEIGHT; i++) {
			for (j = 0; j < MAXWIDTH; j++) {
				if ((board[i][j] == 3) && (i == MAXHEIGHT - 2)) {
					window::gotoXY(0, 29);
					printf("Bounce off bottum         ");
					ballvecYPLUS = ballvecYMINUS;
					ballvecYMINUS = 0;
					return;

				}
				else if (board[i][j] == 3) {
					board[i][j] = 0;
					board[i + 1][j] = 3;
					return;

				}

			}

		}


}
void window::move_ballLEFT() {
	int i = 0;
	int j = 0;

	for (i = 0; i < MAXHEIGHT; i++) {
		for (j = 0; j < MAXWIDTH; j++) {
			if (((board[i][j] == 3) && (j == 2 ))||((board[i][j-1] == 2) && (board[i][j] == 3))) {
				window::gotoXY(0, 29);
				printf("Bounce off left         ");
				ballvecXPLUS = ballvecXMINUS;
				ballvecXMINUS = 0;
				return;

			}
			else if (board[i][j] == 3) {
				board[i][j] = 0;
				board[i][j-1] = 3;
				return;

			}

		}

	}


}
void window::move_ballRIGHT() {
	int i = 0;
	int j = 0;

	for (i = 0; i < MAXHEIGHT; i++) {
		for (j = 0; j < MAXWIDTH; j++) {
			if (((board[i][j] == 3) && (j == MAXWIDTH -2))|| ((board[i][j+1] == 2) && (board[i][j] == 3))) {
				window::gotoXY(0, 29);
				printf("Bounce off right        ");
				ballvecXMINUS = ballvecXPLUS;
				ballvecXPLUS = 0;
				return;

			}
			else if (board[i][j] == 3) {
				board[i][j] = 0;
				board[i][j + 1] = 3;
				return;

			}

		}

	}
	
}


window::window() {
	window::gotoXY(0, 29);
	cout << "Creating board" << endl;

}

window::~window() {
	window::gotoXY(0, 29);
	cout << "Destroying board" << endl;

}

