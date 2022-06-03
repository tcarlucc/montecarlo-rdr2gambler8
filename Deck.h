#ifndef DECK_H
#define DECK_H

#include "Card.h";
#include <vector>
#include <ctime>
#include <random>
#include <algorithm>

using std::shuffle;

std::vector<char> faces{'j', 'q', 'k', 'a'};

class Deck {
    public:
        std::vector<Card> cards;

        Deck() {
            initializeDeck();
        };

        void initializeDeck() {
            for(int i = 2; i <= 10; i++) {
                cards.push_back(Card(Diamond, i, i));
                cards.push_back(Card(Heart, i, i));
                cards.push_back(Card(Spade, i, i));
                cards.push_back(Card(Club, i, i));
            }
            
            for(int i = 0; i < 4; i++) {
                cards.push_back(Card(Diamond, faces[i]));
                cards.push_back(Card(Heart, faces[i]));
                cards.push_back(Card(Spade, faces[i]));
                cards.push_back(Card(Club, faces[i]));
            }
        }

        /* Methods */

        void shuffle() {
            // TODO: Next on agenda
        }
};

#endif // DECK_H