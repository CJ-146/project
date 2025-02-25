#include <iostream> // utilisation de cout et cin
#include "perso.h"
#include "protection.h"
#include "arme.h"

using namespace std;

// Méthodes
Perso::Perso() {
    armePerso = Arme();
    protectionPerso = Protection();
    defPerso = 0;
    atkPerso = 0;
}

Perso::Perso(Arme Weapon, Protection Prot, int Defence, int Attack) {
    defPerso = Defence;
    atkPerso = Attack;
    armePerso = Weapon;
    protectionPerso = Prot;
}

void Perso::setDef(int Defence){
    defPerso = Defence;
}

int Perso::getDef(){
    return defPerso;
}

void Perso::setAtk(int Attack){
    atkPerso = Attack;
}

int Perso::getAtk(){
    return atkPerso;
}

void Perso::setArme(Arme Weapon){
    armePerso = Weapon;
}

Arme Perso::getArme(){
    return armePerso;
}

void Perso::setProtection(Protection Defence){
    protectionPerso = Defence;
}

Protection Perso::getProtection(){
    return protectionPerso;
}

int Perso::getDefTot(){
    int total = defPerso + armePerso.getDef() + protectionPerso.getDef();
    return total;
}

int Perso::getAtkTot(){
    int total = atkPerso + armePerso.getAtk() + protectionPerso.getAtk();
    return total;
}

ostream &operator<<(ostream & flux,Perso &Test){
    flux<<Test.getArme()<<endl;
    flux<<Test.getProtection()<<endl;
    return flux;
}
