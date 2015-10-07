#ifndef NDS_SLIST_H_
#define NDS_SLIST_H_

//#include <NDS/general.h>
#include "general.h"
#include <stdbool.h>

typedef struct nds_slnode_t {
  struct nds_slnode_t *next;
  nds_element_t *data;
} nds_slnode_t;

typedef nds_slnode_t nds_slist_t;

nds_slist_t nds_slist_alloc(const nds_element_t element);
void nds_slist_free(nds_slist_t list, const nds_free_func_t free_f);
bool nds_slist_is_empty(const nds_slist_t list);
unsigned long nds_slist_size(const nds_slist_t list);
void nds_slist_append(nds_slist_t l1, nds_slist_t l2); 


#endif /* NDS_SLIST_H_ */
