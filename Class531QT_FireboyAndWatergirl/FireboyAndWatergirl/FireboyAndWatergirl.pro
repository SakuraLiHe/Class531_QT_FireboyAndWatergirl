QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    game.cpp \
    loseend.cpp \
    main.cpp \
    mainwindow.cpp \
    more.cpp \
    mypushbutton.cpp \
    set.cpp \
    shadewindow.cpp \
    winend.cpp \
    winend2.cpp

HEADERS += \
    game.h \
    loseend.h \
    mainwindow.h \
    more.h \
    mypushbutton.h \
    set.h \
    shadewindow.h \
    winend.h \
    winend2.h

FORMS += \
    game.ui \
    loseend.ui \
    mainwindow.ui \
    winend.ui \
    winend2.ui

TRANSLATIONS += \
    FireboyAndWatergirl_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc
