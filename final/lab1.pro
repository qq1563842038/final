QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calendar.cpp \
    date.cpp \
    main.cpp \
    mainwindow.cpp \
    nomal.cpp \
    programmer.cpp \
    science.cpp \
    transform.cpp \
    transform2.cpp

HEADERS += \
    calendar.h \
    date.h \
    mainwindow.h \
    nomal.h \
    programmer.h \
    science.h \
    transform.h \
    transform2.h

FORMS += \
    calendar.ui \
    date.ui \
    date.ui \
    mainwindow.ui \
    nomal.ui \
    nomal.ui \
    programmer.ui \
    programmer.ui \
    science.ui \
    science.ui \
    transform.ui \
    transform2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
