QT       += core gui sql

CONFIG += c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SchoolDataBase
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS Q_COMPILER_INITIALIZER_LISTS

SOURCES += \
    main.cpp \
    Data/DAO/AdministratorsDAO.cpp \
    Data/Entity/Parent.cpp \
    Data/Entity/Pupil.cpp \
    Utils/DataBase.cpp \
    Views/Forms/LoginForm.cpp \
    Views/Forms/MainForm.cpp \
    Data/Service/AdministratorsService.cpp \
    Data/DAO/PupilsDAO.cpp \
    Views/Forms/MainFormPageSettings.cpp \
    Data/Entity/Employe.cpp \
    Data/DAO/EmployeesDAO.cpp \
    Data/Service/EmployeesService.cpp \
    Data/DAO/ProfessionsDAO.cpp \
    Data/DAO/PredmetsDAO.cpp \
    Views/Forms/MainFormPageEmployees.cpp \
    Views/Dialogs/AddingEmployeDialog.cpp

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
    Exceptions/AdministratorNotFound.h \
    Data/DAO/PupilsDAO.h \
    Views/Forms/MainFormPageSettings.h \
    Data/Entity/Employe.h \
    Data/DAO/EmployeesDAO.h \
    Data/DAO/IEmployeesDAO.h \
    Exceptions/EmployeNotFound.h \
    Data/Service/IEmployeesService.h \
    Data/Service/EmployeesService.h \
    Data/DAO/ProfessionsDAO.h \
    Data/DAO/IPredmetsDAO.h \
    Data/DAO/PredmetsDAO.h \
    Views/Forms/MainFormPageEmployees.h \
    Views/Dialogs/AddingEmployeDialog.h

FORMS += \
    Views/Forms/LogInForm.ui \
    Views/Forms/MainForm.ui \
    Views/Dialogs/AddingEmployeDialog.ui

RESOURCES += \
    Resources/img.qrc
