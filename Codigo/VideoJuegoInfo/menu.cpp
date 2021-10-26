#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent) :QMainWindow(parent), ui(new Ui::Menu)
{
    ui->setupUi(this);

    NameUIngresado = "Santiago";
    PasswordIngresado = "123456";
    Login = new GestorInfo(NameUIngresado,PasswordIngresado);
    GetJuego = Login->getStartGame();

    if(GetJuego == true)
    {
        Juego = new VentanaP;
        this->hide();
        Juego->setFixedSize(1140,540);
        Juego->show();
    }

}

Menu::~Menu()
{
    delete ui;
}
