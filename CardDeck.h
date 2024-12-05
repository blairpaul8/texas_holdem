/* Name: Paul Blair, Camden Goering, Nick Rich
 * Description: This game is three-card poker that will mimic playing it in a casino. 
 * At the table you make a buy-in (blind bet) to play. Then you are dealt three cards
 * and based on your cards you can make an additional bet acoording to how good you think
 * your hand is. Then the dealers cards are revealed and the player and dealer hands are scored.
 * If the player wins the pot is added to their money if not then your bet is deducted from their
 * money.
 */
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
  int rank;
  int suit;

  Card() {
    rank = 0;
    suit = 0;
  }
  //copy constructor 
  Card(const Card& other) {
    this->rank = other.rank;
    this->suit = other.suit;
  }
  //Assignment operator overload
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
