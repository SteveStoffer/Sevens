#include "card.h"
#include <cassert>
#include <iostream>
#include <string_view>

// Constructs a card
Card::Card(Rank rank, Suit suit) :
  rank_{ rank }, suit_{ suit }{}

// Returns a card based on user's input.
// If the input is not card related, this will return
// max_rank and / or max_suits and wil be checked later
// if the card is valid or not for the gameplay.
Card::Card(const std::string_view& str) :
  rank_{ max_rank }, suit_{ max_suits }{
    switch(str[0]){
      case 'A': rank_ = rank_ace; break;
      case '2': rank_ = rank_2; break;
      case '3': rank_ = rank_3; break;
      case '4': rank_ = rank_4; break;
      case '5': rank_ = rank_5; break;
      case '6': rank_ = rank_6; break;
      case '7': rank_ = rank_7; break;
      case '8': rank_ = rank_8; break;
      case '9': rank_ = rank_9; break;
      case 'T': rank_ = rank_10; break;
      case 'J': rank_ = rank_jack; break;
      case 'Q': rank_ = rank_queen; break;
      case 'K': rank_ = rank_king; break;
      default: rank_ = max_rank; break;
    }
    switch(str[1]){
      case 'C': suit_ = clubs; break;
      case 'D': suit_ = diamonds; break;
      case 'H': suit_ = hearts; break;
      case 'S': suit_ = spades; break;
      default: suit_ = max_suits; break;
    }
  }

// Checks if two cards are a match.
bool Card::operator==(const Card& card) const{
  return ((card.getCardRank() == rank_)&& (card.getCardSuit() == suit_));
}

// Prints an individual card.
void Card::printCard() const{
  switch(rank_){
    case rank_ace: std::cout << "A"; break;
    case rank_2: std::cout << "2"; break;
    case rank_3: std::cout << "3"; break;
    case rank_4: std::cout << "4"; break;
    case rank_5: std::cout << "5"; break;
    case rank_6: std::cout << "6"; break;
    case rank_7: std::cout << "7"; break;
    case rank_8: std::cout << "8"; break;
    case rank_9: std::cout << "9"; break;
    case rank_10: std::cout << "T"; break;
    case rank_jack: std::cout << "J"; break;
    case rank_queen: std::cout << "Q"; break;
    case rank_king: std::cout << "K"; break;
    default: std::cout << "?"; break; // Should never happen
  }

  switch(suit_){
    case clubs: std::cout << "C"; break;
    case diamonds: std::cout << "D"; break;
    case hearts: std::cout << "H"; break;
    case spades: std::cout << "S"; break;
    default: std::cout << "?"; break; // Should never happen
  }
}

// Max_rank is treated as a blank card.
bool Card::isBlank() const{
  return ( rank_ == max_rank );
}

// Returns an integer based on the cards rank.
int Card::getCardValue() const{
  switch(rank_){
    case rank_ace: return 1;
    case rank_2: return 2;
    case rank_3: return 3;
    case rank_4: return 4;
    case rank_5: return 5;
    case rank_6: return 6;
    case rank_7: return 7;
    case rank_8: return 8;
    case rank_9: return 9;
    case rank_10: return 10;
    case rank_jack: return 11;
    case rank_queen: return 12;
    case rank_king: return 13;
    default: return 0;
  }
}

// Getter for the card's suit.
Card::Suit Card::getCardSuit() const{
  return suit_;
}

// Getter for the card's rank.
Card::Rank Card::getCardRank() const{
  return rank_;
}
