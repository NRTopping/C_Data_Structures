#include "linkedlist_t.h"

/*
 * Initializes an empty linked list data structure. 
 *
 * @param ll       pointer to the linked list structure pointer
 * @param compar   comparison function used to find elements in the list
 * @param freefunc if not null list will free items in this list with the given
 *                 function
 *
 * @return 0 on success, anyting else indicates an error
 * TODO
 */
int linkedlist_init(struct linkedlist_t *ll, int (*compar) (const void*, const void*),
    void (*freefunc) (void*)) { 
  if (ll == NULL) { 
    // TODO set perror value
    return 1; 
  }

  ll->size     = 0; 
  ll->compar   = compar;
  ll->list     = NULL;
  ll->freefunc = freefunc;

  return 0; 
}

/* 
 * Frees memory assigned to list and resets values 
 *
 * @param ll pointer to linked list data structure
 *
 * @return 0 on success, anything else indicates error
 */
int linkedlist_destroy(struct linkedlist_t *ll) { 
  struct llnode_t *p; 

  // clear values
  ll->size   = 0; 
  ll->compar = NULL;
  
  // Free the list
  p = ll->list;
  while (p != NULL) { 
    // if freefunction isn't null, free data in list 
    if (ll->freefunc != NULL) {
      ll->freefunc(p->data);
    }
    // set up for next loop and free node
    p = p->next;
    free(p);
  }

  return 0;  
}

/*
 * Inserts the given data item at the end of the list
 *
 * @param ll   list to add item to
 * @param data data to insert into list
 *
 * @return 0 on success, anything else indicates error
 */
int linkedlist_insert(struct linkedlist_t *ll, void *data) { 
  struct llnode_t *p; 

  if (ll == NULL)         return 1; // TODO 
  else if ( data == NULL) return 1; 

  if (ll->list == NULL) { 
    ll->list = (struct llnode_t*) malloc(sizeof(struct llnode_t));
    if (ll->list == NULL) return 1; // TODO

    ll->list->data = data; 
    ll->list->next = NULL;
  } else { 
    for (p = ll->list; p->next != NULL; p = p->next);
    p->next = (struct llnode_t*) malloc(sizeof(struct llnode_t));
    if (p->next == NULL) return 1; // TODO

    p->next->data = data; 
    p->next->next = NULL;
  }
  
  ll->size += 1; 
  return 0; 
}

/*
 * Inserts the given data at the front of the given list
 *
 * @param ll   list to put data into 
 * @param data data to put in list
 *
 * @return 0 on success, anything else indicates error
 */ 
int linkedlist_insert_first(struct linkedlist_t *ll, void *data) { 
  struct llnode_t *p; 

  if (ll == NULL)        return 1; // TODO
  else if (data == NULL) return 1; // TODO

  p = (struct llnode_t*) malloc(sizeof(struct llnode_t));
  if (p == NULL) return 1; // TODO 

  p->data = data; 
  p->next = ll->list; 
  ll->list = p; 

  ll->size += 1; 
  return 0; 
}

/*
 * Inserts the given item into the list in sorted order. NOTE this assumes that
 * the list is currently sorted, otherwise it will insert the given data infront
 * of the first item larger than it in the list. 
 *
 * @param ll   list to insert data into
 * @param data item to insert into list
 *
 * @return 0 on success, anything else indicates an error
 */
int linkedlist_insert_sorted(struct linkedlist_t *ll, void *data) { 
  struct llnode_t *p, *prev; 

  if (ll == NULL)              return 1; // TODO
  else if (data == NULL)       return 1; 
  else if (ll->compar == NULL) return 1; 

  prev = NULL; 
  for (p = ll->list; p != NULL && ll->compar(data, p->data) < 0; p = p->next) prev = p; 
    
  if (prev == NULL) { 
    ll->list = (struct llnode_t*) malloc(sizeof(struct llnode_t));
    if (ll->list == NULL) return 1; // TODO

    ll->list->data = data; 
    ll->list->next = NULL; 
  } else { 
    p = prev->next; // store temporarily
    prev->next = (struct llnode_t*) malloc(sizeof(struct llnode_t));
    if (prev->next == NULL) return 1; // TODO

    prev->next->data = data; 
    prev->next->next = p; 
  }
 
  ll->size += 1; 
  return 0; 
}

/*
 * Deletes the first occurrence given item from linked list. Assumes that compar
 * was set in the init function of the list. If item is not found in the list,
 * error indicating so is returned. 
 *
 * @param ll   linked list to delete item from 
 * @param data item to delete from the linked list
 *
 * @return 0 on successful deletion of given item, any other value indicates an
 * error. 
 */
int linkedlist_delete(struct linkedlist_t *ll, void *data) { 
  struct llnode_t *p, *prev; 

  if (ll->compar == NULL) { 
    return 1; // TODO 
  }

  prev = NULL;
  for (p = ll->list; p != NULL; p = p->next) { 
    if (ll->compar(p->data, data) == 0) { 
      // restructure list
      if (prev == NULL) { 
        ll->list = ll->list->next;
      } else { 
        prev->next = p->next;
      } 
      
      // free data
      if (ll->freefunc != NULL) { 
        ll->freefunc(p->data);
      }
      free(p);

      ll->size -= 1; 
      return 0; 
    } 
    prev = p; 
  }

  // Data to delete not found.
  return 2;  
}

/*
 * deletes the first item from a given linked list. 
 *
 * @param ll  list to delete the first item from 
 *
 * @return 0 on success, any other value indicates an error
 */
int linkedlist_delete_first(struct linkedlist_t *ll) { 
  struct llnode_t *p; 

  p = ll->list; 
  if (p != NULL) { 
    // restructure list
    ll->list = ll->list->next; 
    
    // free data
    if (ll->freefunc != NULL) { 
      ll->freefunc(p->data);
    }
    free(p);

    ll->size -= 1; 
  }

  return 1; // size error TODO 
}

/*
 * Deletes the last element from the given list
 *
 * @param ll linked list to delete the last item from 
 *
 * @return 0 on success, anything else indicates an error
 */
int linkedlist_delete_last(struct linkedlist_t *ll) { 
  struct llnode_t *p, *prev;  

  prev = NULL;
  for (p = ll->list; p != NULL; p = p->next) { 
    if (p->next == NULL) { 
      // restructure list
      if (prev == NULL) { 
        ll->list = ll->list->next;
      } else { 
        prev->next = p->next;  
      }
      // free data
      if (ll->freefunc != NULL) { 
        ll->freefunc(p->data);
      }
      free(p);

      ll->size -= 1; 
      return 0; 
    } 

    prev = p;
  }

  return 1; // size error
}

/*
 * Deletes the Nth item from the list - 0 based indexed. Will throw an error if
 * the given index is out of bounds
 *
 * @param ll list to delete item from 
 * @param n  Index of item to delete
 *
 * @return 0 on success, any other value indicates an error
 */
int linkedlist_delete_nth(struct linkedlist_t *ll, unsigned long n) { 
  struct llnode_t *p, *prev; 
  unsigned long i; 

  if (n >= ll->size) { 
    return 1; // out of bounds error
  } else if (n == 0) { 
    return linkedlist_delete_first(ll);
  }

  // advance to correct place in list
  prev = NULL;  
  for (i = 0, p = ll->list; i < n && p != NULL; i++, p = p->next);

  // restructure list 
  prev->next = p->next;

  // free data
  if (ll->freefunc != NULL) { 
    ll->freefunc(p->data); 
  }

  free(p);
  ll->size -= 1; 

  return 0; 
}


