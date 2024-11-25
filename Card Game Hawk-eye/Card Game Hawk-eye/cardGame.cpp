#include <iostream>
#include "cardGame.h"
using namespace std;

string cardToStr(aCard c) {
    string val; //variable used to change the card value
    string suit; //variable used to change the card suit
    if (c.cardVal == 14) val = "A";
    else if (c.cardVal == 11) val = "J";
    else if (c.cardVal == 12) val = "Q";
    else if (c.cardVal == 13) val = "K";
    else val = to_string(c.cardVal); //if not a face card it remains the same
    if (c.cardSuit == 0) suit = "H";
    else if (c.cardSuit == 1) suit = "C";
    else if (c.cardSuit == 2) suit = "D";
    else if (c.cardSuit == 3) suit = "S";
    else suit = to_string(c.cardSuit);
    return val + suit;
}

aCard getCard(string random, bool arr[])
{  // function returns a card using the random seed
    aCard ans;
    int rcard;
    
    string rcardstr = random.substr(rand() % 8, 1) + random.substr(rand() % 8, 1);    // two random characters from randNumStr
    rcard = stoi(rcardstr) % 52;         // get integer in range 0..51
    while (arr[rcard]) {
		// Repeat if the card has already been dealt
		rcard = (rcard + 1) % 52;
        
    }
    arr[rcard] = true; // Mark the card as dealt
    
    ans.cardVal = 2 + rcard % 13;                          // give cardVal 1..13 
    ans.cardSuit = static_cast<Suit>(rcard / 13);         // and for suit
    return ans;
}

void printPack(aCard arr[], int n) {
    for (int count = 0; count < n; count++)
    {
        cout << cardToStr(arr[count]) << " ";
		if ((count + 1) % 13 == 0) cout << endl;
    }
    cout << endl;
}

void shufflePack(aCard arr[], int min, int max) {
    for (int ct = min; ct < max; ct++) {
        int swap = rand() % max;
		while (swap <= min) {
			swap = rand() % max;
		}
        aCard temp = arr[ct];
        arr[ct] = arr[swap];
        arr[swap] = temp;
    }
}
