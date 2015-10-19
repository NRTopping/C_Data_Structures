#ifndef NDS_LNODE_H_
#define NDS_LNODE_H_

#include <stdlib.h>
#include <stdio.h>
//#include <NDS/types.h>
#include "types.h"

typedef struct nds_lnode {
  struct nds_lnode *next;
  struct nds_lnode *prev;
  nds_element_t    *data;
} *nds_lnode_t;

/**
 * @brief Create NDS List Node. 
 *
 * Allocates memory needed for an nds_lnode. Does not allocate any memory for
 * data stored inside the node. This data structure should be destroyed by using
 * the nds_lnode_free function.
 *
 * @return allocated nds_lnode_t with all fields set to NULL on success
 * @return NULL if insufficient memory. 
 */
extern nds_lnode_t nds_lnode_alloc(); 

/**
 * @brief Frees NDS List Node. 
 *
 * Frees all memory allocated by nds_lnode_alloc, does not any memory allocated
 * to the data contained within the node.
 *
 * @pre node must be non-null
 * @param node the node to free
 * @return the data stored within the node, without modification (an
 * nds_element_t)
 */
extern nds_element_t nds_lnode_free(nds_lnode_t node); 

/**
 * @brief Get the Next Node in the Data Structure 
 *
 * Gets the value contained in the next field of the given nds_lnode_t
 *
 * @pre node must be non-null
 * @param node the node to get the next element from
 * @return the value contained within node->next (an nds_lnode_t)
 */
extern nds_lnode_t nds_lnode_get_next(nds_lnode_t node); 

/**
 * @brief Get the Previous Node in the Data Structure
 * 
 * Gets the value containe in the prev field of the given nds_lnode_t
 *
 * @pre node must be non-null
 * @param node the node to get the previous element from
 * @return the value contained within node->prev (an nds_lnode_t)
 */
extern nds_lnode_t nds_lnode_get_prev(nds_lnode_t node); 

/**
 * @brief Get the Node's Data
 *
 * Gets the value contained within the given node's data field
 *
 * @pre node must be non-null
 * @param node the value to get the data from 
 * @return the value contained within node->data (an nds_element_t) 
 */
extern nds_element_t nds_lnode_get_data(nds_lnode_t node); 

/**
 * TODO
 */
extern void nds_lnode_set_next(nds_lnode_t node, nds_lnode_t next);

/**
 * TODO 
 */
extern void nds_lnode_set_prev(nds_lnode_t node, nds_lnode_t prev); 

/**
 * TODO 
 * Sets n1's next value to n2, and n2's previous value to n1
 */
extern void nds_lnode_link(nds_lnode_t n1, nds_lnode_t n2); 

/**
 * TODO 
 * Sets n1's next value to NULL and n2's previous value to NULL
 */
extern void nds_lnode_unlink(nds_lnode_t n1, nds_lnode_t n2); 

/**
 * TODO 
 */
extern void nds_lnode_write(const nds_lnode_t node, 
    const nds_write_func_t write_func, FILE *fp);

/**
 * TODO 
 */
extern nds_lnode_t nds_lnode_read(const nds_read_func_t read_func, FILE *fp);
#endif /* NDS_LNODE_H_ */ 
