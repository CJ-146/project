#ifndef ARME_H
#define ARME_H
#include <objet.h>

class Arme : public Objet
{
public:
    // Constructeurs
    Arme();
    Arme(string,int);

    // Méthodes
    int UtiliserArme();
};

#endif // ARME_H
