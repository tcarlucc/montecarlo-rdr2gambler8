#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>
#include <ctime>
#include <random>
#include <algorithm>

using std::shuffle;

// 10 wont fit in char
std::vector<char> faces{'t', 'j', 'q', 'k', 'a'};

class Deck {
    public:
        std::vector<Card> cards;
        std::vector<Card> cardsInPlay;

        Deck() {
            initializeDeck();
        };

        void initializeDeck() {
            for(int i = 2; i < 10; i++) {
                cards.push_back(Card(Diamond, i, i));
                cards.push_back(Card(Heart, i, i));
                cards.push_back(Card(Spade, i, i));
                cards.push_back(Card(Club, i, i));
            }
            
            for(int i = 0; i < 5; i++) {
                cards.push_back(Card(Diamond, faces[i]));
                cards.push_back(Card(Heart, faces[i]));
                cards.push_back(Card(Spade, faces[i]));
                cards.push_back(Card(Club, faces[i]));
            }
        }

        /* Methods */

        void shuffleDeck() {
            std::random_device rand;
            std::default_random_engine rng(rand());
            shuffle(std::begin(cards), std::end(cards), rng);
        }

        Card draw() {
            cardsInPlay.push_back(cards.back());
            cards.pop_back();

            return cardsInPlay.back();
        }

        void gatherCards() {
            for(int i = 0; i < cardsInPlay.size(); ++i) {
                cards.push_back(cardsInPlay.back());
                cardsInPlay.pop_back();
            }
        }
};

#endif // DECK_H