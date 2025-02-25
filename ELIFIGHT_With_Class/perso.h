#ifndef PERSO_H
#define PERSO_H
#include <protection.h>
#include <string>
#include <arme.h>

struct ResultCombat{
    bool Fuite;
    int DegatInfliges;
    int ProtectionAppliquee;
};

class Perso
{
private:
    std::string name;
    int PV;
    Arme Main_Droite;
    Protection Main_Gauche;

public:
    //constructeurs
    Perso();
    Perso(std::string,int,Arme,Protection);

    //Methodes pour écrire ou récupérer des membres
    std::string getName();
    void setName(std::string);
    int getPV();
    void setPV(int);
    Arme getArme();
    void setArme(Arme);
    Protection getProtection();
    void setProtection(Protection);

    //Méthodes spécifiques
    void DefPerso();
    bool EstVivant();
    ResultCombat Combat();
};

// surdéfinition opérateur d'affichage
std::ostream &operator<<(std::ostream &,Perso &);

#endif // PERSO_H
