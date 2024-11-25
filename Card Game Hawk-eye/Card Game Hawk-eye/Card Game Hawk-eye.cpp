// Card Game Hawk-eye.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "cardGame.h"
using namespace std;

const int maxCard = 52;
aCard thePack[maxCard];
aCard player1Pack[maxCard];
aCard player2Pack[maxCard];
bool dealtCards[maxCard] = { false }; // Array to keep track of dealt cards


int main()
{
    bool freeze = false; // flag to freeze the score
    bool end = false; // flag to end the game
    // flags to make sure the player has at least one round before their deck is copied from
    bool p1r1 = false;
    bool p2r1 = false;
    int count = 0;
    int player1Count = 0;
    int player2Count = 0;
    string whosGo;
    int turn = 0;

    //int maxCard = 52;

    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator
    int randNum = (rand() * rand()) % 99999999; // Generate a random number
    while (randNum < 10000000); {
        randNum += 10000000;
    }
    string randNumStr = to_string(randNum); // Convert the integer to a string

    // Generates the random pack of unique cards
    for (int ct = 0; ct < maxCard; ct++) {
        thePack[ct] = getCard(randNumStr, dealtCards);
    }

    cout << "Welcome to the game of higher or lower!\n";    
    cout << "To decide who starts, player 1 will guess if the next card is higher(h) or lower(l) than an 8\n";
    char choice;
    cin >> choice;
    while (choice != 'h' && choice != 'l') {
        cout << "Invalid choice, please try again: ";
        cin >> choice;
    }
    if (choice == 'h') {
        if (thePack[0].cardVal < thePack[1].cardVal) {
            cout << "Correct! It was a: " << cardToStr(thePack[1]) << endl;
			turn = 1;
        }
        else if (thePack[0].cardVal == thePack[1].cardVal) {
            cout << "You don't get anything for a pair,\n Not in this game! " << cardToStr(thePack[1]) << endl;
			turn = 2;
        }
        else {
            cout << "Incorrect! The next card was: " << cardToStr(thePack[1]) << endl;
			turn = 2;
        }
    }
    else if (choice == 'l') {
        if (thePack[0].cardVal > thePack[1].cardVal) {
            cout << "Correct! It was a: " << cardToStr(thePack[1]) << endl;
			turn = 1;
        }
        else if (thePack[0].cardVal == thePack[1].cardVal) {
            cout << "You don't get anything for a pair,\n Not in this game! " << cardToStr(thePack[1]) << endl;
			turn = 2;
        }
        else {
            cout << "Incorrect! The next card was: " << cardToStr(thePack[1]) << endl;
			turn = 2;
        }
    }
	
    while (end == false) {
        // code to initialise values for each players turn
        if (turn == 1) {
            count = player1Count;
			whosGo = "Player 1";
			if (p1r1) {
				for (int i = 0; i < maxCard; i++) {
					thePack[i] = player1Pack[i];
				}
			}
            else {
				shufflePack(thePack, count, maxCard);
            }
        }
        else {
            count = player2Count;
			whosGo = "Player 2";
            if (p2r1) {
                for (int i = 0; i < maxCard; i++) {
                    thePack[i] = player2Pack[i];
                }
			}
            else {
                shufflePack(thePack, count, maxCard);
            }
        }
        while (freeze == false) {
            cout << "\n";
            cout << whosGo << " your score is: " << count << endl;
            cout << "Your cards: " << endl;
            printPack(thePack, count + 1); // print the pack up to the current card
            cout << "\n";
            cout << "Select from:\n 'h' if you think the next card is higher,\n 'l' if you think the next card is lower,\n 'f' to freeze your score and switch cards,\n 'q' to quit: ";
            cin >> choice;
            if (choice == 'q') {
				// code to quit the game
                freeze = true;
				end = true;
            }
            else if (choice == 's') {
                shufflePack(thePack, count, maxCard);
                printPack(thePack, maxCard);
            }
			else if (choice == 'p') {
				printPack(thePack, maxCard);
			}
            else if (choice == 'f') {
				// code to freeze the score and switch cards
				freeze = true;
				shufflePack(thePack, count, maxCard);
            }
            else if (choice == 'h') {
				// code to compare if the next card is higher
                if (thePack[count].cardVal < thePack[count + 1].cardVal) {
                    cout << "Correct! The next card is: " << cardToStr(thePack[count + 1]) << endl;
                    count++;
                }
                else if (thePack[count].cardVal == thePack[count + 1].cardVal) {
                    cout << "You don't get anything for a pair,\n Not in this game! " << cardToStr(thePack[count + 1]) << endl;
                    count = 0;
                    shufflePack(thePack, count, maxCard);
                    freeze = true;
                }
                else {
                    cout << "Incorrect! The next card was: " << cardToStr(thePack[count + 1]) << endl;
                    count = 0;
                    shufflePack(thePack, count, maxCard);
                    freeze = true;
                }
            }
            else if (choice == 'l') {
				// code to compare if the next card is lower
                if (thePack[count].cardVal > thePack[count + 1].cardVal) {
                    cout << "Correct! The next card is: " << cardToStr(thePack[count + 1]) << endl;
                    count++;
                }
                else if (thePack[count].cardVal == thePack[count + 1].cardVal) {
                    cout << "You don't get anything for a pair,\n Not in this game! " << cardToStr(thePack[count + 1]) << endl;
                    count = 0;
                    shufflePack(thePack, count, maxCard);
                    freeze = true;
                    }
                else {
                    cout << "Incorrect! The next card was: " << cardToStr(thePack[count + 1]) << endl;
                    count = 0;
                    shufflePack(thePack, count, maxCard);
                    freeze = true;
                }
            }
            else {
                cout << "Invlaid choice, please try again" << endl;
            }
            if (count > 3) {
                cout << "Congratulations! " << whosGo << " You have won the game of higher or lower!" << endl;
                freeze = true;
                end = true;
            }
        }
		// code to switch players
        if (turn == 1) {
			turn = 2;
            p1r1 = true;
			player1Count = count;
            for (int i = 0; i < maxCard; i++) {
                player1Pack[i] = thePack[i];
            }
        }
        else if (turn == 2) {
			turn = 1;
			p2r1 = true;
			player2Count = count;
            for (int i = 0; i < maxCard; i++) {
                player2Pack[i] = thePack[i];
            }
        }
        freeze = false; 
    }
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
