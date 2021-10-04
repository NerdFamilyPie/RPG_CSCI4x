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
                                cout << 'S' << RESET;
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
                if (row == Erow and col == Ecol and !first_flight and locale != 'C' and locale != 'T') {
                        set_raw_mode(false);
                        show_cursor(true);
                        movecursor(0,0);
                        clearscreen();
                        locale = 'E';
                        return 'E';
                }
                if (row == titan_row and col == titan_col and warp_D_online == 0 and locale != 'T') {
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
                usleep(15'000); /*15'000*/
        }
	cout << endl;
}

// Same, but without endl; (E) lol
void TYPR(string GM) {
        for (int i = 0; i < GM.size(); i++) {
                cout << GM.at(i);
                cout.flush();
                usleep(15'000); /*15'000*/
        }
}

// TYPER function for computers voice
void TYPERCOM(string GM) {
        for (int i = 0; i < GM.size(); i++) {
                cout << GM.at(i);
                cout.flush();
                usleep(30'000); /*30'000*/
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
        usleep (900'000);  /*900'000*/
}


void elipse() {
        string E = ". . . ";
        for (int i = 0; i < E.size(); i++) {
                cout << E.at(i);
                cout.flush();
                usleep(180'000); /*180'000*/
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
vector<string> key_word_yes {"YES","SURE","OKAY","DEFINITELY","ACCEPT"};
vector<string> key_word_no {"NO","DONT","DON'T","NOPE","NAH"};
vector<string> key_word_launch {"LAUNCH","TAKE OFF","FLY","GO","NAVIGATE","NAVIGATION","WARP","TAKE US OUT","HEAD OUT"};
vector<string> key_word_advice {"HELP","ADVICE","IDEA","ADVISE"};
vector<string> key_word_battle {"ATTACK","BATTLE","SHOOT","FIRE","ENGAGE"};
vector<string> phasers{"PHASERS","PHASER"};
vector<string> photon{"PHOTON","PHOTONS","TORPEDO","TORPEDOES"};
vector<string> evasive{"EVASIVE","MANEUVERS","MANEUVER","DODGE","EVADE"};
vector<string> shields{"SHIELDS","SHIELD","GENERATOR"};
vector<string> hull{"HULL","BODY","STRUCTURAL","STRUCTURE"};
vector<string> engine{"ENGINE","ENGINES","PROPULSTION"};


// Searches user input for a keyword. FIX ME: needs to be changed to call a vector<string> &keyWord for optimization.
bool WRDSRCH(string userString, vector<string> keyPhrase) {
	for (size_t i = 0; i < keyPhrase.size(); i++) {
		if (userString.find(keyPhrase.at(i)) != string::npos) {
			return 1;
		}
	}
	return 0;
}


// BATTLE() **************************************************************************************************************************************



void ADVICE() {
        TYPER("You can fire phasers, fire photon torpedoes, or take evasive action."); cout << endl;
        TYPER("Photon torpedoes are stronger and have a higher critical strike chance, ");
        TYPER("but are more easily evaded.");
        TYPER("They are also in limited supply, so use them wisely!"); NarrP(); cout << endl;
        TYPER("If you choose to attack, you must target the shield generator, ");
        TYPER("the engines, or the hull of the enemy ship."); NarrP(); cout << endl;
        TYPER("If at any time you wish to see this message again, ");
        TYPR("just ask for advice"); elipse(); TYPER("Good luck!!!");
        cout << endl;
}

bool BATTLE(bool &WINNER) {
        TYPER("The enemy ship is charging their weapons!"); NarrP();
        TYPER("Prepare for battle!"); NarrP(); cout << endl;
        ADVICE();
        int pdamage, cdamage;
        int pphoton = 6, pshields = 100, pinteg = 100, pengine = 100, cphoton = 6, cshields = 100, cinteg = 100, cengine = 100;
        const int power_photon = 36, power_phaser = 24;
        string paction;
        string ptarget;
        string caction;
        string ctarget;
        srand(time(0));
        while (pinteg > 0 and cinteg > 0) {
                TYPR("You have "); setcolor(255,255,0); cout << pphoton << RESET;
                if (pphoton != 1) TYPER(" photon torpedoes. ");
                else TYPER(" photon torpedo. ");

                if (pshields > 0) {TYPR("Shields are at "); setcolor(0,213,255); cout << pshields; TYPR("%. "); cout << RESET;}
                else {TYPR("Shields are "); setcolor(255,0,0); TYPR("offline! "); cout << RESET;}
                if (pengine > 0) {TYPR("Engines at "); setcolor(255,166,77); cout << pengine; TYPR("%. "); cout << RESET;}
                else {TYPR("Engines are "); setcolor(255,0,0); TYPR("down! "); cout << RESET;}
                if (pinteg < 0) pinteg = 0;
                TYPR("Structural integrity at ");
                if (pinteg > 20) {setcolor(0,173,67); cout << pinteg; TYPER("%. "); cout << RESET << endl;}
                else {setcolor(255,0,0); cout << pinteg; TYPER("%. "); cout << RESET << endl;}

                TYPR("The enemy has "); setcolor(255,255,0); cout << cphoton << RESET;
                if (cphoton != 1) TYPER(" photon torpedoes. ");
                else TYPER(" photon torpedo. ");
                if (cshields > 0) {TYPR("Enemy shields are at "); setcolor(0,213,255); cout << cshields; TYPR("%. "); cout << RESET;}
                else {TYPR("Enemy shields are "); setcolor(255,0,0); TYPR("offline! "); cout << RESET;}
                if (cengine > 0) {TYPR("Enemy engines at "); setcolor(255,166,77); cout << cengine; TYPR("%. "); cout << RESET;}
                else {TYPR("Enemy engines are "); setcolor(255,0,0); TYPR("down! "); cout << RESET;}
                if (cinteg < 0) cinteg = 0;
                TYPR("Enemy structural integrity at ");
                if (cinteg > 20) {setcolor(0,173,67); cout << cinteg; TYPER("%. "); cout << RESET;}
                else {setcolor(255,0,0); cout << cinteg; TYPER("%. "); cout << RESET;}
                cout << endl;
                // Get player action (loop)
                bool playerd = true;
                while (playerd == true) {
                        TYPER("What would you like to do?");
                        getline(cin, paction);
                        TOUPPER(paction);
                        if (WRDSRCH(paction, key_word_advice)) ADVICE();
                        if (WRDSRCH(paction, phasers)) {
                                paction = "PHASERS";
                                TYPER("You chose to use phasers!");
                                cout << endl;
                        }
                        if (WRDSRCH(paction, photon) and pphoton <= 0) {TYPER("You are out of photon torpedoes!"); cout << endl;}
                        if (WRDSRCH(paction, photon) and pphoton > 0) {
                                paction = "PHOTON";
                                pphoton--;
                                TYPER("You chose to use the photon cannon!"); cout << endl;
                        }
                        if (WRDSRCH(paction, evasive) and pengine <= 0) {TYPER("Your engines are offline!"); cout << endl;}
                        if (WRDSRCH(paction, evasive) and pengine > 0) {
                                paction = "EVASIVE";
                                pengine -= 10;
                                pshields += 2;
                                TYPER("You chose to take evasive action!"); cout << endl;
                                break;
                        }
                        if (paction == "PHASERS" or (paction == "PHOTON")) {
                                while (true) {
                                        TYPER("What part of the enemy ship will you target?");
                                        getline(cin, ptarget);
                                        TOUPPER(ptarget);
                                        if (WRDSRCH(ptarget, key_word_advice)) ADVICE();
                                        if (WRDSRCH(ptarget, shields) and cshields <= 0) {TYPER("Their shields are already down!"); cout << endl;}
                                        if (WRDSRCH(ptarget, shields) and cshields > 0) {
                                                ptarget = "SHIELDS";
                                                playerd = false;
                                                TYPER("You targeted the enemy shield generator!"); cout << endl;
                                                break;
                                        }
                                        if (WRDSRCH(ptarget, hull)) {
                                                ptarget = "HULL";
                                                playerd = false;
                                                TYPER("You targeted the hull of the enemy ship!"); cout << endl;
                                                break;
                                        }
                                        if (WRDSRCH(ptarget, engine) and cengine <= 0) {TYPER("Their engines are already down!"); cout << endl;}
                                        if (WRDSRCH(ptarget, engine) and cengine > 0) {
                                                ptarget = "ENGINE";
                                                playerd = false;
                                                TYPER("You targeted the enemy ship's engines!"); cout << endl;
                                                break;}
                                }
                        }
                }
                // Get computer action
                bool compd = true;
                while (compd == true) {
                        int comp = rand() % 10;
                        if (pphoton > 0) {
                                if ((comp == 0 or comp == 1 or comp == 2 or comp == 3) and cengine > 0) {
                                        caction = "EVASIVE";
                                        cengine -= 10;
                                        cshields += 2;
                                        break;
                                }
                                if (comp == 4 or comp == 5) caction = "PHASERS";
				if (cphoton > 0) {
                                        if (comp == 6 or comp == 7 or comp == 8 or comp == 9) {
                                                caction = "PHOTON";
                                                cphoton--;
                                        }
                                }
                                if (caction == "PHASERS" or caction == "PHOTON") {
                                        while (true) {
                                                comp = rand() % 10;
                                                if ((comp == 0 or comp == 1 or comp == 2 or comp == 3 or comp == 4) and pshields > 0) {
                                                        ctarget = "SHIELDS";
                                                        compd = false;
                                                        break;
                                                }
                                                if (comp == 5) {
                                                        ctarget = "HULL";
                                                        compd = false;
                                                        break;
                                                }
                                                if ((comp == 6 or comp == 7 or comp == 8 or comp == 9) and pengine > 0) {
                                                        ctarget = "ENGINE";
                                                        compd = false;
                                                        break;
                                                }
                                        }
                                }
                        }
                        else {
                                if ((comp == 0 or comp == 1 or comp == 2) and cengine > 0) {
                                        caction = "EVASIVE";
                                        cengine -= 10;
                                        cshields += 2;
                                        break;
                                }
                                if (comp == 3 or comp == 4) caction = "PHASERS";
                                if (cphoton > 0) {
                                        if (comp == 5 or comp == 6 or comp == 7 or comp == 8 or comp == 9) {
                                                caction = "PHOTON";
                                                cphoton--;
                                        }
                                }
                                if (caction == "PHASERS" or caction == "PHOTON") {
                                        while (true) {
                                                comp = rand() % 10;
                                                if ((comp == 0 or comp == 1 or comp == 2 or comp == 3 or comp == 4) and pshields > 0) {
                                                        ctarget = "SHIELDS";
                                                        compd = false;
                                                        break;
                                                }
                                                if (comp == 5 or comp == 6) {
                                                        ctarget = "HULL";
                                                        compd = false;
                                                        break;
                                                }
                                                if ((comp == 7 or comp == 8 or comp == 9) and pengine > 0) {
                                                        ctarget = "ENGINE";
                                                        compd = false;
                                                        break;
                                                }
                                        }
                                }
                        }
                }

                // is critical?
                int pcrit, ccrit;
                bool piscrit = false, ciscrit = false;
                pcrit = rand() % 10, ccrit = rand() % 10;
                if (paction == "PHOTON") {
                        if (pcrit == 0 or pcrit == 1 or pcrit == 2) piscrit = true;
                }
                else if (pcrit == 0) piscrit = true;
                if (caction == "PHOTON") {
                        if (ccrit == 0 or ccrit == 1 or ccrit == 2) ciscrit = true;
                }
                else if (ccrit == 0) ciscrit = true;

                // Did evasive work?
                int pdodge, cdodge;
                bool pevaded = false, cevaded = false;
                if (paction == "EVASIVE") {
                        pevaded = true;
                        pdodge = rand() % 10;
                        if (caction == "PHASERS") {
                                if (pdodge == 0 or pdodge == 1 or pdodge == 2) pevaded = false;
                        }
                        if (caction == "PHOTON") {
                                if (pdodge == 0) pevaded = false;
                        }
                }
                if (caction == "EVASIVE") {
                        cevaded = true;
                        cdodge = rand() % 10;
                        if (paction == "PHASERS") {
                                if (cdodge == 0 or cdodge == 1 or cdodge == 2) cevaded = false;
                        }
                        if (paction == "PHOTON") {
                                if (cdodge == 0) cevaded = false;
                        }
                }

                // Count damage!
                // Player:
                        if (caction == "EVASIVE") {
                                if (cevaded) pdamage = 0;
                        }
                        if (!cevaded) {
                                if (paction == "PHASERS") {
                                        if (piscrit) {
                                                pdamage = power_phaser+(power_phaser/2);
                                                if (cshields > 0) pdamage /= 4;
                                        }
                                        else {
                                                pdamage = power_phaser;
                                                if (cshields > 0) pdamage /= 4;
                                        }
                                }
                                if (paction == "PHOTON") {
                                        if (piscrit) {
                                                pdamage = power_photon+(power_photon/2);
                                                if (cshields > 0) pdamage /= 4;
                                        }
                                        else {
                                                pdamage = power_photon;
                                                if (cshields > 0) pdamage /= 4;
                                        }
                                }
                        }
                // Enemy:
                        if (paction == "EVASIVE") {
                                if (pevaded) cdamage = 0;
                        }
                        if (!pevaded) {
                                if (caction == "PHASERS") {
                                        if (ciscrit) {
                                                cdamage = power_phaser+(power_phaser/2);
                                                if (pshields > 0) cdamage /= 4;
                                        }
                                        else {
                                                cdamage = power_phaser;
                                                if (pshields > 0) cdamage /= 4;
                                        }
                                }
                                if (caction == "PHOTON") {
                                        if (ciscrit) {
                                                cdamage = power_photon+(power_photon/2);
                                                if (pshields > 0) cdamage /= 4;
                                        }
                                        else {
                                                cdamage = power_photon;
                                                if (pshields > 0) cdamage /= 4;
                                        }
                                }
                        }
                if (paction == "EVASIVE") {
                        TYPER("You take evasive action!"); NarrP();
                }
                if (paction != "EVASIVE") {
                        TYPR("You attempt to strike the enemy's "); TYPR(ptarget); TYPR(" with your "); TYPR(paction); TYPER("!"); NarrP();
                }
                if (caction == "EVASIVE") {
                        TYPER("The enemy took evasive action!"); NarrP(); cout << endl;
                        if (cevaded and paction != "EVASIVE") {TYPER("The enemy evaded the attack!"); NarrP(); cout << endl;}
                        if (!cevaded and paction != "EVASIVE") {TYPER("They failed to evade your attack!"); NarrP(); cout << endl;}
                }
                if (caction != "EVASIVE") {
                        TYPR("The enemy attempts to strike your "); TYPR(ctarget); TYPR(" with their "); TYPR(caction); TYPER("!"); NarrP(); cout << endl;
                }

                if (piscrit and paction != "EVASIVE" and !cevaded) {
                        TYPR("You struck the enemy ");
                        TYPR(ptarget); TYPR(" with your "); TYPR(paction);
                        TYPER(" for critical damage!");
                        NarrP();
                }
                else if (!cevaded and paction != "EVASIVE") {
                        TYPR("You struck the enemy "); TYPR(ptarget);
                        TYPR(" with your "); TYPR(paction); TYPER("!");
                        NarrP();
                }
                if (paction == "EVASIVE" and !pevaded and caction != "EVASIVE") {TYPER("You failed to evade their attack!"); cout << endl;}
                if (pevaded and caction != "EVASIVE") {TYPER("You evaded their attack!"); cout << endl;}
                if (ciscrit and caction != "EVASIVE" and !pevaded) {
                        TYPR("The enemy struck your ");
                        TYPR(ctarget); TYPR(" with their ");
                        TYPR(caction);
                        TYPER(" for critical damage!");
                }
                else if (!pevaded and caction != "EVASIVE") {
                        TYPR("The enemy struck your "); TYPR(ctarget);
                        TYPR(" with their "); TYPR(caction); TYPER("!");
                }
                if (paction != "EVASIVE" and ptarget == "SHIELDS" and !cevaded) {pdamage *= 2; cshields -= pdamage; cinteg -= (pdamage/3); cshields -= (pdamage/3); cengine -= (pdamage/3); cout << endl;}
                if (paction != "EVASIVE" and ptarget == "HULL" and !cevaded) {cinteg -= pdamage; cshields -= (pdamage/2); cengine -= (pdamage/2); cout << endl;}
                if (paction != "EVASIVE" and ptarget == "ENGINE" and !cevaded) {pdamage *= 2; cengine -= pdamage; cinteg -= (pdamage/3); cshields -= (pdamage/3); cengine -= (pdamage/3); cout << endl;}

                if (caction != "EVASIVE" and ctarget == "SHIELDS" and !pevaded) {cdamage *= 2; pshields -= cdamage; pinteg -= (cdamage/3); pshields -= (cdamage/3); pengine -= (cdamage/3); usleep(2'500'000); damage();}
                if (caction != "EVASIVE" and ctarget == "HULL" and !pevaded) {pinteg -= cdamage; pshields -= (cdamage/2); pengine -= (cdamage/2); usleep(2'500'000); damage();}
                if (caction != "EVASIVE" and ctarget == "ENGINE" and !pevaded) {cdamage *= 2; pengine -= cdamage; pinteg -= (cdamage/3); pshields -= (cdamage/3); pengine -= (cdamage/3); usleep(2'500'000); damage();}
                if (cshields < 0) cshields = 0;
                if (pshields < 0) pshields = 0;
        }
                TYPR("You have "); setcolor(255,255,0); cout << pphoton << RESET;
                if (pphoton != 1) TYPER(" photon torpedoes. ");
                else TYPER(" photon torpedo. ");

                if (pshields > 0) {TYPR("Shields are at "); setcolor(0,213,255); cout << pshields; TYPR("%. "); cout << RESET;}
                else {TYPR("Shields are "); setcolor(255,0,0); TYPR("offline! "); cout << RESET;}
                if (pengine > 0) {TYPR("Engines at "); setcolor(255,166,77); cout << pengine; TYPR("%. "); cout << RESET;}
                else {TYPR("Engines are "); setcolor(255,0,0); TYPR("down! "); cout << RESET;}
                if (pinteg < 0) pinteg = 0;
                TYPR("Structural integrity at ");
                if (pinteg > 20) {setcolor(0,173,67); cout << pinteg; TYPER("%. "); cout << RESET << endl;}
                else {setcolor(255,0,0); cout << pinteg; TYPER("%. "); cout << RESET << endl;}

                TYPR("The enemy has "); setcolor(255,255,0); cout << cphoton << RESET;
                if (cphoton != 1) TYPER(" photon torpedoes. ");
                else TYPER(" photon torpedo. ");
                if (cshields > 0) {TYPR("Enemy shields are at "); setcolor(0,213,255); cout << cshields; TYPR("%. "); cout << RESET;}
                else {TYPR("Enemy shields are "); setcolor(255,0,0); TYPR("offline! "); cout << RESET;}
                if (cengine > 0) {TYPR("Enemy engines at "); setcolor(255,166,77); cout << cengine; TYPR("%. "); cout << RESET;}
                else {TYPR("Enemy engines are "); setcolor(255,0,0); TYPR("down! "); cout << RESET;}
                if (cinteg < 0) cinteg = 0;
                TYPR("Enemy structural integrity at ");
                if (cinteg > 20) {setcolor(0,173,67); cout << cinteg; TYPER("%. "); cout << RESET;}
                else {setcolor(255,0,0); cout << cinteg; TYPER("%. "); cout << RESET;}
                cout << endl;

        if (cinteg <= 0) {TYPER("You destroyed the enemy ship!!"); WINNER = 1; usleep(2'500'000);}
        if (pinteg <= 0) {TYPER("Your ship was destroyed!!"); WINNER = 0; usleep(2'500'000);}
        system("clear");
	return WINNER;
}

// BATTLE()***********************************************************************************************************************************************************************************************






int main() {
	// All names of people and the game is perfectly subject to change and impermanent
	string action;
	TYPR("WARNING: "); NarrP(); TYPER("This game contains some flashing lights.");
	TYPR("NOTE: "); NarrP(); TYPER("A significant portion of the dialogue may be skipped by 'ignore'-ing some text prompts.");
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
	};

	for (int i = 0; i < titleScreen.size(); i++) {
		TYPERFAST(titleScreen.at(i));
	}

	for(int i = 0; i < 3; i++) cout << endl;
	elipse();
	TYPER("It's approximately 0600 hours."); NarrP(); TYPR("Star Date: 46436.3014"); elipse(); cout << endl; cout << endl;
	TYPER("The pinnacle of coffee aroma fills your nostrils."); elipse();
	TYPR("This wasn't prepared in a replicator"); elipse(); cout << endl;
       	TYPER("You are sitting on the rooftop balcony of the");
	TYPER("best coffee shop in the Federation."); NarrP(); cout << endl;
	TYPER("It sits just on the outskirts of New New York City."); NarrP();
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
	

	
	TYPER("You arrive at the terminal that the general mentioned."); NarrP();
	TYPER("It doesn't look like much, but you approach it"); elipse();
	TYPER("The door is locked!"); NarrP();
	TYPER("It prompts you for your password");
	// Enter password loop.*/
   string correct = "little";
  string test = "";
  bool loop = FALSE;
  string prompt = "";
//This the puzz;e for figuring out the password
  TYPER("Please input your password");NarrP();
  // HELP With the WORDSEARCH
  cin >> test;
  if (test == "little"){
      TYPER("That is correct");NarrP();
      loop = TRUE;
  }else{
  while (loop){
    TYPER("That is incorrect.\n would you like to see your secret prompt?"};NarrP();
    cin >> prompt;
    if(prompt == "no"){
      TYPER("Please input your password\n");NarrP();
      cin >> test;
    } else if(prompt == "yes"){
      TYPER("It is your mothers maiden name, remember its not Tall\n");NarrP();
      cin >> test;
    }
    if (test == "little"){
      TYPER("That is correct\n");NarrP;
      loop = TRUE;

    }}
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
			TYPER("If the ship gets hailed, you can give the order: ");
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
					TYPR("GENERAL: "); NarrP(); TYPR("Morning Captain!"); NarrP; TYPER(" This mission will be pretty routine.");
					TYPER("We just need you to deliver a package to our base in Andromeda."); NarrP();
					TYPER("Do be sure to navigate your ship to the edge of the solar system ");
					TYPER("before jumping past warp-1."); NarrP();
					TYPER("We're experiencing an abnormal amount of debris in the system."); NarrP();
					TYPER("Good luck!");
					elipse(); TYPER("*click*\a");
					NarrP(); cout << endl; TYPER("The ship's engines are warmed and everything is in order."); NarrP();
					TYPER("The ship leaves the dock and begins it's maiden voyage!");
					elipse(); cout << endl; TYPR("COMMANDER: "); TYPR("Hey Cap, "); NarrP(); TYPER("Once we get into space, you ought to take the helm and show ");
					TYPER("us some of those piloting skills you're famous for!");
					TYPR("Pilot: "); NarrP(); TYPER("Yes Captain! Please take the helm!"); NarrP();
					elipse(); cout << endl;
					TYPER("You decide to take the helm."); NarrP(); TYPER("Everyone seems really excited!");
					elipse();
					usleep(2'500'000);
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
	NarrP(); TYPER("The ship trembles violently"); elipse(); cout << endl;
	TYPR("COMMANDER: "); NarrP(); TYPER("Blimey! That was a big one!"); NarrP();
	TYPR("Computer!"); cout << "\a"; NarrP(); TYPER(" Status report!"); NarrP(); cout << endl;
	TYPR("COMPUTER: "); NarrP(); TYPERCOM("SIGNIFICANT DAMAGE SUSTAINED"); elipse(); cout << endl;
	TYPERCOM("ALL CREW MEMBERS ACCOUNTED FOR"); elipse(); cout << endl; TYPERCOM("SOME MINOR INJURIES SUSTAINED"); elipse(); cout << endl;
	TYPERCOM("SHIELDS AT 50%"); elipse(); cout << endl;
	TYPERCOM("STRUCTURAL INTEGRITY AT 70%"); elipse(); cout << endl;
	TYPERCOM("ENGINES OFFLINE, BUT UNDAMAGED"); elipse(); cout << endl;
	TYPERCOM("WARPDRIVE DAMAGED AND INOPERABLE"); elipse(); cout << endl;
	TYPERCOM("END REPORT.\a"); NarrP(); cout << endl << endl;
	
	location_ship = "Engineering Bay";
	TYPR("COMMANDER: "); NarrP(); TYPER("Looks like we are going to have to go to ");
	TYPER("engineering bay and see what's going on!"); NarrP();
	elipse(); cout << endl;
	TYPER("You arrive in the engineering bay."); NarrP();
	TYPR("CHEIF OF ENGINEERING: "); NarrP(); TYPR("Hey Captain!"); NarrP(); TYPER(" We have a huge mess on our hands!");
	TYPER("Not sure how it's possible we hit an object that big,"); 
	TYPER("but all propulsion systems are down!"); NarrP();
	TYPR("I don't think the engine is too bad, We just need to mix some more fuel from our emergency supply"); elipse(); cout << endl;
	TYPER("Think you and the Commander can handle it while I try to get");
        TYPER("this warpdrive back online?");
	elipse(); cout << endl;
	TYPER("You decide to help create more fuel"); elipse();
	
	// NEEDS ENGINE REPAIR PUZZLE. Feel free to change above bracket of text for continuity.
           \\ This is the puzzle to restore fuel to the engine
      bool loop1 = FALSE;
    bool loop2 = FALSE;
    bool loop3 = FALSE;
      int ans1 = 0;
      int ans2 = 0;
      int ans3 = 0;
      TYPER("Here is where we put so sort of dialouge about how we need to vent reserve fuel to the engine if we want to make it to the moon\n",
            "So you need to input the passcodes for the three compartments of raw material that we need to mix together to create more fuel.\n",
            "For each passcode you will be asked a simple math riddle to make sure that you are competent enough to operate the fuel mixology.");NarrP();
    TYPER("The first riddle is:\n");NarrP();
    while (loop1){
      TYPER("What number multiplied by itself and divided by one hundred is equal to four?\n");NarrP();
      cin ans1;
      if (!ans1){TYPER("Invalid Input, Please Try Again");NarrP; continue;}
      if (ans1 == 20){ 
        TYPER("Thats it!\n Lets move on to the next one.\n");NarrP;
        loop1 = TRUE;
      } else { TYPER("Thats not quite it please try again.\n");NarrP;}
    }
       while (loop2){
      TYPER("What number divided by seven and multipled by fifteen equals ninety?\n");NarrP();
      cin ans2;
      if (!ans2){TYPER("Invalid Input, Please Try Again");NarrP(); continue;}
      if (ans2 == 42){ 
        TYPER("Thats it!\n Lets move on to the last one.\n");NarrP();
        loop2 = TRUE;
      }else { TYPER("Thats not quite it please try again.\n");NarrP();}
       }
         while (loop3){
      TYPER("What number times six and divided by twelve is equal to nine?\n");NarrP();
      cin ans3;
      if (!ans3){TYPER("Invalid Input, Please Try Again");NarrP(); continue;}
      if (ans3 == 18){ 
        TYPER("Thats it!\n");NarrP();
        loop3 = TRUE;
      }else {TYPER("Thats not quite it please try again.\n";NarrP();}
    }

	TYPER("The engine is back online!"); NarrP();
	TYPR("You return to the Command Bay"); elipse(); cout << endl;
	location_ship = "Command Bay";
	TYPR("COMMANDER: "); NarrP(); TYPER("I just recieved word from the chief of engineering."); NarrP();
	TYPER("They say we can go to warp-1, but we will need a new warpdrive ");
	TYPER("if we are going to make it to Andromeda!"); NarrP();
	elipse(); cout << endl;
	while (true) {
	TYPER("What would you like to do?");
	getline(cin, action);
	TOUPPER(action);
		if (WRDSRCH(action, key_word_advice)) {
			TYPR("COMMANDER: "); elipse(); TYPER("There's only one place I know of where we can get a new ");
			TYPR("warpdrive without needing to alert the general"); elipse(); cout << endl << endl;
			TYPER("You feel that the Commander has your best interests at heart."); NarrP(); cout << endl;
			TYPR("COMMANDER: "); NarrP(); TYPER("Did you ever wonder why Star Command never put a base ");
			TYPR("on the Saturn moon Titan?"); NarrP(); TYPER(" Despite it being far more terraformable than Mars?"); NarrP();
			TYPR("Well there lives there an archaic relic of humanity's dark past"); elipse(); cout << endl;
			TYPER("Star Command was too benevolent to destroy it, "); TYPER("and in time it proved to be a hotspot for those greedy Ferengi."); NarrP();
			elipse(); TYPER("If we go there, I'm sure we can strike a deal and get a new warpdrive."); cout << endl;
		}
		else if (WRDSRCH(action, key_word_launch)) {SPACE(locale, warp_D_online, first_flight, crash_row, crash_col); break;}
		else TYPER("You can't do that now!");
	}

	// INSERT PASSWORD PUZZLE TO ENTER TITAN AIRSPACE. At the end of this function, be sure to include that "warp_D_online = 1;" so that the player may access Andromeda on the space map.
  bool loopP3 = FALSE;
    string ans = "";
    TYPER("To dock at the illustrous AMAZON space port you must answer a riddle to show that you are an intelligent member of society and someone who it is worth doing business with\n");NarrP();
    TYPER("The riddle is as follows:\n");NarrP();
    while (loopP3){
    TYPER("What can you catch but never throw?");NarrP();
    cin ans;
    if(!ans){TYPER("Bad Input, try again");}
    if(ans == "A cold"){
       TYPER("Thats it!\n");NarrP();
        loopP3 = TRUE;
      warp_D_online = 1;
  }else { TYPER("Thats not quite it please try again.\n");NarrP();}
  }
	TYPER("You and the commander use the teleporter to beam down to the capital of Titan."); NarrP();
	TYPER("This place is highly industrialized with little concern ");
	TYPER("for the potential beauty that could inhabit it since ");
	TYPER("the terraforming process was completed centuries ago."); NarrP(); cout << endl;
	elipse(); TYPR("The view of Saturn is simply breathtaking"); elipse(); cout << endl << endl;
	TYPR("COMMANDER: "); NarrP(); TYPR("Beautiful isn't it? "); NarrP(); TYPER("We'll find the warp-drive if we speak with the head of Titan."); NarrP();
	TYPR("Follow me"); elipse(); cout << endl << endl;
	TYPER("The Commander guides you to the central tower."); NarrP();
	TYPER("An ominous smiling mouth with no other features rests above the entrance"); elipse(); cout << endl;

	TYPER("You arrive in the command room, and sitting on a throne is a 4-legged mechanical ");
	TYPR("robotic podium. "); NarrP(); TYPER("At the top is a glass container with a live bald head inside ");
	TYPER("that has disturbingly intense eye-brows."); NarrP(); cout << endl;
	TYPR("BEZOS: "); NarrP(); TYPER("Welcome to my world!"); NarrP();
	TYPER("Although I don't take too kindly to you Federation types, ");
	TYPER("as you banned my means of appropriating these accomplishments many ");
	TYPR("lifetimes ago"); elipse(); TYPER("What do you want?"); cout << endl;
	TYPER("He snarls"); elipse(); cout << endl;

	//Enter dialogue for riddle and subsequent aquisition of replacement warp-drive.
	int ans = "";
  bool loopP4 = FALSE;
  TYPER("If you want My goods you must prove your worth, I know, how about you answer a simple riddle.\n");NarrP();
  while (loopP4){
    TYPER("What is Black and White and Red all over?\n1) A Newspaper?\n2)A sunburnt cow?\n3)A sunburnt Zebra");NarrP();
    cin ans;
    if(!ans){cout << "Bad Input, try again";}
    if(ans == 3){
       TYPER("Thats it!\n");NarrP();
        loopP4 = TRUE;
  }else {TYPER("Thats not quite it please try again.\n");NarrP;}
  }
  
	location_ship = "Command Bay";
	TYPER("You are beamed back to the ship with the replacement parts for the warp-drive!"); NarrP();
	TYPR("COMMANDER: "); NarrP(); TYPR("Alright captain, "); NarrP(); TYPER("let's get down to engineering and see how we can help!");
	elipse(); cout << endl;

	TYPER("You arrive in engineering with the commander."); NarrP();
	location_ship = "Engineering Bar";

	//Enter dialogue for warp-drive repair puzzle.
	bool loopP5 = FALSE;
   int ans1 = 0;
   while (loopP5){
      TYPER("What number divided by five, multiplied by seven, and divided by six is equal to seven?\n");NarrP();
      cin ans1;
      if (!ans1){TYPER("Invalid Input, Please Try Again");NarrP(); continue;}
      if (ans1 == 30){ 
        TYPER("Thats it!\n Lets get back to the Command Bay and make sure that the Warp Drive is in!");NarrP();
        loopP5 = TRUE;
      } else {TYPER("Thats not quite it please try again.\n");NarrP();}
    }
	location_ship = "Command Bay";
	warp_D_online = 1;
	TYPER("You fixed the warp-drive!"); NarrP(); cout << endl;
	TYPR("COMMANDER: "); NarrP(); TYPER("Okay captain, looks like everything's in order!"); cout << endl;
	quit = 0;
	while (quit == 0) {
                TYPER("What would you like to do?");
                getline(cin, action);
                TOUPPER(action);
                if (WRDSRCH(action, key_word_advice)) {
                        TYPR("COMMANDER: We are currently in "); TYPR(location_ship); TYPER("."); NarrP();
                        TYPER("The ship is prepared to depart.");
			TYPER("We need to get to the edge of the solar system so we can make the jump ");
			TYPR("To warp-9. "); NarrP(); TYPER("When you're ready, you can give the order to take off.");
                }
                else if (WRDSRCH(action, key_word_launch)) quit = 1;
		else {TYPER("You can't do that now"); continue;}
	}
	SPACE(locale, warp_D_online, first_flight, crash_row, crash_col);

	TYPER("You make the jump to warp speed and head to Andromeda!"); elipse();
	TYPR("You arrive in Andromeda safely!"); elipse(); cout << endl;
	TYPR("COMMS: "); NarrP(); TYPR("Captain! "); NarrP(); TYPER("Unknown ship detected in the vicinity!"); NarrP();
	TYPER("They're hailing us!");
	quit = 0;
	while (quit == 0) {
                TYPER("What would you like to do?");
                getline(cin, action);
                TOUPPER(action);
                if (WRDSRCH(action, key_word_advice)) {
			TYPR("COMMANDER: "); NarrP(); TYPER("This is a dicey situation"); elipse();
			TYPER("I'm not sure what the correct course of action is.");
			TYPER("This is why you are the captain rather than me, after all!"); NarrP(); cout << endl;
		}
		else if (WRDSRCH(action, key_word_answer)) {
			TYPER("It's the right-hand guard from Titan!!!"); NarrP();
			TYPR("BEZOS GUARD: "); NarrP(); TYPER("I've been waiting for you captain!"); NarrP();
			TYPER("We gave you a proto-type warp-drive to ensure I would intercept you ");
			TYPER("and claim that precious cargo from Star Command you mentioned!"); NarrP();
			TYPER("After I destroy that piece of Federation garbage you call a 'starship' ");
			TYPER("I will deliver the cargo outside of Federation space, into regions ");
			TYPER("where the mighty dollar still reigns supreme!!"); NarrP; cout << endl;
			quit = 1;
		}
		else if (WRDSRCH(action, key_word_ignore) or WRDSRCH(action, key_word_battle)) quit = 1;
		else {TYPER("You can't do that now!"); continue;}
	}
	bool WINNER = 0;
	while (WINNER == 0) {
		BATTLE(WINNER);
	}
	
	TYPER("You safely reach Federation space and deliver the package!");


        vector<string> SPOCK {
"     :                                 :    ",
"   :                                   :    ",
"   :  RRVIttIti+==iiii++iii++=;:,       :                                     _",
"   : IBMMMMWWWWMMMMMBXXVVYYIi=;:,        :                                   | |",
"   : tBBMMMWWWMMMMMMBXXXVYIti;;;:,,      :     ___ ___  _ __   __ _ _ __ __ _| |_ ___",
"   t YXIXBMMWMMBMBBRXVIi+==;::;::::       ,   / __/ _ \\| '_ \\ / _` | '__/ _` | __/ __|",
"  ;t IVYt+=+iIIVMBYi=:,,,=i+=;:::::,      ;; | (_| (_) | | | | (_| | | | (_| | |_\\__ \\",
"  YX=YVIt+=,,:=VWBt;::::=,,:::;;;:;:     ;;;  \\___\\___/|_| |_|\\__, |_|  \\__,_|\\__|___/",
"   VMiXRttItIVRBBWRi:.tXXVVYItiIi==;:   ;;;;                    __/ |",
"   =XIBWMMMBBBMRMBXi;,tXXRRXXXVYYt+;;: ;;;;;                   |___/",
"    =iBWWMMBBMBBWBY;;;,YXRRRRXXVIi;;;:;,;;;=                   _        _",
"     iXMMMMMWWBMWMY+;=+IXRRXXVYIi;:;;:,,;;=                   | |      (_)",
"     iBRBBMMMMYYXV+:,:;+XRXXVIt+;;:;++::;;;     ___ __ _ _ __ | |_ __ _ _ _ __",
"     =MRRRBMMBBYtt;::::;+VXVIi=;;;:;=+;;;;=    / __/ _` | '_ \\| __/ _` | | '_ \\",
"      XBRBBBBBMMBRRVItttYYYYt=;;;;;;==:;=     | (_| (_| | |_) | || (_| | | | | |",
"       VRRRRRBRRRRXRVYYIttiti=::;:::=;=        \\___\\__,_| .__/ \\__\\__,_|_|_| |_|",
"        YRRRRXXVIIYIiitt+++ii=:;:::;==                  | |",
"        +XRRXIIIIYVVI;i+=;=tt=;::::;:;                  |_|",
"         tRRXXVYti++==;;;=iYt;:::::,;;       ",
"          IXRRXVVVVYYItiitIIi=:::;,::;       ",
"           tVXRRRBBRXVYYYIti;::::,::::       ",
"            YVYVYYYYYItti+=:,,,,,:::::;      ",
"            YRVI+==;;;;;:,,,,,,,:::::::      ",
};
        for (int i = 0; i < SPOCK.size(); i++) {
                TYPERFAST(SPOCK.at(i));
        }
}

/*
                                 _
                                | |
  ___ ___  _ __   __ _ _ __ __ _| |_ ___
 / __/ _ \| '_ \ / _` | '__/ _` | __/ __|
| (_| (_) | | | | (_| | | | (_| | |_\__ \
 \___\___/|_| |_|\__, |_|  \__,_|\__|___/
                  __/ |
                 |___/
                 _        _
                | |      (_)
  ___ __ _ _ __ | |_ __ _ _ _ __
 / __/ _` | '_ \| __/ _` | | '_ \
| (_| (_| | |_) | || (_| | | | | |
 \___\__,_| .__/ \__\__,_|_|_| |_|
          | |
          |_|

*/
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
