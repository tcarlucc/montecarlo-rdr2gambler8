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
#include <iostream>
#include <string>
#include <cctype>

enum suit {
            Diamond,
            Heart,
            Spade,
            Club
        };

class Card {
    private:
        suit cardSuit;
        char cardValue;
        int trueValue;

        int calcTrueValue(char value) {
            if(isdigit(value)) {
                return value;
            } else if(value == 't' || value == 'j' || value == 'q' || value == 'k') {
                return 10;
            } else { 
                return 11; // Ace
            }
        }

    public:
        Card() {
        }

        Card(suit cardSuit, char cardValue) {
            this->cardSuit = cardSuit;
            this->cardValue = cardValue;
            this->trueValue = calcTrueValue(cardValue);
        }

        Card(suit cardSuit, char cardValue, int trueValue) {
            this->cardSuit = cardSuit;
            this->cardValue = cardValue;
            this->trueValue = trueValue;
        }

        /* Getters */

        suit getSuit() {
            return cardSuit;
        }

        char getSuitAsChar() {
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

        void setValue(int cardValue) {
            this->cardValue = cardValue;
        }

        void setTrueValue(int trueValue) {
            this->trueValue = trueValue;
        }

        friend std::ostream &operator<<(std::ostream &os, const Card& card) {
            os << card.trueValue;
            os << " of ";

            if(card.cardSuit == Diamond) {
                os << "???";
            } else if(card.cardSuit == Heart) {
                os << "???";
            } else if(card.cardSuit == Spade) {
                os << "???";
            } else {
                os << "???";
            }

            return os;
        }

};

#endif // CARD_H