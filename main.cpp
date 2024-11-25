#include "CardDeck.h"
#include <vector>
#include <iostream>

using namespace std;


int main() {

  int player_wins = 0, dealer_wins = 0;
  int player_money;
  int blind, raise, pot;
  char turn;
  bool playing = true;

  //prompt player to play and input starting cash.

  //promt player to play a hand for buyin amount $5
  vector<Card> dealer_hand;
  vector<Card> player_hand;

  CardDeck *deck = new CardDeck(52);
  //deck->print_deck();
  deck->shuffle(12); //will always be random unless specific is used (dont use 0)
                     //deck->print_deck();

  /*for (int i = 0; i < 6; i++) {
    if ((i % 2) == 0) {
      Card new_card = deck->deal();
      player_hand.push_back(new_card);
    }
    else {
      Card new_card;
      new_card = deck->deal();
      dealer_hand.push_back(new_card);
    }
  }*/

  //deck->print_hand(dealer_hand);


  cout << "Welcome to 3 Card Poker!" << endl << endl;

  while (true) {

    cout << "How much money would you like to start with? ($10 - $50)" << endl;
    cout << ">> ";
    cin >> player_money;

    if (player_money < 10 || player_money > 50) {
      cout << "Invalid input. Please try again. ";
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
    pot += blind;
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
    deck->print_hand(player_hand);

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
            pot += raise;
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
    deck->print_hand(dealer_hand);

    //player/dealer win check


    //if player wins 
    cout << "Congradulations! You win!" << endl;
    player_money += (pot * 2);
    pot = 0;
    cout << "Your current cash total is now $" << player_money << "!" << endl;

    //if dealer wins
    cout << "Sorry! Dealer wins!" << endl;
    pot = 0;
    cout << "Your current cash total is now $" << player_money << "." << endl;

    while (true) { //pulled from blackjack

      cout << "Would you like to play again? ('y' or 'n')" << endl;
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
