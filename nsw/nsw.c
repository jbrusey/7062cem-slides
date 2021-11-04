#include <stdio.h>
#include "nsw.h"
#include <assert.h>

void nsw_init(struct nsw *nsw) {
  nsw->count = 0;
}

void nsw_add(struct nsw *nsw, float v) {
  if (nsw->count == NSW_SIZE)
    nsw->count = 0;

  assert(nsw->count >= 0 && nsw->count < NSW_SIZE);
  nsw->buf[nsw->count++] = v;
}

int nsw_ready(struct nsw *nsw) {
  return nsw->count == NSW_SIZE;
}

float nsw_get(struct nsw *nsw) {

  assert (nsw->count == NSW_SIZE);

  float total = 0;
  for (int i = 0; i < NSW_SIZE; i++) {
    total += nsw->buf[i];
  }
  return total / NSW_SIZE;
}
    


