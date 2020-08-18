'use strict';

window.addEventListener("load", eventWindowLoaded, false);

function eventWindowLoaded () {
  canvasApp();
}

function canvasSupport () {
  return true;
  //return Modernizr.canvas;
}

function canvasApp () {
  if (! canvasSupport()) {
    return;
  }

  var canvas = document.getElementById("canvas");
  var gc     = canvas.getContext("2d");

  //---

  var resetButton = document.getElementById("resetButton");

  resetButton.addEventListener('click', resetPressed, false);

  var depthSelect = document.getElementById("depthSelect");

  depthSelect.addEventListener("change", depthSelectChanged, false);

  //---

  var needsDraw = true;

  var pixelWidth  = 800;
  var pixelHeight = 640;

  var image = gc.createImageData(pixelWidth, pixelHeight);

  var xmin = -2.0;
  var ymin = -1.2;
  var xmax =  1.2;
  var ymax =  1.2;

  var max_iter = 1;
  var iter_d1  = 1.0;
  var iter_d2  = 1.0;
  var iter_d3  = 1.0;

  var rcolors = new Array;
  var gcolors = new Array;
  var bcolors = new Array;

  setMaxIter(128);

  var mouseDown = false;
  var mouseX1 = 0;
  var mouseY1 = 0;
  var mouseX2 = 0;
  var mouseY2 = 0;

  function calc(x, y) {
    var zr2 = 0.0;
    var zi2 = 0.0;
    var zri = 0.0;

    var num_iter = 0;

    while (zi2 + zr2 < 4.0 && num_iter < max_iter) {
      var zr = zr2 - zi2 + x;
      var zi = zri + zri + y;

      zr2 = zr*zr;
      zi2 = zi*zi;
      zri = zr*zi;

      num_iter++;
    }

    return num_iter;
  }

  function iterToColor(iter) {
    var r = 0;
    var g = 0;
    var b = 0;

    if      (iter == max_iter) { }
    else if (iter < iter_d1) { r = iter_d3* iter           ; }
    else if (iter < iter_d2) { g = iter_d3*(iter - iter_d1); }
    else                     { b = iter_d3*(iter - iter_d2); }

    return {r:r, g:g, b:b};
  }

  function setMaxIter(iter) {
    max_iter = iter;

    if        (max_iter == 32) {
      depthSelect.selectedIndex = 0;
    } else if (max_iter == 64) {
      depthSelect.selectedIndex = 1;
    } else if (max_iter == 128) {
      depthSelect.selectedIndex = 2;
    } else if (max_iter == 256) {
      depthSelect.selectedIndex = 3;
    } else if (max_iter == 512) {
      depthSelect.selectedIndex = 4;
    }

    iter_d1 = (max_iter - 1.0)/3.0;
    iter_d2 = 2.0*iter_d1;
    iter_d3 = 255.0/iter_d1;

    for (var i = 0; i < max_iter; i++) {
      var rgb = iterToColor(i);

      rcolors[i] = rgb.r;
      gcolors[i] = rgb.g;
      bcolors[i] = rgb.b;
    }

    rcolors[max_iter] = 0;
    gcolors[max_iter] = 0;
    bcolors[max_iter] = 0;
  }

  function pixelXToUser(x) {
    return ((x*1.0)/(pixelWidth - 1))*(xmax - xmin) + xmin;
  }

  function pixelYToUser(y) {
    return ((y*1.0)/(pixelHeight - 1))*(ymin - ymax) + ymax;
  }

  function userXToPixel(x) {
    return (pixelWidth - 1)*(x - xmin)/(xmax - xmin)
  }

  function userYToPixel(y) {
    return (pixelHeight - 1)*(y - ymax)/(ymin - ymax)
  }

  function genImage() {
    var pos = 0;

    for (var y = 0; y < pixelHeight; y++) {
      var yy = pixelYToUser(y);

      for (var x = 0; x < pixelWidth; x++) {
        var xx = pixelXToUser(x);

        var iter = calc(xx, yy);

        image.data[pos++] = rcolors[iter];
        image.data[pos++] = gcolors[iter];
        image.data[pos++] = bcolors[iter];
        image.data[pos++] = 255;
      }
    }
  }

  function drawScreen() {
    gc.fillStyle = '#000000';

    gc.fillRect(0, 0, pixelWidth, pixelHeight);

    if (needsDraw) {
      genImage();

      needsDraw = false;
    }

    gc.putImageData(image, 0, 0);

    if (mouseDown) {
      gc.strokeStyle = '#FFFFFF';

      gc.strokeRect(mouseX1, mouseY1, mouseX2 - mouseX1, mouseY2 - mouseY1);
    }
  }

  function eventMouseDown(e) {
    mouseDown = true;

    var rect = canvas.getBoundingClientRect();

    mouseX1 = e.clientX - rect.left;
    mouseY1 = e.clientY - rect.top;
  }

  function eventMouseMove(e) {
    var rect = canvas.getBoundingClientRect();

    mouseX2 = e.clientX - rect.left;
    mouseY2 = e.clientY - rect.top;

    drawScreen();
  }

  function eventMouseUp(e) {
    var rect = canvas.getBoundingClientRect();

    mouseX2 = e.clientX - rect.left;
    mouseY2 = e.clientY - rect.top;

    if (mouseX1 == mouseX2 || mouseY1 == mouseY2) {
      return;
    }

    var xmin1 = pixelXToUser(Math.min(mouseX1, mouseX2));
    var ymin1 = pixelYToUser(Math.max(mouseY1, mouseY2));
    var xmax1 = pixelXToUser(Math.max(mouseX1, mouseX2));
    var ymax1 = pixelYToUser(Math.min(mouseY1, mouseY2));

    xmin = xmin1;
    ymin = ymin1;
    xmax = xmax1;
    ymax = ymax1;

    mouseDown = false;

    needsDraw = true;

    drawScreen();
  }

  function resetPressed() {
    xmin = -2.0;
    ymin = -1.2;
    xmax =  1.2;
    ymax =  1.2;

    needsDraw = true;

    drawScreen();
  }

  function depthSelectChanged(e) {
    var target = e.target;

    setMaxIter(target.value);

    needsDraw = true;

    drawScreen();
  }

  canvas.addEventListener("mousedown",eventMouseDown, false);
  canvas.addEventListener("mousemove",eventMouseMove, false);
  canvas.addEventListener("mouseup"  ,eventMouseUp  , false);

  drawScreen();
}
