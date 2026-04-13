#include "NameGenerator.h"
#include "Fighter.h"
#include "Player.h"
#include "Enemy.h"

#include <iostream>

int main()
{
    // For testing purposes...
    Enemy enemy(100, 20);
    std::cout << "Name: " << enemy.getName() << '\n' // It should be random generated.
              << "Health: " << enemy.getHealth() << '\n'
              << "Damage: " << enemy.getDamage() << '\n';

    return 0;
}