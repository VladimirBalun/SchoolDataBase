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
    Views/Dialogs/AddingEmployeDialog.cpp \
    Views/Dialogs/AddingPupilDialog.cpp \
    Views/Dialogs/AddingParentDialog.cpp \
    Data/Service/ProfessionsService.cpp \
    Utils/Logger.cpp \
    Views/Forms/MainFormPage.cpp \
    Data/Entity/Teacher.cpp \
    Views/Forms/MainFormPagePupils.cpp \
    Data/Service/PupilsService.cpp \
    Data/DAO/ClassesDAO.cpp \
    Data/Service/ClassesService.cpp \
    Data/DAO/ParentsDAO.cpp \
    Data/Service/ParentsService.cpp \
    Data/DAO/TeachersDAO.cpp \
    Data/Service/TeachersService.cpp \
    Views/Forms/MainFormPageTeachers.cpp

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
    Data/Service/IEmployeesService.h \
    Data/Service/EmployeesService.h \
    Data/DAO/ProfessionsDAO.h \
    Data/DAO/IPredmetsDAO.h \
    Data/DAO/PredmetsDAO.h \
    Views/Forms/MainFormPageEmployees.h \
    Views/Dialogs/AddingEmployeDialog.h \
    Views/Dialogs/AddingPupilDialog.h \
    Views/Dialogs/AddingParentDialog.h \
    Data/Service/ProfessionsService.h \
    Data/Service/IProfessionsService.h \
    Utils/Logger.h \
    Views/Forms/MainFormPage.h \
    Data/Entity/Teacher.h \
    Views/Forms/MainFormPagePupils.h \
    Data/Service/IPupilsService.h \
    Data/Service/PupilsService.h \
    Data/DAO/ClassesDAO.h \
    Data/Service/IClassesService.h \
    Data/Service/ClassesService.h \
    Data/DAO/IParentsDAO.h \
    Data/DAO/ParentsDAO.h \
    Data/Service/IParentsService.h \
    Data/Service/ParentsService.h \
    Data/DAO/ITeachersDAO.h \
    Data/DAO/TeachersDAO.h \
    Data/Service/ITeachersService.h \
    Data/Service/TeachersService.h \
    Views/Forms/MainFormPageTeachers.h

FORMS += \
    Views/Forms/LogInForm.ui \
    Views/Forms/MainForm.ui \
    Views/Dialogs/AddingEmployeDialog.ui \
    Views/Dialogs/AddingPupilDialog.ui \
    Views/Dialogs/AddingParentDialog.ui

RESOURCES += \
    Resources/img.qrc
