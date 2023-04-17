#include "node.h"
#include <stdio.h>
int LRU_cache_put(int newpageno, node_t** head_lru, int cache_capacity) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->page_no = newpageno;
    new_node->next = NULL;
    int length = 1;
    if (*head_lru == NULL) {//只有一个node的情况
        *head_lru = new_node;
        return 1; // cache miss
    }

    // check if the page already exists in the cache
    node_t* last_node = *head_lru;
    node_t* before_last_node = *head_lru;
    node_t* p = *head_lru;
    int flag = 0;//判断是否为首次进入循环
    while (last_node != NULL) {
        if (last_node->page_no == newpageno) {//hit 处理
            p = *head_lru;
            while (p->next != NULL) {
                p = p->next;
                length++;
            }
            p->next = new_node;
            if (flag)
                before_last_node->next = last_node->next;//在链表中删除被访问node
            else
                *head_lru = (*head_lru)->next;//node在链头被删除
            return 0; // cache hit
            }
        
    last_node = last_node->next;
    if (flag) 
        before_last_node = before_last_node->next;
    else 
        flag = 1;//第一次不移动 before_last_node
}
//以下为未命中
    while (p->next != NULL) {
        p = p->next;
        length++;
    }
    p->next = new_node;
   
    if (length == cache_capacity) { 
        p = *head_lru;
        *head_lru = (*head_lru)->next;
        free(p);
    }
    return 1; // cache miss
}
