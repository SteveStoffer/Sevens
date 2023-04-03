#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "card.h"
#include "deck.h"
#include "player.h"
#include "printfunctions.h"
#include <string_view>

class Game{
private:
  Player player1_; // User
  Player player2_; 
  Player player3_;
  Player player4_;
  Deck deck_;
  Board board_;

public:
  Game();
  void startMenu();
  void startGame();
  void printStats() const;
  Card getInput();
  void userTurn(Player& player);
  void computerTurn(Player& player);
};

#endif // GAME_H
