#include "node.h"
#include <stdio.h>
int FIFO_cache_put(int Newpageno, node_t** head_fifo, int cache_capacity) {
    int length = 0;
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->page_no = Newpageno;
    new_node->next = NULL;
    if (*head_fifo==NULL) {//没有链表
        *head_fifo = new_node;
        return 1; // 创建，miss返回1
    }

    // find the last node
    node_t* last_node = *head_fifo;
   while (last_node != NULL){ 
       if (last_node->page_no == Newpageno) {//寻找页号
            free(new_node);//找到对应页号
            return 0; // cache hit
        }
            last_node = last_node->next;
            length++;

  } 
   last_node = *head_fifo;
   while (last_node->next != NULL) {//没有找到对应页号
       last_node = last_node->next;
   }
    if (cache_capacity == 1) {
        *head_fifo = new_node;
        free(last_node);
    }
    else {
        last_node->next = new_node; // 尾插法放入node
        if (length == cache_capacity) {
            node_t* p = *head_fifo;
            *head_fifo = (*head_fifo)->next;
            free(p);//删除链头node
        }
        return 1; 
    }
}
