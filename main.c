#include <stdio.h>
#include <omp.h>
#define TIGR_IMPLEMENTATION
#include "node_modules/tigr.c/tigr.h"


// Sequential code for image histogram.
void computeHistogram(int *histogram, Tigr *image) {
  int W = image->w;
  int H = image->h;
  for (int i=0; i<256; ++i)
    histogram[i] = 0;
  for (int y=0; y<H; ++y) {
    for (int x=0; x<W; ++x) {
      TPixel p = image->pix[y * W + x];
      int gray = (int)(p.r + p.g + p.b) / 3;
      histogram[gray]++;
    }
  }
}


int main(int argc, char *argv[]) {
  // Load an image from file.
  const char *file = argc>1? argv[1] : "images\\01-tigr.png";
  Tigr *image  = tigrLoadImage(file);
  if (!image) {
    printf("Failed to load image %s.\n", file);
    return -1;
  }
  // Create a window to display the image.
  Tigr *screen = tigrWindow(image->w, image->h, "Hello", 0);

  // Compute and print the image histogram.
  int histogram[256];
  double t0 = omp_get_wtime();
  computeHistogram(histogram, image);
  double t1 = omp_get_wtime();
  printf("Histogram for %s:\n", file);
  for (int i=0; i<256; ++i)
    printf("%d=%d ", i, histogram[i]);
  printf("\n");
  printf("Histogram computed in %.6f seconds.\n", t1 - t0);

  // TODO:
  // Similarly, you can implement parallel histogram computation using OpenMP.

  // Display the image until the window is closed.
  while (!tigrClosed(screen) && !tigrKeyHeld(screen, TK_ESCAPE)) {
    tigrClear(screen, tigrRGB(0x80, 0x90, 0xa0));
    tigrBlit(screen, image, 0, 0, 0, 0, image->w, image->h);
    tigrUpdate(screen);
  }
  tigrFree(screen);
  return 0;
}
