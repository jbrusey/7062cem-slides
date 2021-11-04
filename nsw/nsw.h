#ifndef NSW_H
#define NSW_H
#define NSW_SIZE 7

struct nsw {
  int count;
  float buf[NSW_SIZE];
};


void nsw_init(struct nsw *nsw);
void nsw_add(struct nsw *nsw, float v);
int nsw_ready(struct nsw *nsw);
float nsw_get(struct nsw *nsw);
#endif
