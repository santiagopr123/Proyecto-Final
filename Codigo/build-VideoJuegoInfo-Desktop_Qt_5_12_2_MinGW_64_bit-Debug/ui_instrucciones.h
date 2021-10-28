/********************************************************************************
** Form generated from reading UI file 'instrucciones.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSTRUCCIONES_H
#define UI_INSTRUCCIONES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Instrucciones
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QPushButton *SalirIns;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Instrucciones)
    {
        if (Instrucciones->objectName().isEmpty())
            Instrucciones->setObjectName(QString::fromUtf8("Instrucciones"));
        Instrucciones->resize(800, 600);
        centralwidget = new QWidget(Instrucciones);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 10, 331, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("Sitka Text"));
        font.setPointSize(14);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 120, 91, 41));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 150, 701, 41));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 180, 531, 21));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 210, 701, 16));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(40, 230, 281, 21));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(30, 260, 701, 16));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(30, 300, 121, 16));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(30, 320, 761, 16));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(30, 340, 751, 16));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(30, 360, 751, 16));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(30, 380, 181, 16));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(30, 410, 751, 16));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(30, 430, 741, 16));
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(30, 450, 711, 16));
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(30, 480, 701, 16));
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(50, 90, 731, 16));
        SalirIns = new QPushButton(centralwidget);
        SalirIns->setObjectName(QString::fromUtf8("SalirIns"));
        SalirIns->setGeometry(QRect(310, 510, 75, 23));
        Instrucciones->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Instrucciones);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        Instrucciones->setMenuBar(menubar);
        statusbar = new QStatusBar(Instrucciones);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Instrucciones->setStatusBar(statusbar);

        retranslateUi(Instrucciones);

        QMetaObject::connectSlotsByName(Instrucciones);
    } // setupUi

    void retranslateUi(QMainWindow *Instrucciones)
    {
        Instrucciones->setWindowTitle(QApplication::translate("Instrucciones", "MainWindow", nullptr));
        label->setText(QApplication::translate("Instrucciones", "Instrucciones y consideraciones", nullptr));
        label_2->setText(QApplication::translate("Instrucciones", "-Solo un jugador: ", nullptr));
        label_3->setText(QApplication::translate("Instrucciones", "1) En el caso de que sea solo un jugador podra mover a la izquierda con la letra A, hacia la derecha con la letra D y hacia arriba con la letra W.", nullptr));
        label_4->setText(QApplication::translate("Instrucciones", " Tambien podra dispara, mas especificamente hacia la derecha con la letra C y hacia la izquierda con la letra X", nullptr));
        label_5->setText(QApplication::translate("Instrucciones", "2) en el caso de que se encuentre en el ultimo nivel, sobre naves espaciles solo se podra mover hacia la derecha con la letra D y hacia la izquierda", nullptr));
        label_6->setText(QApplication::translate("Instrucciones", "con la letra A, asi mismo solo podra disparar con la letra X", nullptr));
        label_7->setText(QApplication::translate("Instrucciones", "3) Cada vez que pase de nivel, la partida se guardara sola", nullptr));
        label_8->setText(QApplication::translate("Instrucciones", "-Multijugador:", nullptr));
        label_9->setText(QApplication::translate("Instrucciones", "1) En el caso de que sea multijugador, el primer jugador  podra mover a la izquierda con la letra A, hacia la derecha con la letra D  y hacia arriba con la letra W.", nullptr));
        label_10->setText(QApplication::translate("Instrucciones", " Tambien podra dispara, mas especificamente hacia la derecha con la letra C y hacia la izquierda con la letra X. En el caso del segundo personaje se podra", nullptr));
        label_11->setText(QApplication::translate("Instrucciones", " mover hacia arriba con la letra I, hacia la derecha con la letra L y hacia la izquierda con la letra J, Ademas disparara hacia la izquierda con la letra N y ", nullptr));
        label_12->setText(QApplication::translate("Instrucciones", "y hacia la derecha con la letra N.", nullptr));
        label_13->setText(QApplication::translate("Instrucciones", "2)en el caso de que se encuentre en el ultimo nivel, sobre naves espaciles el primer jugador solo  se podra mover hacia la derecha con la letra D", nullptr));
        label_14->setText(QApplication::translate("Instrucciones", " hacia la izquierda con la letra A, para disparar solo con la letra X. Respeto al Segundo Jugador soo podra moverse a la izquierda con la letra J y a la ", nullptr));
        label_15->setText(QApplication::translate("Instrucciones", "derecha con la letra L, para disparar solo con la letra M", nullptr));
        label_16->setText(QApplication::translate("Instrucciones", "3) Cada vez que pase de nivel, la partida se guardara sola", nullptr));
        label_17->setText(QApplication::translate("Instrucciones", "Bienvenido a alien invasion game,podras divertirte eliminando enemigos y esuivando obstaculos, llega al ultimo nivel para ganar, \302\241EXITOS!", nullptr));
        SalirIns->setText(QApplication::translate("Instrucciones", "salir", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Instrucciones: public Ui_Instrucciones {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSTRUCCIONES_H
