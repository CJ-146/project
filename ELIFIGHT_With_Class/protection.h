#ifndef PROTECTION_H
#define PROTECTION_H
#include <objet.h>
#include <string.h>

class Protection : public Objet
{
public:
    // Constructeurs
    Protection();
    Protection(string,int);

    // Méthodes
    int UtiliserProtection();
};

#endif // PROTECTION_H
