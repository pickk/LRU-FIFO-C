#include "node.h"

#include <stdio.h> 
FILE* fp;
//尾插法实现先进先出
void r_print(node_t* head);
int main()
{
    int capacity;
    int quantity_of_the_pages;
    int page_number;
    int missing_in_FIFO = 0;
    int missing_in_LRU = 0;
    int n;
    node_t* head_fifo;
    node_t* head_lru;
    head_fifo = NULL;
    head_lru = NULL;
    scanf_s("%d", &capacity);
    scanf_s("%d", &quantity_of_the_pages);
    fp = fopen_s(&fp,"example.txt", "w"); // 打开文件
    if (fp == NULL) { // 检查文件是否成功打开
        printf("Error opening file\n");
        return 1;
    }
    for (n = 0; n < quantity_of_the_pages; n++) {
        scanf_s("%d", &page_number);
        printf("After assessing %d, the elements in FIFO cache :", n + 1); 
        fprintf(fp, "After assessing %d, the elements in FIFO cache :", n + 1); // 将文本内容写入文件
        if (FIFO_cache_put(page_number, &head_fifo, capacity))
            missing_in_FIFO++;
        r_print(head_fifo);
        printf(" the elements in LRU cache:");
        fprintf(fp, " the elements in LRU cache : ");
        if (LRU_cache_put(page_number, &head_lru, capacity))
            missing_in_LRU++;
        r_print(head_lru);
        printf("\n");
    }    fclose(fp); // 关闭文件
    printf("Total times of missing in FIFO : %d\nTotal times of missing in LRU : %d", missing_in_FIFO, missing_in_LRU);
}
void r_print(node_t* head) {
    if (head == NULL) {
        return;
    }
    r_print(head->next);
    printf("%d ", head->page_no);
    fprintf(fp, "%d ", head->page_no);
}