#ifndef PROTECTION_H
#define PROTECTION_H
#include <string>

using namespace std;

class Protection
{
    // Membres privés
    string nom;
    int def;
    int atk;
    int dura;

public:
    // Constructeur
    Protection();
    Protection(string,int,int,int); // Surdéfinition constructeur

    // Méthodes
    void setNom(string);
    void setDef(int);
    void setAtk(int);
    void setDura(int);
    string getNom();
    int getDef();
    int getAtk();
    int getDura();
    void initProtection();
    int protectionAppliquee();
};

// Surdéfinition opérateur d'affichage
std::ostream &operator<<(std::ostream &,Protection);

#endif // PROTECTION_H
