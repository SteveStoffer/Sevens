#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <vector>

class Deck{
private:
  std::vector<Card> deck_{};
  
public:
  Deck();
  void printDeck() const;
  void shuffle();
  bool isEmpty() const;
  Card dealCards();
};

#endif // DECK_H 