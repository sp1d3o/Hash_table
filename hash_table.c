#include "hash_table.h"

int get_hash(void *key, table_t *table)
{
    int res = 1;
    int length = strlen(key);

    for(int i = 0; i < length; i++) {
        res += ((char *)key)[i];
    }
    return (res % table->T_size);
}

void ht_init(table_t *table, size_t ht_size)
{
    table->T_size = ht_size;
    table->table_ptr = (void *)malloc(table->T_size * sizeof(tab_node_t *));

    if(table->table_ptr == NULL) {
        malloc_error(__func__);
    }

    for(size_t i = 0; i < table->T_size; i++) {
        table->table_ptr[i] = NULL;
    }
}

tab_node_t *ht_search(table_t *table, void *key)
{
    int hash = get_hash(key, table);
    tab_node_t *item = (*table).table_ptr[hash];

    while(item != NULL) {
        if(strcmp(key, item->key) == 0) {
            return item;
        }
        item = item->next;
    }
    return NULL;
}

void ht_insert(table_t *table, void *key, void *value)
{
    tab_node_t *item = ht_search(table, key);

    if(item != NULL) {
        item->value = value;
        return;
    }

    int hash = get_hash(key, table);
    tab_node_t *nextItem = (*table).table_ptr[hash];

    item = malloc(sizeof(tab_node_t));
    if(item == NULL) {
        malloc_error(__func__ );
    }

    strcpy(item->key, key);
    item->value = value;
    item->next = nextItem;

    (*table).table_ptr[hash] = item;
}

void *ht_get(table_t *table, void *key)
{
    tab_node_t *item = ht_search(table, key);

    if(item != NULL) {
        return item->value;
    }

    return NULL;
}

void ht_list_delete(tab_node_t **list, void *key)
{
    if(list != NULL && strcmp((*list)->key, key) == 0) {
        tab_node_t *temp = *list;
        *list = (*list)->next;
        free(temp->key);
        free(temp->value);
        free(temp);
    }
    else {
        ht_list_delete(&((*list)->next), key);
    }
}

void ht_delete(table_t *table, void *key)
{
    int hash = get_hash(key, table);

    if((*table).table_ptr[hash] != NULL) {
        ht_list_delete((tab_node_t **)(&((*table).table_ptr[hash])), key);
    }
}

void ht_destroy(table_t *table)
{
    ht_delete_all(table);
    free(table->table_ptr);
    free(table);
}

void ht_delete_all(table_t *table)
{
    for(size_t i = 0; i < table->T_size; i++) {
        tab_node_t *item = (*table).table_ptr[i];

        while(item != NULL) {
            tab_node_t *removedItem = item;
            item = item->next;
            free(removedItem->key);
            free(removedItem->value);
            free(removedItem);

            (*table).table_ptr[i] = NULL;
        }
    }
}