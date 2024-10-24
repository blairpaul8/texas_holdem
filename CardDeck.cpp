#include "CardDeck.h"
#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

const string hearts = reinterpret_cast<const char*>(u8"\u2665");
const string diamonds = reinterpret_cast<const char*>(u8"\u2666");
const string clubs = reinterpret_cast<const char*>(u8"\u2663");
const string spades = reinterpret_cast<const char*>(u8"\u2660");

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
    else if (i >= 27 && i < 39) {
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
  Card card = deck.back();
  deck.pop_back();
  return card;
}

void CardDeck::print_hand(vector<Card> hand) {
  string suit;
  int spaces = 7;

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
      if (hand[j].rank == 8 || hand[j].rank == 21 || hand[j].rank == 33 || hand[j].rank == 47) {
        spaces = 6;
      }

      if (i == 0) {
        cout << " -------- " << "   ";
      }
      if (i == 1) {
        cout << "|" << hand[i].rank << setw(spaces); << "|" << "   ";
      }
      if (i = 2) {
        cout << "|        |" << "   ";
      }
      if (i == 3) {
        cout << "|    " << suit << "   |" << "   ";
      }
      if (i == 4) {
        cout << "|        |" << "   ";
      }
      if (i == 5) {
        cout << "|" setw(space) << hand[j].rank << "|" << "   ";
      }
    }
    cout << endl;
  }
} 
