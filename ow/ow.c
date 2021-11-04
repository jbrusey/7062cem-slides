#include <stdio.h>
#include "ow.h"
#include <assert.h>

void ow_init(struct overlapping_window *ow) {
  ow->write = 0;
  ow->count = 0;
}

void ow_add(struct overlapping_window *ow, float v) {
  ow->buf[ow->write] = v;
  ow->write = (ow->write + 1) % OW_SIZE;
  if (ow->count < OW_SIZE) {
    ow->count++;
  }
}

float ow_average(struct overlapping_window *ow) {
  float total = 0;
  for (int i = 0; i < ow->count; i++) {
    total += ow->buf[i];
  }
  return total / ow->count;
}


