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
 * @brief Get the Next NDS List Node in the Data Structure 
 *
 * Gets the value contained in the next field of the given nds_lnode_t
 *
 * @pre node must be non-null
 * @param node the node to get the next element from
 * @return the value contained within node->next (an nds_lnode_t)
 */
extern nds_lnode_t nds_lnode_get_next(nds_lnode_t node); 

/**
 * @brief Get the Previous NDS List Node in the Data Structure
 * 
 * Gets the value containe in the prev field of the given nds_lnode_t
 *
 * @pre node must be non-null
 * @param node the node to get the previous element from
 * @return the value contained within node->prev (an nds_lnode_t)
 */
extern nds_lnode_t nds_lnode_get_prev(nds_lnode_t node); 

/**
 * @brief Get the NDS List Node's Data
 *
 * Gets the value contained within the given node's data field
 *
 * @pre node must be non-null
 * @param node the value to get the data from 
 * @return the value contained within node->data (an nds_element_t) 
 */
extern nds_element_t nds_lnode_get_data(nds_lnode_t node); 

/**
 * @brief Set the NDS List Node's Next Node
 *
 * Sets the node that will come after this one in the data structure
 *
 * @pre node must be non-null
 * @param node the nds_lnode_t that's next field will be changed
 * @param next the new value for node's next field
 * @return void
 */
extern void nds_lnode_set_next(nds_lnode_t node, nds_lnode_t next);

/**
 * @brief Set the NDS List Node's Prev Node
 *
 * Sets the node that will come before this one in the data structure
 *
 * @pre node must be non-null
 * @param node the nds_lnode_t that's prev field will be changed
 * @param prev the new value for node's prev field
 * @return void
 */
extern void nds_lnode_set_prev(nds_lnode_t node, nds_lnode_t prev); 

/**
 * @brief Set the NDS List Node's Data
 *
 * Sets the data contained within the given node
 *
 * @pre node must be non-null
 * @param node the nds_lnode_t to set/change data 
 * @param data data to put into node
 * @return void
 */
extern void nds_lnode_set_data(nds_lnode_t node, nds_element_t data); 

/**
 * @brief Link Two NDS List Node's Together
 *
 * Sets n1's next value to n2, and n2's previous value to n1
 *
 * @pre n1 and n2 must both be non-null nodes
 *
 * @param n1 the node that will come first in the linkage
 * @param n2 the node that will come last in the linkage
 * @return void
 */
extern void nds_lnode_link(nds_lnode_t n1, nds_lnode_t n2); 

/**
 * @brief Unlink Two Linked NDS List Node's 
 *
 * Sets n1's next value to NULL and n2's previous value to NULL
 *
 * @pre n1 and n2 must both be non-null nodes. n1 and n2 should be
 * linked to eachother, in the order [n1,n2].
 * @param n1 first node in linkage
 * @param n2 second node in linkage
 * @return void
 */
extern void nds_lnode_unlink(nds_lnode_t n1, nds_lnode_t n2); 

/**
 * @brief Write NDS List Node to File in JSON
 *
 * Writes the given nds_lnode_t to the given file pointer. Will also write the
 * data contained within the node, if write_func is not null. The node will be
 * written in JSON format
 *
 * @pre node and fp must be non-null. fp must point to an open file
 * @post fp will be updated, based on what is written. 
 * @param node the node to write to the file
 * @param write_func the function used to write the data contained within the
 * node to the file 
 * @param fp pointer to an open file that node will be written to
 * @return void
 */
extern void nds_lnode_write(const nds_lnode_t node, 
    const nds_write_func_t write_func, FILE *fp);

/**
 * @brief Read JSON Formatted NDS List Node from File 
 *
 * Reads an nds_lnode_t from the given file. 
 *
 * @pre fp should be non-null and point to an open file
 * @post fp will be updated to position in file after one nds_lnode_t
 * @param read_func function used to read the data contained within the node
 * from the file
 * @param fp a non-null pointer to an open file
 * @return a newly allocated nds_lnode_t, this value will have to be freed with
 * nds_lnode_free
 */
extern nds_lnode_t nds_lnode_read(const nds_read_func_t read_func, FILE *fp);
#endif /* NDS_LNODE_H_ */ 
