TAMPLATE = app
TARGET = Geo3D
QT       += core gui
message(Qt $$QT_VERSION is used.)

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    popup.cpp \
    window.cpp

HEADERS += \
    popup.h \
    window.h
