#include "ventanap.h"
#include "ui_ventanap.h"

VentanaP::VentanaP(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VentanaP)
{
    ui->setupUi(this);

    Timer_1 = new QTimer;

    punta = 0;punta_2 = 0;
    ContadorCrono = 0;
    VidaGlobal = 0;
    Puntaje_Global = &punta;

    //Nivel1();
    //Nivel2();
    //Nivel3();

}

VentanaP::~VentanaP()
{
    delete ui;
    delete Timer_1;
}

void VentanaP::keyPressEvent(QKeyEvent *event)
{
    if(Nivel != 3)
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
    else if(Nivel == 3)
    {
        if(event->key() == Qt::Key_A)
        {
            Player->MoverIzquierda();
        }
        else if(event->key() == Qt::Key_D)
        {
            Player->MoverDerecha();
        }
        else if(event->key() == Qt::Key_Space)
        {
            Player->Disparar();
        }
    }

}

void VentanaP::Nivel1()
{
    Nivel = 1;

    Ventana_1 = new QGraphicsScene();
    ui->graphicsView->setScene(Ventana_1);
    ui->graphicsView->setSceneRect(0,0,1100,500);

    Parametros = new Vista;
    Parametros->setPos(0,35);
    Ventana_1->addItem(Parametros);

    Ventana_1->addLine(QLineF(10,450,1100,450),QPen(Qt::black));

    Player = new PersonajePrincipal(20,20,10,440,0,0,0,0,Ventana_1,Parametros,1);
    Ventana_1->addItem(Player);

    Pendulo = new EnemigoPendular(Ventana_1,Player,Puntaje_Global);
    Ventana_1->addItem(Pendulo);

    connect(Timer_1,SIGNAL(timeout()),this,SLOT(Cronometro()));
    Timer_1->start(1000);

}

void VentanaP::Nivel2()
{
    Nivel = 2;

    Ventana_2 = new QGraphicsScene();
    ui->graphicsView->setScene(Ventana_2);
    ui->graphicsView->setSceneRect(0,0,1100,500);

    Parametros = new Vista(VidaGlobal,punta,true);
    Parametros->setPos(0,35);
    Ventana_2->addItem(Parametros);

    Ventana_2->addLine(QLineF(10,450,1100,450),QPen(Qt::black));

    Player = new PersonajePrincipal(20,20,10,440,0,0,0,0,Ventana_2,Parametros,VidaGlobal,1);
    Ventana_2->addItem(Player);

    Platform = new Trampolines(1050,430);
    Ventana_2->addItem(Platform);

    Platform = new Trampolines(850,230);
    Ventana_2->addItem(Platform);

    Platform = new Trampolines(620,100);
    Ventana_2->addItem(Platform);

    ObstaculoEnemy = new EnemigoAmortiguado(200,230,20);
    Ventana_2->addItem(ObstaculoEnemy);

    ObstaculoEnemy = new EnemigoAmortiguado(700,230,17);
    Ventana_2->addItem(ObstaculoEnemy);

    SmartEnemy = new EnemigoInteligente(10,10,Ventana_2,700,440,Player,Puntaje_Global,1000,720,2);
    Ventana_2->addItem(SmartEnemy);

    EnemigoExplosion = new EnemigoMeteoritos(230,30,230,400,Ventana_2);
    Ventana_2->addItem(EnemigoExplosion);

    EnemigoExplosion = new EnemigoMeteoritos(405,150,405,670,Ventana_2);
    Ventana_2->addItem(EnemigoExplosion);

    connect(Timer_1,SIGNAL(timeout()),this,SLOT(Cronometro()));
    Timer_1->start(1000);

}

void VentanaP::Nivel3()
{
    Nivel = 3;

    Ventana_3 = new QGraphicsScene();
    ui->graphicsView->setScene(Ventana_3);
    ui->graphicsView->setSceneRect(0,0,1100,500);

    Parametros = new Vista(VidaGlobal,punta,true);
    Parametros->setPos(0,35);
    Ventana_3->addItem(Parametros);

    Player = new PersonajePrincipal(20,20,10,440,0,0,0,0,Ventana_3,Parametros,VidaGlobal,0);
    Player->setDeltaPosx(7);
    Ventana_3->addItem(Player);

    connect(Timer_1,SIGNAL(timeout()),this,SLOT(Cronometro()));
    Timer_1->start(1000);

}

void VentanaP::Cronometro()
{
    if(Nivel == 1)
    {
        if(punta > punta_2)
        {
            Parametros->IncreaseScore(punta-punta_2);
            punta_2 = punta;
        }

        static int ContadorBombs = 0;
        if(ContadorCrono <=90 && ContadorCrono >=0)
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
                    Bomb = new ProyectilesParabolicos(1050,0,-Velocidad,0,Ventana_1);
                    Ventana_1->addItem(Bomb);
                }
                else if(Opcion == 2)
                {
                    Bomb = new ProyectilesParabolicos(0,0,Velocidad,0,Ventana_1);
                    Ventana_1->addItem(Bomb);
                }
            }
        }
        else
        {
            Timer_1->stop();
            if(punta > 300)
            {
                VidaGlobal = Player->getVida();
                Ventana_1->clear();
                delete Ventana_1;
                Nivel2();
            }
        }
    }
    else if(Nivel == 2)
    {
        if(punta > punta_2)
        {
            Parametros->IncreaseScore(punta-punta_2);
            punta_2 = punta;
        }

        if(Player->getLevel_2() == true)
        {
            Timer_1->stop();
            VidaGlobal = Player->getVida();
            Ventana_2->clear();
            delete Ventana_2;
            Nivel3();
        }
    }
    else if(Nivel == 3)
    {
        static int ContadorBombs = 0,NumEnemys = 3,TiempoJefeFinal = 0,PasosJefeFinal = 0;
        static bool FlagParaEnemys = false,FlagParaEnemys_2 = false;
        ContadorBombs++;

        if(ContadorBombs%4 == 0 && FlagParaEnemys == false)
        {
            int Opcion = 1+rand()%(3-1);
            int Velocidad = 100+rand()%(141-100);
            if(Opcion == 1)
            {
                Bomb = new ProyectilesParabolicos(1050,400,-Velocidad,50,Ventana_3);
                Ventana_3->addItem(Bomb);
            }
            else if(Opcion == 2)
            {
                Bomb = new ProyectilesParabolicos(0,400,Velocidad,-50,Ventana_3);
                Ventana_3->addItem(Bomb);
            }
        }

        if(ContadorBombs%NumEnemys == 0 && FlagParaEnemys == false)
        {
            int num = 50 + rand()%(1051-50);
            EnemigoSimple *enemy = new EnemigoSimple(40,40,num,0,Ventana_3);
            Ventana_3->addItem(enemy);
        }

        TiempoJefeFinal++;
        if(TiempoJefeFinal == 45)
        {
            FlagParaEnemys = true;

            EnemyBossFinal = new Boss(20,20,500,20,Ventana_3);
            Ventana_3->addItem(EnemyBossFinal);
            EnemyBossFinal->setDeltaDesplazamientoY(0.5);

            FlagParaEnemys_2 = true;
        }

        if(FlagParaEnemys_2 == true)
        {
            PasosJefeFinal++;
            if(PasosJefeFinal < 15)
            {
                EnemyBossFinal->setDeltaDesplazamientoX(0);
                EnemyBossFinal->setDeltaDesplazamientoY(0.5);
            }
            else if(PasosJefeFinal > 15 && PasosJefeFinal < 45)
            {
                EnemyBossFinal->setDeltaDesplazamientoX(-0.5);
                EnemyBossFinal->setDeltaDesplazamientoY(0);
            }
            else if(PasosJefeFinal > 45 && PasosJefeFinal < 90)
            {
                EnemyBossFinal->setDeltaDesplazamientoX(0.5);
                EnemyBossFinal->setDeltaDesplazamientoY(0);
            }
            else if(PasosJefeFinal > 90 && PasosJefeFinal < 105)
            {
                EnemyBossFinal->setDeltaDesplazamientoX(0);
                EnemyBossFinal->setDeltaDesplazamientoY(0.5);
            }
        }
    }
}
