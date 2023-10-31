#ifndef CQMANDELBROT_H
#define CQMANDELBROT_H

#include <CQPointFractal.h>
#include <memory>

class CMandelbrot;

class CQMandelbrot : public CQPointFractal {
  Q_OBJECT

 public:
  CQMandelbrot(QWidget *parent=nullptr);

  virtual ~CQMandelbrot();

  CMandelbrot *getMandelbrot() const { return mandelbrot_.get(); }

 private:
  using MandelbrotP = std::unique_ptr<CMandelbrot>;

  MandelbrotP mandelbrot_;
};

#endif
