#include "ventanap.h"
#include "ui_ventanap.h"
/*
VentanaP::VentanaP(QWidget *parent): QMainWindow(parent),ui(new Ui::VentanaP)
{
    ui->setupUi(this);

    Timer_1 = new QTimer;

    Puntaje = 0;Puntaje_2 = 0;
    VidaGlobal = 0;VidaGlobal_2 = 0;
    Puntaje_Global = &Puntaje;
    ContadorCrono = 0;

    NombreU = "Santiago";
    ClaveU = "123456";

    //Multiplayer = true;
    Multiplayer = false;

    //Nivel1();
    //Nivel2();
    //Nivel3();


}
*/
VentanaP::VentanaP(GestorInfo *GestorAux ,QWidget *parent): QMainWindow(parent),ui(new Ui::VentanaP)
{
    ui->setupUi(this);

    SendInformation = GestorAux;
    Timer_1 = new QTimer;

    NombreU = SendInformation->getNameU();
    ClaveU = SendInformation->getPassword();

    Nivel = SendInformation->getLevel();
    Multiplayer = SendInformation->getMultiP();

    if(Nivel == 1)
    {
        Puntaje = 0;Puntaje_2 = 0;
        VidaGlobal = 0;VidaGlobal_2 = 0;
        Puntaje_Global = &Puntaje;
        ContadorCrono = 0;//pasar a static en la funcion cronometro

        Nivel1();
    }
    else if(Nivel == 2)
    {

        Puntaje = SendInformation->getScore();Puntaje_2 = SendInformation->getScore();
        VidaGlobal = SendInformation->getHealthFPlayer();VidaGlobal_2 = SendInformation->getHealthSPlayer();
        Puntaje_Global = &Puntaje;

        Nivel2();
    }
    else if(Nivel == 3)
    {
        Puntaje = SendInformation->getScore();Puntaje_2 = SendInformation->getScore();
        VidaGlobal = SendInformation->getHealthFPlayer();VidaGlobal_2 = SendInformation->getHealthSPlayer();
        Puntaje_Global = &Puntaje;

        Nivel3();
    }

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
            if(Player->pos().y()>415)
            {
                Player->MoverArriba();
            }
        }
        else if(event->key() == Qt::Key_C)
        {
            Player->DispararDerecha();
        }
        else if(event->key() == Qt::Key_X)
        {
            Player->DispararIzquierda();
        }

        if(Multiplayer == true)
        {
            if(event->key() == Qt::Key_J)
            {
                Player_2->MoverIzquierda();
            }
            else if(event->key() == Qt::Key_L)
            {
                Player_2->MoverDerecha();
            }
            else if(event->key() == Qt::Key_I)
            {
                if(Player_2->pos().y()>415)
                {
                    Player_2->MoverArriba();
                }
            }
            else if(event->key() == Qt::Key_M)
            {
                Player_2->DispararDerecha();
            }
            else if(event->key() == Qt::Key_N)
            {
                Player_2->DispararIzquierda();
            }
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
        else if(event->key() == Qt::Key_X)
        {
            Player->DisparaArriba();
        }

        if(Multiplayer == true)
        {
            if(event->key() == Qt::Key_J)
            {
                Player_2->MoverIzquierda();
            }
            else if(event->key() == Qt::Key_L)
            {
                Player_2->MoverDerecha();
            }
            else if(event->key() == Qt::Key_M)
            {
                Player_2->DisparaArriba();
            }
        }
    }
}

void VentanaP::Nivel1()
{
    Nivel = 1;

    Ventana_1 = new QGraphicsScene();
    ui->graphicsView->setScene(Ventana_1);
    ui->graphicsView->setSceneRect(0,0,1100,500);

    Ventana_1->addLine(QLineF(10,450,1100,450),QPen(Qt::black));

    if(Multiplayer == true)
    {
        Parametros = new Vista(true);
        Parametros->setPos(0,35);
        Ventana_1->addItem(Parametros);

        Player = new PersonajePrincipal(20,20,10,440,0,0,0,0,Ventana_1,Parametros,0);
        Ventana_1->addItem(Player);

        Player_2 = new PersonajePrincipal(20,20,35,440,0,0,0,0,Ventana_1,Parametros,1);
        Ventana_1->addItem(Player_2);

        //SendInformation->ReescribirInformacion(NombreU,ClaveU,true,Player->getVida(),Player_2->getVida(),Puntaje,1);

        Pendulo = new EnemigoPendular(Ventana_1,Player,Player_2,Puntaje_Global);
        Ventana_1->addItem(Pendulo);
    }
    else
    {
        Parametros = new Vista(false);
        Parametros->setPos(0,35);
        Ventana_1->addItem(Parametros);

        Player = new PersonajePrincipal(20,20,10,440,0,0,0,0,Ventana_1,Parametros,0);
        Ventana_1->addItem(Player);

        //SendInformation->ReescribirInformacion(NombreU,ClaveU,false,Player->getVida(),0,Puntaje,1);

        Pendulo = new EnemigoPendular(Ventana_1,Player,Puntaje_Global);
        Ventana_1->addItem(Pendulo);
    }

    connect(Timer_1,SIGNAL(timeout()),this,SLOT(Cronometro()));
    Timer_1->start(1000);
}

void VentanaP::Nivel2()
{
    Nivel = 2;

    Ventana_2 = new QGraphicsScene();
    ui->graphicsView->setScene(Ventana_2);
    ui->graphicsView->setSceneRect(0,0,1100,500);

    Ventana_2->addLine(QLineF(10,450,1100,450),QPen(Qt::black));

    if(Multiplayer == true)
    {
        Parametros = new Vista(VidaGlobal,VidaGlobal_2,Puntaje,true);
        Parametros->setPos(0,35);
        Ventana_2->addItem(Parametros);

        Player = new PersonajePrincipal(20,20,10,440,0,0,0,0,Ventana_2,Parametros,VidaGlobal,0);
        Ventana_2->addItem(Player);

        Player_2 = new PersonajePrincipal(20,20,35,440,0,0,0,0,Ventana_2,Parametros,VidaGlobal_2,1);
        Ventana_2->addItem(Player_2);

        //SendInformation->ReescribirInformacion(NombreU,ClaveU,true,Player->getVida(),Player_2->getVida(),Puntaje,Nivel);
    }
    else if(Multiplayer == false)
    {
        Parametros = new Vista(VidaGlobal,VidaGlobal_2,Puntaje,false);
        Parametros->setPos(0,35);
        Ventana_2->addItem(Parametros);

        Player = new PersonajePrincipal(20,20,10,440,0,0,0,0,Ventana_2,Parametros,VidaGlobal,0);
        Ventana_2->addItem(Player);

        //SendInformation->ReescribirInformacion(NombreU,ClaveU,false,Player->getVida(),0,Puntaje,Nivel);
    }

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

    if(Multiplayer == true)
    {
        Parametros = new Vista(VidaGlobal,VidaGlobal_2,Puntaje,true);
        Parametros->setPos(0,35);
        Ventana_3->addItem(Parametros);

        Player = new PersonajePrincipal(20,20,10,440,0,0,0,0,Ventana_3,Parametros,VidaGlobal,0);
        Player->setDeltaPosx(7);
        Ventana_3->addItem(Player);

        Player_2 = new PersonajePrincipal(20,20,35,440,0,0,0,0,Ventana_3,Parametros,VidaGlobal_2,1);
        Player_2->setDeltaPosx(7);
        Ventana_3->addItem(Player_2);

        //SendInformation->ReescribirInformacion(NombreU,ClaveU,true,Player->getVida(),Player_2->getVida(),Puntaje,Nivel);
    }
    else if(Multiplayer == false)
    {
        Parametros = new Vista(VidaGlobal,VidaGlobal_2,Puntaje,false);
        Parametros->setPos(0,35);
        Ventana_3->addItem(Parametros);

        Player = new PersonajePrincipal(20,20,10,440,0,0,0,0,Ventana_3,Parametros,VidaGlobal,0);
        Player->setDeltaPosx(7);
        Ventana_3->addItem(Player);

        //SendInformation->ReescribirInformacion(NombreU,ClaveU,false,Player->getVida(),0,Puntaje,Nivel);
    }

    connect(Timer_1,SIGNAL(timeout()),this,SLOT(Cronometro()));
    Timer_1->start(1000);

}

void VentanaP::Cronometro()
{
    if(Nivel == 1)
    {
        static int ContadorBombsL1 = 0;

        if(Puntaje > Puntaje_2)
        {
            Parametros->IncreaseScore(Puntaje-Puntaje_2);
            Puntaje_2 = Puntaje;
        }

        if(Multiplayer == true)
        {
            if(Player->getVida() < 0 || Player_2->getVida() < 0)
            {
                Timer_1->stop();
                Ventana_1->clear();
                delete Ventana_1;
                QMessageBox::information(this,"¡Perdiste!","vuelve a intertarlo");
                this->hide();
            }
        }
        else
        {
            if(Player->getVida() < 0)
            {
                Timer_1->stop();
                Ventana_1->clear();
                delete Ventana_1;
                QMessageBox::information(this,"¡Perdiste!","vuelve a intertarlo");
                this->hide();
            }
        }


        if(ContadorCrono <=90 && ContadorCrono >=0 )
        {
            ContadorCrono++;
            Parametros->DecreaseTimeofsurvival();

            ContadorBombsL1++;
            if(ContadorBombsL1%3 == 0)
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

            if(Puntaje > 300 && Multiplayer == false)
            {
                Timer_1->stop();
                VidaGlobal = Player->getVida();
                Ventana_1->clear();
                delete Ventana_1;
                Nivel2();
            }
            else if(Puntaje > 500 && Multiplayer == true)
            {
                Timer_1->stop();
                VidaGlobal = Player->getVida();
                VidaGlobal_2 = Player_2->getVida();
                Ventana_1->clear();
                delete Ventana_1;
                Nivel2();
            }
        }
    }
    else if(Nivel == 2)
    {
        if(Puntaje > Puntaje_2)
        {
            Parametros->IncreaseScore(Puntaje-Puntaje_2);
            Puntaje_2 = Puntaje;
        }

        if(Multiplayer == true)
        {
            if(Player->getLevel_2() == true || Player_2->getLevel_2() == true )
            {
                Timer_1->stop();
                VidaGlobal = Player->getVida();
                VidaGlobal_2 = Player_2->getVida();
                Ventana_2->clear();
                delete Ventana_2;
                Nivel3();
            }

            if(Player->getVida() < 0 || Player_2->getVida() < 0)
            {
                Timer_1->stop();
                QMessageBox::information(this,"¡Perdiste!","vuelve a intertarlo");
                this->hide();
            }
        }
        else if(Multiplayer == false)
        {
            if(Player->getLevel_2() == true)
            {
                Timer_1->stop();
                VidaGlobal = Player->getVida();
                Ventana_2->clear();
                delete Ventana_2;
                Nivel3();
            }

            if(Player->getVida() < 0)
            {
                Timer_1->stop();
                QMessageBox::information(this,"¡Perdiste!","vuelve a intertarlo");
                this->hide();
            }
        }


    }
    else if(Nivel == 3)
    {
        static int ContadorBombsL3 = 0,NumEnemys = 4,TiempoJefeFinal = 0,PasosJefeFinal = 0;
        static bool FlagParaEnemys = false,FlagParaEnemys_2 = false;

        if(Puntaje > Puntaje_2)
        {
            Parametros->IncreaseScore(Puntaje-Puntaje_2);
            Puntaje_2 = Puntaje;
        }

        ContadorBombsL3++;
        if(ContadorBombsL3%5 == 0 && FlagParaEnemys == false)
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

        if(ContadorBombsL3%NumEnemys == 0 && FlagParaEnemys == false)
        {
            int num = 50 + rand()%(1051-50);
            EnemigoSimple *enemy = new EnemigoSimple(40,40,num,0,Ventana_3,Puntaje_Global);
            Ventana_3->addItem(enemy);
        }

        TiempoJefeFinal++;
        if(TiempoJefeFinal == 45)
        {
            FlagParaEnemys = true;
            FlagParaEnemys_2 = true;

            ParametrosBoss = new Vista;
            EnemyBossFinal = new Boss(20,20,500,20,Ventana_3,ParametrosBoss);
            Ventana_3->addItem(EnemyBossFinal);
            EnemyBossFinal->setDeltaDesplazamientoY(0.5);
            ParametrosBoss->setPos(930,35);
            Ventana_3->addItem(ParametrosBoss);
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

            if(EnemyBossFinal->getVida() < 0)
            {
               Timer_1->stop();
               QMessageBox::information(this,"¡En Horabuena!","Ganaste");
               this->hide();
            }
            else if(EnemyBossFinal->pos().y() > 450)
            {
                Timer_1->stop();
                QMessageBox::information(this,"¡Perdiste!","vuelve a intertarlo");
                this->hide();
            }
        }

    }
}
