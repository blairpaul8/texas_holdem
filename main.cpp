#include "CardDeck.h"
#include <vector>
#include <iostream>

using namespace std;




int main() {

  //prompt player to play and input starting cash.

  //promt player to play a hand for buyin amount $5
  vector<Card> dealer_hand;
  vector<Card> player_hand;
  
  CardDeck *deck = new CardDeck();
  deck->print_deck();
  
  for (int i = 0; i < 6; i++) {

    if ((i % 2) == 0) {
      Card new_card = deck->deal();
      player_hand.push_back(new_card);
    }
    else {
      Card new_card = deck->deal();
      dealer_hand.push_back(new_card);
    }
  }

  deck->print_hand(player_hand);
}
