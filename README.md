# ArenaBattles 🛡️⚔️

A modular, turn-based terminal RPG built in C++. This project was designed to master the core concepts of Object-Oriented Programming (OOP) and Software Architecture before transitioning into graphical game development.

## 🚀 Features
- **Dynamic Combat System:** Turn-based logic with validation for actions, healing, and fleeing.
- **State Machine Architecture:** Uses a robust `GameState` controller to manage transitions between the Main Menu, Town Hub, Combat Arena, and Shop.
- **Scaling Difficulty:** Enemies procedurally scale their health and damage based on the player's level.
- **Modular Design:** Clear separation of concerns between game logic (Managers), entity data (Fighter/Player/Enemy), and the user interface (UIHandler).

## 🛠️ Technical Deep-Dive
- **Inheritance & Polymorphism:** Utilizes a base `Fighter` class with specialized `Player` and `Enemy` overrides.
- **Memory Management:** Leverages pass-by-reference to ensure persistent state updates across different manager classes.
- **Modern C++ Standards:** Implements `C++17` features, including braced initialization, `std::clamp` for health management, and `static` utility classes.

## 📂 Project Structure
- `CombatManager`: Handles the "grudge match" loop and turn-order logic.
- `ShopManager`: Manages the game economy and inventory transactions.
- `UIHandler`: A centralized interface wrapper to decouple logic from `std::cout`.
- `NameGenerator`: (Add details if you used specific logic here!).


## 🏁 How to build (Linux)
To compile the project manually, run the following command from the root directory:
```bash
g++ -std=c++17 src/*.cpp -Iinclude -o ArenaBattles
```