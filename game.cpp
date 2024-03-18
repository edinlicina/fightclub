//
// Created by edinl on 13.03.2024.
//
#include "game.h"
#include "human.h"
#include "team.h"
#include <cstdlib>
#include <ctime>



Game::Game() {
    Attack kamehameha("Ka-Me-Ha-Me-Ha", 30, 50);
    Attack genkidama("Genkidama", 100, 70);
    Saiyan goku("Goku", {kamehameha, genkidama});
    Attack gallickGun("Gallick Gun", 30, 50);
    Attack finalFlash("Final Flash", 100, 60);
    Saiyan vegeta("Vegeta", {gallickGun, finalFlash});
    this->fighters = {goku, vegeta};
    this->attacks = {kamehameha, genkidama, gallickGun, finalFlash};
}

void Game::printListOfFighters() {
    for (int i = 0; i < this->fighters.size(); i++) {
        std::cout << "[" << i << "] " << this->fighters.at(i).name << std::endl;
    }
}

void Game::printListOfAttacks() {
    for (int i = 0; i < this->attacks.size(); i++) {
        std::cout << "[" << i << "] " << this->attacks.at(i).name << std::endl;
    }
}

void Game::addFighter() {
    int choice;


    std::string name;
    std::cout << "Enter your the Name of your Fighter: ";
    std::cin >> name;
    std::cout << "Your name is: " << name << std::endl;
    printListOfAttacks();
    std::cout << "Choose your Attacks: ";
    std::cin >> choice;
    Attack attack1 = this->attacks.at(choice);
    std::cout << "Good choice, choose another one: ";
    std::cin >> choice;
    Attack attack2 = this->attacks.at(choice);
    std::cout << "Choose your Race" << std::endl;
    std::cout << "[0] Human " << std::endl;
    std::cout << "[1] Saiyan" << std::endl;
    std::cin >> choice;
    if (choice == 0) {

        Human newFighter(name, {attack1, attack2});
        this->fighters.push_back(newFighter);
    } else {
        Saiyan newFighter(name, {attack1, attack2});
        this->fighters.push_back(newFighter);
    }
    std::cout << "You have created a fighter! " << std::endl;
}

int Game::chooseFightMode() {
    int choice;
    std::cout << "[0] Player vs. Player" << std::endl;
    std::cout << "[1] Player vs. Computer" << std::endl;
    std::cout << "[2] Team vs. Team" << std::endl;
    std::cin >> choice;
    return choice;
}

Fighter Game::getFighter(int choice) {
    return this->fighters.at(choice);
}

Fighter* Game::getCharacter(int choice) {
    return &this->fighters.at(choice);
}

int Game::chooseCharacter() {
    int choice;
    printListOfFighters();
    std::cin >> choice;
    return choice;
}

void Game::startPlayerVsPlayer() {
    int choice;
    std::cout << "Choose your Fighter " << std::endl;
    choice = chooseCharacter();
    Fighter fighter1 = getFighter(choice);
    Fighter* gameFighter1 = getCharacter(choice);

    std::cout << "Great Choice! Now choose an enemy" << std::endl;
    choice = chooseCharacter();
    Fighter fighter2 = getFighter(choice);
    Fighter* gameFighter2 = getCharacter(choice);

    while (true) {
        int returnValue;
        std::cout << "Its your turn" << std::endl;
        returnValue = makeTurn(&fighter1, &fighter2);
        if (returnValue == -1) {
            // target has no health anymore, we need to update the character's stats
            gameFighter1->wins++;
            gameFighter2->losses++;
            // And stop the fight
            return;
        }
        std::cout << "Now the enemy plays" << std::endl;
        returnValue = makeTurn(&fighter2, &fighter1);
        if (returnValue == -1) {
            // target has no health anymore, we need to update the character's stats
            gameFighter2->wins++;
            gameFighter1->losses++;
            // And stop the fight
            return;
        }
    }
}

void Game::startTeamVsTeam() {
    int choice;
    std::cout << "Team 1, choose your first fighter" << std::endl;
    choice = chooseCharacter();
    Fighter teamOneFirstFighter = getFighter(choice);
    std::cout << "Team 1, choose your second fighter" << std::endl;
    choice = chooseCharacter();
    Fighter teamOneSecondFighter = getFighter(choice);
    Team teamOne({&teamOneFirstFighter, &teamOneSecondFighter});
    std::cout << "Team 2, choose your first fighter" << std::endl;
    choice = chooseCharacter();
    Fighter teamTwoFirstFighter = getFighter(choice);
    std::cout << "Team 2, choose your second fighter" << std::endl;
    choice = chooseCharacter();
    Fighter teamTwoSecondFighter = getFighter(choice);
    Team teamTwo({&teamTwoFirstFighter, &teamTwoSecondFighter});
    Fighter* turnMaker;
    Fighter* target;
    while(true) {
        int returnValue;
        std::cout << "Team 1, it's your turn" << std::endl;
        turnMaker = teamOne.getFirstFighterAlive();
        target = teamTwo.getFirstFighterAlive();
        if (turnMaker == nullptr || target == nullptr) {
            // If a team has no fighters anymore, stop the fight
            return;
        }
        returnValue = makeTurn(turnMaker, target);
        if (returnValue == -1) {
            // target has no health anymore, we need to update the character's stats
            for(int i=0; i<this->fighters.size(); i++) {
                Fighter* fighter = &this->fighters.at(i);
                if (fighter->name == turnMaker->name) {
                    fighter->wins++;
                }
                if (fighter->name == target->name) {
                    fighter->losses++;
                }
            }
        }
        std::cout << "Team 2, it's your turn" << std::endl;
        turnMaker = teamTwo.getFirstFighterAlive();
        target = teamOne.getFirstFighterAlive();
        if (turnMaker == nullptr || target == nullptr) {
            // If a team has no fighters anymore, stop the fight
            return;
        }
        returnValue = makeTurn(turnMaker, target);
        if (returnValue == -1) {
            // target has no health anymore, we need to update the character's stats
            for(int i=0; i<this->fighters.size(); i++) {
                Fighter* fighter = &this->fighters.at(i);
                if (fighter->name == turnMaker->name) {
                    fighter->wins++;
                }
                if (fighter->name == target->name) {
                    fighter->losses++;
                }
            }
        }
    }
}

void Game::startPlayerVsComputer() {
    int choice;
    std::cout << "Choose your Fighter " << std::endl;
    choice = chooseCharacter();
    Fighter fighter1 = getFighter(choice);
    Fighter* gameFighter1 = getCharacter(choice);

    std::cout << "Great Choice! Now choose an enemy" << std::endl;
    choice = getRandomCharacter();
    Fighter fighter2 = getFighter(choice);
    Fighter* gameFighter2 = getCharacter(choice);
    fighter2.greet();

    while (true) {
        int returnValue;
        std::cout << "Its your turn" << std::endl;
        returnValue = makeTurn(&fighter1, &fighter2);
        if (returnValue == -1) {
            // target has no health anymore, we need to update the character's stats
            gameFighter1->wins++;
            gameFighter2->losses++;
            // And stop the fight
            return;
        }
        std::cout << "Now the enemy plays" << std::endl;
        returnValue = generateTurn(&fighter2, &fighter1);
        if (returnValue == -1) {
            // target has no health anymore, we need to update the character's stats
            gameFighter2->wins++;
            gameFighter1->losses++;
            // And stop the fight
            return;
        }
    }
}

int Game::generateTurn(Fighter *turnMaker, Fighter *target){
    int choice;
    choice = getRandomAction();
    if (choice == 0) {
        choice = getRandomAction();
        Attack attack = turnMaker->attacks.at(choice);
        turnMaker->useAttack(attack, target);
        if (target->health <= 0) {
            return -1;
        }
    } else {
        turnMaker->powerUp();
    }
    return 0;
}

int Game::getRandomCharacter(){
    srand(time(nullptr));
    int randomNumber = rand() % this->fighters.size() ;
    return randomNumber;
}
int Game::getRandomAction(){
    srand(time(nullptr));
    int randomNumber = rand() % 2 ;
    return randomNumber;
}

void Game::startFight() {
    int choice;
    choice = chooseFightMode();
    if (choice == 0) {
        // Player vs. Player
        startPlayerVsPlayer();
    } else if (choice == 1) {
        // Player vs. Computer
        startPlayerVsComputer();
    } else if (choice == 2) {
        // Team vs. Team
        startTeamVsTeam();
    }
}

void Game::startGame() {
    while (true) {
        std::cout << "Welcome to Fightclub Please choose your action in the Menu below" << std::endl;
        std::cout << "[0] Start Fighting! " << std::endl;
        std::cout << "[1] Create Fighter " << std::endl;
        std::cout << "[2] End Game " << std::endl;
        std::cout << "[3] Show all Fighters " << std::endl;
        std::cout << "[4] Show Stats " << std::endl;
        int choice;
        std::cin >> choice;
        if (choice == 0) {  //this could also be a switch case <3
            startFight();
        } else if (choice == 1) {
            addFighter();
        } else if (choice == 2) {
            return;
        } else if (choice == 3) {
            printListOfFighters();
        } else if (choice == 4) {
            printStats();
        }
    }
}

int Game::makeTurn(Fighter *turnMaker, Fighter *target) {
    int choice;
    std::cout << "[0] Choose Attack" << std::endl;
    std::cout << "[1] Power up" << std::endl;
    std::cin >> choice;
    if (choice == 0) {
        std::cout << "Choose your Attack!" << std::endl;
        for (int i = 0; i < turnMaker->attacks.size(); i++) {
            std::cout << "[" << i << "] " << turnMaker->attacks.at(i).name << std::endl;
        }
        std::cin >> choice;
        Attack attack = turnMaker->attacks.at(choice);
        turnMaker->useAttack(attack, target);
        if (target->health <= 0) {
            return -1;
        }
    } else {
        turnMaker->powerUp();
    }
    return 0;
}


void Game::printStats() {
    for (Fighter &fighter: fighters) {
        std::cout << fighter.name << ": " << fighter.wins << " W(s), " << fighter.losses << " L(s)" << std::endl;
    }
}
