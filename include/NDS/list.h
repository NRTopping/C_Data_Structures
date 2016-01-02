#ifndef NDS_LIST_H_
#define NDS_LIST_H_

//#include <NDS/types.h>
#include "types.h"
//#include <NDS/lnode.h>
#include "lnode.h"
#include <stdbool.h>

typedef struct nds_list { 
  nds_lnode_t beg;  // begining of list
  nds_lnode_t end;  // end of list 
  nds_size    size; // size of the list 
  //char         *id;   // optional identifier for the list

  nds_alloc_func_t  alloc_func;  // element allocator for the list
  nds_free_func_t   free_func;   // element deallocater for the list
} *nds_list_t; 

/**
 * @brief Create NDS List
 *
 * Allocates memory needed for an nds_list_t. Initializes function fields to the
 * given values. If a null value is passed in for a necessary function, the
 * default function will be used. 
 *
 * @param alloc_func function used to allocate nds_element_t values in the list
 * @param free_func function used to deallocate nds_element_t values in the list
 * @return an allocated nds_list_t that will need to be freed with nds_list_free
 * on success
 * @return NULL on failure (run out of memory)
 */
extern nds_list_t nds_list_alloc(const nds_alloc_func_t alloc_func, 
    const nds_free_func_t free_func);

/**
 * @brief Frees NDS List
 *
 * Frees a list allocated with nds_list_alloc. Will also free all data contained
 * within the list (does so by calling nds_list_flush). 
 *
 * @param list the nds_list_t list to free. Shoulbe be non-null. 
 * @return void
 */
extern void nds_list_free(nds_list_t list);

/**
 * @brief Flush Data in NDS List
 *
 * This function frees any data that was added to the given nds_list_t after it
 * was allocated. This function will not free the structure of the list itself -
 * only the data.
 *
 * @pre list should be non-null
 * @param list the list to flush
 * @return void
 */
extern void nds_list_flush(nds_list_t list); 

/**
 * @brief See if List is Empty
 *
 * This function checks to see whether or not the size (from nds_list_size) is
 * equivalent to 0. If so this function returns true, otherwise it returns
 * false.
 *
 * @pre list should be initialized, and non-null
 * @param list the list to check for emptiness 
 * @return true if list is empty, false if not
 */
extern bool nds_list_is_empty(const nds_list_t list);

/**
 * @brief Get Size of List
 *
 * This function returns the current size of the list 
 *
 * @pre list should be non-null and initialized
 * @param list the list to get the size of
 * @return an nds_size value indicating the size of the list
 */
extern nds_size nds_list_size(const nds_list_t list);

/**
 * @brief Get the First Element of List
 *
 * This function returns the first element in the list. If there are no elements
 * in the list, null will be returned.
 *
 * @pre list is initialized and non-null
 * @param list the list to get the first element from 
 * @return the value of the first element, otherwise it returns null
 */
extern nds_element_t nds_list_get_head(const nds_list_t list); 

/**
 * @brief Get the Last Element of List
 *
 * This function returns the last element in the list. If there are no elements
 * in the list, null will be returned. 
 *
 * @pre list is initialized and non-null
 * @param list the list to get the last element from 
 * @return the value of the first element, otherwise it returns null
 */
extern nds_element_t nds_list_get_tail(const nds_list_t list); 
extern nds_element_t nds_list_insert_head(const nds_list_t list); 
extern nds_element_t nds_list_insert_tail(const nds_list_t list); 
extern nds_element_t nds_list_remove_head(const nds_list_t list); 
extern nds_element_t nds_list_remove_tail(const nds_list_t list); 
extern nds_element_t nds_list_remove(const nds_list_t list, 
    const nds_compar_func_t compar_func, const nds_element_t element);
extern void nds_list_delete_head(const nds_list_t list); 
extern void nds_list_delete_tail(const nds_list_t list); 
extern void nds_list_delete(const nds_list_t list, 
    const nds_compar_func_t compar_func, const nds_element_t element); 
extern nds_element_t nds_list_search(const nds_list_t list, 
    const nds_compar_func_t compar_func, const nds_element_t element);
extern void nds_list_sort(const nds_list_t list, 
    const nds_compar_func_t compar_func); 
extern nds_list_t nds_list_join(nds_list_t l1, nds_list_t l2);
extern nds_element_t nds_list_map_forward(const nds_list_t list, 
    const nds_map_func_t map_func, void *user_data);
extern nds_element_t nds_list_map_backward(const nds_list_t list, 
    const nds_map_func_t map_func, void *user_data);
extern void nds_list_write(nds_list_t l, const nds_write_func_t write_func, FILE *fp); 
extern nds_list_t nds_list_read(const nds_read_func_t read_func, FILE *fp); 

// TODO iterator functions (own file?)
// TODO merge function
// TODO default free and alloc functions for data

#endif /* NDS_LIST_H_ */
