#include "game.h"
#include <iostream>
#include <string>

// Constructor of the game.
Game::Game(){
  deck_.shuffle();
  
  // Deal cards for each player until deck is empty.
  // Since there are 4 players, the deck divides evenly.
  while(!deck_.isEmpty()){
    player1_.setCard(deck_.dealCards());
    player2_.setCard(deck_.dealCards());
    player3_.setCard(deck_.dealCards());
    player4_.setCard(deck_.dealCards());
  }
}

// Prints each player's card count.
void Game::printStats() const{
  std::cout << "Player 2 has " << player2_.getCardCount() << " cards left.\n";
  std::cout << "Player 3 has " << player3_.getCardCount() << " cards left.\n";
  std::cout << "Player 4 has " << player4_.getCardCount() << " cards left.\n";
  std::cout << "You have " << player1_.getCardCount() << " cards:\n";
  player1_.printHand();
}

// Gets user's input and returns a card based on input. 
Card Game::getInput(){
  std::string input;

  // Only accept an input of 2 characters in length.
  while (input.length() != 2){
    std::cout << "Enter a card or (XX) to pass: ";
    std::cin >> input;
  }
  std::transform(input.begin(), input.end(), input.begin(), ::toupper);

  // Return a card, the card constructor can handle an input of 2 chars.
  return { input };
}

// "Computer's" turn, plays a card if a card can be played.
void Game::computerTurn(Player& player){
  std::vector<Card> temp{ player.getHand() };
  for (const Card& c : temp){
    if (board_.canPlayCard(c)){
      board_.putDownCard(c);
      player.removeCard(c);
      return;
    }
  }
}

// Humans turn. 
void Game::userTurn(Player& player){
  // Creat a card to be used to store user's input
  Card card{Card::max_rank, Card::max_suits};

  do{
    card = getInput();
    
    // Card will be set to max_rank and max_suits if the user tries to pass.
    // If the user has a card that can be played, the user can not pass.
    if (card.getCardRank() == Card::max_rank && card.getCardSuit() == Card::max_suits){
      std::vector<Card> temp {player.getHand()};
      bool canPass{ true };

      for (const Card& c : temp){
        if (board_.canPlayCard(c)){
          canPass = false;
        }
      }
      if (canPass) return;
      std::cout << "You can play a card!\n";
    }

  } while(!(board_.canPlayCard(card) && player.hasCard(card)));

  // User has a valid card to play, so we need to update the board,
  // remove the card from their hand, and decrement their number of cards.
  board_.putDownCard(card);
  player.removeCard(card);
}

// Starts the game
void Game::startGame(){
  while (true){

    // Print the board and other player's card count
    // each time it is the player's turn.
    // After each turn, check if the player has won.
    board_.printBoard();
    printStats();

    userTurn(player1_);
    if (player1_.hasWon()){
      clear();
      printWin();
      return;
    }

    player2_.printHand();
    computerTurn(player2_);
    if (player2_.hasWon()) break;

    player3_.printHand();
    computerTurn(player3_);
    if (player3_.hasWon()) break;

    player4_.printHand();
    computerTurn(player4_);
    if (player4_.hasWon()) break;
    clear();
  }
  clear();
  printLose();
}

// Prints "7EVENS" and waits for user to press enter before starting game.
void Game::startMenu(){
  printMenu();
  pause();
  clear();
  startGame();
}
