#include "Fighter.h"
#include "Player.h"

#include <iostream>

void Player::drinkPotion()
{
    if (m_potions <= 0)
    {
        std::cout << "You don't have any potions left... Buy them at the Shop!" << '\n';
        m_potions = 0; // The amount of potions can't be below zero.
        return;
    }

    m_potions -= 1;

    // Heal process here ---
    // Check if healing is actually needed.
    // Heal to max Health or 25 points or something like that.
}

void Player::spendCoins(int amount)
{
    if (m_coins < amount)
    {
        std::cout << "Not enough coins... Earn coins by defeating enemies!" << '\n';
        if (m_coins <= 0) { m_coins = 0; return; }
    }

    m_coins -= amount;
}