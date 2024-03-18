//
// Created by edinl on 18.03.2024.
//

#include "team.h"

Team::Team(Fighter *firstFighter, Fighter *secondFighter) {
    this->firstFighter = firstFighter;
    this->secondFighter = secondFighter;
}

Fighter *Team::getFirstFighterAlive() {
    if (this->firstFighter->health > 0) {
        return this->firstFighter;
    }
    if (this->secondFighter->health > 0) {
        return this->secondFighter;
    }
    return nullptr;
}

void Team::increaseWin(Fighter *fighter) {
    fighter->wins++;
}

void Team::increaseLosses(Fighter *fighter) {
    fighter->losses++;
}
