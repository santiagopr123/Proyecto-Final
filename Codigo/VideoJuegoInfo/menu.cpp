#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent) :QMainWindow(parent), ui(new Ui::Menu)
{
    ui->setupUi(this);

    connect(ui->BotonYaResgistrado,SIGNAL(clicked()),this,SLOT(BotonJugadorYaRegistrado()));
    connect(ui->BotonRegistrarse,SIGNAL(clicked()),this,SLOT(Registro()));
    connect(ui->BotonMulti,SIGNAL(clicked()),this,SLOT(JuegoMultijugador()));
    connect(ui->QuiereSalir,SIGNAL(clicked()),this,SLOT(Salir()));
    connect(ui->BotonIns,SIGNAL(clicked()),this,SLOT(InstrucionesGame()));

}

Menu::~Menu()
{
    delete ui;
}

void Menu::BotonJugadorYaRegistrado()
{
    QString VariableNombre = ui->NombreUser->text();
    QString VariablePassword = ui->Password->text();

    NameUIngresado = VariableNombre.toStdString();
    PasswordIngresado = VariablePassword.toStdString();

    ui->NombreUser->clear();
    ui->Password->clear();

    Login = new GestorInfo(NameUIngresado,PasswordIngresado);
    GetJuego = Login->getStartGame();

    if(GetJuego == true)
    {
        Juego = new VentanaP(Login);
        Juego->setFixedSize(1140,540);
        Juego->show();
        this->hide();
    }
    else
    {
        QMessageBox::critical(this,"Login","Uusuario No encontrado");
    }

}

void Menu::Registro()
{
    QString VariableNombre = ui->NombreUser->text();
    QString VariablePassword = ui->Password->text();

    NameUIngresado = VariableNombre.toStdString();
    PasswordIngresado = VariablePassword.toStdString();

    ui->NombreUser->clear();
    ui->Password->clear();

    Login = new GestorInfo();
    Login->InscribirNuevoJugador(NameUIngresado,PasswordIngresado,"false",1000,0);

    Juego = new VentanaP(Login);
    Juego->setFixedSize(1140,540);
    Juego->show();
    this->hide();

}

void Menu::JuegoMultijugador()
{
    QString VariableNombre = ui->NombreUser->text();
    QString VariablePassword = ui->Password->text();

    NameUIngresado = VariableNombre.toStdString();
    PasswordIngresado = VariablePassword.toStdString();

    ui->NombreUser->clear();
    ui->Password->clear();

    Login = new GestorInfo();
    Login->InscribirNuevoJugador(NameUIngresado,PasswordIngresado,"true",1000,1000);

    Juego = new VentanaP(Login);
    Juego->setFixedSize(1140,540);
    Juego->show();
    this->hide();
}

void Menu::Salir()
{
    exit(1);
}

void Menu::InstrucionesGame()
{
    Ins = new Instrucciones(this);
    Ins->show();
}


