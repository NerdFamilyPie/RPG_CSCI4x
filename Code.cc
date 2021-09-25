#include <iostream>
#include "/public/colors.h"
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

// Modifies type speed for conversational effect.
void TYPER(string GM) {
        for (int i = 0; i < GM.size(); i++) {
                cout << GM.at(i);
                cout.flush();
                usleep(51'000); /*51'000*/
        }
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


int main() {
  cout << "Hello World";

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
//      These commands include how to enter "void navigation()" mode where a map of the star system comes onto screen and the player may move the starship to another location.
//      Responding to an incoming "HAIL" is introduced when the Star Command general hails the player's starShip to wish them good luck on the mission.
//      Commander Pepe advises the player that he can consult him at anytime with command "ADVICE" to get a hint about what they should do next.
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
// The player returns to the starShip and must return to "ENGINEERING" and use the "warDrive" from their inventory to repair the propulsion system (5th puzzle).
//
//
//



}
