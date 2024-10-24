//Deal file
//Deals cards to dealer and user.
//10-24-24

#include "CardDeck.h"
#include <iostream>
#include <vector>

using namespace std;

struct Card{

	int suit;
	int rank;

};

int main(){
	
	vector<Card> deck;
	
	for(int i=0;i<52;i++){

		Card newCard;

		if(i >= 0 && i<13){
			newCard.suit = 0;
		}
		else if(i >=13 && i < 26){
			newCard.suit = 1;
		}
		else if(i >=26 && i < 39){
			newCard.suit = 2;
		}
		else{
			newCard.suit = 3;
		}

		newCard.rank = i % 13;

		deck.push_back(newCard);

	}

	for(const auto card : deck){
		cout << card.rank << " of " << card.suit << endl;
	}

	

	return 0;
}
