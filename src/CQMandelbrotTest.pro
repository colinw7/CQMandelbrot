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
CThread.cpp \
pthread_rdwr.c \

HEADERS += \
CQMandelbrotTest.h \
CQMandelbrot.h \
CQPointFractal.h \
CMandelbrot.h \
CPointFractal.h \
CPointFractalRenderer.h \
CQUtil.h \
CColorRange.h \
CThread.h \
pthread_rdwr.h \

DESTDIR     = ../bin
OBJECTS_DIR = ../obj
LIB_DIR     = ../lib

INCLUDEPATH += \
../include \
. \
../../CMath/include \
../../CUtil/include \
../../COS/include \

unix:LIBS += \
-L$$LIB_DIR \
