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

extern void nds_list_insert_head(const nds_list_t list, 
    const nds_element_t data) { 
  assert(list != NULL); 
  const nds_lnode_t next = nds_lnode_get_next(list->beg), 
                    newN = nds_lnode_alloc(); 

  nds_lnode_set_data(newN, data);
  nds_lnode_link(list->beg, newN);
  nds_lnode_link(newN, next);
} 

extern void nds_list_insert_tail(const nds_list_t list,
    const nds_element_t data) { 
  assert(list != NULL);
  const nds_lnode_t prev = nds_lnode_get_prev(list->end),
                    newN = nds_lnode_alloc();
  nds_lnode_set_data(newN, data); 
  nds_lnode_link(prev, newN);
  nds_lnode_link(newN, list->end);
}

extern nds_element_t nds_list_remove_head(const nds_list_t list) { 
  assert(list != NULL);
  const nds_lnode_t head    = nds_lnode_get_next(list->beg), 
                    newHead = nds_lnode_get_next(head);
  const nds_element_t ret = nds_lnode_get_data(head);
 
  // Don't modify list if head is the end sentinel of the list.
  if (head == list->end) return NULL;

  nds_lnode_link(list->beg, newHead); 
  nds_lnode_free(head);

  return ret;
}

extern nds_element_t nds_list_remove_tail(const nds_list_t list) { 
  assert(list != NULL); 
  const nds_lnode_t tail    = nds_lnode_get_prev(list->end),
                    newTail = nds_lnode_get_prev(tail);
  const nds_element_t ret = nds_lnode_get_data(tail);  
 
  if (tail == list->beg) return NULL;

  nds_lnode_link(newTail, list->end);
  nds_lnode_free(tail);

  return ret;
}

extern nds_element_t nds_list_remove(const nds_list_t list, 
    const nds_compar_func_t compar_func, const nds_element_t element) { 
  // TODO
  compar_func(list->beg, element);
  return NULL;
}

extern void nds_list_delete_head(const nds_list_t list) { 
  assert(list != NULL && list->free_func != NULL);
  const nds_element_t headVal = nds_list_remove_head(list);

  if (headVal != NULL) list->free_func(headVal);
}

extern void nds_list_delete_tail(const nds_list_t list) { 
  assert(list != NULL && list->free_func != NULL);
  const nds_element_t tailVal = nds_list_remove_tail(list);

  if (tailVal != NULL) list->free_func(tailVal);
}

extern void nds_list_delete(const nds_list_t list, 
    const nds_compar_func_t compar_func, const nds_element_t element) { 
  assert(list != NULL && list->free_func != NULL);
  const nds_element_t val = nds_list_remove(list, compar_func, element); 

  if (val != NULL) list->free_func(val);
}
