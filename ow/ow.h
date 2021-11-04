#ifndef OW_H
#define OW_H
#define OW_SIZE 7

struct overlapping_window {
  int write, count;
  float buf[OW_SIZE];
};


void ow_init(struct overlapping_window *ow);
void ow_add(struct overlapping_window *ow, float v);
float ow_average(struct overlapping_window *ow);
#endif
