#include "Fighter.h"
#include "Player.h"
#include "UIHandler.h"

#include <iostream>
#include <algorithm>

bool Player::drinkPotion()
{
    if (!isAlive()) { return false; } // Can't heal if dead...
    
    if (m_potions <= 0)
    {
        UIHandler::printMessage("You don't have any potions left... Buy them at the Shop!");
        m_potions = 0; // The amount of potions can't be below zero.
        return false;
    }

    if (m_health == m_maxHealth)
    {
        UIHandler::printMessage("You're already at full health...");
        return false;
    }

    m_potions -= 1;
    const int potionHeal { 25 }; // Potions restore 25 hp.
    // Keep health between 0 and maxHealth.
    m_health = std::clamp(m_health + potionHeal, 0, m_maxHealth);
    UIHandler::printMessage("# Health increased by " + std::to_string(potionHeal) + " points...");
    
    return true;
}

bool Player::spendCoins(int amount)
{
    if (m_coins < amount)
    {
        UIHandler::printMessage("Not enough coins... Earn them by defeating enemies!");
        return false;
    }

    m_coins -= amount;
    return true;
}

void Player::addPotion(int amount)
{
    m_potions += amount;
}

void Player::addCoins(int amount)
{
    m_coins += amount;
}

void Player::addLevel()
{
    m_level += 1;
}

void Player::resetHealth()
{
    m_health = m_maxHealth;
}