#ifndef HASH_TABLE_HASH_TABLE_H
#define HASH_TABLE_HASH_TABLE_H

//standard headers
#include <string.h>

//custom headers
#include "error.h"

typedef struct table_t {
    void **table_ptr;
    size_t T_size;
} table_t;

typedef struct tab_node_t {
    void *key;
    void *value;
    struct tab_node_t *next;
} tab_node_t;

//generating hash function
int get_hash(void *key, table_t *table);

//hashtable initializer
void ht_init(table_t *table, size_t ht_size);

//searching by a key - returns hashtable item with appropriate key
tab_node_t *ht_search(table_t *table, void *key);

//inserting a new item to the hashtable
void ht_insert(table_t *table, void *key, void *value);

//get a value from node with appropriate key, if there is any
void *ht_get(table_t *table, void *key);

//delete item with a given key from collection with same hash
//used by ht_delete function
void ht_list_delete(tab_node_t **list, void *key);

//delete item with a given key
void ht_delete(table_t *table, void *key);

//delete all and free table
void ht_destroy(table_t *table);

//delete all items of a hashtable
void ht_delete_all(table_t *table);

#endif //HASH_TABLE_HASH_TABLE_H
