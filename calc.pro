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

# 版本信息
VERSION = 1.0.0.0


# 公司名称
QMAKE_TARGET_COMPANY = "ProgramCX"

# 产品名称
QMAKE_TARGET_PRODUCT = "Calculator"

# 文件说明
QMAKE_TARGET_DESCRIPTION = "Calculator compiled by MSVC 2019, 64 bit"

# # 版权信息
# QMAKE_TARGET_COPYRIGHT = "Copyright 2008-2016 The Qt Company Ltd. All rights reserved."

# 中文（简体）
RC_LANG = 0x0004
