/********************************************************************************
** Form generated from reading UI file 'ventanap.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANAP_H
#define UI_VENTANAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VentanaP
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *VentanaP)
    {
        if (VentanaP->objectName().isEmpty())
            VentanaP->setObjectName(QString::fromUtf8("VentanaP"));
        VentanaP->resize(800, 600);
        centralwidget = new QWidget(VentanaP);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        gridLayout->addWidget(graphicsView, 0, 0, 1, 1);

        VentanaP->setCentralWidget(centralwidget);
        menubar = new QMenuBar(VentanaP);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        VentanaP->setMenuBar(menubar);
        statusbar = new QStatusBar(VentanaP);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        VentanaP->setStatusBar(statusbar);

        retranslateUi(VentanaP);

        QMetaObject::connectSlotsByName(VentanaP);
    } // setupUi

    void retranslateUi(QMainWindow *VentanaP)
    {
        VentanaP->setWindowTitle(QApplication::translate("VentanaP", "VentanaP", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VentanaP: public Ui_VentanaP {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANAP_H
