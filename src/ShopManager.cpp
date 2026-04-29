#include "ShopManager.h"
#include "UIHandler.h"

#include <string>

void ShopManager::openShop(Player& player)
{
    std::vector<std::string> options
    {
        "Buy Potion (" + std::to_string(m_potionCost) + " coins).",
        "Back to the Hub."
    };

    bool shopping { true };
    
    while(shopping)
    {
        UIHandler::clearScreen();
        UIHandler::printHeader("THE SHOP");
        UIHandler::displayInventory(player);
        int choice = UIHandler::getMenuChoice("SELECT AN ACTION", options);

        if (choice == 1)
        {
            if (player.spendCoins(m_potionCost))
            {
                player.addPotion(1);
                UIHandler::printMessage("You bought 1 Potion!");
            }
            UIHandler::pressEnterToContinue();
        }
        else
        {
            // Exit to the Hub
            UIHandler::printMessage("Going back to the Hub...");
            shopping = false;
        }
    }
}