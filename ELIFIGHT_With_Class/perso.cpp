#include <iostream> // utilisation de cout et cin
#include "perso.h"
#include "protection.h"
#include "arme.h"
#include "objet.h"

using namespace std;

Protection Cuirasse("Cuirasse",80);
Protection Plastron("Plastron",90);
Protection Bouclier("Bouclier",100);
Protection Tab_protections[3] = {Cuirasse, Plastron, Bouclier}; // tableau pour accéder plus facilement aux protections

Arme Dague("Dague",25);
Arme Arc("Arc",40);
Arme Lance("Lance",50);
Arme Epee("Epee",80);
Arme Cimeterre("Cimeterre",115);
Arme Tab_armes[5] = {Dague, Arc, Lance, Epee, Cimeterre}; // tableau pour accéder plus facilement aux armes



Perso::Perso() {
    name = "";
    PV = 100;  // Les PV de base pour ne pas permetter à l'utilisateur de les changer
    Main_Droite = Arme();
    Main_Gauche = Protection();
}

Perso::Perso(string nom_perso, int HP, Arme Right_Hand, Protection Left_Hand) {
    name = nom_perso;
    PV = HP;
    Main_Droite = Right_Hand;
    Main_Gauche = Left_Hand;
}

void Perso::setName(string nom_perso){
    name = nom_perso;
}

string Perso::getName(){
    return name;
}

void Perso::setPV(int HP){
    PV = HP;
}

int Perso::getPV(){
    return PV;
}

void Perso::setArme(Arme Right_Hand){
    Main_Droite = Right_Hand;
}

Arme Perso::getArme(){
    return Main_Droite;
}

void Perso::setProtection(Protection Left_Hand){
    Main_Gauche = Left_Hand;
}

Protection Perso::getProtection(){
    return Main_Gauche;
}

void Perso::DefPerso(){
    cout<<"Entrez le nom du joueur"<<endl;
    cin>>name;

    int choix;
    Arme Choix_Arme;
    Protection Choix_Protection;

    cout<<"Entrez le chiffre correspondant a l'arme"<<endl;
    for (int i=0; i<5; i++){
        cout<<"  "<<i+1<<" - "<<Tab_armes[i]; // le +1 du i+1 est pour la lisibilité du choix
    }
    cin>>choix;
    Choix_Arme = Tab_armes[choix-1];
    setArme(Choix_Arme); // comme le choix est un indice de plus que l'arme sélectionnée, il faut retirer 1

    cout<<"Entrez le chiffre correspondant a la puissance"<<endl;
    for (int i=0; i<3; i++){
        cout<<"  "<<i+1<<" - "<<Tab_protections[i]<<endl; // le +1 du i+1 est pour la lisibilité du choix
    }
    cin>>choix;
    Choix_Protection = Tab_protections[choix-1];
    setProtection(Choix_Protection); // comme le choix est un indice de plus que la protection sélectionnée, il faut retirer 1
}

bool Perso::EstVivant(){
    bool Vivant;
    if (getPV()<=0){
        Vivant = 0;
    }
    if (getPV()>=0){
        Vivant = 1;
    }
    return Vivant;
}

ResultCombat Perso::Combat(){
    ResultCombat Action;
    Action.Fuite = false;
    Action.DegatInfliges = 0;
    Action.ProtectionAppliquee = 0;

    int Choix;
    cout<<"Que voulez-vous faire?"<<endl;
    cout<<" 1 - Fuir"<<endl<<" 2 - Combattre"<<endl<<" 3 - Se proteger"<<endl;
    cin>>Choix;
    switch(Choix){
    case 1 :
        Action.Fuite = true;
        break;
    case 2 :
        Action.DegatInfliges = Main_Droite.UtiliserArme();
        break;
    case 3 :
        Action.ProtectionAppliquee = Main_Gauche.UtiliserProtection();
        break;
    default:
        cout<<"Choix invalide, vous ne ferez rien ce tour ci."<<endl;
        break;
    }
    return Action;
}


ostream &operator<<(ostream & flux,Perso &Test){
    flux<<"Le nom du personnage est "<<Test.getName()<<endl<<"Ses points de vie sont "<<Test.getPV()<<endl<<endl;
    flux<<Test.getArme()<<"L'objet est une arme."<<endl<<endl;
    flux<<Test.getProtection()<<"L'objet est une protection."<<endl<<endl;
    return flux;
}
