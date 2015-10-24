/*#include <NDS/list.h>*/
#include "../../include/NDS/list.h"
#include <stdlib.h>

static nds_element_t default_alloc(void *e);
static void default_free(void *e); 

extern nds_list_t nds_list_alloc(const nds_alloc_func_t alloc_func, 
    const nds_free_func_t free_func) { 
  nds_list_t list; 
  
  list = (nds_list_t) malloc(sizeof(struct nds_list));

  if (list == NULL) return NULL; 

  // allocate sentinel nodes 
  list->head = (nds_lnode_t) malloc(sizeof(struct nds_lnode)); 
  if (list->head == NULL) { 
    free(list); 
    return NULL;
  }
  list->tail = (nds_lnode_t) malloc(sizeof(struct nds_lnode)); 
  if (list->tail == NULL) { 
    free(list->head); 
    free(list); 
    return NULL; 
  }
  // link sentinel nodes
  nds_lnode_link(list->head, list->tail); 
  list->head->prev = NULL; 
  list->tail->next = NULL; 

  // set node data
  list->head->data = NULL;
  list->tail->data = NULL; 

  // set function fields 
  list->alloc_func = (alloc_func == NULL) ? default_alloc : alloc_func;
  list->free_func  = (free_func  == NULL) ? default_free  : free_func;

  return list; 
}
