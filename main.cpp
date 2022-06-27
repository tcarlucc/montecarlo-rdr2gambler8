/**
 * @file main.cpp
 * @author Thomas Carlucci (thomascarlucci@me.com)
 * @brief Monte Carlo simulation on the odds for winning a blackjack hand with 3 hits
 * @version 0.1
 * @date 2022-06-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "Deck.h"

std::vector<Card> dealerCards;
std::vector<Card> playerCards;
std::vector<Card> player2Cards;
std::vector<Card> player3Cards;
std::vector<Card> player4Cards;

/**
 * @brief Simulates a game of blackjack with a given number of players
 * 
 * @param numPlayers integer value from 1-4, including the player
 * @return int: 0 on loss/bust/push, 1 on 3 hit win
 */
int simulateHand(int numPlayers, Deck& deck);

int simulateHand(Deck& deck);

int main() {
    int result = 0;
    int total = 0;
    int simulate = 150;
    double ratio = 0.0;   

    for(int i = 0; i < simulate; ++i) { 
        Deck deck; // Initializes Deck    
        deck.shuffleDeck(); // Dealer shuffles once in game, R* attention to detail is pretty spot on so I'm keeping it at 1
        result = simulateHand(1, deck);
        total += result;
        deck.gatherCards();
    }

    ratio = total / simulate;
    std::cout << "Ratio: " << ratio << std::endl;

    return 0;
}

int simulateHand(int numPlayers, Deck& deck) {
    int result = 0; 
    
    if(numPlayers == 1) {
        int dealerSum, playerSum;
        bool dealerBust = false;

        std::unique_ptr<Card> drawnCard = nullptr;

        drawnCard = std::make_unique<Card>(deck.draw());
        dealerCards.emplace_back(*drawnCard); // Hidden

        drawnCard = std::make_unique<Card>(deck.draw());
        playerCards.emplace_back(*drawnCard);

        drawnCard = std::make_unique<Card>(deck.draw());
        dealerCards.emplace_back(*drawnCard); // Shown

        drawnCard = std::make_unique<Card>(deck.draw());
        playerCards.emplace_back(*drawnCard);

        dealerSum = dealerCards[0].getTrueValue() + dealerCards[1].getTrueValue();
        playerSum = playerCards[0].getTrueValue() + playerCards[1].getTrueValue();

        if(playerSum == 21 || dealerSum == 21) { // Check for blackjack off the bat
            result = 0; 
        } 
        else { // Hit 1
                drawnCard = std::make_unique<Card>(deck.draw());
                playerCards.emplace_back(*drawnCard);

                playerSum += playerCards[2].getTrueValue();
                if(playerSum >= 21) { 
                    result = 0; 
                } else { // Hit 2
                    drawnCard = std::make_unique<Card>(deck.draw());
                    playerCards.emplace_back(*drawnCard);
                    
                    playerSum += playerCards[3].getTrueValue();
                    if(playerSum >= 21) { 
                        result = 0; 
                    } else { // Hit 3
                        drawnCard = std::make_unique<Card>(deck.draw());
                        playerCards.emplace_back(*drawnCard);

                        playerSum += playerCards[4].getTrueValue();
                        if(playerSum >= 22) {
                            result = 0;
                        } else {
                            while(!dealerBust || dealerSum >= 17) { // Dealer will always stand on 17+
                                int i = 2;
                                drawnCard = std::make_unique<Card>(deck.draw());
                                dealerCards.emplace_back(*drawnCard);

                                dealerSum += dealerCards[i].getTrueValue();
                                i++;
                            }
                            if(dealerBust || dealerSum < playerSum) {
                                result = 1;
                            } else {
                                result = 0;
                            }
                        }
                    }
                }
        }

        // Debug
        std::cout << dealerSum << std::endl;
        std::cout << playerSum << std::endl;
    }

    // Clear all hands
    dealerCards.clear();
    playerCards.clear();

    return result;
}

int simulateHand(Deck& deck) {
    return simulateHand(1, deck);
}