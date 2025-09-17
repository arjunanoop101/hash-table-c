typedef struct {
    char *key;  // key string
    char* value; //value string
}  ht_item;



typedef struct {
    int size;  // size of hash table
    int count; // number of spaces filled in hashtable
    ht_item** items;  // array of ht_items
} ht_hash_table;



void ht_insert(ht_hash_table* ht, const char* key, const char* value);
char* ht_search(ht_hash_table* ht, const char* key);
void ht_delete(ht_hash_table* h, const char* key);