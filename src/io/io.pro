DESTDIR = ../../lib

TEMPLATE = lib
CONFIG += staticlib c++11
INCLUDEPATH += ..

NAME = io

CONFIG(release, debug|release) {
    TARGET = $$NAME
} else {
    TARGET = $${NAME}_d
}

HEADERS += \
  AppLoader.hpp \
  AppSaver.hpp \
  StrException.hpp \
  Loader.hpp \
  LoaderWrl.hpp \
  LoaderStl.hpp \
  Saver.hpp \
  SaverWrl.hpp \
  SaverStl.hpp \
  Tokenizer.hpp

SOURCES += \
  AppLoader.cpp \
  AppSaver.cpp \
  LoaderWrl.cpp \
  LoaderStl.cpp \
  SaverWrl.cpp \
  SaverStl.cpp \
  Tokenizer.cpp



