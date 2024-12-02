#include "CardDeck.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//We can use this to evauluate both the player and dealer hand.
int score_hand(vector<Card> &hand) {
  //Sort the hand
  sort(hand.begin(), hand.end(), [](const Card &a, const Card &b) {
    return a.rank < b.rank;
  });

  //Straight Flush NOT CORRECT
  if ((hand[1].rank == hand[0].rank + 1 && hand[2].rank == hand[1].rank + 1) && 
      ((hand[0].suit == hand[1].suit && hand[0].suit == hand[2].suit))) {
    return 6;
  }

  //Three of a kind
  if (hand[0].rank == hand[1].rank && hand[0].rank == hand[2].rank) {
    return 5;
  }

  //Straight
  if (hand[1].rank == hand[0].rank + 1 && hand[2].rank == hand[1].rank + 1) {
    return 4;
  }

  //Flush
  if (hand[0].suit == hand[1].suit && hand[0].suit == hand[2].suit) {
    return 3;
  } 
  //Pair
  if (hand[0].rank == hand[1].rank || hand[1].rank == hand[2].rank) {
    return 2;
  }

  //High card 
  return 1;
}

int main() {

  int player_wins = 0, dealer_wins = 0;
  int player_money = 0;
  int blind = 0;
  int raise = 0; 
  int pot = 0;
  char turn;
  bool playing = true;

  int player_hand_score = 0;
  int dealer_hand_score = 0;

  vector<Card> dealer_hand;
  vector<Card> player_hand;

  CardDeck *deck = new CardDeck(52);
  deck->shuffle(12); //will always be random unless specific is used (dont use 0)
                     //deck->print_deck();

  cout << "Welcome to 3 Card Poker!" << endl << endl;

  while (true) {
    cout << "How much money would you like to start with? ($10 - $50)" << endl;
    cout << ">> ";
    cin >> player_money;

    if (player_money < 10 || player_money > 50) {
      cout << "Invalid input. Please try again. ";
      cin.ignore();
      cin.clear();
    }
    else {
      break;
    }
  }

  while (playing) {
    cout << "Starting new game with $" << player_money << "..." << endl;
    cout << "Current Player wins: " << player_wins << endl;
    cout << "Current Dealer wins: " << dealer_wins << endl << endl;

    while (true) {
      cout << "How much money would you like to blind bet? (minimum $5)" << endl; 
      cout << ">> ";
      cin >> blind;

      if (blind < 5 || blind > player_money) {
        cout << "Invalid input. Please try again. ";
      }
      else {
        break;
      }
    }
    player_money -= blind;
    pot += (blind * 2);
    cout << "Your current cash total is now $" << player_money << "." << endl;

    //deal cards
    for (int i = 0; i < 6; i++) {
      if ((i % 2) == 0) {
        Card new_card = deck->deal();
        player_hand.push_back(new_card);
      }
      else {
        Card new_card;
        new_card = deck->deal();
        dealer_hand.push_back(new_card);
      }
    }

    //display playes cards
    cout << endl << "---------------------------------" << endl;
    cout << "Player's Hand" << endl;
    deck->print_hand(player_hand);
    cout << "---------------------------------" << endl << endl;

    cout << "Total pot money: $" << pot << endl;

    while (true) {

      cout << "Would you like to raise or check? ('r' or 'c')" << endl;
      cout << ">> ";
      cin >> turn;

      if (turn == 'c') {
        break;
      }
      else if (turn == 'r') {

        while (true) {
          cout << "How much money would you like to raise?" << endl;
          cout << ">> "; 
          cin >> raise;

          if (raise < 0 || raise > player_money) {
            cout << "Invalid input. Please try again. ";
          }
          else {
            pot += (raise * 2);
            player_money -= raise;
            cout << "Your current cash total is now $" << player_money << "." << endl;
            break;
          }
        }

        break;
      }
      else {
        cout << "Invalid input. Please try again. ";
      }
    }


    //player and dealer reveal cards
    cout << endl << "---------------------------------" << endl;
    cout << "Dealer's Hand" << endl;
    deck->print_hand(dealer_hand);
    cout << "---------------------------------" << endl << endl;

    //player/dealer win check
    player_hand_score = score_hand(player_hand);
    dealer_hand_score = score_hand(dealer_hand);


    //if player wins 
	if (player_hand_score > dealer_hand_score) { 
		cout << "Congradulations! You win!" << endl;
		player_money += pot;
		pot = 0;
    player_wins += 1;
		cout << "Your current cash total is now $" << player_money << "!" << endl;
	}
	else if (player_hand_score < dealer_hand_score) {
		cout << "Sorry! Dealer wins!" << endl;
		pot = 0;
    dealer_wins += 1;
		cout << "Your current cash total is now $" << player_money << "." << endl;
	}
	else {
		cout << "Tie! No winner!" << endl;
		player_money += (pot / 2);
		pot = 0;
		cout << "Your current cash total is now $" << player_money << "." << endl;
	}

    while (true) { //pulled from blackjack
      if (player_money == 0) {
        cout << endl << "You're out of money. Go Home." << endl;
        playing = false;
        break;
      }

      cout << endl << "Would you like to play again? ('y' or 'n')" << endl;
      cout << ">> ";
      cin >> turn;

      if (turn == 'n') { //end the game
        cout << "Thank you for playing!" << endl;
        cout << "Player wins: " << player_wins << endl;
        cout << "Dealer wins: " << dealer_wins << endl;
        cout << "Player ending cash amount: $" << player_money << endl;
        playing = false;
        break;
      }

      if (turn == 'y') {
        break;
      }

      if (turn != 'y' && turn != 'n') { 
        cout << "Invalid input. Please try again. ";
      }
    }
  }

  return 0;
}
