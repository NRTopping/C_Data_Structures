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
