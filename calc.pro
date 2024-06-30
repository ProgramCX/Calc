QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    formmain.cpp \
    main.cpp    \
    windowsizeadapter.cpp

HEADERS += \
    formmain.h  \
    windowsizeadapter.h

FORMS += \
    formmain.ui

TRANSLATIONS += \
    calc_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
msvc {
    QMAKE_CFLAGS += /utf-8
    QMAKE_CXXFLAGS += /utf-8
}
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res/res.qrc
RC_ICONS =res\icon.ico
