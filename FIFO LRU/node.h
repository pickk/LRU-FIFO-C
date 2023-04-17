#ifndef NODE_H
#define NODE_H

typedef struct node {
    int page_no;
    struct node* next;
} node_t;
int FIFO_cache_put(int Newpageno, node_t** head_fifo, int cache_capacity);
int LRU_cache_put(int newpageno, node_t** head_lru, int cache_capacity);
#endif /* node */
