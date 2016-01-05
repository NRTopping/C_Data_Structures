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

/**
 * @brief Insert Element at Begining of List
 *
 * This function inserts a new piece of data at the begining of the list. 
 *
 * @pre list should be initialized and non-null
 * @param list the list to insert an element into
 * @param data data to insert into list
 * @return void
 */
extern void nds_list_insert_head(const nds_list_t list, const nds_element_t data); 

/**
 * @brief Insert Element at the End of List
 *
 * This function inserts a new data item at the end of the list.
 *
 * @pre list should be initialized and non-null
 * @param list the list to insert data into
 * @param data data to isnert into list
 * @return void
 */
extern void nds_list_insert_tail(const nds_list_t list, const nds_element_t data); 

/**
 * @brief Remove Element from Beginning of List
 *
 * This function removes the element from the beginning of the list, without
 * freeing the data. Will return null if no data is currently stored in the list
 *
 * @pre list should be initialized and non-null
 * @param list the list to remove data from 
 * @return pointer to element in list that was removed
 */
extern nds_element_t nds_list_remove_head(const nds_list_t list); 

/**
 * @brief Remove Element from End of List
 *
 * This function removes the element from the end of the list, without freeing
 * the data itself. Will return null if no data is currently stored in the list
 *
 * @pre list should be initialized and non-null
 * @param list the list to remove dat from 
 * @return pointer to element in list that was removed
 */
extern nds_element_t nds_list_remove_tail(const nds_list_t list); 

/**
 * @brief Remove Specific Element From List
 *
 * This function removes the first element of a specific value from a list,
 * without freeing the data itself. Will return null if no data is currently
 * stored in the list, or if the value was not found.
 *
 * @pre list should be initialized and non-null. comparFunc should be non-null
 * @param list the list to search through
 * @param comparFunc function used to compare elements in the list to eachother
 * @param element the element to remove from the list. Can be null
 * @return the element that was removed from the list, or NULL if no value
 * found.
 */
extern nds_element_t nds_list_remove(const nds_list_t list, 
    const nds_compar_func_t comparFunc, const nds_element_t element);

/**
 * @brief Delete First Element in List
 *
 * This function removes the first element from the list, and frees the data
 * allocated to the element using the free_func stored in the list. 
 *
 * @pre list should be non-null and initialized. list should have been
 * initialized with a free_func that corresponds to the data stored in the list
 * @param list the list to delete the head element from 
 * @return void
 */
extern void nds_list_delete_head(const nds_list_t list); 

/**
 * @brief Delete Last Element in List
 *
 * This function removes the last element from the list, and frees the data
 * allocated to the element using the free_func stored in the list. 
 *
 * @pre list should be non-null and initialized. list should have been
 * initialized with a free_func that corresponds to the data stored in the list
 * @param list the list to delete the head element from 
 * @return void
 */
extern void nds_list_delete_tail(const nds_list_t list); 

/**
 * @brief Deletes Element in List
 *
 * This function deletes the first instance of an element in the given list, and
 * frees the data allocated to the element using the free_func store in the list.
 * 
 * @pre list should be non-null and initialized. list should have been
 * initialized with a free_func that corresponds to the data stored in the list
 * @param list the list to delete the element from
 * @param comparFunc comparison function used to compare elements in the list
 * to eachother
 * @param element the element to find in the list, can be null if comparFunc
 * uses other means to find element.
 * @return void
 */
extern void nds_list_delete(const nds_list_t list, 
    const nds_compar_func_t comparFunc, const nds_element_t element); 

/**
 * @brief Searches for Element in the List 
 *
 * This function searches the list to see if the element given is in the
 * function. Essentially comparable to nds_list_contains, but returns NULL or
 * the value rather than a boolean. 
 *
 * @pre list should be non-null and initialized. 
 * @param list the list to search
 * @param comparFunc the function used to compare two nds_element_t's in list
 * together
 * @param element the element to search for
 * @return a pointer to the first instance of the data on success, NULL on
 * failure.
 */
extern nds_element_t nds_list_search(const nds_list_t list, 
    const nds_compar_func_t comparFunc, const nds_element_t element);

extern nds_element_t nds_list_search_min(const nds_list_t list,
    const nds_compar_func_t comparFunc);
extern nds_element_t nds_list_search_max(const nds_list_t list, 
    const nds_compar_func_t comparFunc);
/**
 * @brief Determines if Given Element in List
 *
 * This function searches the list for the given element. If the list contains
 * at least one instance of the given element, then this function will return
 * true. Otherwise this function will return false.
 *
 * @pre list should be non-null and initialized 
 * @param list the list to search
 * @param comparFunc the function used to compare two nds_element_t values in
 * the list together
 * @param element the element to search for
 */
extern bool nds_list_contains(const nds_list_t list, 
    const nds_compar_func_t comparFunc, const nds_element_t element);
extern void nds_list_sort(const nds_list_t list, 
    const nds_compar_func_t comparFunc); 
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
