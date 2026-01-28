#include <stdio.h>
#include <omp.h>
#define TIGR_IMPLEMENTATION
#include "node_modules/tigr.c/tigr.h"


// Define uint8_t for simplicity.
typedef unsigned char uint8_t;


// A complex number has a real and imaginary part.
typedef struct Complex {
  double r;
  double i;
} Complex;


// Compute the modulus squared of a complex number.
inline double mod2(Complex z) {
  return z.r * z.r + z.i * z.i;
}


// Compute the next number in the sequence z = z^2 + c.
inline Complex computeNext(Complex z, Complex c) {
  double r = z.r * z.r - z.i * z.i + c.r;
  double i =   2 * z.r * z.i       + c.i;
  return (Complex) {r, i};
}


// Perform iterations, and return the number of iterations before escape.
inline int computeIterations(Complex z0, Complex c, int maxIters) {
  Complex z = z0; int i;
  // If modulus exceeds 2, we consider it escaped.
  for (i=0; mod2(z) <= 4.0 && i < maxIters; i++)
    z = computeNext(z, c);
  return i;
}


void renderJuliaFractal(Tigr *image, double xmin, double xmax, double ymin, double ymax, Complex c, int maxIters) {
  int W = image->w;
  int H = image->h;
  double xf = (xmax - xmin) / (double) W;
  double yf = (ymax - ymin) / (double) H;
  for (int y=0; y < H; ++y) {
    for (int x=0; x < W; ++x) {
      // Map pixel coordinate to complex number.
      double   r = xmin + x * xf;
      double   i = ymin + y * yf;
      Complex z0 = {r, i};
      // Compute the number of iterations before escape.
      int iters = computeIterations(z0, c, maxIters);
      // Map iterations to color.
      uint8_t color = (uint8_t) (255 * iters / maxIters);
      image->pix[y * W + x] = tigrRGB(color, color, color);
    }
  }
}


int main(int argc, char *argv[]) {
  int W = 1200;
  int H = 600;
  // Create a window to display the image.
  Tigr *screen = tigrWindow(W, H, "Julia Fractal", 0);
  Tigr *image  = tigrBitmap(W, H);
  // Define the region in the complex plane to visualize.
  double xmin = -2, xmax = 2;
  double ymin = -2, ymax = 2;
  double zoom = 0.995;
  // Define the complex constant c for the Julia set.
  Complex c = {-0.7, 0.27015};
  // Display the image until the window is closed.
  while (!tigrClosed(screen) && !tigrKeyHeld(screen, TK_ESCAPE)) {
    double t0 = omp_get_wtime();
    renderJuliaFractal(image, xmin, xmax, ymin, ymax, c, 100);
    double t1 = omp_get_wtime();
    tigrBlit(screen, image, 0, 0, 0, 0, W, H);
    tigrUpdate(screen);
    printf("Rendered in %.6f seconds.\n", t1 - t0);
    // Zoom in slightly for the next frame.
    xmin *= zoom; xmax *= zoom;
    ymin *= zoom; ymax *= zoom;
  }
  tigrFree(screen);
  return 0;

  // TODO:
  // Similarly, you can implement parallel histogram computation using OpenMP.
}
