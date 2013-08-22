#ifndef CQPOINT_FRACTAL_H
#define CQPOINT_FRACTAL_H

#include <QWidget>
#include <QImage>

#include <CRGBA.h>

class CPointFractalCalc;
class CQPointFractalRenderer;
class QPainter;
class QRubberBand;

class CQPointFractal : public QWidget {
  Q_OBJECT

 public:
  CQPointFractal(QWidget *parent = 0);

  virtual ~CQPointFractal();

  void setFractal(CPointFractalCalc *fractal);

  void setThreaded(bool threaded);
  bool isThreaded() const { return threaded_; }

  void resetRange();

  void setRange(double xmin, double ymin, double xmax, double ymax);

  void setIterations(int iterations);

  void toggleShowVector();

  void setForeground(const CRGBA &rgba);

  void drawPoint(int x, int y);

  void redraw();

 private:
  void paintEvent(QPaintEvent *);
  void resizeEvent(QResizeEvent *);

  void mousePressEvent(QMouseEvent *event);
  void mouseMoveEvent(QMouseEvent *event);
  void mouseReleaseEvent(QMouseEvent *event);

  void updateRubberband(const QPoint &p1, const QPoint &p2);

  void selectionNotify(const QPoint &p1, const QPoint &p2);

 private:
  CQPointFractalRenderer *renderer_;
  QImage                  qimage_;
  bool                    threaded_;
  bool                    redraw_;
  QPainter               *painter_;
  QRubberBand            *rubber_band_;
  QPoint                  press_pos_;
};

#endif
