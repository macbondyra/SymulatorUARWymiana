QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialog.cpp \
    dialogonline.cpp \
    main.cpp \
    nadajnik.cpp \
    qcustomplot.cpp \
    symulator.cpp

HEADERS += \
    dialog.h \
    dialogonline.h \
    klasy.h \
    nadajnik.h \
    qcustomplot.h \
    symulator.h

FORMS += \
    dialog.ui \
    dialogonline.ui \
    symulator.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

