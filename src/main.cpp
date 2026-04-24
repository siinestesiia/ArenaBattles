#include "GameState.h"
#include "UIHandler.h"
#include "NameGenerator.h"
#include "Fighter.h"
#include "Player.h"
#include "Enemy.h"
#include "CombatManager.h"

#include <iostream>

int main()
{
    // For testing purposes...
    Player player("Player", 100, 20, 1, 0);
    Enemy enemy(100, 15);
    CombatManager::startFighting(player, enemy);

    // =====================================================================================================
    
    // GameState currentState { GameState::MainMenu };
    // bool isRunning { true };

    // while (isRunning)
    // {
    //     switch (currentState)
    //     {
    //         case GameState::MainMenu:
    //             // Welcome message, some guidance about how to play.
    //             // Ask player --> Start Playing or Quit Game.
    //             // Go to The Hub
    //             break;

    //         case GameState::Hub:
    //             // Let the player choose where to go:
    //             // Enter Arena and fight; Enter Shop and buy potions; talk to passersby; Exit game and save inventory.
    //             break;

    //         case GameState::Combat:
    //             // Fight enemy; Win or lose;
    //             // Go back to The Hub, or Exit Game
    //             break;

    //         case GameState::Shop:
    //             // Buy potions.
    //             // Go back to The Hub.
    //             break;

    //         case GameState::Win:
    //             // Beat the enemy; fight the next one or go back to The Hub.
    //             break;
            
    //         case GameState::GameOver:
    //             // Lose against the Enemy, you have another chance to fight with 50% health or lose game (permadeath).
    //             break;

    //         case GameState::Exit:
    //             // Exit the game and save inventory.
    //             isRunning = false;
    //             break;
    //     }
    // }

    return 0;
}