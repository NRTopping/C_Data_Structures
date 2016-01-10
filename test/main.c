#include <stdio.h>
#include <assert.h>
#include <NDS/lnode.h>

int main() {
  printf("Test\n");
  nds_lnode_t test = nds_lnode_alloc();
  nds_lnode_set_data(test,  (nds_element_t)1);
  assert((int)nds_lnode_get_data(test) == 1);
  printf("Data: %d", (int) nds_lnode_get_data(test));
  return 0;
}
