#-------------------------------------------------
#
# Project created by QtCreator 2019-07-07T15:11:56
#
#-------------------------------------------------

QT       += gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = imageProcess
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++17

QMAKE_CXXFLAGS = $$QMAKE_CFLAGS -std=c++17

SOURCES += \
        main.cpp \
        View/mainwindow.cpp \
        App/app.cpp \
        ViewModel/ViewModel.cpp \
        Model/Model.cpp \
        Common/Command.cpp \
        ViewModel/Command/OpenFileCommand.cpp \
        Common/myImage.cpp \
        Utility/utility.cpp \
        Common/ImageList.cpp \
        Common/Notification.cpp \
        View/Notification/UpdateNotification.cpp

HEADERS += \
        View/mainwindow.h \
        App/app.h \
        Common/myImage.h \
        ViewModel/ViewModel.h \
        Model/Model.h \
        Common/Command.h \
        ViewModel/Command/OpenFileCommand.h \
        Utility/utility.h \
        Common/ImageList.h \
        Common/Notification.h \
        View/Notification/UpdateNotification.h
FORMS += \
       View/mainwindow.ui

INCLUDEPATH += /usr/local/include/

LIBS += -L/usr/local/lib \
     -lopencv_core \
     -lopencv_ml \
     -lopencv_photo \
     -lopencv_shape \
     -lopencv_stitching \
     -lopencv_videoio \
     -lopencv_imgproc \
     -lopencv_features2d\
     -lopencv_highgui\
     -lopencv_imgcodecs\
     -lopencv_calib3d \
     -lopencv_flann \
     -lopencv_imgcodecs \
     -lopencv_imgproc \
     -lopencv_objdetect \
     -lopencv_superres \
     -lopencv_video \
     -lopencv_videostab \
     -v

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
