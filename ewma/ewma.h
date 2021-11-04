#ifndef EWMA_H
#define EWMA_H

struct ewma {
  int first;
  float alpha;
  float x;
};


void ewma_init(struct ewma *ewma, float alpha);
float ewma_estimate(struct ewma *ewma, float v);
#endif
