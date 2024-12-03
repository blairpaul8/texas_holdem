#include <iostream>
#include <string>
using namespace std;
int main() {

  int card_num1;
  int card_num2;
  cout << "Enter card 1 number: ";
  cin >> card_num1;
  cout << "Enter card 2 number: ";
  cin >> card_num2;
  std::string heart = reinterpret_cast<const char*>(u8"\u2665");
  std::string diamond = reinterpret_cast<const char*>(u8"\u2666");
  std::string club = reinterpret_cast<const char*>(u8"\u2663");
  std::string spade = reinterpret_cast<const char*>(u8"\u2660");

  std::cout << "Heart: " << heart << "\n";
  std::cout << "Diamond: " << diamond << "\n";
  std::cout << "Club: " << club << "\n";
  std::cout << "Spade: " << spade << "\n";
  char a = (char)184;
  string line = reinterpret_cast<const char*>(u8"\u007c");
  cout << "Line: " << line << endl;

  cout << " -------- " << "   "<< " -------- " << endl;
  cout << "|" << card_num1 << "       |" << "   " << "|" << card_num2 << "       |" << endl;
  cout << "|        |" << "   " << "|        |" << endl;
  cout << "|    " << heart << "   |" << "   " << "|   " << spade << "    |" << endl;
  cout << "|        |" << "   " << "|        |" << endl;
  cout << "|       " << card_num1 << "|" << "   " << "|       " << card_num2 << "|" << endl;
  cout << " -------- " << "   " << " -------- " << endl;
  return 0;
}

/*
   cardeck vector
   [1,2,3,4,5 ........ ,52]


   deal() {
   random() % 52;

   return int num;
   4
   }
   if (card_num < 13) {
   suit = heart;
   }

   hearts 0-12
   diamons 13-*/
