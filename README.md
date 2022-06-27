# montecarlo-rdr2gambler8
Monte Carlo simulation of one of the worst video game challenges ever made

![Blackjack table in Game](https://external-content.duckduckgo.com/iu/?u=https%3A%2F%2Fwww.gtabase.com%2Fimages%2Fred-dead-redemption-2%2Factivities%2Frdr2-blackjack.jpg&f=1&nofb=1) *Blackjack table in game. Source: gtabase.com*


# About
Red Dead Redmption 2 is a western adventure video game developed by Rockstar Games that takes place very early on in the 20th century. A requirement for 100% completion of the game are chains of challenges that must be completed in order. One chain of these challenges are the "Gambler" challenges. The 8th challenge in the Gambler chain is notoriously hated for being one of the most lucrative and luck-based challenges in the game. The challenge requires the player to win a hand of blackjack with three hits or more, three seperate times. Pushes (ties with the dealer) do not count as wins. Most players have reported hundreds of hands of blackjack being played before completing the challenge, and I sought out to find the actual odds and best strategy for doing so with this program.

# What is Monte Carlo?
A Monte Carlo Simulation is defined by IBM as a mathematical technique used to estimate the possible outcomes of an uncertain event. Put simply, it is to run a simulation thousands of times to analyze trends in the data that is yielded from the simulations. This is helpful in the case of this program because I am trying to nail down an average number of hands needed to play, as well as seeing if factors such as extra NPCs at the table have an effect on the outcome.

*Source: https://www.ibm.com/cloud/learn/monte-carlo-simulation*

# The Logic
For the player, the only viable outcome is that they hit three times, and the dealer busts or stands at a lower value than the player. For this reason, the player will only choose to hit until they bust or reach three hits. The dealer will hit until they bust or reach a number greater than or equal to 17, where they will stand.

# Findings
TBD :)