#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include <vector>

class Player{
private:
  std::vector<Card> hand_{};
  int cardCount_{ 13 };

public:
  Player() = default;
  void setCard(const Card& card);
  void printHand() const;
  void removeCard(const Card& card);
  bool hasWon() const;
  bool hasCard(const Card& card) const;
  int getCardCount() const;
  const std::vector<Card>& getHand() const;
};

#endif // PLAYER_H