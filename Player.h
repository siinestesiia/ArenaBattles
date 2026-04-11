#ifndef PLAYER_H
#define PLAYER_H

#include "Fighter.h"

class Player : public Fighter
{
private:
    int m_potions;
    int m_coins;

public:
    // Constructor ---
    Player(std::string name, int health, int damage, int potions, int coins)
        : Fighter(name, health, damage), m_potions{ potions }, m_coins{ coins }
    {}
    
    // Methods ---
    void drinkPotion();
    void spendCoins(int amount); // Used by the Shop.

    // Getters ---
    int getPotions() const { return m_potions; }
    int getCoins() const { return m_coins; }
};

#endif