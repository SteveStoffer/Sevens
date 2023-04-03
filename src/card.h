#ifndef CARD_H
#define CARD_H

#include <string_view>

class Card{
public:
  enum Suit{
    clubs,
    diamonds,
    hearts,
    spades,

    max_suits
  };

  enum Rank{
    rank_ace,
    rank_2,
    rank_3,
    rank_4,
    rank_5,
    rank_6,
    rank_7,
    rank_8,
    rank_9,
    rank_10,
    rank_jack,
    rank_queen,
    rank_king,

    max_rank
  };

protected:
  Rank rank_{};
  Suit suit_{};

public:
  Card() = default;

  Card(Rank rank, Suit suit);

  Card(const std::string_view& str);

  bool operator==(const Card& card) const;

  void printCard() const;
  bool isBlank() const;
  int getCardValue() const;
  Suit getCardSuit() const; 
  Rank getCardRank() const;
};

#endif // CARD_H
