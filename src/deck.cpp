#include "headers/deck.h"
#include <algorithm> // std::shuffle
#include <ctime>
#include <iostream>
#include <random>

// Constructs a deck
Deck::Deck(){
  for (int suit{ 0 }; suit < static_cast<int>(Card::max_suits); ++suit){
    for (int rank{ 0 }; rank < static_cast<int>(Card::max_rank); ++rank){
      deck_.push_back( { static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit) });
    }
  }
}

// Prints each card in the deck (not used)
void Deck::printDeck() const{
  for (const auto& card : deck_){
    card.printCard();
    std::cout << " ";
  }
  std::cout << "\n";
}

// Shuffles the deck of cards.
void Deck::shuffle(){
  static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
  std::shuffle(deck_.begin(), deck_.end(), mt);
  // cardIndex_ = 0;
}

// Checks if the deck is empty.
bool Deck::isEmpty() const{
  return (deck_.empty());
}

// Returns a card and removes the card from the "deck" (vector).
Card Deck::dealCards(){
  Card card{ deck_.back() };
  deck_.pop_back();
  return card;
}
