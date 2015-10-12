#ifndef NDS_LNODE_H_
#define NDS_LNODE_H_

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
//#include <NDS/types.h>
#include "types.h"

typedef struct nds_lnode {
  struct nds_lnode *next;
  struct nds_lnode *prev;
  nds_element_t    *data;
} *nds_lnode_t;

/**
 * TODO 
 */
extern nds_lnode_t nds_lnode_alloc(); 

/**
 * TODO 
 */
extern nds_element_t nds_lnode_free(); 

/**
 * TODO 
 */
extern nds_lnode_t nds_lnode_get_next(nds_lnode_t node); 

/**
 * TODO 
 */
extern nds_lnode_t nds_lnode_get_prev(nds_lnode_t node); 

/**
 * TODO 
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
