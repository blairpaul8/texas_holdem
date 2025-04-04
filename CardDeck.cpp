/* Name: Paul Blair, Camden Goering, Nick Rich
 * Description: This game is three-card poker that will mimic playing it in a casino. 
 * At the table you make a buy-in (blind bet) to play. Then you are dealt three cards
 * and based on your cards you can make an additional bet acoording to how good you think
 * your hand is. Then the dealers cards are revealed and the player and dealer hands are scored.
 * If the player wins the pot is added to their money if not then your bet is deducted from their
 * money.
 */
#include "CardDeck.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <ctime> //random_shuffle
#include <algorithm> //srand
#include <cstdlib> //time 
#include <random>

using namespace std;

//Used to display the symbols for the card (hearts, diamonds, clubs, and spades)
const string hearts = reinterpret_cast<const char*>(u8"\u2665");
const string diamonds = reinterpret_cast<const char*>(u8"\u2666");
const string clubs = reinterpret_cast<const char*>(u8"\u2663");
const string spades = reinterpret_cast<const char*>(u8"\u2660");

const string cardValues[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

//Contructor
CardDeck::CardDeck(int n) {
  this->n = n;
  for (int i = 0; i < n; i++) {
    Card playingCard;
    if (i >= 0 && i < 13) {
      playingCard.suit = 0;
    }
    else if (i >= 13 && i < 26) {
      playingCard.suit = 1;
    }
    else if (i >= 26 && i < 39) {
      playingCard.suit = 2;
    }
    else {
      playingCard.suit = 3;
    }
    playingCard.rank = i % 13;
    this->deck.push_back(playingCard);
  }
}


void CardDeck::print_deck() {
  for (size_t i = 0; i < deck.size(); i++) {
    cout << deck[i].suit << ", " << deck[i].rank << "; ";
    if ((i % 13) == 12) {
      cout << endl << endl;
    } 
  } 
  cout <<endl;
}

Card CardDeck::deal() {
  Card dealt_card = deck.back();
  deck.pop_back();
  return dealt_card;
}

void CardDeck::print_hand(vector<Card> &hand) {
  string suit;
  int spaces = 7;
  int spaces2 = 7;

  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 3; j++) {

      if (hand[j].suit == 0) {
        suit = hearts;
      }
      if (hand[j].suit == 1) {
        suit = diamonds;
      }
      if (hand[j].suit == 2) {
        suit = spades;
      }
      if (hand[j].suit == 3) {
        suit = clubs;
      }
      //If the rank is 10 the spacing for the card printing has to change
      if (hand[j].rank == 8) {
        spaces = 6;
        spaces2 = 7;
      }
      else {
        spaces = 7;
        spaces2 = 7;
      }

      //Gross cout printing of the cards to be displayed in the terminal.
      if (i == 0) {
        cout << " ------- " << "   ";
      }
      if (i == 1) {
        cout << "|" << cardValues[hand[j].rank] << setw(spaces) << "|" << "   ";
      }
      if (i == 2) {
        cout << "|       |" << "   ";
      }
      if (i == 3) {
        cout << "|   " << suit << "   |" << "   ";
      }
      if (i == 4) {
        cout << "|       |" << "   ";
      }
      if (i == 5) {
        cout << "|" << setw(spaces2) << cardValues[hand[j].rank] << "|" << "   ";
      }
      if (i == 6) {
        cout << " ------- " << "   ";
      }
    }
    cout << endl;
  }
} 

void CardDeck::shuffle(int seed) {

  srand(time(0));

  random_shuffle(deck.begin(), deck.end());
}
