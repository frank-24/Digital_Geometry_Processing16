DESTDIR = ../../lib

TEMPLATE = lib
CONFIG += staticlib c++11
INCLUDEPATH += ..

NAME = util

CONFIG(release, debug|release) {
    TARGET = $$NAME
} else {
    TARGET = $${NAME}_d
    CONFIG += console
}

HEADERS += \
  BBox.hpp \
  StaticRotation.hpp

SOURCES += \
  BBox.cpp \
  StaticRotation.cpp
