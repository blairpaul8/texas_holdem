#include <vector>
#include <stdlib.h>

using namespace std;

// The ranks are 0 is 2 and 12 is ACE.
//The suit numbers are as follows
// 0 = hearts
// 1 = diamonds
// 2 = spades
// 3 = clubs
struct Card {
  string rank;
  int suit;

  Card() {
    rank = "";
    suit = 0;
  }
  Card(const Card& other) {
    this->rank = other.rank;
    this->suit = other.suit;
  }
  
  Card& operator=(const Card& other) {
    if (this != &other) {
      rank = other.rank;
      suit = other.suit;
    }
    return *this;
  }
};

class CardDeck {
  public:
    CardDeck(int n = 52);
    void shuffle(int seed = 0);
    Card deal();
    vector<Card> player_hand;
    vector<Card> dealer_hand;
    void print_hand(vector<Card> &hand);

    void print_deck();

  private:
    int n = 52;
    vector<Card> deck;
};


