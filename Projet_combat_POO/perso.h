#ifndef PERSO_H
#define PERSO_H
#include <protection.h>
#include <arme.h>

class Perso
{
private:
    Arme armePerso;
    Protection protectionPerso;
    int defPerso;
    int atkPerso;

public:
    //constructeurs
    Perso();
    Perso(Arme,Protection,int,int);

    //Methodes pour écrire ou récupérer des membres
    int getDef();
    void setDef(int);
    int getAtk();
    void setAtk(int);
    Arme getArme();
    void setArme(Arme);
    Protection getProtection();
    void setProtection(Protection);
    int getDefTot();
    int getAtkTot();
};

// surdéfinition opérateur d'affichage
std::ostream &operator<<(std::ostream &,Perso &);

#endif // PERSO_H
