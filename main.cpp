#include "Fighter.h"
#include "Player.h"

#include <iostream>

int main()
{
    Fighter fighter("Cornelious Maximus", 100, 8);

    std::cout << "Name: " << fighter.getName() << '\n'
              << "Damage: " << fighter.getDamage() << '\n'
              << "Health: " << fighter.getHealth() << '\n'
              << "Is Alive? " << fighter.isAlive() << '\n';
    
    fighter.takeDamage(10);
    std::cout << "Health: " << fighter.getHealth() << '\n'
              << "Is Alive? " << fighter.isAlive() << '\n';

    // ========================================================

    Player player("Maximus Decimus", 100, 10, 1, 25);
    std::cout << "\n== PLAYER ==\n";
    std::cout << "Name: " << player.getName() << '\n'
              << "Damage: " << player.getDamage() << '\n'
              << "Health: " << player.getHealth() << '\n'
              << "Is Alive? " << player.isAlive() << '\n'
              << "Amount of Potions: " << player.getPotions() << '\n'
              << "Amount of Coins: " << player.getCoins() << '\n';
    
    player.takeDamage(101);
    player.drinkPotion();
    player.drinkPotion();
    player.spendCoins(25);
    player.spendCoins(1);

    std::cout << "Health: " << player.getHealth() << '\n'
              << "Is Alive? " << player.isAlive() << '\n'
              << "Amount of Potions: " << player.getPotions() << '\n'
              << "Amount of Coins: " << player.getCoins() << '\n';

    return 0;
}