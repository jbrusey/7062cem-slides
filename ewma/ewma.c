#include <stdio.h>
#include "ewma.h"
#include <assert.h>

void ewma_init(struct ewma *ewma, float alpha) {
  ewma->alpha = alpha;
  ewma->first = 1;
}

float ewma_estimate(struct ewma *ewma, float z) {
  if (ewma->first) {
    ewma->x = z;
    ewma->first = 0;
  }
  else {
    ewma->x = ewma->x + ewma->alpha * (z - ewma->x);
  }
  return ewma->x;
}
      
   
