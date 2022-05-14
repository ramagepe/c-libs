#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct {
    char* key;
    char* value;
} ht_item;

typedef struct {
    int size;
    int count;
    ht_item** items;
} hash_table;

static const int HT_PRIME_1 = 151;
static const int HT_PRIME_2 = 131;

static ht_item HT_DELETED_ITEM = {NULL, NULL};

hash_table* ht_new_hash_table(int init_size);
void ht_delete_hash_table(hash_table* ht);
void ht_insert(hash_table* ht, char* key, char* value);
char* ht_search(hash_table* ht, const char* key);
void ht_delete(hash_table* ht, const char* key);
void ht_print_all(hash_table* ht);
void ht_print(hash_table* ht);