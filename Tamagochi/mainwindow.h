#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qgridlayout.h"
#include <QMainWindow>
#include <QLineEdit>
#include <QProgressBar>
#include <QPushButton>
#include <QLabel>
#include <QMenuBar>
#include <QToolBar>
#include <QPixmap>
#include <QTimer>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void augmentevaleur_Vie();
    void augmentevaleur_Faim();
    void augmentevaleur_Joie();
    void ChangementJour();
    void YouDied();
private:
    QProgressBar *Progress_Vie,*Progress_Faim,*Progress_Joie;
    QPushButton *BP_Soigner,*BP_Nourrir,*BP_Jouer;
    QLabel *Ligne_Age,*Ligne_Vie,*Ligne_Faim,*Ligne_Joie,*Image;
    QTimer *timer;
    QGridLayout *layoutFinDeJeu,*layoutCentral;
    QWidget *fenetre,*fenetredefin;
};
#endif // MAINWINDOW_H
