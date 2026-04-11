#include "Fighter.h"

void Fighter::takeDamage(int damage)
{
    m_health -= damage;
    if (m_health < 0) { m_health = 0; }
}

bool Fighter::isAlive() const
{
    return m_health > 0;
}