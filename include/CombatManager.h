#ifndef COMBATMANAGER_H
#define COMBATMANAGER_H

#include <vector>
#include "Player.h"
#include "Enemy.h"

// Defining the outcome of the fight.
enum class CombatResult { Victory, Defeat, Fled };

class CombatManager
{
private:
    static const std::vector<std::string> m_combatOptions;

public:
    static CombatResult startFighting(Player& player, Enemy& enemy);
};

#endif