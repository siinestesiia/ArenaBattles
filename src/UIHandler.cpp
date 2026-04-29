#include "UIHandler.h"
#include "Player.h"
#include "Enemy.h"

#include <iostream>
#include <string>
#include <limits>

// Output Layer ---
void UIHandler::printMessage(const std::string& message)
{
    std::cout << '\n' << message << '\n';
}

void UIHandler::printHeader(const std::string& header)
{
    std::cout << "\t=== " << header << " ===" << '\n';
}

void UIHandler::clearScreen()
{
    std::cout << "\n\n";
}

// Interaction Layer ---
void UIHandler::pressEnterToContinue()
{   
    std::cout << "\n[Press Enter to continue...]";
    // If there's an Enter sitting there, eat it, then wait for the next one. 
    std::cin.sync(); 
    std::cin.get();
}

int UIHandler::getMenuChoice(const std::string& title, std::vector<std::string> options)
{
    int choice{ 0 };

    while (true) // Keep asking until getting a valid input.
    {
        UIHandler::printHeader(title);
        for (size_t i = 0; i < options.size(); i++)
        {
            // i + 1 so the user sees numbered options correctly.
            std::cout << (i + 1) << ". " << options[i] << '\n';
        }

        std::cout << "\nSelection: ";
        if (std::cin >> choice) // Did they type a number?
        {
            if (choice >= 1 && choice <= static_cast<int>(options.size()))
            {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return choice;
            }
        }

        // If the code gets here, the input is invalid..
        std::cout << "Invalid selection. Please try again..\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clean the bad input.
    }
}

void UIHandler::displayStatus(const Player& player, const Enemy& enemy)
{
    std::cout << "\n-- " << player.getName() << " ----\n"
              << "\tHP: " << player.getHealth() << " points." << '\n'
              << "\tDamage: " << player.getDamage() << " points." << '\n'
              << "\tLevel: " << player.getLevel() << "." << '\n'
              << "\tPotions: " << player.getPotions() << '.' << '\n'
              << "\tCoins: " << player.getCoins() << '.' << '\n'

              << "-- " << enemy.getName() << " ----\n"
              << "\tHP: " << enemy.getHealth() << '.' << '\n'
              << "\tDamage: " << enemy.getDamage() << " points." << "\n\n";
}

void UIHandler::displayAction(const std::string& attacker, const std::string& target, int damage)
{
    std::cout << "\n>> " << attacker << " attacks " << target << " dealing " << damage << " damage points.\n";
}

void UIHandler::displayInventory(const Player& player)
{
    std::cout << "-- " << player.getName() << "'s Inventory ----\n"
              << "- Potions: " << player.getPotions() << ".\n"
              << "- Coins: " << player.getCoins() << ".\n";
}