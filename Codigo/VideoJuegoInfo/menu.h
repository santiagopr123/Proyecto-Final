#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <string>

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

private:
    Ui::Menu *ui;

    VentanaP *Juego;
    GestorInfo *Login;

    std::string NameUIngresado;
    std::string PasswordIngresado;

    bool GetJuego;

    void ComenzarJuego();

};

#endif // MENU_H
