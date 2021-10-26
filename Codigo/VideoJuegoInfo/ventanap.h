#ifndef VENTANAP_H
#define VENTANAP_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QTimer>
#include <QMessageBox>
#include <QPen>
#include <fstream>
#include <QDebug>


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
#include "gestorinfo.h"

#include <string>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class VentanaP; }
QT_END_NAMESPACE

class VentanaP : public QMainWindow
{
    Q_OBJECT

public:
    VentanaP(QWidget *parent = nullptr);
    VentanaP(GestorInfo *GestorAux, QWidget *parent = nullptr);
    ~VentanaP();

    void keyPressEvent(QKeyEvent *event);

public slots:

    void Cronometro();

private:
    Ui::VentanaP *ui;

    std::string NombreU,ClaveU;

    QGraphicsScene *Ventana_1,*Ventana_2,*Ventana_3;
    PersonajePrincipal *Player,*Player_2;

    EnemigoMeteoritos *EnemigoExplosion;
    EnemigoAmortiguado *ObstaculoEnemy;
    Vista *Parametros,*ParametrosBoss;
    EnemigoInteligente *SmartEnemy;
    ProyectilesParabolicos *Bomb;
    EnemigoMovCircular *EnemyCir;
    EnemigoPendular *Pendulo;
    Trampolines *Platform;
    EnemigoSimple *Enemy;
    Boss *EnemyBossFinal;
    QTimer *Timer_1;

    GestorInfo *SendInformation;

    int Puntaje,Puntaje_2,ContadorCrono,Nivel;
    double VidaGlobal,VidaGlobal_2;
    int *Puntaje_Global;   
    bool Multiplayer,Final,MandarInfo;

    //Metodos

    void Nivel1();
    void Nivel2();
    void Nivel3();


};
#endif // VENTANAP_H
