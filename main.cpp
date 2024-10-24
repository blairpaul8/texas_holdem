#include "CardDeck.h"
#include <vector>
#include <iostream>

using namespace std;


#define STARTING_CASH = 0;


int main() {

  //prompt player to play and input starting cash.

  //promt player to play a hand for buyin amount $5
  vector<Card> dealer_hand;
  vector<Card> player_hand;
  
  CardDeck *deck = new CardDeck();
  deck->print_deck();
  
  for (int i = 0; i < 6; i++) {

    if ((i % 2) == 0) {
      Card card = deck->deal();
      player_hand.push_back(card);
    }
    else {
      Card card = deck->deal();
      dealer_hand.push_back(card);
    }
  }

  deck->print_hand(player_hand);
}
