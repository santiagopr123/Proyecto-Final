#include "instrucciones.h"
#include "ui_instrucciones.h"

Instrucciones::Instrucciones(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Instrucciones)
{
    ui->setupUi(this);

    connect(ui->SalirIns,SIGNAL(clicked()),this,SLOT(Salir()));
}

Instrucciones::~Instrucciones()
{
    delete ui;
}

void Instrucciones::Salir()
{
    this->hide();
}
