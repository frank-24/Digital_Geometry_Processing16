DESTDIR = ../../lib

TEMPLATE = lib
CONFIG += staticlib c++11
INCLUDEPATH += ..

NAME = wrl

CONFIG(release, debug|release) {
    TARGET = $$NAME
} else {
    TARGET = $${NAME}_d
}

HEADERS += \
  Node.hpp \
  SceneGraph.hpp \
  SceneGraphTraversal.hpp \
  SceneGraphProcessor.hpp \
  Group.hpp \
  Transform.hpp \
  Shape.hpp \
  Appearance.hpp \
  Material.hpp \
  PixelTexture.hpp \
  ImageTexture.hpp \
  IndexedFaceSet.hpp \
  IndexedLineSet.hpp \
  Rotation.hpp

SOURCES += \
  Node.cpp \
  SceneGraph.cpp \
  SceneGraphTraversal.cpp \
  SceneGraphProcessor.cpp \
  Group.cpp \
  Transform.cpp \
  Shape.cpp \
  Appearance.cpp \
  Material.cpp \
  PixelTexture.cpp \
  ImageTexture.cpp \
  IndexedFaceSet.cpp \
  IndexedLineSet.cpp \
  Rotation.cpp
