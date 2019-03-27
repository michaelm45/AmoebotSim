QT += 3dcore 3drender 3dinput 3dquick 3dlogic qml quick 3dquickextras widgets

SOURCES += \
    main/main.cpp \
    core/system.cpp \
    core/particle.cpp \
    interface/simulator.cpp \
    helper/randomnumbergenerator.cpp \
    helper/conversion.cpp \
    helper/utility.cpp
    core/localparticle.cpp

HEADERS += \
    core/particle.h \
    core/system.h \
    core/node.h \
    interface/simulator.h \
    helper/randomnumbergenerator.h \
    helper/conversion.h \
    helper/utility.h
    core/localparticle.h

RESOURCES += \
    res/qml.qrc

OTHER_FILES +=
