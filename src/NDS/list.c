/*#include <NDS/list.h>*/
#include "../../include/NDS/list.h"
#include <stdlib.h>

/**
 * TODO 
 */
nds_list_t nds_list_alloc(const nds_element_t element) { 
  nds_list_t list = malloc(sizeof(nds_list_t));
  if (list != NULL) { 
    list->data = element; 
  }
  return list; 
}


void nds_list_free(nds_list_t list, const nds_free_func_t free_f) { 

}

bool nds_list_is_empty(const nds_list_t list) { 

}

unsigned long nds_list_size(const nds_list_t list) { 

}
 
void nds_list_link(nds_list_t l1, nds_list_t l2) { 

}

void nds_list_insert_after(nds_list_t l1, nds_list_t l2) { 

}

void nds_list_insert_before(nds_list_t l1, nds_list_t l2) { 

}
 
void nds_list_remove(nds_list_t l, nds_lnode_t node) { 

}

void nds_list_search(nds_list_t l, const nds_compar_func_t comp_f, void *value) { 

}

void nds_list_write(nds_list_t l) { 

}

void nds_list_read(nds_list_t l) { 

}
