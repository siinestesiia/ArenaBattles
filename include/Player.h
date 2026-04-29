#ifndef PLAYER_H
#define PLAYER_H

#include "Fighter.h"

class Player : public Fighter
{
private:
    int m_level; // Player's experience level.
    int m_potions;
    int m_coins;

public:
    // Constructor ---
    Player(std::string name, int health, int damage, int potions, int coins)
        : Fighter(name, health, damage), m_level { 0 }, m_potions{ potions }, m_coins{ coins }
    {}
    
    // Methods ---
    bool drinkPotion();
    void addPotion(int amount); // Used by the Shop.
    bool spendCoins(int amount); // Used by the Shop.
    void addCoins(int amount);

    void addLevel();
    void resetHealth();

    // Getters ---
    int getLevel() const { return m_level; }
    int getPotions() const { return m_potions; }
    int getCoins() const { return m_coins; }
};

#endif