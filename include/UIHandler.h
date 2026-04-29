#ifndef UIHANDLER_H
#define UIHANDLER_H

#include "Player.h"
#include "Enemy.h"

#include <string>
#include <vector>

// Utility class for printing text and handling user input.
class UIHandler
{
public:
    // Output layer ---    
    static void printMessage(const std::string& message);
    static void printHeader(const std::string& header);
    static void clearScreen();

    static void displayStatus(const Player& player, const Enemy& enemy);
    static void displayAction(const std::string& attacker, const std::string& target, int damage);
    static void displayInventory(const Player& player);
    
    // Interaction layer ---
    static void pressEnterToContinue();
    static int getMenuChoice(const std::string& title, std::vector<std::string> options);
};

#endif