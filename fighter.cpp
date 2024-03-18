//
// Created by edinl on 13.03.2024.
//
#include "fighter.h"

Fighter::Fighter(std::string name, std::vector<Attack> attacks, int maxKi) {
    this->name = name;
    this->currKi = maxKi;
    this->maxKi = maxKi;
    this->attacks = attacks;
    this->health = 100;
    this->wins = 0;
    this->losses = 0;

}

void Fighter::greet() {
    std::cout << "Hello, my name is " << this->name << std::endl;
}

void Fighter::powerUp() {
    if (currKi <= 90) {
        this->currKi += 20;
        std::cout << "Current Ki " << this->currKi << std::endl;
    } else {
        this->currKi = 100;
        std::cout << "You maxed your Ki" << std::endl;
    }
}

void Fighter::useAttack(Attack attack, Fighter *target) {
    std::cout << attack.name << std::endl;
    target->health -= attack.damage;
    std::cout << target->name << " has been damaged current HP " << target->health << std::endl;
    this->currKi -= attack.kiCon;
    std::cout << "Your current Ki amounts: " << this->currKi << std::endl;
}

void Fighter::reset(){
    this->health = 100;
    this->currKi = this->maxKi;
}
