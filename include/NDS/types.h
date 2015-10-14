#ifndef NDS_GENERAL_H_
#define NDS_GENERAL_H_

#include <stdio.h>

/**
 * @brief NDS element type
 *
 * All NDS data structures contain a field of this type in order to to hold
 * data. 
 */
typedef void* nds_element_t; 

/**
 * @brief NDS constants
 */
typedef enum { 
  NDS_MAP_STOP = 0,
  NDS_MAP_CONT = 1
} nds_constant_t; 

/**
 * @brief NDS Allocate Element Function Type. 
 *
 * This function type is for allocating an nds_element_t value, based on user
 * provided data. 
 *
 * @param data the data that should be allocated to create a nds_element_t
 * @return a pointer to an nds_element_t value on success
 * @return NULL on failure (generally due to running out of memory)
 */
typedef nds_element_t(* nds_alloc_func_t)(void *data);

/**
 * @brief NDS Free Element Function Type. 
 *
 * This function type is used to free an nds_element_t from memory.
 *
 * @param e the nds_element_t to free, should be non-null
 * @return void
 */
typedef void(* nds_free_func_t)(nds_element_t e);

/**
 * @brief NDS Copy Element Function Type.
 *
 * This function type is used to create an exact copy of the given element. This
 * is useful for some data strcuture types (such as skiplists) or if the user
 * would like to keep a copy of the data after destroying the datastructure.
 *
 * @param e the nds_element_t to make a copy of 
 * @return a copy of e on success
 * @return NULL on failure (generally due to running out of memory)
 */
typedef nds_element_t(* nds_copy_func_t)(const nds_element_t e);

/**
 * @brief NDS Compare Elements Function Type.
 *
 * This function type is used to compare an nds_element_t value to some user
 * provided value (generally another nds_element_t value).
 *
 * @param e the nds_element_t variable contained within the data structure. 
 * @param value the user provided value to compare to
 * @return < 0 if the user data is less than value
 * @return 0 if e is equivalent to value
 * @return > 0 if e is greater than than value
 */
typedef int(* nds_compar_func_t)(const nds_element_t e, void *value);

/**
 * @brief NDS Write Element Function Type.
 *
 * This function is used to write an nds_element_t type to a file. It is
 * suggested that users format their nds_element_t types as JSON when writing to
 * a file - as that is how all data structures in this library are written. 
 * 
 * @param e a non-null nds element
 * @param fp a pointer to the output file
 * @return void
 */
typedef void(* nds_write_func_t)(const nds_element_t e, FILE *fp);

/**
 * @brief NDS Read Element Function Type.
 *
 * This function is used to read in an nds_elemnt_t type. It is suggested that
 * users format their nds_element_t types as JSON when writing to a file, so
 * this function should read in this JSON form. 
 *
 * @param fp the file to read the nds_element_t from
 * @return a non-null nds_element_t if the function successfully read the object
 * @retunr NULL if the function did not successfully read the object. 
 */
typedef nds_element_t(* nds_read_func_t)(FILE *fp);

/**
 *  @brief NDS Map Element Function Type.
 *
 *  This function type is for ampping an nds_element_t variable from an NDS data
 *  structure. 
 *
 *  @param e the mapped nds_element_t value
 *  @return NDS_MAP_STOP if the mapping function should stop
 *  @return NDS_MAP_CONT if the mapping function should continue
 */
typedef int (* nds_map_func_t)(const nds_element_t e);

#endif /* NDS_GENERAL_H_ */
