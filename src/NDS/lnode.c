/*#include <NDS/lnode.h>*/
#include "../../include/NDS/lnode.h"
#include <assert.h>


extern nds_lnode_t nds_lnode_alloc() {
  nds_lnode_t node;
  
  node = (nds_lnode_t) malloc(sizeof(struct nds_lnode));

  if (node == NULL) return NULL; 

  node->next = NULL; 
  node->prev = NULL; 
  node->data = NULL; 

  return node; 
} 

extern nds_element_t nds_lnode_free(nds_lnode_t node) { 
  nds_element_t data;
  
  assert(node != NULL);

  data = node->data;
  free(node); 
 
  return data;
}

extern nds_lnode_t nds_lnode_get_next(nds_lnode_t node) { 
  assert(node != NULL);
   
  return node->next; 
}

extern nds_lnode_t nds_lnode_get_prev(nds_lnode_t node) { 
  assert(node != NULL); 

  return node->prev;
}

extern nds_element_t nds_lnode_get_data(nds_lnode_t node) { 
  assert(node != NULL); 

  return node->data;
}

extern void nds_lnode_set_next(nds_lnode_t node, nds_lnode_t next) { 
  assert(node != NULL); 

  node->next = next;
}

extern void nds_lnode_set_prev(nds_lnode_t node, nds_lnode_t prev) { 
  assert(node != NULL); 

  node->prev = prev; 
}

extern void nds_lnode_link(nds_lnode_t n1, nds_lnode_t n2) { 
  assert(n1 != NULL && n2 != NULL); 

  n1->next = n2; 
  n2->prev = n1; 
}

extern void nds_lnode_unlink(nds_lnode_t n1, nds_lnode_t n2) { 
  assert(n1 != NULL && n2 != NULL); 
  assert(n1->next == n2 && n2->prev == n1); 

  n1->next = NULL;
  n2->prev = NULL;
}

extern void nds_lnode_write(const nds_lnode_t node, 
    const nds_write_func_t write_func, FILE *fp) { 
  assert(node != NULL); 
  assert(fp != NULL);

  // TODO 
  fprintf(fp, "%p\n", node); 
  write_func(node->data, fp);
}

extern nds_lnode_t nds_lnode_read(const nds_read_func_t read_func, FILE *fp) { 
  nds_element_t data; 

  assert(fp != NULL); 

  // TODO 
  fscanf(fp, "");
  data = read_func(fp);
  return nds_lnode_alloc(); 
}
