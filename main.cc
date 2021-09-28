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

int move_titan(size_t &titan_row, size_t &titan_col) {
        if (titan_row == tr1) {
                if (titan_col == tc2) {titan_col = tc3;}
                else if (titan_col == tc3) {titan_col = tc4;}
                else if (titan_col == tc4) {titan_col = tc5, titan_row = tr2; return 0;}
        }
        if (titan_row == tr2) {
                if (titan_col == tc5) {titan_col = tc4, titan_row = tr3;}
                else if (titan_col == tc1) {titan_col = tc2, titan_row = tr1; return 0;}
        }
        if (titan_row == tr3) {
                if (titan_col == tc4) {titan_col = tc3;}
                else if (titan_col == tc3) {titan_col = tc2;}
                else if (titan_col == tc2) {titan_col = tc1, titan_row = tr2;}
        }
        return 0;
}



char SPACE(char &locale, bool &warp_D_online, bool &first_flight, int &crash_row, int &crash_col) {

        int row, col, inputCounter = 0;
        size_t titan_row = tr1, titan_col = tc4;
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
                        move_titan(titan_row, titan_col);
                        if (row == titan_row and col == titan_col) {
                                set_raw_mode(false);
                                show_cursor(true);
                                movecursor(0,0);
                                clearscreen();
                                locale = 'T';
                                return 'T';
                        }
                        row--;
                        if (row < 1) row = world_map.size() - 2;
                }
                if (c == 'S' or c == DOWN_ARROW) {
                        inputCounter++;
                        move_titan(titan_row, titan_col);
                        if (row == titan_row and col == titan_col) {
                                set_raw_mode(false);
                                show_cursor(true);
                                movecursor(0,0);
                                clearscreen();
                                locale = 'T';
                                return 'T';
                        }
                        row++;
                        if (row >= world_map.size() - 1) row = 1;
                }
                if (c == 'A' or c == LEFT_ARROW) {
                        inputCounter++;
                        move_titan(titan_row, titan_col);
                        if (row == titan_row and col == titan_col) {
                                set_raw_mode(false);
                                show_cursor(true);
                                movecursor(0,0);
                                clearscreen();
                                locale = 'T';
                                return 'T';
                        }
                        col--;
                        if (col < 1) col = world_map.at(row).size() - 2;
                }
                if (c == 'D' or c == RIGHT_ARROW) {
                        inputCounter++;
                        move_titan(titan_row, titan_col);
                        if (row == titan_row and col == titan_col) {
                                set_raw_mode(false);
                                show_cursor(true);
                                movecursor(0,0);
                                clearscreen();
                                locale = 'T';
                                return 'T';
                        }
                        col++;
                        if (col > world_map.at(row).size() - 2) col = 1;
                }
                print_world(row, col, titan_row, titan_col, Jrow, Jcol, Arow, Acol, Erow, Ecol);
                //move_titan(titan_row, titan_col); //makes constant orbit while stationary
                movecursor(0,0);
                cout.flush();
                if (first_flight == 1) {
                        if (inputCounter == 7) {
                                damage();
                                set_raw_mode(false);
                                show_cursor(true);
                                movecursor(0,0);
                                clearscreen();
                                crash_row = row, crash_col = col;
                                first_flight = 0;
				warp_D_online = 0;
                                locale = 'C';
                                return 'C';
                        }
                }
                if (row == Erow and col == Ecol and !first_flight) {
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
                if (row == Arow and col == Acol and warp_D_online == 1) {
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





// Modifies type speed for conversational effect.
void TYPER(string GM) {
        for (int i = 0; i < GM.size(); i++) {
                cout << GM.at(i);
                cout.flush();
                usleep(45'000); /*45'000*/
        }
	cout << endl;
}

// Same, but without endl; (E) lol
void TYPR(string GM) {
        for (int i = 0; i < GM.size(); i++) {
                cout << GM.at(i);
                cout.flush();
                usleep(45'000); /*45'000*/
        }
}


// Same, but faster
void TYPERFAST(string GM) {
        for (int i = 0; i < GM.size(); i++) {
                cout << GM.at(i);
                cout.flush();
                usleep(1'000); /*1'000*/
        }
        cout << endl;
}


// Inputs pause for dramatic effect.
void NarrP() {
        usleep (1'500'000);  /*1'500'000*/
}


void elipse() {
        string E = ". . . ";
        for (int i = 0; i < E.size(); i++) {
                cout << E.at(i);
                cout.flush();
                usleep(270'000); /*270'000*/
        }
}


// Changes input to all caps.
string TOUPPER(string &userString) {
        for (size_t i = 0; i < userString.size(); i++) {
        userString.at(i) = toupper(userString.at(i));
        }
        return userString;
}

vector<string> key_word_answer {"ANSWER","PICK UP","YES","ON SCREEN"};
vector<string> key_word_ignore {"IGNORE","NO","DONT","DON'T","COFFEE"};
vector<string> key_word_yes {"YES","SURE","OKAY","DEFINITELY"};
vector<string> key_word_no {"NO","DONT","DON'T","NOPE","NAH"};
vector<string> key_word_launch {"LAUNCH","TAKE OFF","FLY","GO","NAVIGATE","NAVIGATION"};
vector<string> key_word_advice {"HELP","ADVICE","IDEA"};


// Searches user input for a keyword. FIX ME: needs to be changed to call a vector<string> &keyWord for optimization.
bool WRDSRCH(string userString, vector<string> keyPhrase) {
	for (size_t i = 0; i < keyPhrase.size(); i++) {
		if (userString.find(keyPhrase.at(i)) != string::npos) {
			return 1;
		}
	}
	return 0;
}


int main() {
	// All names of people and the game is perfectly subject to change and impermanent
	string action;
	TYPR("WARNING: "); NarrP(); TYPER("This game contains some flashing lights.");
	usleep(3'000'000);
	system("clear");

	// Introduction and aquisition of the mission
	vector<string> titleScreen {
"          ____ _____      _______                                   ",
"         / __//_  _/ ,/| /____   )                                  ",
"        ( (    / / ,/  |   __ ) /                                   ",
"         \\ \\  / /,/ _  |  / // /                                    ",
"      ____) )/ //,-' `.| / / \\ \\                                   ",
"     /_____//_///     ||/_/   \\ \\_ ______ ______     ______  __   __",
"                               \\_//_  __//___   )   / ____/ / /  / /",
"                                   / /    __ ) /   / /_    / / /'/' ",
"                                  / /    / // /   / ___|  / //'/'   ",
"                                 / /    / / \\ \\  / /____ / / \\ \\    ",
"                                /_/    /_/   \\ \\/______//_/   \\_\\   ",
"                                              \\/	             ",
	};
	for (int i = 0; i < titleScreen.size(); i++) {
		TYPERFAST(titleScreen.at(i));
	}

	for(int i = 0; i < 3; i++) cout << endl;
	elipse();
	TYPER("It's approximately 0600 hours."); NarrP(); TYPR("Star Date: 46436.3014"); elipse(); cout << endl; cout << endl;
	TYPER("The pinnacle of coffee scents fills your nostrils."); NarrP();
	TYPR("This wasn't prepared in a replicator"); elipse(); cout << endl;
       	TYPER("You are sitting on the rooftop balcony of the");
	TYPER("best coffee shop in the Federation."); NarrP(); cout << endl;
	TYPER("It sits just on the outskirts of New York City."); NarrP();
	TYPER("Based on the weather patterns in the sky,");
	TYPER("you sense that this will be one of the most ");
	TYPR("beautiful sunrises over the city that you've ever seen.\n"); NarrP(); 
	TYPER("What a great day to have off!"); elipse();
	while (true) {
		elipse(); cout << endl;
		TYPER("Someone is hailing you on your communicator!\a");
		TYPER("What would you like to do?");
		getline(cin, action);
		TOUPPER(action);
		if (WRDSRCH(action, key_word_ignore)) TYPER("You ignore the call and take another glorius sip.");
		else if (WRDSRCH(action, key_word_answer)) break;
		else TYPER("You can't do that now.");
	}
	TYPR("You answer the call"); elipse(); cout << endl;
	TYPER("It's General Pepper from Star Command!"); NarrP();
	TYPR("GENERAL: "); NarrP(); TYPER("Captain, the Federation is in dire need of your assistance!"); NarrP();
	TYPER("We have already assembled a crew and readied a new space craft."); NarrP();
	TYPER("Please be careful with this one, as there was nothing ");
	TYPR("salvageable from your last "); usleep(250'000); TYPR("*ahem*"); usleep(500'000); TYPER(" accident.");
	elipse();
	TYPER("Will you accept the mission?");
	getline(cin, action);
	TOUPPER(action);
		if (WRDSRCH(action, key_word_yes)) {
			TYPR("GENERAL: "); elipse(); TYPER("Thanks! I can always count on you!"); NarrP();
			}
		else {
			while (true) {
				TYPR("GENERAL: "); NarrP(); TYPER("Sorry, I didn't get that"); elipse(); TYPER("What?");
				getline(cin, action);
				TOUPPER(action);
				if (WRDSRCH(action, key_word_yes)) {
					TYPR("GENERAL: "); elipse(); TYPR("Great!"); TYPR(" I always know I can count on you!"); NarrP(); TYPER(" ;O"); NarrP();
					break;
				}
			}
		}
	TYPER("Head to terminal 96 at the space port."); NarrP();
	TYPER("I'll brief you once on board."); NarrP();
	TYPER("*click*\a");
	elipse(); cout << endl;
	TYPR("Your coffee is cold"); elipse(); TYPER("Guess it's time to go!"); 
	elipse(); elipse(); cout << endl;
	

	// REPLACE WITH puzzle1();
	//
	/*// Puzzle1
	TYPER("You arrive at the terminal that the general mentioned."); NarrP();
	TYPER("It doesn't look like much, but you approach it"); elipse();
	TYPER("The door is locked!"); NarrP();
	TYPER("It prompts you for your password");
	// Enter password loop.*/

	
	// First Time aboard the Starship.
	int crash_row = 0, crash_col = 0;
	bool first_flight = 1; //this will be one at game start, then 0 for the rest of the game
	bool warp_D_online = 1;
	string location_ship = "Command Bay";
	char locale = 'E';
	TYPER("You board the Starship!"); NarrP();
	TYPR("COMMANDER: "); NarrP(); TYPER("Welcome aboard sir!"); NarrP();
	TYPER("If you need help at any time, you can ask me for advice!");
	bool quit = 0;
	while (quit == 0) {
		TYPER("What would you like to do?");
		getline(cin, action);
		TOUPPER(action);
		if (WRDSRCH(action, key_word_advice)) {
			// HELP1();
			TYPR("We are currently in "); TYPR(location_ship); TYPER("."); NarrP();
			TYPER("If the ship gets hailed, you can give the order ");
			TYPER("\"on screen.\""); NarrP();
			TYPER("We need to begin the mission by taking off.");
		}
		else if (WRDSRCH(action, key_word_launch)) {
			while(true) {
				elipse(); cout << endl; TYPR("COMMS: "); NarrP(); TYPER("Incoming transmission from Star Command!");
				TYPER("What would you like to do?");
				getline(cin, action);
				TOUPPER(action);
				if (WRDSRCH(action, key_word_answer)) {
					TYPER("It's General Pepper!"); NarrP();
					TYPR("GENERAL: "); NarrP(); TYPER("Morning Captain! This mission will be pretty routine.");
					TYPER("We just need you to deliver a package to our base in Andromeda."); NarrP();
					TYPER("Do be sure to navigate your ship to the edge of the solar system ");
					TYPER("before jumping past warp-1."); NarrP();
					TYPER("We're experiencing an abnormal amount of debris in the system."); NarrP();
					TYPER("Good luck!");
					elipse(); TYPER("*click*\a");
					NarrP(); cout << endl; TYPER("The ship's engines are warmed and everything is in order."); NarrP();
					TYPER("The ship leaves the dock and begins it's maiden voyage!");
					elipse(); TYPR("COMMANDER: "); TYPER("Hey Cap, "); NarrP(); TYPER("Once we get into space, you ought to take the helm and show ");
					TYPER("us some of those piloting skills you're famous for!");
					TYPR("Pilot: "); NarrP(); TYPER("Yes Captain! Please take the helm!"); NarrP();
					elipse(); cout << endl;
					TYPER("You decide to take the helm."); NarrP(); TYPER("Everyone seems really excited!");
					elipse();
					usleep(2'000'000);
					quit = 1;
					break;
				}
				else if (WRDSRCH(action, key_word_ignore)) {
					NarrP(); cout << endl; TYPER("The ship's engines are warmed and everything is in order."); NarrP();
					TYPER("The ship leaves the dock and begins it's maiden voyage!");
					elipse(); cout << endl; TYPR("COMMANDER: "); TYPR("Hey Cap, "); NarrP(); TYPER("Once we get into space, you ought to take the helm and show ");
					TYPER("us some of those piloting skills you're famous for!");
					TYPR("Pilot: "); NarrP(); TYPER("Yes Captain! I would be honored to offer you the helm"); NarrP();
					elipse(); cout << endl;
					TYPER("You decide to take the helm."); NarrP(); TYPER("Everyone seems really excited!");
					elipse();
					usleep(3'000'000);
					quit = 1;
					break;
				}
				else TYPER("You can't do that now!");
			}
		}
		else TYPER("You can't do that now!");
	}
	SPACE(locale, warp_D_online, first_flight, crash_row, crash_col);


	// After crash
	TYPER("YOU HIT AN ASTEROID AND DAMAGED THE SHIP!!!"); 
	NarrP(); cout << endl;
}


	

// GAME START: You recieve a call from Star Command detailing a mission to deliver a valuable package to SC base in a nearby star system.
//
//
// Before boarding the spacecraft, the place must enter their "userName" and must solve a puzzle in order to 'remember' your password (1st puzzle).
//
//
// After the first failed attempt, the Player is greeted by their first mate (Commander Pepe) who drops a subtle hint that contains the answer to this puzzle.
//
//
// Once onboard, the player is introduced to their crew and some of the commands they can enter to navigate the game and names their brand new "string starShip" before embarking on it's maiden voyage.
// 	These commands include how to enter "void navigation()" mode where a map of the star system comes onto screen and the player may move the starship to another location.
// 	Responding to an incoming "HAIL" is introduced when the Star Command general hails the player's starShip to wish them good luck on the mission.
// 	Commander Pepe advises the player that he can consult him at anytime with command "ADVICE" to get a hint about what they should do next.
//	  
//
// Upon leaving earth, after the player moves "X" spaces on the worldmap, the screen flashes "void damage()": Commander Pepe advises the player that they will need to "void fixEngine()" (2nd puzzle) in order to visit the Star Command base on the Jupiter moon "TITAN" where there the only "bool warpDrive" manufacturing company exists in this star system.
//
//
// After moving to "ENGINEERING" and aiding the chief of engineering in fixing the engines, the player may now "void navigation()" and navigate to "TITAN".
//
//
// Upon arrival the player must 'remember' their Star Command interstellar ID to safely land on "TITAN" (3rd puzzle)
// 
// After landing on at the base, the player meets Bezos, the dismembered head in a jar that owns "TITAN" and the warp-drive manufacturing company.
//
//
// The player must convince Bezos that the mission is dire and the aquisition of a warpDrive is critical for the future of Star Command (4th puzzle).
//
//
// The player returns to the starShip and must return to "ENGINEERING" and use the "warpDrive" from their inventory to repair the propulsion system (5th puzzle).
//
//
// Now that the player has fixed the warpdrive, they may move to position with "NAVIGATE". If "bool warpDriveOnline(true)" we enter into text mode and Commander Pepe asks if the player would like to make the jump to warp speed.
//
//
// The text will tell the player that they have arrived near the planet in a star system in Andromeda galaxy. The "COMMS" lieutenant says there are several ships of unknown origin in their vicinity. The commanding ship hails the player at which time they may put the comm "ON SCREEN" or "REFUSE". If ("ON SCREEN") the player has a short adversarial interaction with the enemy before engaging in battle. If ("REFUSE") the enemy ships engage in battle.
//
//
// "void battle()" is called and the player engages in battle. They may get "ADVICE" from Commander Pepe who tells them to use proton torpedos sparingly, and save them for when the enemy shields are down.
// 	If player ship takes damage "void damage()" is called. If "playerHP == 0" they restart from the drop out of warp speed. If "enemyHP == 0" they land sucesfully on the planet and deliver the cargo. Player wins!

