#include <iostream>
#include "/home/StGermain/Documents/code/packages/colors.h"
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// Modifies type speed for conversational effect.
void TYPER(string GM) {
        for (int i = 0; i < GM.size(); i++) {
                cout << GM.at(i);
                cout.flush();
                usleep(24'000); /*24'000*/
        }
        cout << endl;
}

void TYPR(string GM) {
        for (int i = 0; i < GM.size(); i++) {
                cout << GM.at(i);
                cout.flush();
                usleep(24'000); /*24'000*/
        }
}


// Inputs pause for dramatic effect.
void NarrP() {
        usleep (1'000'000);  /*1'000'000*/
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

vector<string> key_word_advice {"HELP","ADVICE","IDEA"};
vector<string> phasers{"PHASERS","PHASER"};
vector<string> photon{"PHOTON","PHOTONS","TORPEDO","TORPEDOES"};
vector<string> evasive{"EVASIVE","MANEUVERS","MANEUVER","DODGE","EVADE"};
vector<string> shields{"SHIELDS","SHIELD","GENERATOR"};
vector<string> hull{"HULL","BODY"};
vector<string> engine{"ENGINE","ENGINES"};

// Searches user input for a keyword. FIX ME: needs to be changed to call a vector<string> &keyWord for optimization.
bool WRDSRCH(string userString, vector<string> keyPhrase) {
        for (size_t i = 0; i < keyPhrase.size(); i++) {
                if (userString.find(keyPhrase.at(i)) != string::npos) {
                        return 1;
                }
        }
        return 0;
}

void damage() {
        for (int j = 0; j < 6; j++) {
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

int main() {
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

		if (caction != "EVASIVE" and ctarget == "SHIELDS" and !pevaded) {cdamage *= 2; pshields -= cdamage; pinteg -= (cdamage/3); pshields -= (cdamage/3); pengine -= (cdamage/3); usleep(3'000'000); damage();}
                if (caction != "EVASIVE" and ctarget == "HULL" and !pevaded) {pinteg -= cdamage; pshields -= (cdamage/2); pengine -= (cdamage/2); usleep(3'000'000); damage();}
                if (caction != "EVASIVE" and ctarget == "ENGINE" and !pevaded) {cdamage *= 2; pengine -= cdamage; pinteg -= (cdamage/3); pshields -= (cdamage/3); pengine -= (cdamage/3); usleep(3'000'000); damage();}
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

	if (pinteg <= 0) {TYPER("Your ship was destroyed!!"); return 0;}
	if (cinteg <= 0) {TYPER("Congratulations!"); NarrP(); TYPER("You destroyed the enemy ship!!");}
}
