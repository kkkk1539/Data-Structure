#define _CRT_SECURE_NO_WARNINGS 1
#include"DCListNode.h"
DCListNode* BuyListNode(DCLDataType x) {
	DCListNode* newNode = (DCListNode*)malloc(sizeof(DCListNode));
	if (newNode == NULL) {
		perror("BuyListNode");
		return NULL;
	}
	newNode->_next = NULL;
	newNode->_prev = NULL;
	newNode->_data = x;
	return newNode;
}

DCListNode* ListCreate() {
	DCListNode* pHead = BuyListNode(-1);
	if (pHead == NULL) {
		perror("ListCreate::BuyListNode");
		return NULL;
	}
	pHead->_next = pHead;
	pHead->_prev = pHead;
	return pHead;
}

void ListDestory(DCListNode* pHead) {
	assert(pHead);
	DCListNode* cur = pHead->_next;
	while (cur != pHead) {
		DCListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	free(pHead);
	pHead = NULL;
}

void ListPrint(DCListNode* pHead) {
	assert(pHead);
	DCListNode* cur = pHead->_next;
	while (cur!=pHead) {
		printf("%d<=>", cur->_data);
		cur = cur->_next;
	}
	printf("из╠Ь╫А╣Ц");
}

void ListPushBack(DCListNode* phead,DCLDataType x) {
	DCListNode* newNode = BuyListNode(x);
	if (newNode == NULL) {
		perror("ListPushBack::BuyListNode");
		return;
	}
	phead->_prev->_next = newNode;
	newNode->_next = phead;
	newNode->_prev = phead->_prev;
	phead->_prev = newNode;
}	

void ListPushFront(DCListNode* phead, DCLDataType x) {
	DCListNode* newNode = BuyListNode(x);
	if (newNode == NULL) {
		perror("ListNodeFront::BuyListNode");
		return;
	}
	phead->_next->_prev = newNode;
	newNode->_prev = phead;
	newNode->_next = phead->_next;
	phead->_next = newNode;
}

void ListPopBack(DCListNode* phead) {
	if (phead->_prev == phead) {
		return; 
	}
	DCListNode* tail = phead->_prev;
	tail->_prev->_next = phead;
	phead->_prev = tail->_prev;
	free(tail);
	tail = NULL;
}

void ListPopFront(DCListNode* phead) {
	if (phead->_next == phead) {
		return;
	}
	DCListNode* head = phead->_next;
	head->_next->_prev = phead;
	phead->_next = head->_next;
	free(head);
	head = NULL;
}

DCListNode* ListFind(DCListNode* phead, DCLDataType x) {
	if (phead->_next == phead) {
		return NULL;
	}
	DCListNode* cur = phead->_next;
	while (cur != phead) {
		if (cur->_data == x) {
			return cur;
		}
		cur=cur->_next;
	}
	return NULL;
}

void ListInsert(DCListNode* pos, DCLDataType x) {
	assert(pos);
	DCListNode* newNode = BuyListNode(x);
	if (newNode == NULL) { 
		perror("ListInsert::BuyListNode");
		return;
	}
	pos->_prev->_next = newNode;
	newNode->_next = pos;
	newNode->_prev = pos->_prev;
	pos->_prev = newNode;
}

void ListErase(DCListNode* pos) {
	assert(pos);
	assert(pos->_prev);
	if (pos->_prev == pos) {
		perror("ListErase::Cannot erase head node");
		return;
	}
	DCListNode* tmp = pos->_prev;
	pos->_prev->_next = pos->_next;
	pos->_next->_prev = tmp;
	free(pos);
	pos = NULL;
}