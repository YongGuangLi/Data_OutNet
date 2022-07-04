#-------------------------------------------------
#
# Project created by QtCreator 2022-05-23T14:50:37
#
#-------------------------------------------------

QT       += core xml

QT       -= gui

TARGET = Data_OutNet
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    outnetferry.cpp \
    RedisHelper.cpp \
    mqttasyncclient.cpp \
    ferryutils.cpp \
    RemotePoint.pb.cc

HEADERS += \
    outnetferry.h \
    RedisHelper.h \
    mqttasyncclient.h \
    ferryutils.h \
    RemotePoint.pb.h

unix:!macx: LIBS += -L$$PWD/../crypto/lib/ -lyyapi

INCLUDEPATH += $$PWD/../crypto/include
DEPENDPATH += $$PWD/../crypto/include


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../qjson/lib/release/ -lqjson
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../qjson/lib/debug/ -lqjson
else:unix: LIBS += -L$$PWD/../qjson/lib/ -lqjson

INCLUDEPATH += $$PWD/../qjson/include
DEPENDPATH += $$PWD/../qjson/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../hiredis-0.14.1/release/ -lhiredis
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../hiredis-0.14.1/debug/ -lhiredis
else:unix: LIBS += -L$$PWD/../hiredis-0.14.1/ -lhiredis

INCLUDEPATH += $$PWD/../hiredis-0.14.1
DEPENDPATH += $$PWD/../hiredis-0.14.1

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../protobuf-3.3.0/lib/release/ -lprotobuf
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../protobuf-3.3.0/lib/debug/ -lprotobuf
else:unix: LIBS += -L$$PWD/../protobuf-3.3.0/lib/ -lprotobuf

INCLUDEPATH += $$PWD/../protobuf-3.3.0/include
DEPENDPATH += $$PWD/../protobuf-3.3.0/include


unix:!macx: LIBS += -L$$PWD/../mqtt/lib/ -lpaho-mqtt3a

INCLUDEPATH += $$PWD/../mqtt/include
DEPENDPATH += $$PWD/../mqtt/include
