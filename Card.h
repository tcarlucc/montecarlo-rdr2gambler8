/**
 * @file Card.h
 * @author Thomas Carlucci (thomascarlucci@me.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef CARD_H
#define CARD_H

#include <vector>
#include <string>

enum suit {
            Diamond = 'd',
            Heart = 'h',
            Spade = 's',
            Club = 'c'
        };

class Card {
    private:
        suit cardSuit;
        char cardValue;
        int trueValue;

        int calcTrueValue(char value) {
            
        }

    public:
        Card() {
        }

        Card(suit cardSuit, char cardValue, int trueValue) {
            this->cardSuit = cardSuit;
            this->cardValue = cardValue;
            this->trueValue = trueValue;
        }

        /* Getters */
        char getSuit() {
            switch (cardSuit)  {
                case Diamond:
                    return 'd';
                case Heart:
                    return 'h';
                case Spade:
                    return 's';
                case Club:
                    return 'c';
                default:
                    return 'x'; // Shouldn't happen
            }
        }

        char getCardValue() {
            return cardValue;
        }

        int getTrueValue() {
            return trueValue;
        }

        /* Setters */
        void setSuit(suit cardSuit) {
            this->cardSuit = cardSuit;
        }

        int returnTrueValue(Card card) {

        }
};

#endif // CARD_H