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
    // ����һ���½ڵ�
    LNode* newNode = BuyLinkListNode(x);
   
    // �������Ϊ�գ�ֱ�ӽ��½ڵ���Ϊͷ�ڵ�
    if (*pplist == NULL) {
        *pplist = newNode;
    } else {
        // �����ҵ������β�ڵ㲢���½ڵ���ӵ�β��
        LNode* tail = *pplist;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = newNode;
    }
}

void LinkListPushFront(LNode** pplist, SLTDateType x) {
    assert(pplist);
    // ����һ���½ڵ�
    LNode* newNode = BuyLinkListNode(x);

    // ���½ڵ�� next ָ��ָ��ǰ��ͷ�ڵ�
    newNode->next = *pplist;

    // ����ͷ�ڵ�Ϊ�½ڵ�
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
    //��ע���ڴ��ͷ�
    free(tail->next);
    tail->next = NULL;
}

void LinkListPopFront(LNode** pplist) {
    assert(pplist);
    assert(*pplist);
    //��ע���ڴ��ͷ�
    LNode* temp = *pplist; // ���浱ǰͷ�ڵ��ָ��
    *pplist = (*pplist)->next; // ����ͷ�ڵ�Ϊ��һ���ڵ�
    free(temp); // �ͷž�ͷ�ڵ���ڴ�
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
    assert(pos); // ȷ�� pos ��Ϊ��
    if (pos->next == NULL) {
        return; // ��� pos ֮��û�нڵ㣬ֱ�ӷ���
    }
    LNode* tmp = pos->next; // ����Ҫɾ���Ľڵ�
    pos->next = pos->next->next; // ��������ṹ������Ҫɾ���Ľڵ�
    free(tmp); // �ͷ��ڴ�
    tmp = NULL; // ��ָ����Ϊ�գ���ֹ����ָ��
}
