#ifndef ARME_H
#define ARME_H
#include <string>

using namespace std;

class Arme
{
    // Membres privés
    string nom;
    int def;
    int atk;

public:
    // Constructeur
    Arme();
    Arme(string,int,int); // Surdéfinition constructeur

    // Méthodes
    void setNom(string);
    void setDef(int);
    void setAtk(int);
    string getNom();
    int getDef();
    int getAtk();
    void initArme();
    int UtiliserArme();
};

// Surdéfinition opérateur d'affichage
std::ostream &operator<<(std::ostream &,Arme);

#endif // ARME_H
