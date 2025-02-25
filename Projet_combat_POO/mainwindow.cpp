#include "mainwindow.h"
#include "arme.h"
#include <QGridLayout>
#include <QRandomGenerator>
#include <QMessageBox>
#include <perso.h>

// Protections
Protection Cuirasse("Cuirasse",7,-4,8);
Protection Maille("Cote de maille",11,-8,12);
Protection Plastron("Plastron",35,-10,16);

// Armes
Arme Dague("Dague",18,-2);
Arme Arc("Arc",20,0);
Arme Lance("Lance",28,-2);
Arme Epee("Epee",32,0);
Arme Cimeterre("Cimeterre",40,-10);

// déclaration des personnages
Perso boss1(Dague, Cuirasse,0,0);
Perso boss2(Arc, Cuirasse,0,0);
Perso boss3(Lance, Maille,0,0);
Perso boss4(Epee, Maille,0,0);
Perso bossFinal(Cimeterre, Plastron,0,0);

Perso Hero(Dague, Cuirasse,1,5);
Perso bossActuel(Dague, Cuirasse,0,0);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *fenetre = new QWidget;
    QGridLayout *layoutCentral = new QGridLayout;

    affichage_regle = new QLabel;
    affichage_regle->setText(
        "Comment jouer : "
        "\n\n 1. Choisir son arme"
        "\n\n    la dague est la plus faible pour plus de challenge, le cimeterre est la plus forte"
        "\n\n 2. Choisir sa protection "
        "\n\n    la cuirrasse est la plus faible pour plus de challenge, le plastron est la plus resistante"
        "\n\n 3. Choisir la difficulte des combats aux portails"
        "\n\n 4. Vaincre les boss (mechant)"
        "\n\n 5. Vaincre cthulhu et gagner le jeu !");

    affichage_regle->setFont(QFont("Comic Sans MS", 14));
    layoutCentral->addWidget(affichage_regle,2, 2, 5, 5);
    affichage_regle->QWidget::setVisible(false);

    difficulte = new QProgressBar;

    VieHero = new QProgressBar;
    VieHero->setValue(100);
    layoutCentral->addWidget(VieHero, 11, 0,1,4);
    VieHero->QWidget::setVisible(false);

    VieBoss = new QProgressBar;
    VieBoss->setValue(100);
    layoutCentral->addWidget(VieBoss, 11, 7,1,4);
    VieBoss->QWidget::setVisible(false);

    Exp = new QProgressBar;
    Exp->setValue(0);
    layoutCentral->addWidget(Exp, 12, 0,1,4);
    Exp->QWidget::setVisible(false);

    Combat = new QProgressBar;
    Combat->setValue(0);
    layoutCentral->addWidget(Combat, 13, 0,1,11);
    Combat->QWidget::setVisible(false);

    img_accueil = new QLabel;
    img_accueil->setPixmap(QPixmap(":/picture/Accueil"));
    img_accueil->setScaledContents(false);
    img_accueil->setFixedSize(850, 450);
    layoutCentral->addWidget(img_accueil, 0,0,11,11,Qt::AlignCenter);

    BP_Start = new QPushButton;
    BP_Start -> setIcon(QIcon(":/picture/start"));
    BP_Start -> setIconSize(QSize(100,100));
    layoutCentral->addWidget(BP_Start,8,5);

    final = new QPushButton;
    final -> setText("Combat \n Final");
    final -> setIconSize(QSize(100,100));
    layoutCentral->addWidget(final,8,5);
    final->QWidget::setVisible(false);

    BP_afficherPortails = new QPushButton;
    BP_afficherPortails -> setIcon(QIcon(":/picture/next"));
    BP_afficherPortails -> setIconSize(QSize(100,100));
    layoutCentral->addWidget(BP_afficherPortails,9,9,2,1);
    BP_afficherPortails->QWidget::setVisible(false);

    armeNext = new QPushButton;
    armeNext -> setIcon(QIcon(":/picture/next"));
    armeNext -> setIconSize(QSize(100,100));
    layoutCentral->addWidget(armeNext,9,9,2,1);
    armeNext->QWidget::setVisible(false);

    protecNext = new QPushButton;
    protecNext -> setIcon(QIcon(":/picture/next"));
    protecNext -> setIconSize(QSize(100,100));
    layoutCentral->addWidget(protecNext,9,9,2,1);
    protecNext->QWidget::setVisible(false);

    BP_Portails_1 = new QPushButton;
    BP_Portails_1 -> setText("Portail 1: \n Niveau Facile");
    layoutCentral->addWidget(BP_Portails_1,8,2);

    BP_Portails_2 = new QPushButton;
    BP_Portails_2 -> setText("Portail 2: \n Niveau Moyen");
    layoutCentral->addWidget(BP_Portails_2,8,5);

    BP_Portails_3 = new QPushButton;
    BP_Portails_3 -> setText("Portail 3: \n Niveau Difficile");
    layoutCentral->addWidget(BP_Portails_3,8,8);
    cacherBPchoix();

    // Boutons choix armes
    arme1 = new QPushButton;
    arme1 -> setText("Dague");
    layoutCentral->addWidget(arme1,3,5);
    arme1->QWidget::setVisible(false);

    arme2 = new QPushButton;
    arme2 -> setText("Arc");
    layoutCentral->addWidget(arme2,4,5);
    arme2->QWidget::setVisible(false);

    arme3 = new QPushButton;
    arme3 -> setText("Lance");
    layoutCentral->addWidget(arme3,5,5);
    arme3->QWidget::setVisible(false);

    arme4 = new QPushButton;
    arme4 -> setText("Epee");
    layoutCentral->addWidget(arme4,6,5);
    arme4->QWidget::setVisible(false);

    arme5 = new QPushButton;
    arme5 -> setText("Cimeterre");
    layoutCentral->addWidget(arme5,7,5);
    arme5->QWidget::setVisible(false);

    // Boutons choix protections
    protec1 = new QPushButton;
    protec1 -> setText("Cuirasse");
    layoutCentral->addWidget(protec1,4,5);
    protec1->QWidget::setVisible(false);

    protec2 = new QPushButton;
    protec2 -> setText("Maille");
    layoutCentral->addWidget(protec2,5,5);
    protec2->QWidget::setVisible(false);

    protec3 = new QPushButton;
    protec3 -> setText("Plastron");
    layoutCentral->addWidget(protec3,6,5);
    protec3->QWidget::setVisible(false);

    attaque = new QPushButton;
    attaque -> setText("Attaquer");
    layoutCentral->addWidget(attaque,9,5);
    attaque->QWidget::setVisible(false);

    esq = new QPushButton;
    esq -> setText("Esquiver");
    layoutCentral->addWidget(esq,9,6);
    esq->QWidget::setVisible(false);

    esqProtec = new QPushButton;
    esqProtec -> setText("Esquiver protection");
    layoutCentral->addWidget(esqProtec,9,4);
    esqProtec->QWidget::setVisible(false);

    img_ennemi_facile = new QLabel;
    img_ennemi_facile->setScaledContents(true);
    img_ennemi_facile->setFixedSize(100, 100);
    layoutCentral->addWidget(img_ennemi_facile, 5,7,0,0,Qt::AlignCenter);
    img_ennemi_facile->QWidget::setVisible(false);

    img_ennemi_moyen = new QLabel;
    img_ennemi_moyen->setScaledContents(true);
    img_ennemi_moyen->setFixedSize(100, 100);
    layoutCentral->addWidget(img_ennemi_moyen, 7,7,0,0,Qt::AlignCenter);
    img_ennemi_moyen->QWidget::setVisible(false);

    img_ennemi_difficile = new QLabel;
    img_ennemi_difficile->setScaledContents(true);
    img_ennemi_difficile->setFixedSize(100, 100);
    layoutCentral->addWidget(img_ennemi_difficile, 8,7,0,0,Qt::AlignCenter);
    img_ennemi_difficile->QWidget::setVisible(false);

    img_hero_facile = new QLabel;
    img_hero_facile->setPixmap(QPixmap(":/picture/chavalier"));
    img_hero_facile->setScaledContents(true);
    img_hero_facile->setFixedSize(100, 100);
    layoutCentral->addWidget(img_hero_facile, 6,2,0,0,Qt::AlignCenter);
    img_hero_facile->QWidget::setVisible(false);

    img_hero_moyen = new QLabel;
    img_hero_moyen->setPixmap(QPixmap(":/picture/chavalier"));
    img_hero_moyen->setScaledContents(true);
    img_hero_moyen->setFixedSize(100, 100);
    layoutCentral->addWidget(img_hero_moyen, 7,3,0,0,Qt::AlignCenter);
    img_hero_moyen->QWidget::setVisible(false);

    img_hero_difficile = new QLabel;
    img_hero_difficile->setPixmap(QPixmap(":/picture/chavalier"));
    img_hero_difficile->setScaledContents(true);
    img_hero_difficile->setFixedSize(100, 100);
    layoutCentral->addWidget(img_hero_difficile, 8,3,0,0,Qt::AlignCenter);
    img_hero_difficile->QWidget::setVisible(false);

    QMenu *menuTest = menuBar()->addMenu("Menu");
    QAction *actionReset = new QAction("Reset", this);
    menuTest->addAction(actionReset);
    QAction *actionQuitter = new QAction("Quitter", this);
    menuTest->addAction(actionQuitter);

    QMenu *menuSkip = menuBar()->addMenu("Cheat");
    QAction *sauterCombat = new QAction("Instant kill", this);
    menuSkip->addAction(sauterCombat);
    QAction *Suicide = new QAction("Suicide", this);
    menuSkip->addAction(Suicide);


    fenetre->setLayout(layoutCentral);
    setCentralWidget(fenetre);


    QObject::connect(actionQuitter,SIGNAL(triggered()),this,SLOT(close()));
    QObject::connect(sauterCombat,SIGNAL(triggered()),this,SLOT(fin_combat()));
    QObject::connect(Suicide,SIGNAL(triggered()),this,SLOT(suicide()));
    QObject::connect(actionReset,SIGNAL(triggered()),this,SLOT(reset()));

    QObject::connect(BP_Start,SIGNAL(pressed()),this,SLOT(regle()));
    QObject::connect(armeNext,SIGNAL(pressed()),this,SLOT(afficher_arme()));
    QObject::connect(protecNext,SIGNAL(pressed()),this,SLOT(afficher_protec()));
    QObject::connect(BP_afficherPortails,SIGNAL(pressed()),this,SLOT(portail()));

    QObject::connect(BP_Portails_1,SIGNAL(pressed()),this,SLOT(facile()));
    QObject::connect(BP_Portails_2,SIGNAL(pressed()),this,SLOT(moyen()));
    QObject::connect(BP_Portails_3,SIGNAL(pressed()),this,SLOT(difficile()));

    QObject::connect(attaque,SIGNAL(pressed()),this,SLOT(atk()));
    QObject::connect(esq,SIGNAL(pressed()),this,SLOT(esquive()));
    QObject::connect(esqProtec,SIGNAL(pressed()),this,SLOT(esquiveProtection()));

    QObject::connect(final,SIGNAL(pressed()),this,SLOT(combat_de_boss()));

    QObject::connect(arme1,SIGNAL(pressed()),this,SLOT(changerArme1()));
    QObject::connect(arme2,SIGNAL(pressed()),this,SLOT(changerArme2()));
    QObject::connect(arme3,SIGNAL(pressed()),this,SLOT(changerArme3()));
    QObject::connect(arme4,SIGNAL(pressed()),this,SLOT(changerArme4()));
    QObject::connect(arme5,SIGNAL(pressed()),this,SLOT(changerArme5()));

    QObject::connect(protec1,SIGNAL(pressed()),this,SLOT(changerProtec1()));
    QObject::connect(protec2,SIGNAL(pressed()),this,SLOT(changerProtec2()));
    QObject::connect(protec3,SIGNAL(pressed()),this,SLOT(changerProtec3()));
}

void MainWindow::changerArme1(){
    Hero.setArme(Dague);
}
void MainWindow::changerArme2(){
    Hero.setArme(Arc);
}
void MainWindow::changerArme3(){
    Hero.setArme(Lance);
}
void MainWindow::changerArme4(){
    Hero.setArme(Epee);
}
void MainWindow::changerArme5(){
    Hero.setArme(Cimeterre);
}

void MainWindow::changerProtec1(){
    Hero.setProtection(Cuirasse);
}
void MainWindow::changerProtec2(){
    Hero.setProtection(Maille);
}
void MainWindow::changerProtec3(){
    Hero.setProtection(Plastron);
}

void MainWindow::atk(){
    // attaque mutuelle
    int atk = Hero.getAtkTot() ;
    int atkBoss = bossActuel.getAtkTot() ;
    int def = Hero.getDefTot() ;
    int defBoss = bossActuel.getDefTot() ;

    int degatHero = atkBoss - def;
    int degatBoss = atk - defBoss;

    if (degatHero>0){
        if (VieHero->value()-degatHero<0){
            VieHero->setValue(0);
        }
        VieHero->setValue(VieHero->value()-degatHero);
    }
    if (degatBoss>0){
        if (VieBoss->value()-degatBoss<0){
            VieBoss->setValue(0);
        }
        VieBoss->setValue(VieBoss->value()-degatBoss);
    }
    verif_kill();
    Verif_GameOver();
    verif_win();
}

void MainWindow::esquiveProtection(){
    // la durabilité d'une protection est une défence bonus
    int def = Hero.getProtection().protectionAppliquee() + Hero.getDefTot();
    int atkBoss = bossActuel.getAtkTot();

    int degatHero = atkBoss - def;

    if (degatHero>0){
        if (VieHero->value()-degatHero<0){
            VieHero->setValue(0);
        }
        VieHero->setValue(VieHero->value()-degatHero);
    }
    verif_kill();
    Verif_GameOver();
    verif_win();
}

void MainWindow::esquive(){
    bool reussite = rand() % 2;
    if (!reussite){
        int atkBoss = bossActuel.getAtkTot() ;
        int def = Hero.getDefTot();

        int degatHero = atkBoss - def;

        if (degatHero>0){
            if (VieHero->value()-degatHero<0){
                VieHero->setValue(0);
            }
            VieHero->setValue(VieHero->value()-degatHero);
        }
    }
    else{

        int atk = Hero.getAtkTot() ;
        int defBoss = bossActuel.getDefTot() ;

        int degatBoss = atk - defBoss;

        if (degatBoss>0){
            if (VieBoss->value()-degatBoss<0){
                VieBoss->setValue(0);
            }
            VieBoss->setValue(VieBoss->value()-degatBoss);
        }
    }
    verif_kill();
    Verif_GameOver();
    verif_win();
}

void MainWindow::afficher_arme(){
    img_accueil->setPixmap(QPixmap(":/picture/black"));
    img_accueil->setScaledContents(true);
    affichage_regle->QWidget::setVisible(false);
    armeNext->QWidget::setVisible(false);
    protecNext->QWidget::setVisible(true);
    arme1->QWidget::setVisible(true);
    arme2->QWidget::setVisible(true);
    arme3->QWidget::setVisible(true);
    arme4->QWidget::setVisible(true);
    arme5->QWidget::setVisible(true);
    protec1->QWidget::setVisible(false);
    protec2->QWidget::setVisible(false);
    protec3->QWidget::setVisible(false);
}

void MainWindow::afficher_protec(){
    img_accueil->setPixmap(QPixmap(":/picture/black"));
    img_accueil->setScaledContents(true);
    protecNext->QWidget::setVisible(false);
    BP_afficherPortails->QWidget::setVisible(true);
    arme1->QWidget::setVisible(false);
    arme2->QWidget::setVisible(false);
    arme3->QWidget::setVisible(false);
    arme4->QWidget::setVisible(false);
    arme5->QWidget::setVisible(false);
    protec1->QWidget::setVisible(true);
    protec2->QWidget::setVisible(true);
    protec3->QWidget::setVisible(true);

}

void MainWindow::regle(){
    BP_Start->QWidget::setVisible(false);
    affichage_regle->QWidget::setVisible(true);
    armeNext->QWidget::setVisible(true);
    img_accueil->setPixmap(QPixmap(":/picture/blanc"));
    img_accueil->setScaledContents(true);
}

void MainWindow::portail(){
    int combat = Combat->value()/20;
    protecNext->QWidget::setVisible(false);

    protec1->QWidget::setVisible(false);
    protec2->QWidget::setVisible(false);
    protec3->QWidget::setVisible(false);

    BP_Start->QWidget::setVisible(false);
    BP_afficherPortails->QWidget::setVisible(false);

    BP_Portails_1->QWidget::setVisible(true);
    BP_Portails_2->QWidget::setVisible(true);
    BP_Portails_3->QWidget::setVisible(true);

    VieBoss->QWidget::setVisible(false);
    VieHero->QWidget::setVisible(false);
    Combat->QWidget::setVisible(true);
    Exp->QWidget::setVisible(false);
    cacher_pnj();

    Cuirasse.setDura(8);
    Maille.setDura(12);
    Plastron.setDura(16);

    if (combat <4){
        img_accueil->setPixmap(QPixmap(":/picture/triple_portail"));
        img_accueil->setScaledContents(true);

    }
    else if (combat == 4){
        img_accueil->setPixmap(QPixmap(":/picture/Portail_final"));
        img_accueil->setScaledContents(true);
        final->QWidget::setVisible(true);
        cacherBPchoix();
    }
}

void MainWindow::facile(){
    difficulte -> setValue(10);
    int combat = Combat->value()/20;
    img_accueil->setPixmap(QPixmap(":/picture/arene_facile"));
    img_accueil->setScaledContents(true);
    cacherBPchoix();
    img_ennemi_facile->QWidget::setVisible(true);
    img_hero_facile->QWidget::setVisible(true);
    if (combat ==0) {
        img_ennemi_facile->setPixmap(QPixmap(":/picture/com1_fac"));
        bossActuel = boss1;
        afficher_vie();
        AfficherBPfight();
    }
    else if (combat==1){
        img_ennemi_facile->setPixmap(QPixmap(":/picture/com2_fac"));
        bossActuel = boss2;
        afficher_vie();
        AfficherBPfight();
    }
    else if (combat==2){
        img_ennemi_facile->setPixmap(QPixmap(":/picture/com3_fac"));
        bossActuel = boss3;
        afficher_vie();
        AfficherBPfight();
    }
    else if (combat==3){
        img_ennemi_facile->setPixmap(QPixmap(":/picture/com4_fac"));
        bossActuel = boss4;
        afficher_vie();
        AfficherBPfight();
    }
    bossActuel.setAtk(0);
    bossActuel.setDef(0);
}

void MainWindow::moyen(){
    difficulte -> setValue(20);
    int combat = Combat->value()/20;
    img_accueil->setPixmap(QPixmap(":/picture/arene_moyen"));
    img_accueil->setScaledContents(true);
    cacherBPchoix();
    img_hero_moyen->QWidget::setVisible(true);
    img_ennemi_moyen->QWidget::setVisible(true);
    if(combat==0){
        img_ennemi_moyen->setPixmap(QPixmap(":/picture/com2_moy"));
        bossActuel = boss1;
        afficher_vie();
        AfficherBPfight();
    }
    else if (combat==1){
        img_ennemi_moyen->setPixmap(QPixmap(":/picture/com2_moy"));
        bossActuel = boss2;
        afficher_vie();
        AfficherBPfight();
    }
    else if (combat==2){
        img_ennemi_moyen->setPixmap(QPixmap(":/picture/com3_moy"));
        bossActuel = boss3;
        afficher_vie();
        AfficherBPfight();
    }
    else if (combat==3){
        img_ennemi_moyen->setPixmap(QPixmap(":/picture/com4_moy"));
        bossActuel = boss4;
        afficher_vie();
        AfficherBPfight();
    }
    bossActuel.setAtk(2);
    bossActuel.setDef(2);
}

void MainWindow::difficile(){
    difficulte -> setValue(30);
    int combat = Combat->value()/20;
    img_accueil->setPixmap(QPixmap(":/picture/arene_difficile"));
    img_accueil->setScaledContents(true);
    cacherBPchoix();
    img_hero_difficile->QWidget::setVisible(true);
    img_ennemi_difficile->QWidget::setVisible(true);
    if(combat==0){
        img_ennemi_difficile->setPixmap(QPixmap(":/picture/com3_dif"));
        bossActuel = boss1;
        afficher_vie();
        AfficherBPfight();
    }
    else if (combat==1){
        img_ennemi_difficile->setPixmap(QPixmap(":/picture/com2_dif"));
        bossActuel = boss2;
        afficher_vie();
        AfficherBPfight();
    }
    else if (combat==2){
        img_ennemi_difficile->setPixmap(QPixmap(":/picture/com3_dif"));
        bossActuel = boss3;
        afficher_vie();
        AfficherBPfight();
    }
    else if (combat==3){
        img_ennemi_difficile->setPixmap(QPixmap(":/picture/com4_dif"));
        bossActuel = boss4;
        afficher_vie();
        AfficherBPfight();
    }
    bossActuel.setAtk(4);
    bossActuel.setDef(4);
}

void MainWindow::combat_de_boss(){
    final->QWidget::setVisible(false);
    img_accueil->setPixmap(QPixmap(":/picture/boss"));
    img_accueil->setScaledContents(true);
    bossActuel = bossFinal;
    bossActuel.setAtk(0);
    bossActuel.setDef(0);
    AfficherBPfight();
    VieBoss->QWidget::setVisible(true);
    VieHero->QWidget::setVisible(true);
}

void MainWindow::gain_exp(){
    int diff = difficulte->value();
    if (diff == 10){
        int exp = Exp->value()+70;
        if (exp < 100){
            Exp->setValue(exp);
        }
        else if (exp >= 100){
            Exp->setValue(exp - 100);
            lvl_up();
        }
    }
    if (diff == 20){
        int exp = Exp->value()+100;
        if (exp < 100){
            Exp->setValue(exp);
        }
        else if (exp >= 100){
            Exp->setValue(exp - 100);
            lvl_up();
        }
    }
    else if (diff == 30){
        int exp = Exp->value()+130;
        if (exp < 100){
            Exp->setValue(exp);
        }
        else if (exp >= 100){
            Exp->setValue(exp - 100);
            lvl_up();
        }
    }
}

void MainWindow::lvl_up(){
    img_accueil->setPixmap(QPixmap(":/picture/level_up"));
    img_accueil->setScaledContents(true);
    Hero.setDef(Hero.getDef()+3);
    Hero.setAtk(Hero.getAtk()+3);
    VieHero->setValue(100);
    BP_afficherPortails->QWidget::setVisible(true);
    cacher_pnj();
}

void MainWindow::verif_kill(){
    int vieBoss=VieBoss->value();
    if (vieBoss == 0){
        Combat->setValue(Combat->value()+20);
        gain_exp();
        VieBoss->setValue(100);
        VieHero->setValue(VieHero->value()+(100-VieHero->value())/2);
        VieBoss->QWidget::setVisible(false);
        BP_afficherPortails->QWidget::setVisible(true);

        attaque->QWidget::setVisible(false);
        esq->QWidget::setVisible(false);
        esqProtec->QWidget::setVisible(false);
    }
}

void MainWindow::verif_win(){
    int combat=Combat->value()/20;
    if (combat == 5){
        img_accueil->setPixmap(QPixmap(":picture/You_win"));
        cacher_pnj();
        foreach (QPushButton* bouton, this->findChildren<QPushButton*>())
        {
            bouton->setVisible(false);
        }
        foreach (QProgressBar* progressBar, this->findChildren<QProgressBar*>())
        {
            progressBar->setVisible(false);
        }
    }
}

void MainWindow::Verif_GameOver(){
    int PV=VieHero->value();
    if (PV==0){
        img_accueil->setPixmap(QPixmap(":picture/You_died"));
        cacher_pnj();
        foreach (QPushButton* bouton, this->findChildren<QPushButton*>())
        {
            bouton->setVisible(false);
        }
        foreach (QProgressBar* progressBar, this->findChildren<QProgressBar*>())
        {
            progressBar->setVisible(false);
        }
    }
}

void MainWindow::cacherBPchoix(){
    BP_Portails_1->QWidget::setVisible(false);
    BP_Portails_2->QWidget::setVisible(false);
    BP_Portails_3->QWidget::setVisible(false);
}

void MainWindow::cacher_pnj(){
    img_ennemi_facile->QWidget::setVisible(false);
    img_ennemi_moyen->QWidget::setVisible(false);
    img_ennemi_difficile->QWidget::setVisible(false);
    img_hero_facile->QWidget::setVisible(false);
    img_hero_moyen->QWidget::setVisible(false);
    img_hero_difficile->QWidget::setVisible(false);
    attaque->QWidget::setVisible(false);
    esq->QWidget::setVisible(false);
    esqProtec->QWidget::setVisible(false);
    VieHero->QWidget::setVisible(false);
    VieBoss->QWidget::setVisible(false);
}

void MainWindow::AfficherBPfight(){
    attaque->QWidget::setVisible(true);
    esq->QWidget::setVisible(true);
    esqProtec->QWidget::setVisible(true);
}

void MainWindow::afficher_vie(){
    VieHero->QWidget::setVisible(true);
    VieBoss->QWidget::setVisible(true);
    Exp->QWidget::setVisible(true);
}

void MainWindow::suicide(){
    VieHero->setValue(0);
    Verif_GameOver();
}

void MainWindow::fin_combat(){
    VieBoss->setValue(0);
    verif_kill();
    verif_win();
}

void MainWindow::reset(){
    VieHero->setValue(100);
    VieBoss->setValue(100);

    Hero.setDef(5);
    Hero.setAtk(1);
    Hero.setArme(Dague);
    Hero.setProtection(Cuirasse);

    Cuirasse.setDura(8);
    Maille.setDura(12);
    Plastron.setDura(16);

    Exp->setValue(0);
    Combat->setValue(0);
    img_accueil->setPixmap(QPixmap(":/picture/Accueil"));
    img_accueil->setScaledContents(false);
    cacher_pnj();
    cacherBPchoix();
    BP_Start->QWidget::setVisible(true);
    Exp->QWidget::setVisible(false);
}
MainWindow::~MainWindow() {}
