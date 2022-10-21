#include <iostream>
using namespace std;

class Fighter{
private:
    std::string name;
    int health;
    int damagePerAttack;

public:
    Fighter(std::string name,int health,int damagePerAttack){
        this->name = name;
        this->health = health;
        this->damagePerAttack = damagePerAttack;
    }

    std::string getName(){
        return name;
    }

    int getHealth(){
        return health;
    }
    int getDamage(){
        return damagePerAttack;
    }

    void setHealth(int value){
        health = value;
    }

};
std::string declareWinner(Fighter* fighter1,Fighter* fighter2,std::string firstAttack){

    Fighter* first;
    Fighter* second;

    if(first->getName() == firstAttack){
        first = fighter1;
        second = fighter2;
    }
    else if(second->getName() == firstAttack){
        second = fighter1;
        first = fighter2;
    }

    while(true){
        second->setHealth(second->getHealth() - first->getDamage());
        if(second->getHealth() <= 0) return first->getName();

        first->setHealth(first->getHealth() - second->getDamage());
        if(first->getHealth() <= 0) return second->getName();
    }
}
int main() {

   Fighter* fighter = new Fighter("Ali",100,14);
   Fighter* fighter2 = new Fighter("Vali",100,15);
   string first = "Vali";

   cout << declareWinner(fighter,fighter2,first);
}
