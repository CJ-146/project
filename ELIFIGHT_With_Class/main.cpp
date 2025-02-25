#include <iostream>
#include "perso.h"

using namespace std;

int menu(){
    int choix;
    cout<<"Que voulez-vous faire :"<<endl<<"   (1) - voir vos caracteristiques;"<<endl;
    cout<<"   (2) - combattre un autre joueur;"<<endl<<"   (3) - changer les caracteristiques;"<<endl;
    cout<<"   (4) - mettre fin au jeu :(."<<endl;
    cin>>choix;
    return choix;
}



int main()
{
    int Degat;
    int fin = 0;

    ResultCombat Choix_Perso_1;
    ResultCombat Choix_Perso_2;

    Perso Regeneration_PV;
    Perso Perso_Jouable_1;
    Perso Perso_Jouable_2;

    Perso_Jouable_1.DefPerso();
    Perso_Jouable_2.DefPerso();

    while (fin == 0){
        int action = menu();
        switch(action){
        case 1:{
            cout<<"Vous avez choisi d'afficher les caracteristique des personnages."<<endl;
            cout<<Perso_Jouable_1<<endl;
            cout<<Perso_Jouable_2<<endl;
            break;}
        case 2:{
            cout<<"Vous avez choisi de combattre un autre joueur"<<endl;
            while(Perso_Jouable_1.getPV()>0 && Perso_Jouable_2.getPV()>0){
                cout<<Perso_Jouable_1<<endl;
                cout<<Perso_Jouable_2<<endl;

                cout<<"Au tour de "<<Perso_Jouable_1.getName()<<endl;
                Choix_Perso_1 = Perso_Jouable_1.Combat();
                if (Choix_Perso_1.Fuite){
                    Perso_Jouable_1.setPV(0); // La fuite "tue" le joueur pour connaître le vainqueur
                }
                else if (!Choix_Perso_1.Fuite){
                    Degat = Choix_Perso_1.DegatInfliges-Choix_Perso_2.ProtectionAppliquee;
                    if (Degat<0){
                        Degat = 0; // Pour ne pas régénérer des dégats
                    }
                    Perso_Jouable_2.setPV(Perso_Jouable_2.getPV()-Degat);
                }

                // Pour éviter que le joueur joue alors qu'il a été battu au tour précédent
                if (Perso_Jouable_2.getPV()>0 && !Choix_Perso_1.Fuite){
                    cout<<Perso_Jouable_1<<endl;
                    cout<<Perso_Jouable_2<<endl;

                    cout<<"Au tour de "<<Perso_Jouable_2.getName()<<endl;
                    Choix_Perso_2 = Perso_Jouable_2.Combat();
                    if (Choix_Perso_2.Fuite){
                        Perso_Jouable_2.setPV(0); // La fuite "tue" le joueur pour connaître le vainqueur
                    }
                    else if (!Choix_Perso_2.Fuite){
                        Degat = Choix_Perso_2.DegatInfliges-Choix_Perso_1.ProtectionAppliquee;
                        if (Degat<0){
                            Degat = 0; // Pour ne pas régénérer des dégats
                        }
                        Perso_Jouable_1.setPV(Perso_Jouable_1.getPV()-Degat);
                    }
                }
            }
            if (Perso_Jouable_1.getPV()<=0){
                cout<<"Le vainqueur est "<<Perso_Jouable_2.getName()<<endl;
            }
            else if (Perso_Jouable_2.getPV()<=0){
                cout<<"Le vainqueur est "<<Perso_Jouable_1.getName()<<endl;
            }

            // Pour remettre les dégats à jour
            Perso_Jouable_1.setPV(Regeneration_PV.getPV());
            Perso_Jouable_2.setPV(Regeneration_PV.getPV());
            break;}
        case 3:{
            cout<<"Vous avez choisi de changer les caracteristique des personnages."<<endl;
            cout<<"Caracteristiques de "<<Perso_Jouable_1.getName()<<endl;
            Perso_Jouable_1.DefPerso();
            cout<<"Caracteristiques de "<<Perso_Jouable_2.getName()<<endl;
            Perso_Jouable_2.DefPerso();
            break;}
        case 4:{
            cout<<"Vous avez mis fin au jeu."<<endl;
            fin = 1;
            break;}
        default:{
            cout<<"Le choix n'est pas valide."<<endl;
            break;}
        }
    }

    /*
    // Code pour comprendre l'erreur dans la puissance de la protection
    Arme Dague("Dague",25);
    Protection Cuirasse("Cuirasse",80);

    Perso Perso_Jouable_1("vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",100,Dague,Cuirasse);

    //Perso_Jouable_1.DefPerso();

    int Prot;

    Prot = Perso_Jouable_1.getProtection().UtiliserProtection();
    cout<<Prot<<endl<<Perso_Jouable_1.getProtection()<<endl;
    Prot = Perso_Jouable_1.getProtection().UtiliserProtection();
    cout<<Prot<<endl<<Perso_Jouable_1.getProtection()<<endl;
    Prot = Perso_Jouable_1.getProtection().UtiliserProtection();
    cout<<Prot<<endl<<Perso_Jouable_1.getProtection()<<endl;
    Prot = Perso_Jouable_1.getProtection().UtiliserProtection();
    cout<<Prot<<endl<<Perso_Jouable_1.getProtection()<<endl;
    Prot = Perso_Jouable_1.getProtection().UtiliserProtection();
    cout<<Prot<<endl<<Perso_Jouable_1.getProtection()<<endl;
*/

    return 0;
}
