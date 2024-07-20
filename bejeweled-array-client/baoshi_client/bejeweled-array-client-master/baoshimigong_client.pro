QT +=   core gui
QT +=   sql
QT +=   network
QT +=   widgets
QT += multimedia multimediawidgets
CONFIG+=resources_big

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    animation.cpp \
    dialog.cpp \
    form.cpp \
    jewel.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    play.cpp \
    port.cpp

HEADERS += \
    animation.h \
    dialog.h \
    form.h \
    jewel.h \
    mainwindow.h \
    menu.h \
    play.h \
    port.h

FORMS += \
    dialog.ui \
    form.ui \
    mainwindow.ui \
    menu.ui \
    play.ui \
    port.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    iamge.qrc \
    icon.qrc \
    music.qrc
