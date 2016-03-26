TEMPLATE = lib
TARGET = Models
QT += qml quick sql
CONFIG += qt plugin c++11

TARGET = $$qtLibraryTarget($$TARGET)
uri = Models

INCLUDEPATH += include source

# Input
SOURCES +=               \
    sqlmodel_plugin.cpp  \
    source/sqlcolumn.cpp \
    source/sqlmodel.cpp  \
    source/sqlthreadedmodel.cpp

HEADERS +=              \
    sqlmodel_plugin.h   \
    include/sqlcolumn.h \
    include/sqlmodel.h  \
    include/sqlthreadedmodel.h

DISTFILES = qmldir

!equals(_PRO_FILE_PWD_, $$OUT_PWD) {
    copy_qmldir.target = $$OUT_PWD/qmldir
    copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
    copy_qmldir.commands = $(COPY_FILE) \"$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)\" \"$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)\"
    QMAKE_EXTRA_TARGETS += copy_qmldir
    PRE_TARGETDEPS += $$copy_qmldir.target
}

qmldir.files = qmldir
unix {
    installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
    qmldir.path = $$installPath
    target.path = $$installPath
    INSTALLS += target qmldir
}
