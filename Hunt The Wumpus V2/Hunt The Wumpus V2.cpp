// Hunt The Wumpus V2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <conio.h>
#include <Windows.h>
using namespace std;

/*
void MoveDown(int row, int matrix[5][5], int col) {
	/*
	cout << "Down" << endl;
	row += 1;
	cout << "row = " << row << "; col = " << col << endl;
	for (int r = 0; r < 5; r++)
	{
	for (int c = 0; c < 5; c++)
	{
	if ((r == row) && (c == col)) {
	colors.setfg(light_yellow);
	}
	cout << matrix[r][c];
	colors.setcolors(colors.initial_colors);
	cout << " ";
	}
	cout << endl;
	}
	cout << endl;
	
}​
*/

struct colors_t
{
	HANDLE hstdout;
	int    initial_colors;

	colors_t()
	{
		hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
		initial_colors = getcolors();
	}

	~colors_t()
	{
		setcolors(initial_colors);
	}

	int getcolors() const
	{
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(hstdout, &csbi);
		return csbi.wAttributes;
	}

	void setcolors(int color)
	{
		SetConsoleTextAttribute(hstdout, color);
	}

	void setfg(int color)
	{
		int current_colors = getcolors();
		setcolors((current_colors & 0xF0) | (color & 0x0F));
	}

	void setbg(int color)
	{
		int current_colors = getcolors();
		setcolors(((color & 0x0F) << 4) | (current_colors & 0x0F));
	}

	int getfg() const { return  getcolors() & 0x0F; }
	int getbg() const { return (getcolors() >> 4) & 0x0F; }
};


void Move() {}




	enum {
		black,
		dark_blue,
		dark_green,
		dark_cyan,
		dark_red,
		dark_magenta,
		dark_yellow,
		light_gray,
		dark_gray,
		light_blue,
		light_green,
		light_cyan,
		light_red,
		light_magenta,
		light_yellow,
		white
	};

	//

	/*
	void MoveUp (int row, int matrix[5][5], int col){
		colors_t colors;
		cout << "UP" << endl;

		row -= 1;
		cout << "row = " << row << "; col = " << col << endl;
		for (int r = 0; r < 5; r++)
		{
			for (int c = 0; c < 5; c++)
			{
				if ((r == row) && (c == col))
					colors.setfg(light_yellow);

				cout << matrix[r][c];
				colors.setcolors(colors.initial_colors);
				cout << " ";
			}
			cout << endl;
		}
		cout << endl;
	}


	void MoveLeft(int row, int matrix[5][5], int col) {
		colors_t colors;
		cout << "Left" << endl;
		col -= 1;
		cout << "row = " << row << "; col = " << col << endl;
		for (int r = 0; r < 5; r++)
		{
			for (int c = 0; c < 5; c++)
			{
				if ((r == row) && (c == col))
					colors.setfg(light_yellow);
				cout << matrix[r][c];
				colors.setcolors(colors.initial_colors);
				cout << " ";
			}
			cout << endl;
		}
		cout << endl;
	}



	​
	void MoveRight(int row, int matrix[5][5], int col) {
		colors_t colors;
		cout << "Right" << endl;
		col += 1;
		cout << "row = " << row << "; col = " << col << endl;
		for (int r = 0; r < 5; r++)
		{
			for (int c = 0; c < 5; c++)
			{
				if ((r == row) && (c == col))
					colors.setfg(light_yellow);
				cout << matrix[r][c];
				colors.setcolors(colors.initial_colors);
				cout << " ";
			}
			cout << endl;
		}
		cout << endl;
	}​
	*/



	int main()
	{
		colors_t colors;
		cout << "	Hunt to kill the Wumpus." << endl;
		cout << "	The Wumpus is hiding in a 5x5 square." << endl;
		cout << "	You are the yellow zero." << endl;
		cout << "	You will be given hints about what you are the surrounded by, every time you move." << endl;
		cout << "	When you think you've found the Wumpus, shoot an arrow in that direction." << endl;
		cout << "	But make sure not to move into his square because he will eat you." << endl;
		cout << "	**CAUTION There are pits that you can fall into, so use the hints given and try to avoid them.**" << endl;
		cout << " " << endl;
		cout << " " << endl;
		//	How to Move
		cout << "	How to Move" << endl;
		cout << "	Press 1 to move up one square" << endl;
		cout << "	Press 2 to move down one square" << endl;
		cout << "	Press 3 to move to the left one square" << endl;
		cout << "	Press 4 to move to the Right one square" << endl;
		cout << " " << endl;
		//	How to Shoot an Arrow
		cout << "	How to SHOOT an Arrow" << endl;
		cout << "	Press the 1 to shoot an arrow UP one square" << endl;
		cout << "	Press the 2 to shoot an arrow DOWN one square" << endl;
		cout << "	Press the 3 to shoot an arrow LEFT one square" << endl;
		cout << "	Press the 4 to shoot an arrow RIGHT one square" << endl;

		random_device rd;
		uniform_int_distribution<int> RandomStartrow(0, 4);

		random_device rr;
		uniform_int_distribution<int> RandomStartcol(0, 4);

		random_device pp;
		uniform_int_distribution<int> RandomPit1r(0, 4);

		random_device pr;
		uniform_int_distribution<int> RandomPit2r(0, 4);

		random_device rp;
		uniform_int_distribution<int> RandomPit3r(0, 4);

		random_device pw;
		uniform_int_distribution<int> RandomPit1c(0, 4);

		random_device wp;
		uniform_int_distribution<int> RandomPit2c(0, 4);

		random_device ww;
		uniform_int_distribution<int> RandomPit3c(0, 4);

		random_device re;
		uniform_int_distribution<int> RandomWumpusrow(0, 4);

		random_device rc;
		uniform_int_distribution<int> RandomWumpuscol(0, 4);

		int row = RandomStartrow(rd);

		int col = RandomStartcol(rr);
		int wumpusrow = RandomWumpusrow(re);
		int wumpuscol = RandomWumpuscol(rc);
		int pit1r = RandomPit1r(pp);
		int pit2r = RandomPit2r(pr);
		int pit3r = RandomPit3r(rp);
		int pit1c = RandomPit1c(pw);
		int pit2c = RandomPit2c(wp);
		int pit3c = RandomPit3c(ww);

		int matrix[5][5] = {
			{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0 }
		};

		cout << "row = " << row + 1 << "; col = " << col + 1 << endl;

		for (int r = 0; r < 5; r++)
		{
			for (int c = 0; c < 5; c++)
			{
				if ((r == row) && (c == col))
					colors.setfg(light_yellow);
				cout << matrix[r][c];
				colors.setcolors(colors.initial_colors);
				cout << " ";
			}
			cout << endl;
		}
		//colors.setfg(light_yellow);
		//cout << matrix[row][col] << endl;
		//colors.setcolors(colors.initial_colors);
		
		bool WumpusFound = false;
		bool FallInPit = false;
		int input;
		int arrowsleft = 5;
		while (WumpusFound == false && FallInPit == false) {
			cout << "Would you like to move(1) or shoot(2)?" << endl;
			
		int q;
			cin >> q;
			if (q == 1) {
				

					cout << "What direction would you like to move" << endl;
					cout << "UP - 1" << endl;
					cout << "DOWN - 2" << endl;
					cout << "LEFT - 3" << endl;
					cout << "RIGHT - 4" << endl;
					cout << " " << endl;
					cin >> input;

					if (input == 1) {

						//MoveUp(row, matrix, col);



						cout << "UP" << endl;

						cout << "row = " << row << "; col = " << col << endl;
						row -= 1;
						if (row == wumpusrow && col == wumpuscol) {

							WumpusFound = true;
							cout << "GAME OVER" << endl;
							cout << "You walked into the Wumpus, HE ATE YOU!" << endl;
						}
						else if (wumpusrow == row + 1) {
							cout << " You hear a growl nearby." << endl;

						}
						else if (wumpusrow == row - 1) {
							cout << " You hear a growl nearby." << endl;

						}
						else if (wumpuscol == col + 1) {
							cout << " You hear a growl nearby." << endl;

						}
						else if (wumpuscol == col - 1) {
							cout << " You hear a growl nearby." << endl;

						}
						else if (row == -1) {
							cout << "Invalid direction. You almost went off the grid. Please choose another direction." << endl;
							WumpusFound = false;
							FallInPit = false;
							row = 0;
						}
						else if (row == 4) {
							cout << "Invalid direction.You almost went off the grid.Please choose another direction." << endl;

							FallInPit = false;

						}
						else if (col == -1) {
							cout << "Invalid direction. You almost went off the grid. Please choose another direction." << endl;
							WumpusFound = false;
							FallInPit = false;
							col = 0;
						}
						else if (col == 5) {
							cout << "Invalid direction.You almost went off the grid.Please choose another direction." << endl;
							WumpusFound = false;
							FallInPit = false;
							col = 4;
						}
						else if (col < 0) {
							cout << "Invalid direction. You almost went off the grid. Please choose another direction." << endl;
							WumpusFound = false;
							FallInPit = false;
							col = 0;
						}
						else if (col > 4) {
							cout << "Invalid direction.You almost went off the grid.Please choose another direction." << endl;
							WumpusFound = false;
							FallInPit = false;
							col = 4;
						}
						else if (row < 0) {
							cout << "Invalid direction. You almost went off the grid. Please choose another direction." << endl;
							WumpusFound = false;
							FallInPit = false;
							row = 0;
						}
						else if (row == 4) {
							cout << "Invalid direction.You almost went off the grid.Please choose another direction." << endl;
							WumpusFound = false;
							FallInPit = false;
							row = 4;
						}
						else if (row == pit1r && col == pit1c) {
							cout << "OH NO! You fell down a Pit. YOU DEAD." << endl;
							FallInPit = true;
						}
						else if (row == pit2r && col == pit2c) {
							cout << "OH NO! You fell down a Pit. YOU DEAD." << endl;
							FallInPit = true;
						}
						else if (row == pit3r && col == pit3c) {
							cout << "OH NO! You fell down a Pit. YOU DEAD." << endl;
							FallInPit = true;
						}
						else if (pit1r == row + 1) {
							cout << "You feel a breeze go by." << endl;

						}
						else if (pit2r == row + 1) {
							cout << "You feel a breeze go by." << endl;

						}
						else if (pit3r == row + 1) {
							cout << "You feel a breeze go by." << endl;

						}
						else if (pit1r == row - 1) {
							cout << "You feel a breeze go by." << endl;

						}
						else if (pit2r == row - 1) {
							cout << "You feel a breeze go by." << endl;

						}
						else if (pit3r == row - 1) {
							cout << "You feel a breeze go by." << endl;

						}
						else if (pit1c == col + 1) {
							cout << "You feel a breeze go by." << endl;

						}
						else if (pit2c == col + 1) {
							cout << "You feel a breeze go by." << endl;

						}
						else if (pit3c == col + 1) {
							cout << "You feel a breeze go by." << endl;

						}
						else if (pit1c == col - 1) {
							cout << "You feel a breeze go by." << endl;

						}
						else if (pit2c == col - 1) {
							cout << "You feel a breeze go by." << endl;

						}
						else if (pit3c == col - 1) {
							cout << "You feel a breeze go by." << endl;

						}
					}
					else if (input == 2) {
						cout << "Down" << endl;

						cout << "row = " << row << "; col = " << col << endl;
						row += 1;
						if (row == wumpusrow && col == wumpuscol) {

							WumpusFound = true;
							cout << "GAME OVER" << endl;
							cout << "You walked into the Wumpus, HE ATE YOU!" << endl;
						}
						else if (wumpusrow == row + 1) {
							cout << " You hear a growl nearby." << endl;

						}
						else if (wumpusrow == row - 1) {
							cout << " You hear a growl nearby." << endl;

						}
						else if (wumpuscol == col + 1) {
							cout << " You hear a growl nearby." << endl;

						}
						else if (wumpuscol == col - 1) {
							cout << " You hear a growl nearby." << endl;

						}

						if (row == 0) {
							cout << "Invalid direction. You almost went off the grid. Please choose another direction." << endl;
							WumpusFound = false;
							FallInPit = false;
							row = 0;
						}
						else if (row == 4) {
							cout << "Invalid direction.You almost went off the grid.Please choose another direction." << endl;
							WumpusFound = false;
							FallInPit = false;
							row = 4;
						}
						else if (col < 0) {
							cout << "Invalid direction. You almost went off the grid. Please choose another direction." << endl;
							WumpusFound = false;
							FallInPit = false;
							col = 0;
						}
						else if (col > 4) {
							cout << "Invalid direction.You almost went off the grid.Please choose another direction." << endl;
							WumpusFound = false;
							FallInPit = false;
							col = 4;
						}
						else if (row < 0) {
							cout << "Invalid direction. You almost went off the grid. Please choose another direction." << endl;
							WumpusFound = false;
							FallInPit = false;
							row = 0;
						}
						else if (row == 5) {
							cout << "Invalid direction.You almost went off the grid.Please choose another direction." << endl;
							WumpusFound = false;
							FallInPit = false;
							row = 4;
						}
						else if (col == -1) {
							cout << "Invalid direction. You almost went off the grid. Please choose another direction." << endl;
							WumpusFound = false;
							FallInPit = false;
							col = 0;
						}
						else if (col == 5) {
							cout << "Invalid direction.You almost went off the grid.Please choose another direction." << endl;
							WumpusFound = false;
							FallInPit = false;
							col = 4;
						}
						else if (row == pit1r && col == pit1c) {
							cout << "OH NO! You fell down a Pit. YOU DEAD." << endl;
							FallInPit = true;
						}
						else if (row == pit2r && col == pit2c) {
							cout << "OH NO! You fell down a Pit. YOU DEAD." << endl;
							FallInPit = true;
						}
						else if (row == pit3r && col == pit3c) {
							cout << "OH NO! You fell down a Pit. YOU DEAD." << endl;
							FallInPit = true;
						}
						else if (pit1r == row + 1) {
							cout << "You feel a breeze go by." << endl;

						}
						else if (pit2r == row + 1) {
							cout << "You feel a breeze go by." << endl;

						}
						else if (pit3r == row + 1) {
							cout << "You feel a breeze go by." << endl;

						}
						else if (pit1r == row - 1) {
							cout << "You feel a breeze go by." << endl;

						}
						else if (pit2r == row - 1) {
							cout << "You feel a breeze go by." << endl;

						}
						else if (pit3r == row - 1) {
							cout << "You feel a breeze go by." << endl;

						}
						else if (pit1c == col + 1) {
							cout << "You feel a breeze go by." << endl;

						}
						else if (pit2c == col + 1) {
							cout << "You feel a breeze go by." << endl;

						}
						else if (pit3c == col + 1) {
							cout << "You feel a breeze go by." << endl;

						}
						else if (pit1c == col - 1) {
							cout << "You feel a breeze go by." << endl;

						}
						else if (pit2c == col - 1) {
							cout << "You feel a breeze go by." << endl;

						}
						else if (pit3c == col - 1) {
							cout << "You feel a breeze go by." << endl;

						}
						//MoveDown(row, matrix, col);


					}
					else if (input == 3) {
						cout << "LEFT" << endl;

						cout << "row = " << row << "; col = " << col << endl;
						col -= 1;
						if (row == wumpusrow && col == wumpuscol) {

							WumpusFound = true;
							cout << "GAME OVER" << endl;
							cout << "You walked into the Wumpus, HE ATE YOU!" << endl;
						}
						else if (wumpusrow == row + 1) {
							cout << " You hear a growl nearby." << endl;

						}
						else if (wumpusrow == row - 1) {
							cout << " You hear a growl nearby." << endl;

						}
						else if (wumpuscol == col + 1) {
							cout << " You hear a growl nearby." << endl;

						}
						else if (wumpuscol == col - 1) {
							cout << " You hear a growl nearby." << endl;

						}
						else if (row == -1) {
							cout << "Invalid direction. You almost went off the grid. Please choose another direction." << endl;
							WumpusFound = false;
							FallInPit = false;
							row = 0;
						}
						else if (row == 5) {
							cout << "Invalid direction.You almost went off the grid.Please choose another direction." << endl;
							WumpusFound = false;
							FallInPit = false;
							row = 4;
						}
						else if (col == 0) {
							cout << "Invalid direction. You almost went off the grid. Please choose another direction." << endl;
							WumpusFound = false;
							FallInPit = false;
							col = 0;
						}
						else if (col == 5) {
							cout << "Invalid direction.You almost went off the grid.Please choose another direction." << endl;
							WumpusFound = false;
							FallInPit = false;
							col = 4;
						}
						else if (col < 0) {
							cout << "Invalid direction. You almost went off the grid. Please choose another direction." << endl;
							WumpusFound = false;
							FallInPit = false;
							col = 0;
						}
						else if (col > 4) {
							cout << "Invalid direction.You almost went off the grid.Please choose another direction." << endl;
							WumpusFound = false;
							FallInPit = false;
							col = 4;
						}
						else if (row < 0) {
							cout << "Invalid direction. You almost went off the grid. Please choose another direction." << endl;
							WumpusFound = false;
							FallInPit = false;
							row = 0;
						}
						else if (row > 4) {
							cout << "Invalid direction.You almost went off the grid.Please choose another direction." << endl;
							WumpusFound = false;
							FallInPit = false;
							row = 4;
						}
						else if (row == pit1r && col == pit1c) {
							cout << "OH NO! You fell down a Pit. YOU DEAD." << endl;
							FallInPit = true;
						}
						else if (row == pit2r && col == pit2c) {
							cout << "OH NO! You fell down a Pit. YOU DEAD." << endl;
							FallInPit = true;
						}
						else if (row == pit3r && col == pit3c) {
							cout << "OH NO! You fell down a Pit. YOU DEAD." << endl;
							FallInPit = true;
						}
						else if (pit1r == row + 1) {
							cout << "You feel a breeze go by." << endl;

						}
						else if (pit2r == row + 1) {
							cout << "You feel a breeze go by." << endl;

						}
						else if (pit3r == row + 1) {
							cout << "You feel a breeze go by." << endl;

						}
						else if (pit1r == row - 1) {
							cout << "You feel a breeze go by." << endl;

						}
						else if (pit2r == row - 1) {
							cout << "You feel a breeze go by." << endl;

						}
						else if (pit3r == row - 1) {
							cout << "You feel a breeze go by." << endl;

						}
						else if (pit1c == col + 1) {
							cout << "You feel a breeze go by." << endl;

						}
						else if (pit2c == col + 1) {
							cout << "You feel a breeze go by." << endl;

						}
						else if (pit3c == col + 1) {
							cout << "You feel a breeze go by." << endl;

						}
						else if (pit1c == col - 1) {
							cout << "You feel a breeze go by." << endl;

						}
						else if (pit2c == col - 1) {
							cout << "You feel a breeze go by." << endl;

						}
						else if (pit3c == col - 1) {
							cout << "You feel a breeze go by." << endl;

						}
						//MoveLeft(row, matrix, col);

					}
					else if (input == 4) {
						cout << "RIGHT" << endl;

						cout << "row = " << row << "; col = " << col << endl;
						col += 1;
						if (row == wumpusrow && col == wumpuscol) {

							WumpusFound = true;
							cout << "GAME OVER" << endl;
							cout << "You walked into the Wumpus, HE ATE YOU!" << endl;
						}
						else if (wumpusrow == row + 1) {
							cout << " You hear a growl nearby." << endl;

						}
						else if (wumpusrow == row - 1) {
							cout << " You hear a growl nearby." << endl;

						}
						else if (wumpuscol == col + 1) {
							cout << " You hear a growl nearby." << endl;

						}
						else if (wumpuscol == col - 1) {
							cout << " You hear a growl nearby." << endl;

						}
						else if (row == -1) {
							cout << "Invalid direction. You almost went off the grid. Please choose another direction." << endl;
							WumpusFound = false;
							FallInPit = false;
							row = 0;
						}
						else if (row == 4) {
							cout << "Invalid direction.You almost went off the grid.Please choose another direction." << endl;
							WumpusFound = false;
							FallInPit = false;
							row = 4;
						}
						else if (col == -1) {
							cout << "Invalid direction. You almost went off the grid. Please choose another direction." << endl;
							WumpusFound = false;
							FallInPit = false;
							col = 0;
						}
						else if (col == 5) {
							cout << "Invalid direction.You almost went off the grid.Please choose another direction." << endl;
							WumpusFound = false;
							FallInPit = false;
							col = 4;
						}
						else if (col < 0) {
							cout << "Invalid direction. You almost went off the grid. Please choose another direction." << endl;
							WumpusFound = false;
							FallInPit = false;
							col = 0;
						}
						else if (col > 4) {
							cout << "Invalid direction.You almost went off the grid.Please choose another direction." << endl;
							WumpusFound = false;
							FallInPit = false;
							col = 4;
						}
						else if (row < 0) {
							cout << "Invalid direction. You almost went off the grid. Please choose another direction." << endl;
							WumpusFound = false;
							FallInPit = false;
							row = 0;
						}
						else if (row > 4) {
							cout << "Invalid direction.You almost went off the grid.Please choose another direction." << endl;
							WumpusFound = false;
							FallInPit = false;
							row = 4;
						}
						else if (row == pit1r && col == pit1c) {
							cout << "OH NO! You fell down a Pit. YOU DEAD." << endl;
							FallInPit = true;
						}
						else if (row == pit2r && col == pit2c) {
							cout << "OH NO! You fell down a Pit. YOU DEAD." << endl;
							FallInPit = true;
						}
						else if (row == pit3r && col == pit3c) {
							cout << "OH NO! You fell down a Pit. YOU DEAD." << endl;
							FallInPit = true;
						}
						else if (pit1r == row + 1) {
							cout << "You feel a breeze go by." << endl;

						}
						else if (pit2r == row + 1) {
							cout << "You feel a breeze go by." << endl;

						}
						else if (pit3r == row + 1) {
							cout << "You feel a breeze go by." << endl;

						}
						else if (pit1r == row - 1) {
							cout << "You feel a breeze go by." << endl;

						}
						else if (pit2r == row - 1) {
							cout << "You feel a breeze go by." << endl;

						}
						else if (pit3r == row - 1) {
							cout << "You feel a breeze go by." << endl;

						}
						else if (pit1c == col + 1) {
							cout << "You feel a breeze go by." << endl;

						}
						else if (pit2c == col + 1) {
							cout << "You feel a breeze go by." << endl;

						}
						else if (pit3c == col + 1) {
							cout << "You feel a breeze go by." << endl;

						}
						else if (pit1c == col - 1) {
							cout << "You feel a breeze go by." << endl;

						}
						else if (pit2c == col - 1) {
							cout << "You feel a breeze go by." << endl;

						}
						else if (pit3c == col - 1) {
							cout << "You feel a breeze go by." << endl;

						}
						//MoveRight(row, matrix, col);

					}
					int matrix[5][5] = {
						{ 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0 } };

					for (int r = 0; r < 5; r++)
					{
						for (int c = 0; c < 5; c++)
						{
							if ((r == row) && (c == col)) {
								colors.setfg(light_yellow);
							}
							cout << matrix[r][c];
							cout;
							colors.setcolors(colors.initial_colors);


							cout << " ";
						}
						cout << endl;
					}
			}
			else if (q == 2) {
				if (arrowsleft > 0 ) {

					cout << "What direction would you like to shoot" << endl;
					cout << "UP - 1" << endl;
					cout << "DOWN - 2" << endl;
					cout << "LEFT - 3" << endl;
					cout << "RIGHT - 4" << endl;
					cout << " " << endl;




					int input2;
					cin >> input2;
					if (input2 == 1) {
						if (wumpusrow == row - 1) {
							cout << "SHOOT UP" << endl;
							cout << "Congrationlations!! You Have Killed The Wumpus!!" << endl;
							WumpusFound = true;
						}
						else {
							arrowsleft -= 1;
							cout << "Unfortunatley you have missed the wumpus. You have " << arrowsleft << " left" << endl;
							if (arrowsleft == 0) {
								cout << "Unfortunatley you have ran out of arrows! " << endl;
								FallInPit = false;
							}
							else if (arrowsleft < 0) {
								arrowsleft = 0;
							}
							else {
								FallInPit = false;
							}
						}

					}
					else if (input2 == 2) {
						cout << "SHOOT DOWN" << endl;
						if (wumpusrow == row + 1) {
							cout << "Congrationlations!! You Have Killed The Wumpus!!" << endl;
							WumpusFound = true;
						}
						else {
							arrowsleft -= 1;
							cout << "Unfortunatley you have missed the wumpus. You have " << arrowsleft << " left" << endl;
							if (arrowsleft == 0) {
								cout << "Unfortunatley you have ran out of arrows! " << endl;
								FallInPit = false;
							}
							else if (arrowsleft < 0) {
								arrowsleft = 0;
							}
							else {
								FallInPit = false;
							}

						}
					}
					else if (input2 == 3) {
						cout << "SHOOT LEFT" << endl;
						if (wumpusrow == col - 1) {
							cout << "Congrationlations!! You Have Killed The Wumpus!!" << endl;
							WumpusFound = true;
						}
						else {
							arrowsleft -= 1;
							cout << "Unfortunatley you have missed the wumpus. You have " << arrowsleft << " left" << endl;
							if (arrowsleft == 0) {
								cout << "Unfortunatley you have ran out of arrows! " << endl;
								FallInPit = false;
							}
							else if (arrowsleft < 0) {
								arrowsleft = 0;
							}
							else {
								FallInPit = false;
							}
						}
					}
					else if (input2 == 4) {
						cout << "SHOOT RIGHT" << endl;
						if (wumpusrow == col + 1) {
							cout << "Congrationlations!! You Have Killed The Wumpus!!" << endl;
							WumpusFound = true;
						}
						else {
							arrowsleft -= 1;
							cout << "Unfortunatley you have missed the wumpus. You have " << arrowsleft << " left" << endl;
							if (arrowsleft == 0) {
								cout << "Unfortunatley you have ran out of arrows! " << endl;
								FallInPit = false;
							}
							else if (arrowsleft < 0) {
								arrowsleft = 0;
							}

						}
					}
				}
				else {
					cout << "Please choose move. You have ran out of arrows" << endl;
					cout << " " << endl;
					cout << " " << endl;
					WumpusFound = false;
				}
			}
			else {
				cout << "invalid input, please put 1 or 2." << endl;
			}

			
			
			/*if (WumpusFound == true) {
				int matrix[5][5] = {
					{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 } };
				for (int wr = 0; wr < 5; wr++)
				{
					for (int wc = 0; wc < 5; wc++)
					{
						if ((wr == wumpusrow) && (wc == wumpuscol)) {
							colors.setfg(dark_red);
						}
						cout << matrix[wr][wc];
						cout;
						colors.setcolors(colors.initial_colors);


						cout << " ";
					}
					cout << endl;
				}
				for (int p1r = 0; p1r < 5; p1r++)
				{
					for (int p1c = 0; p1c < 5; p1c++)
					{
						if ((p1r == wumpusrow) && (p1c == wumpuscol)) {
							colors.setfg(light_magenta);
						}
						cout << matrix[p1r][p1c];
						cout;
						colors.setcolors(colors.initial_colors);


						cout << " ";
					}
					cout << endl;
				}
				for (int p2r = 0; p2r < 5; p2r++)
				{
					for (int p2c = 0; p2c < 5; p2c++)
					{
						if ((p2r == wumpusrow) && (p2c == wumpuscol)) {
							colors.setfg(light_magenta);
						}
						cout << matrix[p2r][p2c];
						cout;
						colors.setcolors(colors.initial_colors);


						cout << " ";
					}
					cout << endl;
				}
				for (int p3r = 0; p3r < 5; p3r++)
				{
					for (int p3c = 0; p3c < 5; p3c++)
					{
						if ((p3r == wumpusrow) && (p3c == wumpuscol)) {
							colors.setfg(light_magenta);
						}
						cout << matrix[p3r][p3c];
						cout;
						colors.setcolors(colors.initial_colors);


						cout << " ";
					}
					cout << endl;
				}
			}
			if (FallInPit == true) {
				int matrix[5][5] = {
					{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 } };
				for (int wr = 0; wr < 5; wr++)
				{
					for (int wc = 0; wc < 5; wc++)
					{
						if ((wr == wumpusrow) && (wc == wumpuscol)) {
							colors.setfg(dark_red);
						}
						cout << matrix[wr][wc];
						cout;
						colors.setcolors(colors.initial_colors);


						cout << " ";
					}
					cout << endl;
				}
				for (int p1r = 0; p1r < 5; p1r++)
				{
					for (int p1c = 0; p1c < 5; p1c++)
					{
						if ((p1r == wumpusrow) && (p1c == wumpuscol)) {
							colors.setfg(light_magenta);
						}
						cout << matrix[p1r][p1c];
						cout;
						colors.setcolors(colors.initial_colors);


						cout << " ";
					}
					cout << endl;
				}
				for (int p2r = 0; p2r < 5; p2r++)
				{
					for (int p2c = 0; p2c < 5; p2c++)
					{
						if ((p2r == wumpusrow) && (p2c == wumpuscol)) {
							colors.setfg(light_magenta);
						}
						cout << matrix[p2r][p2c];
						cout;
						colors.setcolors(colors.initial_colors);


						cout << " ";
					}
					cout << endl;
				}
				for (int p3r = 0; p3r < 5; p3r++)
				{
					for (int p3c = 0; p3c < 5; p3c++)
					{
						if ((p3r == wumpusrow) && (p3c == wumpuscol)) {
							colors.setfg(light_magenta);
						}
						cout << matrix[p3r][p3c];
						cout;
						colors.setcolors(colors.initial_colors);


						cout << " ";
					}
					cout << endl;
				}
			}
			cout << endl;
		}*/

			
		}
		return 0;
	}


	
		
