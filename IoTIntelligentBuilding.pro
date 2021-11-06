#-------------------------------------------------
#
# Project created by QtCreator 2021-11-01T11:01:09
#
#-------------------------------------------------

QT += core gui
QT += sql
QT += widgets
QT += core gui multimedia multimediawidgets
QT += qml quick quick-private
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IoTIntelligentBuilding
TEMPLATE = app


SOURCES += main.cpp\
    mainwindow.cpp \
    admlogindlg.cpp \
    reslogindlg.cpp \
    visitlogindlg.cpp \
    admdlg.cpp \
    resdlg.cpp \
    vistdlg.cpp \
    vrviewdlg.cpp \
    resipcheckdlg.cpp \
    myvideo.cpp \
    parkdlg.cpp

HEADERS  += mainwindow.h \
    admlogindlg.h \
    reslogindlg.h \
    visitlogindlg.h \
    admdlg.h \
    resdlg.h \
    vistdlg.h \
    vrviewdlg.h \
    resipcheckdlg.h \
    myvideo.h \
    parkdlg.h

FORMS += mainwindow.ui \
    admlogindlg.ui \
    reslogindlg.ui \
    visitlogindlg.ui \
    admdlg.ui \
    resdlg.ui \
    vistdlg.ui \
    vrviewdlg.ui \
    resipcheckdlg.ui \
    myvideo.ui \
    parkdlg.ui

RESOURCES += \
    image.qrc \
    video.qrc

OTHER_FILES +=
