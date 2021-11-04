#include <stdio.h>

#include <assert.h>
#include <math.h>
#include "ewma.h"


int approx_equal(float a, float b) {
  return fabs(a - b) < 1e-4;
}

void test_init() {
  struct ewma ewma;

  ewma_init(&ewma, 0.1);
  assert(ewma.first == 1);
}

void test_estimate() {
  struct ewma ewma;

  ewma_init(&ewma, 0.1);
  assert(ewma_estimate(&ewma, 1) == 1);

  float v = ewma_estimate(&ewma, 0);
  assert(approx_equal(v,  (1 + 0.1 * (0 - 1))));
}

int main() {
  test_init();
  test_estimate();
  return 0;
}
