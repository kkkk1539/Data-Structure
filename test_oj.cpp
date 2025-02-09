#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
 struct ListNode {
     int val;
     struct ListNode *next;
 };
 
//struct ListNode* reverseList(struct ListNode* head) {
//    if (head == NULL || head->next == NULL) {
//        return head;
//    }
//    struct ListNode* newhead = reverseList(head->next);
//    head->next->next = head;
//    head->next = NULL;
//    return newhead;
//}

 //struct ListNode* reverseList(struct ListNode* head) {
 //    if (!head || !head->next)
 //        return head;
 //    struct ListNode* n1 = head;
 //    struct ListNode* n2 = head->next;
 //    struct ListNode* n3 = n2->next;
 //    n1->next = NULL;
 //    while (n2) {
 //        n2->next = n1;
 //        n1 = n2;
 //        n2 = n3;
 //        if (n3) {
 //            n3 = n3->next;
 //        }
 //    }
 //    return n1;
 //}
 // 
 //struct ListNode* reverseList(struct ListNode* head) {
 //    struct ListNode* newhead = NULL;
 //    struct ListNode* cur = head;
 //    while (cur) {
 //        struct ListNode* tmp = cur->next;
 //        cur->next = newhead;
 //        newhead = cur;
 //        cur = tmp;
 //    }
 //    return newhead;
 //}
 //struct ListNode* removeElements(struct ListNode* head, int val) {
 //    struct ListNode* prev = NULL;
 //    struct ListNode* cur = head;
 //    while (cur) {
 //        if (cur->val != val) {
 //            prev = cur;
 //            cur = cur->next;
 //        }
 //        else {
 //            if (prev == NULL) {
 //                head = cur->next;
 //                free(cur);
 //                cur = head;
 //            }
 //            else {
 //                prev->next = cur->next;
 //                free(cur);
 //                cur = prev->next;
 //            }
 //        }
 //    }
 //}
 //struct ListNode* middleNode(struct ListNode* head) {
 //    size_t i = 0;
 //    struct ListNode* cur = head;
 //    while (cur->next != NULL) {
 //        cur = cur->next;
 //        i++;
 //    }
 //    cur = head;
 //    i = i / 2;
 //    while (i--) {
 //        cur = cur->next;
 //    }
 //    return cur;
 //}

 
 //struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
 //    if (!list1) return list2;
 //    if (!list2) return list1;

 //    struct ListNode* newhead = NULL;
 //    struct ListNode* tail = NULL;

 //    if (list1->val < list2->val) {
 //        newhead = list1;
 //        list1 = list1->next;
 //    } else {
 //        newhead = list2;
 //        list2 = list2->next;
 //    }
 //    tail = newhead;

 //    while (list1 && list2) {
 //        if (list1->val < list2->val) {
 //            tail->next = list1;
 //            list1 = list1->next;
 //        } else {
 //            tail->next = list2;
 //            list2 = list2->next;
 //        }
 //        tail = tail->next;
 //    }
 //    tail->next = list1 ? list1 : list2;
 //    return newhead;
 //}
 int main() {
     struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
     struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
     struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
     struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
     struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));

     n1->val = 1;
     n2->val = 2;
     n3->val = 3;
     n4->val = 4;
     n5->val = 5;

     n1->next = n2;
     n2->next = n3;
     n3->next = n4;
     n4->next = n5;
     n5->next = NULL;
    /* printf("%d", middleNode(n1)->val);*/
     //reverseList(n1);
     return 0;
 }