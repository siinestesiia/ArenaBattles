#include "GameState.h"
#include "UIHandler.h"
#include "NameGenerator.h"
#include "Fighter.h"
#include "Player.h"
#include "Enemy.h"
#include "CombatManager.h"
#include "ShopManager.h"

#include <iostream>

int main()
{    
    GameState currentState { GameState::MainMenu };
    bool isRunning { true };
    
    Player player("Player", 100, 10, 2, 0);

    while (isRunning)
    {
        switch (currentState)
        {
            case GameState::MainMenu:
                UIHandler::printHeader("ARENA BATTLES");

                if (UIHandler::getMenuChoice("Main Menu", {"Start Game", "Quit Game"}) == 1)
                {
                    // Go to The Hub
                    currentState = GameState::Hub;
                }
                else { currentState = GameState::Exit; }
                break;

            case GameState::Hub:
            {   
                UIHandler::clearScreen();
                UIHandler::printHeader("THE TOWN HUB");
                UIHandler::displayInventory(player);

                int choice = UIHandler::getMenuChoice("What would you like to do?", {"Enter Arena", "Go the Shop", "Quit Game"});

                if (choice == 1) currentState = GameState::Combat;
                else if (choice == 2) currentState = GameState::Shop;
                else currentState = GameState::Exit;
                break;
            }

            case GameState::Combat:
            {   
                // Enemy progression logic ---
                int scaleHP = 50 + (player.getLevel() * 15);
                int scaleDMG = 5 + (player.getLevel() * 3);
                Enemy enemy(scaleHP, scaleDMG);
                // Fight enemy ---
                CombatResult result = CombatManager::startFighting(player, enemy);

                if (result == CombatResult::Victory)
                {
                    int coinReward { 25 };
                    player.addCoins(coinReward);
                    UIHandler::printMessage("Victory! You earned " + std::to_string(coinReward) + " coins.");
                    UIHandler::pressEnterToContinue();
                    currentState = GameState::Win;
                }
                // Go back to The Hub, or last change.
                else if (result == CombatResult::Defeat) currentState = GameState::GameOver;
                else currentState = GameState::Hub; // Player fled.
                break;
            }

            case GameState::Shop:
                // Buy potions and/or go back to the Hub.
                ShopManager::openShop(player);
                currentState = GameState::Hub;
                break;

            case GameState::Win:
            {   
                player.addLevel();
                // fight the next one or go back to The Hub.
                int choice = UIHandler::getMenuChoice("What would you like to do?", {"Fight the next enemy.", "Go back to the Town Hub.", "Quit Game."});

                if (choice == 1) currentState = GameState::Combat;
                else if (choice == 2) currentState = GameState::Hub;
                else currentState = GameState::Exit;
                break;
            }
            
            case GameState::GameOver:
                UIHandler::printMessage("The enemy has beaten you...");
                if (UIHandler::getMenuChoice("Last chance. What would you do?", {"Keep fighting", "Surrender."}) == 1)
                {
                    UIHandler::printMessage("That's the spirit!!");
                    player.resetHealth(); // Reset health.
                    currentState = GameState::Hub; // Restart the game at the Hub.
                }
                else 
                {
                    UIHandler::printMessage("Game Over...");
                    player.resetHealth(); // Reset health.
                    currentState = GameState::MainMenu; // Go back to main menu.
                }
                break;

            case GameState::Exit:
                // Exit the game.
                UIHandler::printMessage("Quitting game...");
                isRunning = false;
                break;
        }
    }

    return 0;
}