QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SchoolDataBase
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        main.cpp \
        views/forms/main_form.cpp \
        data/dao/administrators_dao.cpp \
        utils/database.cpp \
    data/entity/pupil.cpp \
    data/entity/parent.cpp


HEADERS += \
        views/forms/main_form.h \
        data/dao/iadministrators_dao.h \
        data/dao/iprofessions_dao.h \
        data/dao/iclasses_dao.h \
        data/dao/administrators_dao.h \
        utils/database.h \
    data/dao/ipupils_dao.h \
    data/entity/pupil.h \
    data/entity/parent.h

FORMS += \
        views/forms/main_form.ui
