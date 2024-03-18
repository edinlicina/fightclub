//
// Created by edinl on 18.03.2024.
//
#include "fighter.h"

#ifndef TEAM_H
#define TEAM_H


class Team {
public:
    Team(Fighter* firstFighter, Fighter* secondFighter);
    Fighter* firstFighter;
    Fighter* secondFighter;
    Fighter* getFirstFighterAlive();

};

#endif
