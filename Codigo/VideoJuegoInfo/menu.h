#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <string>
#include <QDebug>

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
    void on_pushButton_clicked();

private:
    Ui::Menu *ui;

    VentanaP *Juego;
    GestorInfo *Login;

    std::string NameUIngresado;
    std::string PasswordIngresado;
    bool Multijugador;

    bool GetJuego;

    void cerrar();
};

#endif // MENU_H
