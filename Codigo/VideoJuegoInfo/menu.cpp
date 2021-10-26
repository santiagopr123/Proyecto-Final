#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent) :QMainWindow(parent), ui(new Ui::Menu)
{
    ui->setupUi(this);

    NameUIngresado = "Santiago";
    PasswordIngresado = "123456";
    Multijugador = false;
    Login = new GestorInfo(NameUIngresado,PasswordIngresado);

}

Menu::~Menu()
{
    delete ui;
}

void Menu::cerrar()
{

    GetJuego = Login->getStartGame();
    if(GetJuego == true)
    {
        Juego = new VentanaP(Login);
        Juego->show();
        this->hide();
    }
    else
    {
        this->hide();
    }

}

void Menu::on_pushButton_clicked()
{
    cerrar();
}
