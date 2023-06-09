#include "player.h"
#include "board.h"
#include <iostream>
#include <algorithm>

// Adds a card to the user's "hand".
void Player::setCard(const Card& card){
  hand_.push_back(card);
}

// Prints each card in the user's "hand".
void Player::printHand() const{
  for (const auto& card : hand_){
    card.printCard();
    std::cout << " ";
  }
  std::cout << "\n";
}

// Removes a card from the user's "hand" and decrements their 
// card count by one.
void Player::removeCard(const Card& card){
  --cardCount_;
  for (int i{ 0 }; i < hand_.size(); ++i){
    if (card == hand_[i]){
      hand_.erase(hand_.begin()+i);
    }
  }
}

// Sorts players hand so the game is easier to play.
void Player::sortHand(){
  std::sort(hand_.begin(), hand_.end(), [](const Card& a, const Card& b){
    return (a.getCardSuit() == b.getCardSuit()) ? (a.getCardValue() < b.getCardValue()) : (a.getCardSuit() < b.getCardSuit());
  });
}

// Returns true if the player has no cards left.
bool Player::hasWon() const{
  return (cardCount_ == 0);
}

// Checks if a player has a card in their "hand".
bool Player::hasCard(const Card& card) const{
  for (const auto& c : hand_){
    if (c == card){
      return true;
    }
  }
  return false;
}

// Getter for user's card count.
int Player::getCardCount() const{
  return cardCount_;
}

// Getter for user's "hand".
const std::vector<Card>& Player::getHand() const{
  return hand_;
}
