#ifndef SHOPMANAGER_H
#define SHOPMANAGER_H

#include "Player.h"

class ShopManager
{
private:
    static const int m_potionCost { 15 };

public:
    static void openShop(Player& player);
};

#endif