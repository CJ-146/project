#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressBar>
#include <QtWidgets/QPushButton>
#include <QLabel>
#include <QMenuBar>
#include <QToolBar>
#include <QGridLayout>
#include <perso.h>

struct difficulteETniveauCombat{
    bool facile;
    bool moyen;
    bool difficile;
    int niveau;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void regle();

    void changerArme1();
    void changerArme2();
    void changerArme3();
    void changerArme4();
    void changerArme5();

    void changerProtec1();
    void changerProtec2();
    void changerProtec3();

    void portail();
    void facile();
    void moyen();
    void difficile();
    void combat_de_boss();

    void gain_exp();
    void lvl_up();
    void fin_combat();
    void Verif_GameOver();
    void verif_kill();
    void verif_win();

    void reset();
    void suicide();

    void atk();
    void esquive();
    void esquiveProtection();

    void cacherBPchoix();
    void cacher_pnj();
    void afficher_vie();
    void AfficherBPfight();
    void afficher_arme();
    void afficher_protec();

private:
    QProgressBar *VieBoss,*VieHero,*Exp,*Combat,*difficulte;

    QPushButton *BP_Start,*BP_Portails_1,*BP_Portails_2,*BP_Portails_3;
    QPushButton *arme1,*arme2,*arme3,*arme4,*arme5,*protec1,*protec2,*protec3;
    QPushButton *esq,*esqProtec,*attaque,*BP_afficherPortails,*armeNext,*protecNext,*final;

    QLabel *img_ennemi_facile,*img_ennemi_moyen,*img_ennemi_difficile;
    QLabel *img_hero_facile,*img_hero_moyen,*img_hero_difficile;
    QLabel *img_accueil,*affichage_regle;

    QMenu *menu;

};
#endif // MAINWINDOW_H








