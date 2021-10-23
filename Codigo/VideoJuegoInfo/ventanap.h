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

    QGraphicsScene *Ventana_2;

    Vista *Parametros;
    PersonajePrincipal *Player;

    EnemigoPendular *Pendulo;

    ProyectilesParabolicos *Bomb;

    int *Puntaje_Global;
    int punta,punta_2,ContadorCrono,ContadorProyectilesP,Nivel;

    QTimer *Timer_1;




    //Desde Aqui Variables Segundo Nivel

    EnemigoMeteoritos *EnemigoExplosion;
    Trampolines *Platform;
    EnemigoAmortiguado *ObstaculoEnemy;
    EnemigoInteligente *SmartEnemy;

    EnemigoSimple *Enemy;


    void Nivel1();
    void Nivel2();
    void Nivel3();

};
#endif // VENTANAP_H
