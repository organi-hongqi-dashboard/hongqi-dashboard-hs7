# QT Modules
QT += qml quick serialport

# Target
TARGET = hongqi-H7
TEMPLATE = app

# Extra Configs
DEFINES += HONGQI_RECV
DEFINES += HONGQI
DEFINES += TIMER_FREQ

#CONFIG(release, debug|release) {
#    DEFINES += QT_NO_DEBUG_OUTPUT
#}
CONFIG += qtquickcompiler
QMAKE_DISTCLEAN += *_qtquickcompiler.qrc

# Sources and Headers
SOURCE_FOLDER = src
HEADER_FOLDER = src/include

INCLUDEPATH += $$HEADER_FOLDER
HEADERS += $$HEADER_FOLDER/carstatus.h \
    $$HEADER_FOLDER/protocol.h \
    $$HEADER_FOLDER/fontName.h

SOURCES += $$SOURCE_FOLDER/main.cpp \
    $$SOURCE_FOLDER/carstatus.cpp \
    $$SOURCE_FOLDER/protocol.cpp

# Add Carnation Custom Module
CONFIG += Carnation_Spe_Protocol
Carnation_Spe_Protocol {
DEFINES += Carnation
HEADERS += \
        $$HEADER_FOLDER/carnation_protocol.h \
        $$HEADER_FOLDER/carnation_carstatus.h
    SOURCES += $$SOURCE_FOLDER/carnation_carstatus.cpp
}
# Qml Files
QML_FOLDER = qml/content
OTHER_FILES += qml/mainViewer.qml \
    $$QML_FOLDER/*.qml \
    $$QML_FOLDER/warning/*.qml \
    $$QML_FOLDER/functionMode/*.qml \
    $$QML_FOLDER/qmldir


# Resources
RESOURCES += hongqi.qrc
QMAKE_RESOURCE_FLAGS += -no-compress


fontsFiles.files = fonts/MicroSoftYahei.TTF
fontsFiles.path = /usr/lib/fonts
INSTALLS += fontsFiles

#target.path = /opt/Hongqi
#INSTALLS += target

# Target Pathes
#modelFiles.files = car.dae
#modelFiles.path = /opt/QtQuick/model
#INSTALLS += modelFiles

#target.path = /opt/QtQuick
#INSTALLS += target

# Objects Pathes
DESTDIR = bin
UI_DIR = build
MOC_DIR = build
RCC_DIR = build
OBJECTS_DIR = build
