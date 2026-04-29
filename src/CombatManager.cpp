#include "UIHandler.h"
#include "CombatManager.h"
#include "Player.h"
#include "Enemy.h"

const std::vector<std::string> CombatManager::m_combatOptions {"Attack.", "Drink potion.", "Flee."};

CombatResult CombatManager::startFighting(Player& player, Enemy& enemy)
{
    UIHandler::printHeader("GET READY TO FIGHT");
    int choice{};

    
    while (player.isAlive() && enemy.isAlive())
    {
        // Print fighters is status
        UIHandler::displayStatus(player, enemy);
        
        choice = UIHandler::getMenuChoice("SELECT AN ACTION", m_combatOptions);

        switch (choice)
        {
            case 1: // Attack.
            {   int damage { player.getDamage() };
                enemy.takeDamage(damage);
                UIHandler::displayAction(player.getName(), enemy.getName(), damage);
                UIHandler::pressEnterToContinue();
                break;
            }
            case 2: // Drink Potion.
                if (!player.drinkPotion()) { continue; }
                break;
            case 3: // Flee from the fight.
                UIHandler::printMessage("You fled combat..");
                return CombatResult::Fled;
            default:
                break;
        }

        if (enemy.isAlive())
        {
            int damage {enemy.getDamage()};
            player.takeDamage(damage);
            UIHandler::displayAction(enemy.getName(), player.getName(), damage);
            UIHandler::pressEnterToContinue();
        }
    }

    // If out of the loop, check who is still standing
    return (player.isAlive()) ? CombatResult::Victory : CombatResult::Defeat;
}