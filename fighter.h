//
// Created by edinl on 13.03.2024.
//
#include <vector>
#include <iostream>
#include "attack.h"

#ifndef FIGHTER_H
#define FIGHTER_H

class Fighter{
public:
    Fighter(std::string name,std::vector<Attack> attacks, int maxKi);
    std::string name;
    int currKi;
    int maxKi;
    int health;
    int wins;
    int losses;
    std::vector<Attack> attacks;
    void powerUp();
    void greet();
    void useAttack(Attack attack, Fighter *target);

};

#endif
