QT += 3dcore 3drender 3dinput 3dquick 3dlogic qml quick 3dquickextras widgets

SOURCES += \
    main/main.cpp \
    core/system.cpp \
    core/particle.cpp \
    interface/simulator.cpp

OTHER_FILES +=

HEADERS += \
    core/particle.h \
    core/system.h \
    core/node.h \
    interface/simulator.h

DISTFILES +=

RESOURCES += \
    main/qml.qrc


