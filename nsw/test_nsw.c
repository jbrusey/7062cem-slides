#include <stdio.h>

#include <assert.h>
#include <math.h>
#include "nsw.h"



void test_init() {
  struct nsw nsw;

  nsw_init(&nsw);

  assert(nsw.count == 0);
}

void test_add() {
  struct nsw nsw;

  nsw_init(&nsw);
  nsw_add(&nsw, 1.5);
  
  assert(nsw.count == 1);
  assert(nsw.buf[0] == 1.5);

  for (int i = 0; i < 10; i++) {
    nsw_add(&nsw, 1);
  }
  assert(nsw.count == 11 % NSW_SIZE);
  assert(nsw.buf[0] == 1);
}

void test_ready() {
  struct nsw nsw;
  nsw_init(&nsw);
  assert(! nsw_ready(&nsw));
  for (int i = 0; i < 7; i++) {
    nsw_add(&nsw, 1);
  }
  assert(nsw_ready(&nsw));

}

void test_get() {
  struct nsw nsw;

  nsw_init(&nsw);
  assert(! nsw_ready(&nsw));
  for (int i = 0; i < 7; i++) {
    nsw_add(&nsw, 1);
  }
  assert(nsw_ready(&nsw));
  assert(nsw_get(&nsw) == 1.0f);

  for (int i = 0; i < 7; i++) {
    nsw_add(&nsw, i);
  }
  assert(nsw_ready(&nsw));
  assert(nsw_get(&nsw) == 3.0f);
}


/* void test_average() { */
/*   struct nsw nsw; */

/*   nsw_init(&nsw); */
/*   for (int i = 0; i < 3; i++) { */
/*     nsw_add(&nsw, i); */
/*   } */

/*   assert (nsw_average(&nsw) == 1.0f); */

  
/*   nsw_init(&nsw); */
/*   assert (isnan(nsw_average(&nsw))); */
  
/*   for (int i = 0; i < 10; i++) { */
/*     nsw_add(&nsw, i); */
/*   } */

/*   assert (nsw_average(&nsw) == 6.0f); */
/* } */
  

int main() {
  test_init();
  test_add();
  test_ready();
  return 0;
}
