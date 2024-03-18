//
// Created by edinl on 13.03.2024.
//

#include <string>

#ifndef ATTACK_H
#define ATTACK_H

class Attack {
public:
    Attack(std::string name, int damage, int kiCon);
    std::string name;
    int damage;
    int kiCon;
};

#endif
