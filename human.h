//
// Created by edinl on 18.03.2024.
//
#include <iostream>
#include "attack.h"
#include <vector>
#include "fighter.h"

#ifndef HUMAN_H
#define HUMAN_H


class Human : public Fighter{
public:
    Human(std::string name,std::vector<Attack> attacks);
};


#endif
