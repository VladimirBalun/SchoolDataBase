QT       += core gui sql

CONFIG   += console

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SchoolDataBase
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    main.cpp \
    Data/DAO/AdministratorsDAO.cpp \
    Data/Entity/Parent.cpp \
    Data/Entity/Pupil.cpp \
    Utils/DataBase.cpp \
    Views/Forms/LoginForm.cpp \
    Views/Forms/MainForm.cpp \
    Data/Service/AdministratorsService.cpp

HEADERS += \
    Exceptions/NotWorkingRequest.h \
    Data/DAO/AdministratorsDAO.h \
    Data/DAO/IAdministratorsDAO.h \
    Data/DAO/IClassesDAO.h \
    Data/DAO/IProfessionsDAO.h \
    Data/DAO/IPupilsDAO.h \
    Data/Entity/Parent.h \
    Data/Entity/Pupil.h \
    Utils/DataBase.h \
    Views/Forms/LoginForm.h \
    Views/Forms/MainForm.h \
    Data/Service/IAdministratorsService.h \
    Data/Service/AdministratorsService.h \
    Exceptions/AdministratorNotFound.h

FORMS += \
    Views/Forms/LogInForm.ui \
    Views/Forms/MainForm.ui
