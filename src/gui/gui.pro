BASEDIR   = ../..
TOPDIR    = $$BASEDIR/..
DESTDIR   = $$BASEDIR/bin
LIBDIR    = $$BASEDIR/lib
FORMSDIR  = $$BASEDIR/forms
SOURCEDIR = $$BASEDIR/src
ASSETSDIR = $$BASEDIR/assets

NAME      = DGP2016

CONFIG   += qt c++11
QT       += widgets
QT       += gui
QT       += opengl

INCLUDEPATH += ..

LIBS += -L$$LIBDIR

win32 {
  DEFINES += VC_EXTRALEAN WIN32_LEAN_AND_MEAN
}

unix:!macx {
}

macx {
  ICON = $$ASSETSDIR/bunny.icns
}

CONFIG(release, debug|release) {
    TARGET = $$NAME
    LIBS += -lutil -lio -lwrl
} else {
    TARGET = $${NAME}_d
    LIBS += -lutil_d -lio_d -lwrl_d
    CONFIG += console
}

HEADERS += \
        GuiAboutDialog.hpp \
        GuiMainWindow.hpp \
        GuiToolsWidget.hpp \
        GuiGLWidget.hpp \
        GuiGLBuffer.hpp \
        GuiGLShader.hpp \
        GuiGLHandles.hpp \
        GuiViewerData.hpp \
        GuiQtLogo.hpp \
        GuiStrings.hpp

SOURCES += \
        GuiAboutDialog.cpp \
        GuiViewerApp.cpp \
        GuiMainWindow.cpp \
        GuiToolsWidget.cpp \
        GuiGLWidget.cpp \
        GuiGLBuffer.cpp \
        GuiGLShader.cpp \
        GuiGLHandles.cpp \
        GuiViewerData.cpp \
        GuiQtLogo.cpp

RESOURCES = \
        $$(NULL)

FORMS = \
        $$(NULL)

