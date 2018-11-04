!include( ../amoebotsim/examples.pri ) {
    error( "Couldn't find the examples.pri file!" )
}

QT += 3dcore 3drender 3dinput 3dquick 3dlogic qml quick 3dquickextras widgets

SOURCES += \
    main/main.cpp

OTHER_FILES += \
    main.qml


RESOURCES += \
    simple-qml.qrc \

HEADERS += \
    backend.h

DISTFILES += \
    examples.pri \
