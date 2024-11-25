#include <string>

enum Suit { h, c, d, s };      // define suits

struct aCard {                          // defines a card
    int cardVal;                        // number 1..13
    Suit cardSuit;                      // suit
};

std::string cardToStr(aCard c);			// declare function to represent a card as a two character string

aCard getCard(std::string random, bool arr[]);        // declares function to get a card from random string

void printPack(aCard arr[], int n);             // declares function to print an array of cards

void shufflePack(aCard arr[], int min, int max);           // declares function to shuffle an array of cards

void higher(aCard card1, aCard card2);		  // declares function to compare two cards