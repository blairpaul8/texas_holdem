/* Name: Paul Blair, Camden Goering, Nick Rich
 * Description: This game is three-card poker that will mimic playing it in a casino. 
 * At the table you make a buy-in (blind bet) to play. Then you are dealt three cards
 * and based on your cards you can make an additional bet acoording to how good you think
 * your hand is. Then the dealers cards are revealed and the player and dealer hands are scored.
 * If the player wins the pot is added to their money if not then your bet is deducted from their
 * money.
 */
#include "CardDeck.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

//Used to evauluate both the player and dealer hand.
int score_hand(vector<Card> &hand) {
  //Sort the hand
  sort(hand.begin(), hand.end(), [](const Card &a, const Card &b) {
      return a.rank < b.rank;
      });

  //Straight Flush
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

  vector<Card> dealer_hand;
  vector<Card> player_hand;

  cout << "Welcome to 3 Card Poker!" << endl << endl;

  while (true) {
    cout << "How much money would you like to start with? ($10 - $50)" << endl;
    cout << ">> ";

    if (!(cin >> player_money)) {
      cout << "Invalid input. Please try again. " << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      continue;
    }

    if (player_money < 10 || player_money > 50) {
      cout << "Invalid input. Please try again. " << endl;
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      continue;
    }
    else {
      break;
    }
  }

  while (playing) {
	CardDeck *deck = new CardDeck(52);	  
	deck->shuffle(); //will always be random unless specific is used (dont use 0)

	int player_hand_score = 0;
	int dealer_hand_score = 0;

	cout << "Starting new game with $" << player_money << "..." << endl;
    cout << "Current Player wins: " << player_wins << endl;
    cout << "Current Dealer wins: " << dealer_wins << endl << endl;

    while (true) {
      cout << "How much money would you like to blind bet? (minimum $5)" << endl; 
      cout << ">> ";

      if (!(cin >> blind)) {
        cout << "Invalid input. Please try again. " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        continue;
      }
      if (blind < 5 || blind > player_money) {
        cout << "Invalid input. Please try again. " << endl;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        continue;
      }
      
      break;
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

    //display players cards
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


    //dealer reveal cards
    cout << endl << "---------------------------------" << endl;
    cout << "Dealer's Hand" << endl;
    deck->print_hand(dealer_hand);
    cout << "---------------------------------" << endl << endl;

    //player/dealer win score hand
    player_hand_score = score_hand(player_hand);
    dealer_hand_score = score_hand(dealer_hand);


    //if player wins 
    if (player_hand_score > dealer_hand_score) { 
		if (player_hand_score == 6) {
			cout << "Straight Flush! ";
		}
		if (player_hand_score == 5) {
			cout << "Three of a Kind! ";
		}
		if (player_hand_score == 4) {
			cout << "Straight! ";
		}
		if (player_hand_score == 3) {
			cout << "Flush! ";
		}
		if (player_hand_score == 2) {
			cout << "Pair! ";
		}
		if (player_hand_score == 1) {
			cout << "High Card! ";
		}
      cout << "Congratulations! You win!" << endl;
      player_money += pot;
      pot = 0;
      player_wins += 1;
      cout << "Your current cash total is now $" << player_money << "!" << endl;
    }
    // If dealer wins
    else if (player_hand_score < dealer_hand_score) {
		if (dealer_hand_score == 6) {
            cout << "Straight Flush! ";
        }
        if (dealer_hand_score == 5) {
            cout << "Three of a Kind! ";
        }
        if (dealer_hand_score == 4) {
            cout << "Straight! ";
        }
        if (dealer_hand_score == 3) {
            cout << "Flush! ";
        }
        if (dealer_hand_score == 2) {
            cout << "Pair! ";
        }
        if (dealer_hand_score == 1) {
            cout << "High Card! ";
        }
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

    dealer_hand.clear();
	player_hand.clear();
	
	while (true) { 
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
