#include <iostream>
#include <random>
#include <string>
#include <chrono>

using namespace std;

int Nb_Alea (int min, int max){

    unsigned graine = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(graine);

    uniform_int_distribution<int> distribution(min, max);
    int Nb_Alea = distribution(generator);
    return Nb_Alea;
}

void afficher_carateristiques (string Nom, int Arme, int Protection){
    const string nom_armes[] = {"Lance", "Epee", "Epee deux mains", "Hache", "Hache de guerre"};
    const string nom_protections[] = {"Cuir", "Cotte de maille", "Armure complete en fer"};

    cout<<Nom<<" a choisi "<<nom_armes[Arme-1]<<" en arme et "<<nom_protections[Protection-1]<<" en protection."<<endl;
}

void afficher (string Nom, float PV){
    cout<<Nom<<" a encore "<<PV<<" PV."<<endl;
}

string choix_nom (){
    string nom_hero;
    cout<<"Veuillez entrer le nom de votre personnage"<<endl;
    cin>>nom_hero;
    cout<<"Votre nom est "<<nom_hero<<"."<<endl;
    return nom_hero;
}

int choix_arme (int monnaie){
    int arme;
    cout<<"Quelle arme voulez-vous choisir? Entrez le numero correspondant :"<<endl<<"   (1) - Lance; (degat 11 - 21 - cout 0 victoire)"<<endl<<"   (2) - Epee; (degat 12 - 22 - cout 1 victoire)"<<endl<<"   (3) - Epee deux mains; (degat 13 - 23 - cout 2 victoire)"<<endl<<"   (4) - Hache; (degat 14 - 24 - cout 3 victoire)"<<endl<<"   (5) - Hache de guerre. (degat 15 - 25 - cout 4 victoire)"<<endl;
    cin>>arme;
    while((arme<1 || arme>5) || (arme-1>monnaie)){
        if (arme<1 || arme>5){
            cout<<"Le choix est invalide, veuillez reessayer :"<<endl;
            cin>>arme;
        }
        else if (arme-1>monnaie){
            cout<<"Vous n'avez pas assez d'argent, veuillez reessayer :"<<endl;
            cin>>arme;
        }
    }
    return arme;
}

int choix_protection (int monnaie){
    int protection;
    cout<<"Quelle protection voulez-vous choisir? Entrez le numero correspondant :"<<endl<<"   (1) - Cuir (100% a 25% de protection - cout 0 victoire);"<<endl<<"   (2) - Cotte de maille (100% a 50% de protection - cout 1 victoire);"<<endl<<"   (3) - Armure complete en fer (100% a 75% de protection - cout 2 victoire)."<<endl;
    cin>>protection;
    while((protection<1 || protection>3) || (protection-1>monnaie)){
        if (protection<1 || protection>3){
            cout<<"Le choix est invalide, veuillez reessayer :"<<endl;
            cin>>protection;
        }
        else if (protection-1>monnaie){
            cout<<"Vous n'avez pas assez d'argent, veuillez reessayer :"<<endl;
            cin>>protection;
        }
    }
    return protection;
}

int menu(){
    int choix;
    cout<<"Que voulez-vous faire :"<<endl<<"   (1) - voir vos caracteristiques;"<<endl<<"   (2) - combattre un autre joueur;"<<endl<<"   (3) - combattre l'ordinateur;"<<endl<<"   (4) - aller voir le marchand;"<<endl<<"   (5) - mettre fin au jeu :(."<<endl;
    cin>>choix;
    return choix;
}

int menu_combat(){
    int choix;
    cout<<"Que voulez-vous faire :"<<endl<<"   (1) - fuir tel le lache que vous etes et mettre fin au combat;"<<endl<<"   (2) - utiliser votre arme;"<<endl<<"   (3) - utiliser votre protection."<<endl;
    cin>>choix;
    while((choix<1 || choix>3)){
        cout<<"Le choix est invalide, veuillez reessayer :"<<endl;
        cin>>choix;
    }
    return choix;
}

int combat(bool invite, bool ordinateur, string Nom_hero, int Arme_hero, int Protection_hero, string Nom_2, int Arme_2, int Protection_2){
    int victoire = 2;
    int degat;
    int choix;
    float PV_hero = 50;
    float PV_2 = 50;
    float prot_hero = 1;
    float prot_2 = 1;
    int pourcentage_protection_hero = 100;
    int pourcentage_protection_2 = 100;
    int commencement = Arme_hero - Arme_2;
    if (invite==1){
        while (victoire == 2){
            if (commencement>=0){
                cout<<"C'est au tour de "<<Nom_2<<"."<<endl;
                afficher (Nom_2, PV_2);
                afficher (Nom_hero, PV_hero);
                choix = menu_combat();
                switch (choix){
                case 1:
                    victoire = 1;
                    break;
                case 2:
                    degat = Nb_Alea(10+Arme_2,20+Arme_2)*prot_hero;
                    PV_hero = PV_hero - degat;
                    break;
                case 3:
                    prot_2 = 1 - pourcentage_protection_2/100;
                    if (Protection_2==1 && pourcentage_protection_2>25){
                        pourcentage_protection_2 = pourcentage_protection_2-5;
                    }
                    else if (Protection_2==2 && pourcentage_protection_2>50){
                        pourcentage_protection_2 = pourcentage_protection_2-5;
                    }
                    else if (Protection_2==3 && pourcentage_protection_2>75){
                        pourcentage_protection_2 = pourcentage_protection_2-5;
                    }
                    break;
                }
                if (PV_hero<=0){
                    victoire = 0;
                }
                prot_hero = 1;
            }
            commencement = 0;
            if (victoire==2){
                cout<<"C'est au tour de "<<Nom_hero<<"."<<endl;
                afficher (Nom_hero, PV_hero);
                afficher (Nom_2, PV_2);
                choix = menu_combat();
                switch (choix){
                case 1:
                    victoire = 0;
                    break;
                case 2:
                    degat = Nb_Alea(10+Arme_hero,20+Arme_hero)*prot_2;
                    PV_2 = PV_2 - degat;
                    break;
                case 3:
                    prot_hero = 1 - pourcentage_protection_hero/100;
                    if (Protection_hero==1 && pourcentage_protection_hero>25){
                        pourcentage_protection_hero = pourcentage_protection_hero-5;
                    }
                    else if (Protection_hero==2 && pourcentage_protection_hero>50){
                        pourcentage_protection_hero = pourcentage_protection_hero-5;
                    }
                    else if (Protection_hero==3 && pourcentage_protection_hero>75){
                        pourcentage_protection_hero = pourcentage_protection_hero-5;
                    }
                    break;
                }
            }
            prot_2 = 1;
            if (PV_2<=0){
                victoire = 1;
            }
        }
    }
    if (ordinateur==1){
        while (victoire == 2){
            if (commencement>=0){
                cout<<"C'est au tour de "<<Nom_2<<"."<<endl;
                choix = Nb_Alea(2,3);
                switch (choix){
                case 2:
                    degat = Nb_Alea(10+Arme_2,20+Arme_2)*prot_hero;
                    PV_hero = PV_hero - degat;
                    break;
                case 3:
                    prot_2 = 1 - pourcentage_protection_2/100;
                    if (Protection_2==1 && pourcentage_protection_2>25){
                        pourcentage_protection_2 = pourcentage_protection_2-5;
                    }
                    else if (Protection_2==2 && pourcentage_protection_2>50){
                        pourcentage_protection_2 = pourcentage_protection_2-5;
                    }
                    else if (Protection_2==3 && pourcentage_protection_2>75){
                        pourcentage_protection_2 = pourcentage_protection_2-5;
                    }
                    break;
                }
                if (PV_hero<=0){
                    victoire = 0;
                }
                prot_hero = 1;
            }
            commencement = 0;
            if (victoire==2){
                cout<<"C'est au tour de "<<Nom_hero<<"."<<endl;
                afficher (Nom_hero, PV_hero);
                afficher (Nom_2, PV_2);
                choix = menu_combat();
                switch (choix){
                case 1:
                    victoire = 0;
                    break;
                case 2:
                    degat = Nb_Alea(10+Arme_hero,20+Arme_hero)*prot_2;
                    PV_2 = PV_2 - degat;
                    break;
                case 3:
                    prot_hero = 1 - pourcentage_protection_hero/100;
                    if (Protection_hero==1 && pourcentage_protection_hero>25){
                        pourcentage_protection_hero = pourcentage_protection_hero-5;
                    }
                    else if (Protection_hero==2 && pourcentage_protection_hero>50){
                        pourcentage_protection_hero = pourcentage_protection_hero-5;
                    }
                    else if (Protection_hero==3 && pourcentage_protection_hero>75){
                        pourcentage_protection_hero = pourcentage_protection_hero-5;
                    }
                    break;
                }
            }
            if (PV_2<=0){
                victoire = 1;
            }
            prot_2 = 1;
        }
    }
    if (victoire==0){
        cout<<Nom_2<<" a remporte la victoire."<<endl<<endl<<endl;
    }
    else if (victoire==1){
        cout<<Nom_hero<<" a remporte la victoire."<<endl<<endl<<endl;
    }
    return victoire;
}

int main()
{
    int argent_hero = 0;
    string nom_hero = choix_nom ();
    int arme_hero = choix_arme (argent_hero);
    int protection_hero = choix_protection (argent_hero);

    int argent_invite = 0;


    int fin = 0;
    while (fin == 0){
        int action = menu();
        switch(action){
        case 1:{
            cout<<"Vous avez choisi d'afficher les caracteristique de votre personnage."<<endl;
            afficher_carateristiques(nom_hero, arme_hero, protection_hero);
            break;}
        case 2:{
            cout<<"Vous avez choisi de vous battre contre un autre joueur."<<endl;
            string nom_invite = choix_nom ();
            int arme_invite = choix_arme (argent_invite);
            int protection_invite = choix_protection (argent_invite);
            bool resultat = combat(1, 0, nom_hero, arme_hero, protection_hero, nom_invite, arme_invite, protection_invite);
            if (resultat==1){
                argent_hero++;
            }
            else if (resultat==0){
                argent_invite++;
            }
            break;}
        case 3:{
            cout<<"Vous avez choisi de vous battre contre l'ordinateur."<<endl;
            string nom_ennemi = "Ennemi";
            int arme_ennemi = Nb_Alea(1, 5);
            int protection_ennemi = Nb_Alea(1, 3);
            bool resultat = combat(0, 1, nom_hero, arme_hero, protection_hero, nom_ennemi, arme_ennemi, protection_ennemi);
            if (resultat==1){
                argent_hero++;
            }
            break;}
        case 4:{
            cout<<"Vous allez voir le marchand."<<endl<<"Celui-ci vous propose différentes armes et protection"<<endl<<"Que voulez-vous faire"<<endl<<"   (1) - Acheter une nouvelle arme;"<<endl<<"   (2) - Acheter une nouvelle protection."<<endl;
            int choix;
            cin>>choix;
            while((choix<1 || choix>2)){
                cout<<"Le choix est invalide, veuillez reessayer :"<<endl;
                cin>>choix;
            }
            if (choix == 1){
                arme_hero = choix_arme (argent_hero);
            }
            else if (choix == 2){
                protection_hero = choix_protection (argent_hero);
            }
            cout<<"Le marchand vous remercie d'etre venu"<<endl;
            break;}
        case 5:{
            cout<<"Vous avez mis fin au jeu."<<endl;
            fin = 1;
            break;}
        default:{
            cout<<"Le choix n'est pas valide."<<endl;
            break;}

        }
    }
    return 0;
}
