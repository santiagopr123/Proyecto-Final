QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    balamovarmsim.cpp \
    balasimple.cpp \
    enemigoamortiguado.cpp \
    enemigointeligente.cpp \
    enemigopendular.cpp \
    main.cpp \
    personajeprincipal.cpp \
    proyectilesparabolicos.cpp \
    ventanap.cpp \
    vista.cpp

HEADERS += \
    balamovarmsim.h \
    balasimple.h \
    enemigoamortiguado.h \
    enemigointeligente.h \
    enemigopendular.h \
    personajeprincipal.h \
    proyectilesparabolicos.h \
    ventanap.h \
    vista.h

FORMS += \
    ventanap.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
