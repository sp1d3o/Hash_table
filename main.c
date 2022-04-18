#include "hash_table.h"

int main(int argc, char *argv[])
{
    //initialize hashtable
    table_t *hashtable = malloc(sizeof(table_t));
    ht_init(hashtable, (size_t)128);

    //prepare hashtable content
    char *keys[1] = {"test"};
    int *valptr = malloc(sizeof(int));
    if(valptr == NULL) {
        ERR_MEMFAIL;
    }

    *valptr = 5;

    ht_insert(hashtable, keys[0], valptr);

    //TEST: ht_search

    tab_node_t *search_res = ht_search(hashtable, keys[0]);
    printf("%s, %d\n", (char *)search_res->key, *(int *)search_res->value);

    //TEST: ht_get
    printf("%d\n", *(int *) ht_get(hashtable, keys[0]));

    //TEST: ht_delete
    ht_delete(hashtable, keys[0]);

    if(ht_get(hashtable, keys[0]) == NULL) {
        printf("No element found in the hashtable under the key: %s\n", keys[0]);
    }

    ht_destroy(hashtable);

    return 0;
}
