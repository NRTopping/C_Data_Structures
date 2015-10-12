#ifndef NDS_LIST_H_
#define NDS_LIST_H_

//#include <NDS/types.h>
#include "types.h"
//#include <NDS/lnode.h>
#include "lnode.h"
#include <stdbool.h>

typedef struct nds_list { 
  nds_lnode_t   head; // begining of list
  nds_lnode_t   end;  // end of list 
  unsigned long size; // size of the list 
  char         *id;   // optional identifier for the list

  nds_alloc_func_t  alloc_func;  // element allocator for the list
  nds_free_func_t   free_func;   // element deallocater for the list
  nds_compar_func_t compar_func; // element comparison function for the list
  nds_write_func_t  write_func;  // element write function for the list 
  nds_read_func_t   read_func;   // element read function for the list
} *nds_list_t; 

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




#endif /* NDS_LIST_H_ */
