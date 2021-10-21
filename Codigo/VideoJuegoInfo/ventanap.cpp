#include "ventanap.h"
#include "ui_ventanap.h"

VentanaP::VentanaP(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::VentanaP)
{
    ui->setupUi(this);

    punta = 0;
    punta_2 = punta;
    Puntaje_Global = &punta;

    Ventana_2 = new QGraphicsScene();
    ui->graphicsView->setScene(Ventana_2);
    ui->graphicsView->setSceneRect(0,0,1100,500);

    Parametros = new Vista();
    Parametros->setPos(0,35);
    Ventana_2->addItem(Parametros);

    Player = new PersonajePrincipal(20,20,10,440,0,0,0,0,Puntaje_Global,Ventana_2,Parametros);
    Ventana_2->addItem(Player);

    Pendulo = new EnemigoPendular(Ventana_2,Player);
    Ventana_2->addItem(Pendulo);
}

VentanaP::~VentanaP()
{
    delete ui;
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

