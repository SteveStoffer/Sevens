#include "board.h"
#include <iostream>

// Constructs the board. Each value is set to false since no cards
// have ben played. When a card is played, the value will be true.
Board::Board(){
  for (int i{ 0 }; i < static_cast<int>(Card::max_suits); ++i){
    for (int j{ 0 }; j < static_cast<int>(Card::max_rank); ++j){
      board_[i][j] = false;
    }
  }
}

// Prints the board.
void Board::printBoard() const{
  int count{ 0 };
  for (int i{ 0 }; i < static_cast<int>(Card::max_rank); ++i){
    for (int j{ 0 }; j < static_cast<int>(Card::max_suits); ++j){
      if (board_[j][i] == false){
        std::cout << "               ";
        if (j == static_cast<int>(Card::max_suits) - 1) ++count;
        continue;
      } else if(count == 0 && i < static_cast<int>(Card::rank_7)){
        std::cout << "+------------+ ";
        if (j == static_cast<int>(Card::max_suits) - 1) ++count;
        continue;
      } else if(count == 1 && i < static_cast<int>(Card::rank_7)){
        std::cout << "| ";
        switch(i){
          case 0: std::cout << "A          | "; break;
          case 1: std::cout << "2          | "; break;
          case 2: std::cout << "3          | "; break;
          case 3: std::cout << "4          | "; break;
          case 4: std::cout << "5          | "; break;
          case 5: std::cout << "6          | "; break;
        }
        if (j == static_cast<int>(Card::max_suits) - 1) ++count;
        continue;
      } else if(count == 0 && i > static_cast<int>(Card::rank_7)){
        std::cout << "|         ";
        switch(i){
          case 7: std::cout << " 8 | "; break;
          case 8: std::cout << " 9 | "; break;
          case 9: std::cout << "10 | "; break;
          case 10: std::cout << " J | "; break;
          case 11: std::cout << " Q | "; break;
          case 12: std::cout << " K | "; break;
        }
        if (j == static_cast<int>(Card::max_suits) - 1) ++count;
        continue;
      } else if(count == 1 && i > static_cast<int>(Card::rank_7)){
        std::cout << "+------------+ ";
        if (j == static_cast<int>(Card::max_suits) - 1) ++count;
        continue;
      } else if(i == static_cast<int>(Card::rank_7)){
        switch(count){
          case 0: std::cout << "+------------+ "; break;
          case 1: std::cout << "| 7          | "; break;
        }
        if (j == static_cast<int>(Card::clubs)){
          switch (count){
            case 2: std::cout << "|     ..     | "; break;
            case 3: std::cout << "|    (  )    | "; break;
            case 4: std::cout << "|   (_/\\_)   | "; break;
            case 5: std::cout << "|     /\\     | "; break;
          }
        } else if(j == static_cast<int>(Card::diamonds)){
          switch (count){
            case 2: std::cout << "|     /\\     | "; break;
            case 3: std::cout << "|    /  \\    | "; break;
            case 4: std::cout << "|    \\  /    | "; break;
            case 5: std::cout << "|     \\/     | "; break;
          }
        } else if(j == static_cast<int>(Card::hearts)){
          switch (count){
            case 2: std::cout << "|  ( \\  / )  | "; break;
            case 3: std::cout << "|   \\    /   | "; break;
            case 4: std::cout << "|    \\  /    | "; break;
            case 5: std::cout << "|     \\/     | "; break;
          }
        } else if(j == static_cast<int>(Card::spades)){
          switch (count){
            case 2: std::cout << "|     /\\     | "; break;
            case 3: std::cout << "|    /  \\    | "; break;
            case 4: std::cout << "|   (____)   | "; break;
            case 5: std::cout << "|     /\\     | "; break;
          }
        }
        switch (count){
          case 6: std::cout << "|          7 | "; break;
          case 7: std::cout << "+------------+ "; break;
        }
        if(j == static_cast<int>(Card::max_suits) - 1) ++count;
      }
    }
    std::cout << "\n";
    if (count == 2 && i != static_cast<int>(Card::rank_7)){
      count = 0;
      continue;
    } else if (count == 8 && i == static_cast<int>(Card::rank_7)){
      count = 0;
      continue;
    }
    if (count < 2 && i != static_cast<int>(Card::rank_7)){
      --i;
    } else if( count < 8 && i == static_cast<int>(Card::rank_7)){
      --i;
    }
  }
}

// Sets the value to true based on the card given.
// Since the board is an array[i][j], the 'i' value is the card suit,
// and the 'j' value is the card rank. The card given can have it's suit
// and rank staticly casted to an int to manage the array.
void Board::putDownCard(const Card& card){
  board_[static_cast<int>(card.getCardSuit())][static_cast<int>(card.getCardRank())] = true;
}

// Checks if a card can be played.
bool Board::canPlayCard(const Card& card){

  // No card has a value of 0 unless the rank is "max_rank".
  // If a card is passed with a value of 0, the card is not
  // valid and can not be played.
  if (card.getCardValue() == 0){
    return false;

  // If the card value is less than 7, the value above the card is checked for true or false.
  // If the value is true, then the current card can be played. If the value is false, the
  // card can not be played, since a higher card (up to a 7) has not been played yet.
  } else if (card.getCardValue() < 7){
    if (board_[static_cast<int>(card.getCardSuit())][static_cast<int>(card.getCardRank()) + 1]){
      return true;
    }

  // If the card value is greater than 7, the value below the card is checked for true or false.
  // If the value is true, then the current card can be played. If the calue is false, the card
  // can not be played, since a lower card (down to a 7) has not been played yet.
  } else if (card.getCardValue() > 7){
    if (board_[static_cast<int>(card.getCardSuit())][static_cast<int>(card.getCardRank()) - 1]){
      return true;
    }

  // If a card with a value of 7 is given, it can always be played since it is the first card to
  // be played.
  } else if (card.getCardValue() == 7) {
    return true;
  }
  return false;
}
