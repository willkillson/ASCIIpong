#pragma once

#define MAXHEIGHT 25
#define MAXWIDTH 80
#define boarder '*'
#define missile '='
#define ball 'o'
#define space ' '
#define player '|'

class window {

public:
	
	void gotoXY(int x, int y);
	window();
	~window();
	void create_board();
	void print_board();
	void create_player1();
	void create_player2();
	void move_player1(int y);
	void move_player2(int y);
	void create_ball();
	void move_ballMASTER();
	void move_ballUP();
	void move_ballDOWN();
	void move_ballLEFT();
	void move_ballRIGHT();

	void setstate_board();


private:
	int board[MAXHEIGHT][MAXWIDTH];// 0 = space // 1 = boarder//2 = player // 3 = ball // 4 = missile
	int size_paddle_playr1;
	int size_paddle_playr2;

	int scorep1;
	int scorep2;

	int ballvecXPLUS;
	int ballvecXMINUS;

	int ballvecYPLUS;
	int ballvecYMINUS;

	int ballmovX;
	int ballmovY;


};