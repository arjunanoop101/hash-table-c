#ifndef HASHTABLE_H
#define HASHTABLE_H

#define HT_INITIAL_BASE_SIZE 50
#define HT_PRIME_1 151
#define HT_PRIME_2 163

// One key-value pair
typedef struct {
    char* key;
    char* value;
} ht_item;

// Hash table structure
typedef struct {
    int base_size;   // base size (used for resizing)
    int size;        // actual size (prime number >= base_size)
    int count;       // number of elements stored
    ht_item** items; // array of pointers to items
} ht_hash_table;

// API
ht_hash_table* ht_new();
void ht_insert(ht_hash_table* ht, const char* key, const char* value);
char* ht_search(ht_hash_table* ht, const char* key);
void ht_delete(ht_hash_table* ht, const char* key);
void ht_del_hash_table(ht_hash_table* ht);

#endif
