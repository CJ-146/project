#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Initialisation de la fenêtre et création du layout.
    //------------------------------------------------------------------------------------------------------------
    fenetre = new QWidget;
    layoutCentral = new QGridLayout;

    // Timer pour augmenter l'âge du Tamagochi toutes les 15 secondes
    timer = new QTimer;
    connect(timer, &QTimer::timeout, this, &MainWindow::ChangementJour);
    timer->start(15000); // Toutes les 15 secondes

    // Mise en page
    //------------------------------------------------------------------------------------------------------------

// Ajout de l'image du tamagoshi
    Image = new QLabel; // on ajout le qlabel receptionnant l'image
    QPixmap pixmap(":/Icones/image/lobster3"); // on utilise pixmap pour trouver le chemin de l'image
    Image->setPixmap(pixmap); // on convertie l'image pixmap en widget
    layoutCentral->addWidget(Image); // on affiche l'image


    //------------------------------------------------------------------------------------------------------------
// Ajout des Labels et positionnements
    // Label Age
    Ligne_Age = new QLabel;
    Ligne_Age->setText("Age : 1");
    Ligne_Age->setFont(QFont("Comic Sans MS", 10));
    layoutCentral->addWidget(Ligne_Age, 0, 1);

    // Label Vie
    Ligne_Vie = new QLabel;
    Ligne_Vie->setText("Vie");
    Ligne_Vie->setFont(QFont("Comic Sans MS", 10));
    layoutCentral->addWidget(Ligne_Vie, 1, 1);

    // Label Vie
    Ligne_Faim = new QLabel;
    Ligne_Faim->setText("Faim");
    Ligne_Faim->setFont(QFont("Comic Sans MS", 10));
    layoutCentral->addWidget(Ligne_Faim, 2, 1);

    // Label Vie
    Ligne_Joie = new QLabel;
    Ligne_Joie->setText("Joie");
    Ligne_Joie->setFont(QFont("Comic Sans MS", 10));
    layoutCentral->addWidget(Ligne_Joie, 3, 1);


    //------------------------------------------------------------------------------------------------------------
// Ajout des progress bars
    //Ajout de la progress bar de vie
    Progress_Vie = new QProgressBar;
    Progress_Vie->setValue(5);
    layoutCentral->addWidget(Progress_Vie, 1, 2);

    //Ajout de la progress bar de faim
    Progress_Faim = new QProgressBar;
    Progress_Faim->setValue(5);
    layoutCentral->addWidget(Progress_Faim, 2, 2);

    //Ajout de la progress bar de joie
    Progress_Joie = new QProgressBar;
    Progress_Joie->setValue(5);
    layoutCentral->addWidget(Progress_Joie, 3, 2);


    //------------------------------------------------------------------------------------------------------------
// Ajout des BPs
    //Ajout du BP Soigner
    BP_Soigner = new QPushButton;
    BP_Soigner->setText("Soigner");
    layoutCentral->addWidget(BP_Soigner,4,0);

    //Ajout du BP Nourrir
    BP_Nourrir = new QPushButton;
    BP_Nourrir->setText("Nourrir");
    layoutCentral->addWidget(BP_Nourrir,4,1);

    //Ajout du BP Jouer
    BP_Jouer = new QPushButton;
    BP_Jouer->setText("Jouer");
    layoutCentral->addWidget(BP_Jouer,4,2);



    // Affectation du layout à la fenêtre et affectation de la fenêtre à la zone centrale de la MainWindow
    //------------------------------------------------------------------------------------------------------------
    fenetre->setLayout(layoutCentral);
    setCentralWidget(fenetre);

    // Ajout d'un menu
    //------------------------------------------------------------------------------------------------------------
    QMenu *menuFichier = menuBar()->addMenu("Fichier");
    QAction *actionSoigner = new QAction("Soigner", this);
    QAction *actionNourrir = new QAction("Nourrir", this);
    QAction *actionJouer = new QAction("Jouer", this);
    QAction *actionQuitter = new QAction("Quitter", this);
    menuFichier->addAction(actionSoigner);
    menuFichier->addAction(actionNourrir);
    menuFichier->addAction(actionJouer);
    menuFichier->addAction(actionQuitter);

    QMenu *menuTest = menuBar()->addMenu("Test");
    QAction *actionForcageJour = new QAction("Forçage jour", this);
    menuTest->addAction(actionForcageJour);

    // Ajout d'une tool bar (bar d'outil mobile )
    //------------------------------------------------------------------------------------------------------------
    QToolBar *toolBarFichier = addToolBar("Action");
    actionSoigner->setIcon(QIcon(":/Icones/image/seringue2"));
    toolBarFichier->addAction(actionSoigner);
    actionNourrir->setIcon(QIcon(":/Icones/image/etoile1"));
    toolBarFichier->addAction(actionNourrir);
    actionJouer->setIcon(QIcon(":/Icones/image/lobster7"));
    toolBarFichier->addAction(actionJouer);
    actionQuitter->setIcon(QIcon(":/Icones/image/lobster5"));
    toolBarFichier->addAction(actionQuitter);

    // Gestion des actions :
    //------------------------------------------------------------------------------------------------------------
    // actions du menu et toolbar
    QObject::connect(actionSoigner,SIGNAL(triggered()),this,SLOT(augmentevaleur_Vie()));
    QObject::connect(actionNourrir,SIGNAL(triggered()),this,SLOT(augmentevaleur_Faim()));
    QObject::connect(actionJouer,SIGNAL(triggered()),this,SLOT(augmentevaleur_Joie()));
    QObject::connect(actionQuitter,SIGNAL(triggered()),this,SLOT(close()));
    QObject::connect(actionForcageJour,SIGNAL(triggered()),this,SLOT(ChangementJour()));
    // actions des BPs
    QObject::connect(BP_Soigner,SIGNAL(pressed()),this,SLOT(augmentevaleur_Vie()));
    QObject::connect(BP_Nourrir,SIGNAL(pressed()),this,SLOT(augmentevaleur_Faim()));
    QObject::connect(BP_Jouer,SIGNAL(pressed()),this,SLOT(augmentevaleur_Joie()));
}

    //------------------------------------------------------------------------------------------------------------
void MainWindow::augmentevaleur_Vie(){
    if (Progress_Vie->value()>50){
        Progress_Vie->setValue(100);
    }
    Progress_Vie->setValue(Progress_Vie->value()+50);
}
void MainWindow::augmentevaleur_Faim(){
    if (Progress_Faim->value()>80){
        Progress_Faim->setValue(100);
    }
    Progress_Faim->setValue(Progress_Faim->value()+20);
}
void MainWindow::augmentevaleur_Joie(){
    if (Progress_Joie->value()>90){
        Progress_Joie->setValue(100);
    }
    Progress_Joie->setValue(Progress_Joie->value()+10);
}
void MainWindow::ChangementJour(){
    // mise à 10% de sa jauge de faim
    if (Progress_Faim->value()>10){
        Progress_Faim->setValue(10);
    }
    // évènement aléatoire
    int event = rand() % 3 + 1;
    switch (event){
    case 2:
        if (Progress_Vie->value()<50){
            Progress_Vie->setValue(0);
        }
        Progress_Vie->setValue(Progress_Vie->value()-50);
        break;
    case 3:
        if (Progress_Joie->value()<50){
            Progress_Joie->setValue(0);
        }
        Progress_Joie->setValue(Progress_Joie->value()-50);
        break;
    }
    YouDied();
    static int Age_int=1; // pour que l'age commence à 1
    Age_int++; // l'age augmente de 1
    std::string Age_s = std::to_string(Age_int); // convertie en string
    QString Age_Qs = QString::fromStdString(Age_s); // convertie en QString
    Ligne_Age->setText("Age : "+Age_Qs); // on affiche l'age convertie en QString
}

void MainWindow::YouDied(){
    if (Progress_Vie->value()<=0 || Progress_Joie->value()<=0){
        // Action de quitter le layout principal pour le layout de fin de jeu
        layoutFinDeJeu = new QGridLayout;
        fenetredefin = new QWidget;
        fenetredefin->setLayout(layoutFinDeJeu);
        setCentralWidget(fenetredefin);

        Image = new QLabel;
        QPixmap pixmap(":/Icones/image/YouDied1");
        Image->setPixmap(pixmap);
        layoutFinDeJeu->addWidget(Image);
    }
}

MainWindow::~MainWindow()
{
}