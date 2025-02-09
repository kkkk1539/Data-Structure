#define _CRT_SECURE_NO_WARNINGS 1
#include"LinkList.h"


LNode* BuyLinkListNode(SLTDateType x) {
	LNode* newNode = (LNode*)malloc(sizeof(LNode));
	if (newNode == NULL) {
		perror("BuyLinkListNode::malloc");
		return NULL;
	}
    newNode->data = x;
    newNode->next = NULL;
	return newNode;
}

void LinkListPrint(LinkList p) {
	while (p != NULL) {
		printf("%d->",p->data);
		p = p->next;
	}
	printf("NULL\n");
}

void LinkListPushBack(LNode** pplist, SLTDateType x) {
    assert(pplist);
    // 创建一个新节点
    LNode* newNode = BuyLinkListNode(x);
   
    // 如果链表为空，直接将新节点作为头节点
    if (*pplist == NULL) {
        *pplist = newNode;
    } else {
        // 否则，找到链表的尾节点并将新节点添加到尾部
        LNode* tail = *pplist;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = newNode;
    }
}

void LinkListPushFront(LNode** pplist, SLTDateType x) {
    assert(pplist);
    // 创建一个新节点
    LNode* newNode = BuyLinkListNode(x);

    // 将新节点的 next 指针指向当前的头节点
    newNode->next = *pplist;

    // 更新头节点为新节点
    *pplist = newNode;
}

void LinkListPopBack(LNode** pplist) {
    assert(pplist);
    assert(*pplist);
    LNode* tail = *pplist;
    if (tail->next == NULL) {
        free(tail);
        *pplist = NULL;
        return;
    }
    while (tail->next->next != NULL) {
        tail = tail->next;
    }
    //需注意内存释放
    free(tail->next);
    tail->next = NULL;
}

void LinkListPopFront(LNode** pplist) {
    assert(pplist);
    assert(*pplist);
    //需注意内存释放
    LNode* temp = *pplist; // 保存当前头节点的指针
    *pplist = (*pplist)->next; // 更新头节点为下一个节点
    free(temp); // 释放旧头节点的内存
}

LNode* LinkListFind(LNode* plist, SLTDateType x) {
    assert(plist);
    LNode* cur = plist;
    while (cur) {
        if (cur->data == x) {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

void LinkListInsertAfter(LNode* pos, SLTDateType x) {
    LNode* newNode = BuyLinkListNode(x);
    if (pos != NULL) {
        newNode->next = pos->next;
        pos->next = newNode;
    }
    
}

void LinkListEraseAfter(LNode* pos) {
    assert(pos); // 确保 pos 不为空
    if (pos->next == NULL) {
        return; // 如果 pos 之后没有节点，直接返回
    }
    LNode* tmp = pos->next; // 保存要删除的节点
    pos->next = pos->next->next; // 更新链表结构，跳过要删除的节点
    free(tmp); // 释放内存
    tmp = NULL; // 将指针置为空，防止悬空指针
}
