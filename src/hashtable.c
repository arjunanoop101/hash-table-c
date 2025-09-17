#include<stdlib.h>
#include<string.h>

#include"hashtable.h"

static ht_item* ht_new_item(const char* k, const char* v){
    ht_item* i = malloc(sizeof(ht_item));
    i->key = strdup(k);
    i->value = strdup(v);
    return i;
}

ht_hash_table* ht_new() {
    ht_hash_table* ht = malloc(sizeof(ht_hash_table));

    ht->size = 53;
    ht->count = 0;
    ht->items = calloc((size_t)ht->size, sizeof(ht_item*));
    return ht;
}

// delete one key value pair
static void ht_del_item(ht_item* i){
    free(i->key);
    free(i->value);
    free(i);

}

//delete hash table
void ht_del_hash_table(ht_hash_table* ht){
    for(int i=0;i< ht->size;i++){
        ht_item* item = ht->items[i];
        if(item != NULL){
            ht_del_item(item);
        }
    }
    free(ht->items);
    free(ht);
}

// main.c


int main() {
    ht_hash_table* ht = ht_new();
    ht_del_hash_table(ht);
}