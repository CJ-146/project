#include "protection.h"
#include <iostream>

using namespace std;

Protection::Protection() {
    nom = "";
    def = 0;
    atk = 0;
    dura = 0;
}

Protection::Protection(string Name,int Power, int Attack, int Durabilite) {
    nom = Name;
    def = Power;
    atk = Attack;
    dura = Durabilite;
}

void Protection::setNom(string Name){
    nom = Name;
}

string Protection::getNom(){
    return nom;
}

void Protection::setDef(int Power) {
    def = Power;
    if (Power<0 || getDura()<=0){
        def = 0;
    }
}

int Protection::getDef(){
    return def;
}

void Protection::setAtk(int Attack) {
    atk = Attack;
    if (Attack>0){
        atk = 0;
    }
}

int Protection::getAtk(){
    return atk;
}

int Protection::getDura(){
    return dura;
}

void Protection::setDura(int Durabilite){
    dura = Durabilite;
    if(Durabilite<0){
        dura = 0;
    }
}

int Protection::protectionAppliquee(){
    dura--;
    return dura;
}

ostream &operator<<(ostream & flux,Protection Test){
    flux<<"Le nom de la protection est "<<Test.getNom()<<endl;
    flux<<"La puissance de la protection est "<<Test.getDef()<<endl;
    flux<<"L'attaque de la protection est "<<Test.getAtk()<<endl;
    flux<<"La durabilite de la protection est "<<Test.getDura()<<endl;
    return flux;
}
