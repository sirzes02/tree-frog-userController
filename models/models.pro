TARGET = model
TEMPLATE = lib
CONFIG += shared x86_64
QT += sql qml
QT -= gui
DEFINES += TF_DLL
DESTDIR = ../lib
INCLUDEPATH += ../helpers
DEPENDPATH  += ../helpers
LIBS += -L../lib -lhelper
MOC_DIR = .obj/
OBJECTS_DIR = .obj/

include(../appbase.pri)
HEADERS += sqlobjects/usersobject.h
HEADERS += objects/users.h
SOURCES += objects/users.cpp
HEADERS += apiusersservice.h
SOURCES += apiusersservice.cpp
