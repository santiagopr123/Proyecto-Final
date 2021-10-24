#ifndef VENTANAP_H
#define VENTANAP_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QTimer>
#include <QPen>

#include "balamovarmsim.h"
#include "balasimple.h"
#include "enemigointeligente.h"
#include "enemigopendular.h"
#include "vista.h"
#include "personajeprincipal.h"
#include "proyectilesparabolicos.h"
#include "trampolines.h"
#include "enemigoamortiguado.h"
#include "enemigometioritos.h"
#include "door.h"
#include "enemigosimple.h"
#include "enemigomovcircular.h"
#include "boss.h"


QT_BEGIN_NAMESPACE
namespace Ui { class VentanaP; }
QT_END_NAMESPACE

class VentanaP : public QMainWindow
{
    Q_OBJECT

public:
    VentanaP(QWidget *parent = nullptr);
    ~VentanaP();

    void keyPressEvent(QKeyEvent *event);

public slots:

    void Cronometro();

private:
    Ui::VentanaP *ui;

    QGraphicsScene *Ventana_1,*Ventana_2,*Ventana_3;

    Vista *Parametros;
    PersonajePrincipal *Player;
    PersonajePrincipal *Player_1;

    EnemigoPendular *Pendulo;

    ProyectilesParabolicos *Bomb;

    int *Puntaje_Global;
    int punta,punta_2,ContadorCrono,Nivel;
    int VidaGlobal,VidaGlobal_2;
    bool Multiplayer;


    QTimer *Timer_1;


    PersonajePrincipal *ArregloMultiplayer[2];

    //Desde Aqui Variables Segundo Nivel

    EnemigoMeteoritos *EnemigoExplosion;
    Trampolines *Platform;
    EnemigoAmortiguado *ObstaculoEnemy;
    EnemigoInteligente *SmartEnemy;

    EnemigoSimple *Enemy;
    Boss *EnemyBossFinal;
    EnemigoMovCircular *EnemyCir;


    void Nivel1();
    void Nivel2();
    void Nivel3();

    void EscrituraDeDatos();

};
#endif // VENTANAP_H
