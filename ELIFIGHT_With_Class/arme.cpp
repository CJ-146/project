#include "arme.h"
#include "objet.h"

Arme::Arme() {
}

Arme::Arme(string N, int P):Objet(N,P) {
}

int Arme::UtiliserArme(){
    return rand() % getPuissance() + 10;
}
