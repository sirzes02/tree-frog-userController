TARGET = helper
TEMPLATE = lib
CONFIG += shared x86_64
QT += xml qml
QT -= gui
DEFINES += TF_DLL
DESTDIR = ../lib
INCLUDEPATH +=
DEPENDPATH  +=
LIBS +=
MOC_DIR = .obj/
OBJECTS_DIR = .obj/

include(../appbase.pri)

HEADERS += applicationhelper.h
SOURCES += applicationhelper.cpp
HEADERS += uservalidator.h
SOURCES += uservalidator.cpp
HEADERS += loggingvalues.h
