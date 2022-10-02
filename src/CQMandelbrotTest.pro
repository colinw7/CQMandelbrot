TEMPLATE = app

QT += widgets

TARGET = CQMandelbrot

DEPENDPATH += .

QMAKE_CXXFLAGS += -std=c++17

MOC_DIR = .moc

#CONFIG += debug

# Input
SOURCES += \
CQMandelbrotTest.cpp \
CQMandelbrot.cpp \
CMandelbrot.cpp \

HEADERS += \
CQMandelbrotTest.h \
CQMandelbrot.h \
CMandelbrot.h \

DESTDIR     = ../bin
OBJECTS_DIR = ../obj
LIB_DIR     = ../lib

INCLUDEPATH += \
. ../include \
../../CFractal/qinclude \
../../CFractal/include \
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
-L../../CFractal/lib \
-L../../CQColors/lib \
-L../../CQUtil/lib \
-L../../CConfig/lib \
-L../../CImageLib/lib \
-L../../CFont/lib \
-L../../CThread/lib \
-L../../CFile/lib \
-L../../CFileUtil/lib \
-L../../COS/lib \
-L../../CUtil/lib \
-L../../CStrUtil/lib \
-L../../CRegExp/lib \
-lCQFractal -lCFractal -lCQColors -lCQUtil -lCConfig -lCFont -lCImageLib \
-lCThread -lCFile -lCFileUtil -lCUtil -lCRegExp -lCStrUtil -lCOS \
-ljpeg -lpng -ltre -ltcl
