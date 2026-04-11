#ifndef FIGHTER_H
#define FIGHTER_H

#include <string>

class Fighter
{
protected:
    std::string m_name;
    int m_health;
    int m_damage;

public:
    // Constructor ---
    Fighter(const std::string& name, int health, int damage)
        : m_name{ name }, m_health{ health }, m_damage{ damage }
    {}

    // Methods ---
    void takeDamage(int damage);
    bool isAlive() const;

    // Getters ---
    std::string getName() const { return m_name; }
    int getHealth() const { return m_health; }
    int getDamage() const { return m_damage; }
};

#endif