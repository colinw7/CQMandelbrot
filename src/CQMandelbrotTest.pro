TEMPLATE = app
TARGET = 
DEPENDPATH += .

#CONFIG += debug

# Input
SOURCES += \
CQMandelbrotTest.cpp \
CQMandelbrot.cpp \
CQPointFractal.cpp \
CMandelbrot.cpp \
CPointFractal.cpp \
CPointFractalRenderer.cpp \
CColorRange.cpp \
CQUtil.cpp \

HEADERS += \
CQMandelbrotTest.h \
CQMandelbrot.h \
CQPointFractal.h \
CMandelbrot.h \
CPointFractal.h \
CPointFractalRenderer.h \
CQUtil.h \
CColorRange.h \

DESTDIR     = ../bin
OBJECTS_DIR = ../obj
LIB_DIR     = ../lib

INCLUDEPATH += \
../include \
. \
../../CMath/include \
../../CUtil/include \
../../COS/include \
../../CThread/include \

unix:LIBS += \
-L$$LIB_DIR \
-L../../CThread/lib \
-lCThread
