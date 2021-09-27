#include <iostream>
#include "/home/StGermain/Documents/code/packages/colors.h"
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

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
        usleep (1'000'000);  /*1'500'000*/
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
string TOUPPER(string userString) {
        for (size_t i = 0; i < userString.size(); i++) {
        userString.at(i) = toupper(userString.at(i));
        }
        return userString;
}


// Searches user input for a keyword. FIX ME: needs to be changed to call a vector<string> &keyWord for optimization.
bool WRDSRCH(string userString, string keyPhrase) {
        if (userString.find(keyPhrase) != string::npos) {
                return 1;
        }
        else {
                return 0;
        }
}

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
	TYPER("It's approximately 0600 hours\nStar Date: 46436.3014"); NarrP();
	TYPER("The pinnacle of coffee scents fills your nostrils.");
	TYPR("This wasn't prepared in a replicator"); elipse(); cout << endl;
       	TYPER("You are you sitting on the rooftop balcony of the");
	TYPER("best coffee shop in the Federation."); NarrP(); cout << endl;
	TYPER("It sits just on the outskirts of New York City.");
	TYPER("Based on the weather patterns in the sky,");
	TYPER("you sense that this will be one of the most ");
	TYPR("beautiful sunrises over the city that you've ever seen\n"); elipse();
	while (true) {
		elipse(); cout << endl;
		TYPER("Someone is hailing you on your communicator.\a");
		TYPER("What would you like to do?");
		getline(cin, action);
		if (action == "ignore") TYPER("You ignore the call and take another glorius sip."); 
		else if (action == "answer") break;
		else continue;
	}
	TYPER("It's General Pepper from Star Command.");
	TYPR("GENERAL: "); NarrP(); TYPER("Captain, the Federation is in dire need of your assistance."); NarrP();
	TYPER("We need you to deliver a valuable care-package on a top secret mission to Andromeda."); NarrP();
	TYPER("We have already assembled a crew and readied a new space craft."); NarrP();
	TYPER("Please be careful with this one, as there was nothing ");
	TYPER("salvageable from your last *ahem* accident.");
	elipse();
	TYPER("Will you accept the mission?");
	getline(cin, action);
	TYPR("GENERAL: "); elipse(); TYPER("Thanks! I knew you would do it!"); NarrP();
	TYPER("Head to terminal 96 at the space port."); NarrP();
	TYPER("I'll brief you once board."); NarrP();
	TYPER("\a*click*");
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



}
