#include <stdio.h>

#include <assert.h>
#include <math.h>
#include "ow.h"



void test_init() {
  struct overlapping_window ow;

  ow_init(&ow);

  assert(ow.write == 0);
  assert(ow.count == 0);
}

void test_add() {
  struct overlapping_window ow;

  ow_init(&ow);
  ow_add(&ow, 1.5);
  assert(ow.write == 1);
  assert(ow.count == 1);
  assert(ow.buf[0] == 1.5);

  for (int i = 0; i < 10; i++) {
    ow_add(&ow, 1);
  }
  assert(ow.count <= OW_SIZE);
  //  printf("ow.buf[0] is %f\n", ow.buf[0]);
  assert(ow.buf[0] == 1);
}


void test_average() {
  struct overlapping_window ow;

  ow_init(&ow);
  for (int i = 0; i < 3; i++) {
    ow_add(&ow, i);
  }

  assert (ow_average(&ow) == 1.0f);

  
  ow_init(&ow);
  assert (isnan(ow_average(&ow)));
  
  for (int i = 0; i < 10; i++) {
    ow_add(&ow, i);
  }

  assert (ow_average(&ow) == 6.0f);
}
  

int main() {
  test_init();
  test_add();
  test_average();
  return 0;
}
