#include "hash_table.h"

int main() {
    hash_table* ht = ht_new_hash_table(53);
    ht_insert(ht, "apples", "yummy");
    ht_insert(ht, "carrots", "meh");
    ht_insert(ht, "melons", "brrrrrrr");
    ht_insert(ht, "chocolate", "yupiiiiiii");
    ht_insert(ht, "jojoba", "what?");
    char* found = ht_search(ht, "cacahuates");
    printf("FOUND = %s\n", found);
    ht_delete(ht, "apples");
    // ht_print(ht);
}