#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <string>
#include <QDebug>
#include <QMessageBox>

#include "ventanap.h"
#include "gestorinfo.h"


namespace Ui {
class Menu;
}

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void BotonJugadorYaRegistrado();
    void Registro();
    void JuegoMultijugador();
    void Salir();

private:
    Ui::Menu *ui;

    VentanaP *Juego;
    GestorInfo *Login;

    std::string NameUIngresado;
    std::string PasswordIngresado;
    bool Multijugador;

    bool GetJuego;

};


#endif // MENU_H
