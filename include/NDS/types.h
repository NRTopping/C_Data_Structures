#ifndef NDS_GENERAL_H_
#define NDS_GENERAL_H_

typedef void* nds_element_t; 

typedef nds_element_t(* nds_alloc_func_t)(void *data);
typedef void(* nds_free_func_t)(nds_element_t e);
typedef nds_element_t(* nds_copy_func_t)(const nds_element_t e);
typedef int(* nds_compar_func_t)(const nds_element_t e, void *value);
typedef int(* nds_write_func_t)(const nds_element_t e);
typedef nds_element_t(* nds_read_func_t)(const nds_element_t e);
#endif /* NDS_GENERAL_H_ */
