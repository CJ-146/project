#ifndef OBJET_H
#define OBJET_H
#include <string>

using namespace std;

class Objet
{
    // Membres privés
    string Nom;
    int Puissance;

public:
    // Constructeur
    Objet();
    Objet(string,int); // Surdéfinition constructeur

    // Méthodes
    void setNom(string);
    void setPuissance(int);
    string getNom();
    int getPuissance();
    void initUtilObjet();
};

// Surdéfinition opérateur d'affichage
std::ostream &operator<<(std::ostream &,Objet);

#endif // OBJET_H
