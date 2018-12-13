QT += 3dcore 3drender 3dinput 3dquick 3dlogic qml quick 3dquickextras widgets

SOURCES += \
    main/main.cpp \
    core/system.cpp \
    core/simulator.cpp \
    core/particle.cpp

OTHER_FILES +=

HEADERS += \
    sim/vis_simulator.h \
    core/particle.h \
    core/system.h \
    core/node.h

DISTFILES +=

RESOURCES += \
    main/qml.qrc


