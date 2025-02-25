#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode* next;
};
typedef struct ListNode ListNode;
ListNode* create(int n) {
    ListNode* phead = NULL, * tail = NULL;
    for (int i = 0; i < n; i++) {
        ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
        if (newnode == NULL) {
            perror("malloc fail");
            return NULL;
        }
        newnode->val = i + 1;
        newnode->next = phead ? phead : newnode;//智能自环
        if (!phead) {
            phead = tail = newnode;
        }
        else {
            tail->next = newnode;
            tail = newnode;
        }
    }
    return phead;
}


int ysf(int n, int m) {
    ListNode* phead = create(n);
    if (!phead) {
        return -1; 
    }
    ListNode* cur = phead;
    ListNode* prev = phead;
    //定位前一个节点
    while (prev->next != phead) {
        prev = prev->next;
    }
    int i = 1;
    while (cur->next != cur) {
        if (i == m) {
            prev->next = cur->next;
            free(cur);
            cur = prev->next;
            i = 1;
        }
        else {
            prev = cur;
            cur = cur->next;
            i++;
        }
    }
    int res = cur->val;
    free(cur);
    return res;
}
