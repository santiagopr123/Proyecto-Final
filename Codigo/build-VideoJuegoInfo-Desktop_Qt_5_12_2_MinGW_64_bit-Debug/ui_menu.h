/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QWidget *centralwidget;
    QPushButton *BotonYaResgistrado;
    QPushButton *BotonMulti;
    QLabel *label;
    QLineEdit *NombreUser;
    QLabel *label_2;
    QLineEdit *Password;
    QPushButton *QuiereSalir;
    QPushButton *BotonRegistrarse;
    QLabel *label_3;
    QPushButton *BotonIns;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName(QString::fromUtf8("Menu"));
        Menu->resize(461, 411);
        centralwidget = new QWidget(Menu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        BotonYaResgistrado = new QPushButton(centralwidget);
        BotonYaResgistrado->setObjectName(QString::fromUtf8("BotonYaResgistrado"));
        BotonYaResgistrado->setGeometry(QRect(180, 230, 99, 23));
        BotonMulti = new QPushButton(centralwidget);
        BotonMulti->setObjectName(QString::fromUtf8("BotonMulti"));
        BotonMulti->setGeometry(QRect(290, 230, 75, 23));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 150, 41, 31));
        NombreUser = new QLineEdit(centralwidget);
        NombreUser->setObjectName(QString::fromUtf8("NombreUser"));
        NombreUser->setGeometry(QRect(170, 150, 133, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(100, 190, 54, 16));
        Password = new QLineEdit(centralwidget);
        Password->setObjectName(QString::fromUtf8("Password"));
        Password->setGeometry(QRect(170, 180, 133, 20));
        QuiereSalir = new QPushButton(centralwidget);
        QuiereSalir->setObjectName(QString::fromUtf8("QuiereSalir"));
        QuiereSalir->setGeometry(QRect(140, 260, 75, 23));
        BotonRegistrarse = new QPushButton(centralwidget);
        BotonRegistrarse->setObjectName(QString::fromUtf8("BotonRegistrarse"));
        BotonRegistrarse->setGeometry(QRect(100, 230, 75, 23));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(110, 20, 341, 111));
        QFont font;
        font.setFamily(QString::fromUtf8("NSimSun"));
        font.setPointSize(20);
        label_3->setFont(font);
        BotonIns = new QPushButton(centralwidget);
        BotonIns->setObjectName(QString::fromUtf8("BotonIns"));
        BotonIns->setGeometry(QRect(250, 260, 75, 23));
        Menu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Menu);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 461, 21));
        Menu->setMenuBar(menubar);
        statusbar = new QStatusBar(Menu);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Menu->setStatusBar(statusbar);

        retranslateUi(Menu);

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QMainWindow *Menu)
    {
        Menu->setWindowTitle(QApplication::translate("Menu", "MainWindow", nullptr));
        BotonYaResgistrado->setText(QApplication::translate("Menu", "Jugador registrado", nullptr));
        BotonMulti->setText(QApplication::translate("Menu", "Multijugador", nullptr));
        label->setText(QApplication::translate("Menu", "Nombre", nullptr));
        NombreUser->setText(QString());
        label_2->setText(QApplication::translate("Menu", "contrase\303\261a", nullptr));
        QuiereSalir->setText(QApplication::translate("Menu", "Salir", nullptr));
        BotonRegistrarse->setText(QApplication::translate("Menu", "Jugar", nullptr));
        label_3->setText(QApplication::translate("Menu", "Alien Invasion Game", nullptr));
        BotonIns->setText(QApplication::translate("Menu", "Instrucciones ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
