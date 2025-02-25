#include "objet.h"
#include <iostream>

using namespace std;

Objet::Objet() {
    Nom = "";
    Puissance = 0;
}

Objet::Objet(string Name,int Power) {
    Nom = Name;
    Puissance = Power;
}

void Objet::setNom(string Name){
    Nom = Name;
}

string Objet::getNom(){
    return Nom;
}

void Objet::setPuissance(int Power) {
    Puissance = Power;
    if (Power<0){
        Puissance = 0;
    }
}

int Objet::getPuissance(){
    return Puissance;
}

void Objet::initUtilObjet(){
    cout<<"Veuillez entrer le nom"<<endl;
    cin>>Nom;
    cout<<"Veuillez entrer le puissance"<<endl;
    cin>>Puissance;
}

ostream &operator<<(ostream & flux,Objet Test){
    flux<<"Le nom de l'objet est "<<Test.getNom()<<endl<<"La puissance de l'objet est "<<Test.getPuissance()<<endl;
    return flux;
}
