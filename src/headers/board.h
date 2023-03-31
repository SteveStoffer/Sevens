#ifndef BOARD_H
#define BOARD_H

#include "card.h"
#include "deck.h"
#include <array>

class Board{
public:
  using BoardType = std::array<std::array<bool, 13>, 4>;

private:
  BoardType board_{};

public:
  Board();
  void printBoard() const;
  void putDownCard(const Card& card);
  bool canPlayCard(const Card& card);  
};

#endif // BOARD_H