#ifndef INSTRUCCIONES_H
#define INSTRUCCIONES_H

#include <QMainWindow>

namespace Ui {
class Instrucciones;
}

class Instrucciones : public QMainWindow
{
    Q_OBJECT

public:
    explicit Instrucciones(QWidget *parent = nullptr);
    ~Instrucciones();

private:
    Ui::Instrucciones *ui;

private slots:
    void Salir();
};

#endif // INSTRUCCIONES_H
