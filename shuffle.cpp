#include <ctime> //random_shuffle
#include <algorithm> //srand
#include <cstdlib> //time
using namespace std;

void CardDeck::shuffle(int seed = 0) {
	
	if (seed == 0) { //if no set seed, random seed generated
		seed = static_cast<int>(time(0)); //cast to int
	}

	srand(seed);

	random_shuffle(deck.being(), deck.end());
}
