//
// Created by edinl on 13.03.2024.
//
#include "fighter.h"
#include "saiyan.h"

#ifndef GAME_H
#define GAME_H

class Game {
public:
    Game();
    std::vector<Fighter> fighters;
    std::vector<Attack> attacks;
    void addFighter();
    void startGame();
    void printListOfFighters();
    void printListOfAttacks();
    void startFight();
    int makeTurn(Fighter *turnMaker, Fighter *target);
    void printStats();
    int chooseFightMode();
    int chooseCharacter();
    Fighter* getCharacter(int choice); // get real Character for stats
    Fighter getFighter(int choice); //clone the character for fights
    void startPlayerVsPlayer();
    void startTeamVsTeam();
    void startPlayerVsComputer();
    int getRandomCharacter();
    int getRandomAction();
    int generateTurn(Fighter *turnMaker, Fighter *target);
};

#endif
