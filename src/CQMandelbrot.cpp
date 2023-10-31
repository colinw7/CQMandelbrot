#include <CQMandelbrot.h>
#include <CMandelbrot.h>

CQMandelbrot::
CQMandelbrot(QWidget *parent) :
 CQPointFractal(parent)
{
  mandelbrot_ = std::make_unique<CMandelbrot>();

  setFractal(getMandelbrot());
}

CQMandelbrot::
~CQMandelbrot()
{
}
