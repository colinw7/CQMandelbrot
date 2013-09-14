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

HEADERS += \
CQMandelbrotTest.h \
CQMandelbrot.h \
CQPointFractal.h \
CMandelbrot.h \
CPointFractal.h \
CPointFractalRenderer.h \
CColorRange.h \

DESTDIR     = ../bin
OBJECTS_DIR = ../obj
LIB_DIR     = ../lib

INCLUDEPATH += \
. ../include \
../../CQUtil/include \
../../CFont/include \
../../CImageLib/include \
../../CFile/include \
../../COS/include \
../../CUtil/include \
../../CMath/include \
../../CStrUtil/include \
../../CThread/include \

unix:LIBS += \
-L$$LIB_DIR \
-L../../CQUtil/lib \
-L../../CConfig/lib \
-L../../CImageLib/lib \
-L../../CFont/lib \
-L../../CThread/lib \
-L../../CFile/lib \
-L../../COS/lib \
-L../../CStrUtil/lib \
-L../../CRegExp/lib \
-lCQUtil -lCConfig -lCFont -lCImageLib \
-lCThread -lCFile -lCStrUtil -lCOS -lCRegExp \
-ljpeg -lpng -ltre
