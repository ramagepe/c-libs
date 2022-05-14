#include "hash_table.h"

// Creates a new hash table item.
static ht_item *ht_new_item(char *key, char *value) {
  ht_item *item = malloc(sizeof(ht_item));
  item->key = key;
  item->value = value;
  return item;
}

// Initializes a new hash table.
hash_table *ht_new_hash_table(int init_size) {
  hash_table *ht = malloc(sizeof(hash_table));
  ht->size = init_size;
  ht->count = 0;
  ht->items = calloc((size_t)init_size, sizeof(ht_item));
  return ht;
}

// Deletes a hash table item.
static void ht_delete_item(ht_item *item) {
  free(item->value);
  free(item->key);
  free(item);
}

// Removes a hash table and all its items.
void ht_delete_hash_table(hash_table *ht) {
  for (int i = 0; i < ht->size; i++) {
    ht_item *item = ht->items[i];
    if (item != NULL) {
      ht_delete_item(item);
    }
  }
  free(ht->items);
  free(ht);
}

// Hash generator returning the index where an item is or will be stored.
static int ht_hash(const char *s, const int attempt, const int num_buckets) {
  long hash = 0;
  const int str_len = strlen(s);
  for (int i = 0; i < str_len; i++) {
    hash += (long)pow(attempt, str_len - (i + 1)) * s[i];
    hash = hash % num_buckets;
  }
  return (int)hash;
}

// Double hashing function to deal with collisions.
static int ht_get_hash(const char *s, const int attempt, const int num_buckets) {
  const int hash_a = ht_hash(s, HT_PRIME_1, num_buckets);
  const int hash_b = ht_hash(s, HT_PRIME_2, num_buckets);
  return (hash_a + (attempt * (hash_b + 1))) % num_buckets;
}

static int check_collision(hash_table *ht, int index) {
    ht_item* current_item = ht->items[index];
    int i = 0;
    while (current_item) {
        index = ht_get_hash(current_item->key, i, ht->size);
        current_item = ht->items[index];
        i++;
    }
    return index;
}

void ht_insert(hash_table* ht, char* key, char* value) {
    ht_item* item = ht_new_item(key, value);
    int index = ht_get_hash(key, 0, ht->size);
    index = check_collision(ht, index);
    ht->items[index] = item;
    ht->count++;
}

char* ht_search(hash_table* ht, const char* key) {
    char* found = NULL;
    int index = ht_get_hash(key, 0, ht->size);
    if (ht->items[index]) {
        found = ht->items[index]->value; 
    }
    return found;
}

void ht_delete(hash_table* ht, const char* key) {
    int index = ht_get_hash(key, ht->size, 0);
    ht_item* item = ht->items[index];
    int i = 1;
    while (item) {
        if (item != &HT_DELETED_ITEM) {
            if (strcmp(item->key, key) == 0) {
                ht_delete_item(item);
                ht->items[index] = &HT_DELETED_ITEM;
            }
        }
        index = ht_get_hash(key, ht->size, i);
        item = ht->items[index];
        i++;
    } 
    ht->count--;
}

// ----------------------------------------------------------------

void ht_print_all(hash_table* ht) {
    printf("[ ");
    for (int i = 0; i < ht->size; i++) {
        ht_item* current_item = ht->items[i];
        if (current_item != NULL) {
            printf("{'%s': '%s'}, ", current_item->key, current_item->value);
        } else {
            printf("(NULL), ");
        }
    }
    printf(" ]");
}

void ht_print(hash_table* ht) {
    printf("[ ");
    for (int i = 0; i < ht->size; i++) {
        ht_item* current_item = ht->items[i];
        if (current_item != NULL) {
            printf("{'%s': '%s'}, ", current_item->key, current_item->value);
        }
    }
    printf(" ]");
}