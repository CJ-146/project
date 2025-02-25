#include "arme.h"
#include <iostream>

using namespace std;

Arme::Arme() {
    nom = "";
    atk = 0;
    def = 0;
}

Arme::Arme(string Name, int Attack,int Defence) {
    nom = Name;
    atk = Attack;
    def = Defence;
}

void Arme::setNom(string Name){
    nom = Name;
}

string Arme::getNom(){
    return nom;
}

void Arme::setDef(int Defence) {
    def = Defence;
    if (Defence<-5){
        def = -5;
    }
}

int Arme::getDef(){
    return def;
}

void Arme::setAtk(int Attack) {
    atk = Attack;
    if (Attack<1){
        atk = 1;
    }
}

int Arme::getAtk(){
    return atk;
}

void Arme::initArme(){
    cout<<"Veuillez entrer le nom"<<endl;
    cin>>nom;
    cout<<"Veuillez entrer l'attaque"<<endl;
    cin>>def;
    cout<<"Veuillez entrer la defence bonus"<<endl;
    cin>>atk;
}

int Arme::UtiliserArme(){
    return rand() % getAtk();
}

ostream &operator<<(ostream & flux,Arme Test){
    flux<<"Le nom de l'arme est "<<Test.getNom()<<endl;
    flux<<"L'attaque de l'arme est "<<Test.getAtk()<<endl;
    flux<<"La defence de l'arme est "<<Test.getDef()<<endl;
    return flux;
}
