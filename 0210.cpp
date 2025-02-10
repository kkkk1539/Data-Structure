#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
struct ListNode {
    int val;
    struct ListNode* next;
};
struct  ListNode* partition(ListNode* pHead, int x) {
    struct ListNode* Lguard, * Ltail, * Gguard, * Gtail;
    Lguard = Gguard = (struct ListNode*)malloc(sizeof(struct ListNode));
    Ltail = Gtail = (struct ListNode*)malloc(sizeof(struct ListNode));
    Ltail->next = Gtail->next = NULL;
    struct ListNode* cur = pHead;
    while (cur) {
        if (cur->val < x) {
            Ltail->next = cur;
            Ltail = Ltail->next;
        }
        else {
            Gtail->next = cur;
            Gtail = Gtail->next;
        }
        cur = cur->next;
    }
    Ltail->next = Gguard->next;
    Gtail->next = NULL;
    pHead = Lguard->next;
    free(Gguard);
    return pHead;
}
//
//bool isPalindrome(struct ListNode* head) {
//    struct ListNode* mid = middle(head);
//    struct ListNode* rhead = reverse(mid);
//    while (head && rhead) {
//        if (head->val != rhead->val) {
//            return false;
//        }
//        head = head->next;
//        rhead = rhead->next;
//    }
//    return true;
//}

int main() {
    struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    //struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));

    n1->val = 1;
    n2->val = 1;
    n3->val = 2;
    n4->val = 1;
    //n5->val = 5;

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL;
    //n5->next = NULL;
    //partition(n1, 5);
    isPalindrome(n1);
    return 0;
}