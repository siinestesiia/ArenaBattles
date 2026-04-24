#include "Fighter.h"
#include "Player.h"

#include <iostream>
#include <algorithm>

bool Player::drinkPotion()
{
    if (!isAlive()) { return false; } // Can't heal if dead...
    
    if (m_potions <= 0)
    {
        std::cout << "\nYou don't have any potions left... Buy them at the Shop!" << '\n';
        m_potions = 0; // The amount of potions can't be below zero.
        return false;
    }

    if (m_health == m_maxHealth)
    {
        std::cout << "\nYou're already at full health..." << '\n';
        return false;
    }

    m_potions -= 1;
    const int potionHeal { 25 }; // Potions restore 25 hp.
    // Keep health between 0 and maxHealth.
    m_health = std::clamp(m_health + potionHeal, 0, m_maxHealth);
    std::cout << "\n# Health increased by " << potionHeal << " points...\n";
    
    return true;
}

void Player::spendCoins(int amount)
{
    if (m_coins < amount)
    {
        std::cout << "Not enough coins... Earn coins by defeating enemies!" << '\n';
        return;
    }
    m_coins -= amount;
}