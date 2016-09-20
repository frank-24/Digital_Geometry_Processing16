DESTDIR = ../../lib

TEMPLATE = lib
CONFIG += staticlib c++11
INCLUDEPATH += ..

NAME = core

CONFIG(release, debug|release) {
    TARGET = $$NAME
} else {
    TARGET = $${NAME}_d
    CONFIG += console
}

HEADERS += \
  Faces.hpp \
  Graph.hpp \
  GraphTraversal.hpp \
  Partition.hpp \
  PolygonMesh.hpp \
  PriorityQueueFloat.hpp \
  QueueInt.hpp \
  SplittablePartition.hpp

SOURCES += \
  Faces.cpp \
  Graph.cpp \
  GraphTraversal.cpp \
  Partition.cpp \
  PolygonMesh.cpp \
  PriorityQueueFloat.cpp \
  QueueInt.cpp \
  SplittablePartition.cpp
