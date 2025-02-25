#include "protection.h"
#include "objet.h"

Protection::Protection() {}

Protection::Protection(string N, int P):Objet(N,P) {
}

int Protection::UtiliserProtection(){
    int Nouvelle_puissance = getPuissance()-5;
    setPuissance(Nouvelle_puissance);
    return getPuissance()+5; // La protection protègera toujours des dégats inférieur à 5
}
