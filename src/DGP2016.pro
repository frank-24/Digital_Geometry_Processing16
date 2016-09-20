# DEFINES +=
# QMAKE_CXXFLAGS += -I

TEMPLATE = subdirs

TARGET   += \
  DGP2016

CONFIG   += ordered

SUBDIRS  += \
  io \
  util \
  wrl \
  core \
  gui
