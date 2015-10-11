#ifndef NDS_LIST_H_
#define NDS_LIST_H_

//#include <NDS/general.h>
#include "general.h"
#include <stdbool.h>

typedef struct nds_lnode {
  struct nds_lnode *next;
  nds_element_t *data;
} *nds_lnode_t;

typedef nds_lnode_t nds_list_t;

nds_list_t nds_list_alloc(const nds_element_t element);
void nds_list_free(nds_list_t list, const nds_free_func_t free_f);
bool nds_list_is_empty(const nds_list_t list);
unsigned long nds_list_size(const nds_list_t list);
void nds_list_link(nds_list_t l1, nds_list_t l2); 
void nds_list_insert_after(nds_list_t l1, nds_list_t l2);
void nds_list_insert_before(nds_list_t l1, nds_list_t l2); 
void nds_list_remove(nds_list_t l, nds_lnode_t node); 
void nds_list_search(nds_list_t l, const nds_compar_func_t comp_f, void *value); 
void nds_list_write(nds_list_t l); 
void nds_list_read(nds_list_t l); 
void nds_list_dump(nds_list_t l); 




#endif /* NDS_LIST_H_ */
