#include <iostream>
#include "/home/StGermain/Documents/code/packages/colors.h"
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
// MAP FUNCTION**************************************************************************************************
// This will be a function that returns a char, which will determine what occurs in the next part according to the location of the player
vector<string> world_map = {
	"________________________",
	"|               .      |",
	"|   .          .   .   |",
	"|.    .   .            |",
	"| .               .    |",
	"|          .          .|",
	"|             .        |",
	"| .       .            |",
	"|                      |",
	"|   . .        .  .    |",
	"|     .         .      |",
	"|.       .      .      |",
	"|                 .  . |",
	"^^^^^^^^^^^^^^^^^^^^^^^^",
};

void damage() {
        for (int j = 0; j < 9; j++) {
                setbgcolor(255,0,0);
                for (int i = 0; i < 100'000; i++)
                        cout << ' ';
                setbgcolor(255,255,255);
                for (int i = 0; i < 100'000; i++)
                        cout << " \a";
                }
        setbgcolor(0,0,0);
        clearscreen();
        cout << endl;
        system("clear");
}


char get_world_location(size_t row, size_t col) {
	if (row >= world_map.size()) return ' ';
	if (col >= world_map.at(row).size()) return ' ';
	return world_map.at(row).at(col);
}

void print_world(size_t player_row, size_t player_col, size_t titan_row, size_t titan_col, size_t Jrow, size_t Jcol, size_t Arow, size_t Acol, size_t Erow, size_t Ecol) {
	clearscreen();
	movecursor(0,0);
	for (size_t row = 0; row < world_map.size(); row++) {
		for (size_t col = 0; col < world_map.at(row).size(); col++) {
			if (row == player_row and col == player_col) cout << RED << '%' << RESET;
			else if (row == Jrow and col == Jcol) {
				if (Jrow != player_row or Jcol != player_col) {
				setcolor(255,165,0); 
				cout << 'J' << RESET;
				}
			}
			else if (row == Erow and col == Ecol) {
				if (Erow != player_row or Ecol != player_col) cout << BLUE << 'E' << RESET;
			}
			else if (row == Arow and col == Acol) {
				if (Arow != player_row or Acol != player_col) {
					setcolor(255,255,0);
					cout << 'A' << RESET;
				}
			}
			else if (row == titan_row and col == titan_col) {
				setcolor(102,153,204);
				cout << 'T' << RESET;
			}
			else
				cout << world_map.at(row).at(col);
		}
		cout << endl;
	}
}

const size_t tr1 = 4, tr2 = 5, tr3 = 6, tc1 = 4, tc2 = 5, tc3 = 6, tc4 = 7, tc5 = 8;

void move_titan(size_t &titan_row, size_t &titan_col) {
	if (titan_row == tr1) {
		if (titan_col == tc2) titan_col = tc3; 
		else if (titan_col == tc3) titan_col = tc4;
		else if (titan_col == tc4) titan_col = tc5, titan_row = tr2; //error
	}
	if (titan_row == tr2) {
		if (titan_col == tc5) titan_col = tc4, titan_row = tr3; // error
		else if (titan_col == tc1) titan_col = tc2, titan_row = tr1;
	}
	if (titan_row == tr3) {
		if (titan_col == tc4) titan_col = tc3;
		else if (titan_col == tc3) titan_col = tc2;
		else if (titan_col == tc2) titan_col = tc1, titan_row = tr2;
	}
}

bool first_flight = 1; //this will be one at game start, then 0 for the rest of the game

int main(/*char &locale, bool &warp_D_online, bool &first_flight, int &crash_row, int &crash_col*/) {
	char locale = 'E';//remove, should get from gameplay
	cout << "Where did the player start from?\n";
	cin >> locale;//remove
	

	int row, col, inputCounter = 0, crash_row, crash_col;
	size_t titan_row = tr1, titan_col = tc2;
	const size_t Jrow = 5, Jcol = 6, Arow = 1, Acol = 22, Erow = 11, Ecol = 4;
	const int ROWS = world_map.size();
	const int COLS = world_map.at(0).size();
	const int FPS = 5;
	if (locale == 'E') row = 11, col = 5;
	if (locale == 'T') row = 4, col = 3;
	if (locale == 'C') row = crash_row, col = crash_col;
	set_raw_mode(true);
	show_cursor(false);
	while (true) {
		int c = toupper(quick_read());
		if (c == 'W' or c == UP_ARROW) {
			inputCounter++;
			row--;
			move_titan(titan_row, titan_col);
		}
		if (c == 'S' or c == DOWN_ARROW) {
			inputCounter++;
			row++;
			move_titan(titan_row, titan_col);
		}
		if (c == 'A' or c == LEFT_ARROW) {
			inputCounter++;
			col--;
			move_titan(titan_row, titan_col);
		}
		if (c == 'D' or c == RIGHT_ARROW) {
			inputCounter++;
			col++;
			move_titan(titan_row, titan_col);
		}
		print_world(row, col, titan_row, titan_col, Jrow, Jcol, Arow, Acol, Erow, Ecol);
		//move_titan(titan_row, titan_col); //makes constant orbit while stationary
		movecursor(0,0);
		cout.flush();
		/*if (first_flight == 1) {
			if (inputCounter == 7) {
				damage();
				set_raw_mode(false);
				show_cursor(true);
				movecursor(0,0);
				clearscreen();
				crash_row = row, crash_col = col;
				first_flight = 0;
				locale = 'C';
				return 'C';
			}
		}*/
		if (row == Erow and col == Ecol) {
			set_raw_mode(false);
			show_cursor(true);
			movecursor(0,0);
			clearscreen();
			locale = 'E';
			return 'E';
		}
		if (row == titan_row and col == titan_col) {
			set_raw_mode(false);
			show_cursor(true);
			movecursor(0,0);
        		clearscreen();
			locale = 'T';
			return 'T';
		}
		if (row == Arow and col == Acol/* and bool warpDrive == true*/) {
			set_raw_mode(false);
			show_cursor(true);
			movecursor(0,0);
			clearscreen();
			locale = 'A';
			return 'A';
		}
		if (c == ERR) usleep(1'000'000 / FPS);
	}
}
// MAP FUNCTION**************************************************************************************************
	
