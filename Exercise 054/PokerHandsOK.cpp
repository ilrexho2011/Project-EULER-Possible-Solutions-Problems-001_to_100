//	 Poker hands
/*	 In the card game poker, a hand consists of five cards and are ranked, from lowest to highest, in the following way:

High Card: Highest value card.
One Pair: Two cards of the same value.
Two Pairs: Two different pairs.
Three of a Kind: Three cards of the same value.
Straight: All cards are consecutive values.
Flush: All cards of the same suit.
Full House: Three of a kind and a pair.
Four of a Kind: Four cards of the same value.
Straight Flush: All cards are consecutive values of same suit.
Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.
The cards are valued in the order:
2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace.

If two players have the same ranked hands then the rank made up of the highest value wins; 
for example, a pair of eights beats a pair of fives (see example 1 below). 
But if two ranks tie, for example, both players have a pair of queens, 
then highest cards in each hand are compared (see example 4 below); 
if the highest cards tie then the next highest cards are compared, and so on.

Consider the following five hands dealt to two players:

Hand	 	Player 1	 	Player 2	 	Winner
1	 	5H 5C 6S 7S KD
Pair of Fives
 	2C 3S 8S 8D TD
Pair of Eights
 	Player 2
2	 	5D 8C 9S JS AC
Highest card Ace
 	2C 5C 7D 8S QH
Highest card Queen
 	Player 1
3	 	2D 9C AS AH AC
Three Aces
 	3D 6D 7D TD QD
Flush with Diamonds
 	Player 2
4	 	4D 6S 9H QH QC
Pair of Queens
Highest card Nine
 	3D 6D 7H QD QS
Pair of Queens
Highest card Seven
 	Player 1
5	 	2H 2D 4C 4D 4S
Full House
With Three Fours
 	3C 3D 3S 9S 9D
Full House
with Three Threes
The file, poker.txt, contains one-thousand random hands dealt to two players. 
Each line of the file contains ten cards (separated by a single space): 
the first five are Player 1's cards and the last five are Player 2's cards. 
You can assume that all hands are valid (no invalid characters or repeated cards), 
each player's hand is in no specific order, and in each hand there is a clear winner.

How many hands does Player 1 win? Pergjigja e sakte eshte: 376	*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Card {
  private:
    char suit;
    char type;
  public:
    Card() {}
    Card(string card) {
      type = card[0];
      suit = card[1];
    }
    bool operator<(const Card& c) {
      int temp1 = (int) this->type;
      int temp2 = (int) c.type;
      if (this->type == 'T')
        temp1 = 64;
      else if (this->type == 'K')
        temp1 = 99;
      else if (this->type == 'A')
        temp1 = 100;
      if (c.type == 'T')
        temp2 = 64;
      else if (c.type == 'K')
        temp2 = 99;
      else if (c.type == 'A')
        temp2 = 100;
      return (temp1 < temp2);
    }
    bool operator>(const Card& c) {
      int temp1 = (int) this->type;
      int temp2 = (int) c.type;
      if (this->type == 'T')
        temp1 = 64;
      else if (this->type == 'K')
        temp1 = 99;
      else if (this->type == 'A')
        temp1 = 100;
      if (c.type == 'T')
        temp2 = 64;
      else if (c.type == 'K')
        temp2 = 99;
      else if (c.type == 'A')
        temp2 = 100;
      return (temp1 > temp2);
    }
    bool sameType(const Card& c) {
      return (this->type == c.type);
    }
    bool sameSuit(const Card& c) {
      return (this->suit == c.suit);
    }
    bool before(const Card& c) {
      bool ret = (int) (c.type - this->type) == 1;
      ret &= (this->type != 'J') || (c.type != 'K');
      ret |= (this->type == 'A') && (c.type == '2');
      ret |= (this->type == '9') && (c.type == 'T');
      ret |= (this->type == 'T') && (c.type == 'J');
      ret |= (this->type == 'J') && (c.type == 'Q');
      ret |= (this->type == 'Q') && (c.type == 'K');
      ret |= (this->type == 'K') && (c.type == 'A');
      return ret;
    }
    void print() {
      cout << type << suit << " ";
    }
};

class PokerHand {
  private:
    Card cards[5];
    int handRank;
    Card highPair;
    Card lowPair;
  public:
    PokerHand(string hand) {
      //Initialize cards in descending order
      cards[0] = Card(hand.substr(0,2));
      for (int i = 1; i < 5; i++) {
        int temp = i;
        Card newCard = Card(hand.substr(3*i,2));
        while (temp > 0) {
          if (newCard > cards[temp - 1])
            cards[temp] = cards[temp - 1];
          else
            break;
          temp--;
        }
        cards[temp] = newCard;
      }

      //find hand rank, first searching pairs
      handRank = 0;
      highPair = Card("11");
      for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
          if (cards[i].sameType(cards[j])) {
            handRank++;
            if (cards[i] > highPair) {
              lowPair = highPair;
              highPair = cards[i];
            }
            else
              lowPair = cards[i];
          }
        }
      }
      //4 of kind, reassign to right rank
      if (handRank == 6)
        handRank = 7;
      //full house, make sure highPair is 3 of a kind
      if (handRank == 4) {
        handRank = 6;
        for (int i = 0; i < 3; i++) {
          int count = 0;
          for (int j = i + 1; j < 5; j++)
            if (cards[i].sameType(cards[j]))
              count++;
          if ((count == 3) && (!cards[i].sameType(highPair))) {
            Card temp = highPair;
            highPair = lowPair;
            lowPair = temp;
          }
        }
      }

      //Check if all are consecutive
      bool consecutive = true;
      for (int i = 0; i < 4; i++) {
          if ((i == 0) && (cards[0] > Card("KH"))) {
            if (!cards[0].before(cards[4]) && !cards[1].before(cards[0]))
              consecutive = false;
          }
          else
            if (!cards[i+1].before(cards[i]))
              consecutive = false;
      }
      if (consecutive && (handRank < 4))
        handRank = 4;

      //Check if all are same suit
      bool sameSuit = true;
      for (int i = 1; i < 5; i++)
        if (!cards[0].sameSuit(cards[i]))
          sameSuit = false;
      if (sameSuit && (handRank < 5))
        handRank = 5;

      //Straight Flush or Royal Flush
      if (consecutive && sameSuit)
        handRank = 8;
      if (consecutive && sameSuit && (cards[1] > Card("QS")))
        handRank = 9;
    }
    bool operator>(PokerHand& ph) {
      //Return the higher ranking hand
      if (this->handRank > ph.handRank)
        return true;
      else if (this->handRank < ph.handRank)
        return false;

      //If equal return based on higher pair(s)
      if ((this->handRank == ph.handRank) && (this->handRank == 1)) {
        if (this->highPair > ph.highPair)
          return true;
        else if (this->highPair < ph.highPair)
          return false;
      }
      if ((this->handRank == ph.handRank) && (this->handRank == 2)) {
        if (this->highPair > ph.highPair)
          return true;
        else if (this->highPair < ph.highPair)
          return false;
        if (this->lowPair > ph.lowPair)
          return true;
        else if (this->highPair < ph.lowPair)
          return false;
      }
      if ((this->handRank == ph.handRank) && (this->handRank == 3)) {
        if (this->highPair > ph.highPair)
          return true;
        else if (this->highPair < ph.highPair)
          return false;
      }
      if ((this->handRank == ph.handRank) && (this->handRank == 6)) {
        if (this->highPair > ph.highPair)
          return true;
        else if (this->highPair < ph.highPair)
          return false;
        if (this->lowPair > ph.lowPair)
          return true;
        else if (this->highPair < ph.lowPair)
          return false;
      }

      //If same pairs decide on high card
      for (int i = 0; i < 5; i++) {
        if (this->cards[i] > ph.cards[i])
          return true;
        else if (this->cards[i] < ph.cards[i])
          return false;
      }

      //Tie
      return false;
    }
};

int main() {
  int totalWins = 0;
  int numberOfHands = 1000;
  string round;
  ifstream myfile("poker.txt");
  for (int i = 0; i < numberOfHands; i++) {
    getline(myfile, round);
    PokerHand player1 = PokerHand(round.substr(0,14));
    PokerHand player2 = PokerHand(round.substr(15,14));
    if (player1 > player2)
      totalWins++;
  }
  cout << "Player 1 Wins: " << totalWins;
  return 0;
}
