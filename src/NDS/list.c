/*#include <NDS/list.h>*/
#include "../../include/NDS/list.h"
#include <stdlib.h>
#include <assert.h>

static nds_element_t default_alloc(void *e) { 
  return (nds_element_t) e; 
}

static void default_free(nds_element_t e) {
  (void)(e);
}

extern nds_list_t nds_list_alloc(const nds_alloc_func_t alloc_func, 
    const nds_free_func_t free_func) { 
  nds_list_t list; 
  
  list = (nds_list_t) malloc(sizeof(struct nds_list));

  if (list == NULL) return NULL; 

  // allocate sentinel nodes 
  list->beg = nds_lnode_alloc(); 
  if (list->beg == NULL) { 
    free(list); 
    return NULL;
  }
  list->end = nds_lnode_alloc();
  if (list->end == NULL) { 
    nds_lnode_free(list->end);
    free(list); 
    return NULL; 
  }
  // link sentinel nodes
  nds_lnode_link(list->beg, list->end); 

  // set function fields 
  list->alloc_func = (alloc_func == NULL) ? default_alloc : alloc_func;
  list->free_func  = (free_func  == NULL) ? default_free  : free_func;

  return list; 
}

extern void nds_list_free(nds_list_t list) { 

  assert(list != NULL); 

  nds_list_flush(list); 

  nds_lnode_free(list->beg); 
  nds_lnode_free(list->end); 
  free(list); 
}

extern void nds_list_flush(nds_list_t list) { 
  nds_lnode_t curr, next;

  assert(list != NULL); 

  curr = nds_lnode_get_next(list->beg); 
  while (curr != list->end) { 
    list->free_func(nds_lnode_get_data(curr));
    next = nds_lnode_get_next(curr); 
    nds_lnode_free(curr); 
    curr = next;
  }
}

extern bool nds_list_is_empty(const nds_list_t list) { 
  return (nds_list_size(list) == 0); 
}

extern nds_size nds_list_size(const nds_list_t list) { 
  assert(list != NULL);
  return list->size; 
}

extern nds_element_t nds_list_get_head(const nds_list_t list) {
  assert(list != NULL);
  return nds_lnode_get_data(nds_lnode_get_next(list->beg));
}

extern nds_element_t nds_list_get_tail(const nds_list_t list) { 
  assert(list != NULL);   
  return nds_lnode_get_data(nds_lnode_get_prev(list->end));
}
