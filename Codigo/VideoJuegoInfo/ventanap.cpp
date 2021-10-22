#include "ventanap.h"
#include "ui_ventanap.h"

VentanaP::VentanaP(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VentanaP)
{
    ui->setupUi(this);

    punta = 0;
    punta_2 = 0;
    Puntaje_Global = &punta;

    Parametros = new Vista();
    Timer_1 = new QTimer;

    //Nivel1();
    Nivel2();

/*
//    Ventana_2 = new QGraphicsScene();
//    ui->graphicsView->setScene(Ventana_2);
//    ui->graphicsView->setSceneRect(0,0,1100,500);

//    Parametros = new Vista();
//    Parametros->setPos(0,35);
//    Ventana_2->addItem(Parametros);

//    Player = new PersonajePrincipal(20,20,10,440,0,0,0,0,Puntaje_Global,Ventana_2,Parametros);
//    Ventana_2->addItem(Player);

//    Pendulo = new EnemigoPendular(Ventana_2,Player);
//    Ventana_2->addItem(Pendulo);

//    Timer_1 = new QTimer;
//    connect(Timer_1,SIGNAL(timeout()),this,SLOT(Cronometro()));
//    Timer_1->start(1000);
*/
}

VentanaP::~VentanaP()
{
    delete ui;
    delete Timer_1;
}

void VentanaP::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A)
    {
        Player->MoverIzquierda();
    }
    else if(event->key() == Qt::Key_D)
    {
        Player->MoverDerecha();
    }
    else if(event->key() == Qt::Key_W)
    {
        if(Player->pos().y()>400)
        {
                Player->MoverArriba();
        }
    }
    else if(event->key() == Qt::Key_Space)
    {
        Player->Disparar();
    }
}

void VentanaP::Cronometro()
{
    if(punta > punta_2)
    {
        Parametros->IncreaseScore(punta-punta_2);
        punta_2 = punta;
        qDebug()<<"entro"<<endl;
    }

    static int ContadorBombs = 0;
    if(ContadorCrono <=45 && ContadorCrono >=0)
    {
        ContadorCrono++;
        Parametros->DecreaseTimeofsurvival();
        ContadorBombs++;
        if(ContadorBombs%3 == 0)
        {
            int Opcion = 1+rand()%(3-1);
            int Velocidad = 40+rand()%(101-40);
            if(Opcion == 1)
            {
                Bomb = new ProyectilesParabolicos(1050,0,-Velocidad,0,Ventana_2);
                Ventana_2->addItem(Bomb);
            }
            else if(Opcion == 2)
            {
                Bomb = new ProyectilesParabolicos(0,0,Velocidad,0,Ventana_2);
                Ventana_2->addItem(Bomb);
            }
        }
    }
    else
    {
        Timer_1->stop();
    }
}

void VentanaP::Nivel1()
{

    Ventana_2 = new QGraphicsScene();
    ui->graphicsView->setScene(Ventana_2);
    ui->graphicsView->setSceneRect(0,0,1100,500);

    Ventana_2->addLine(QLineF(10,450,1100,450),QPen(Qt::black));

    ContadorCrono = 0;
    ContadorProyectilesP = 0;

    //Parametros = new Vista();
    Parametros->setPos(0,35);
    Ventana_2->addItem(Parametros);

    Player = new PersonajePrincipal(20,20,10,440,0,0,0,0,Ventana_2,Parametros);
    Ventana_2->addItem(Player);

    Pendulo = new EnemigoPendular(Ventana_2,Player,Puntaje_Global);
    Ventana_2->addItem(Pendulo);

    connect(Timer_1,SIGNAL(timeout()),this,SLOT(Cronometro()));
    Timer_1->start(1000);

}

void VentanaP::Nivel2()
{

    Ventana_2 = new QGraphicsScene();
    ui->graphicsView->setScene(Ventana_2);
    ui->graphicsView->setSceneRect(0,0,1100,500);

    Ventana_2->addLine(QLineF(10,450,1100,450),QPen(Qt::black));

    Player = new PersonajePrincipal(20,20,10,440,0,0,0,0,Ventana_2,Parametros);
    Ventana_2->addItem(Player);

    Parametros->setPos(0,35);
    Ventana_2->addItem(Parametros);

    Platform = new Trampolines(1050,430);
    Ventana_2->addItem(Platform);

    Platform = new Trampolines(850,230);
    Ventana_2->addItem(Platform);

    Platform = new Trampolines(600,100);
    Ventana_2->addItem(Platform);

    ObstaculoEnemy = new EnemigoAmortiguado(200,230,20);
    Ventana_2->addItem(ObstaculoEnemy);

    ObstaculoEnemy = new EnemigoAmortiguado(700,230,17);
    Ventana_2->addItem(ObstaculoEnemy);

    SmartEnemy = new EnemigoInteligente(10,10,Ventana_2,700,440,Puntaje_Global,1000,720,2);
    Ventana_2->addItem(SmartEnemy);

    EnemigoExplosion = new EnemigoMeteoritos(230,30,230,400,Ventana_2);
    Ventana_2->addItem(EnemigoExplosion);

    EnemigoExplosion = new EnemigoMeteoritos(405,150,405,670,Ventana_2);
    Ventana_2->addItem(EnemigoExplosion);

}

