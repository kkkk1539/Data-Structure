#include<stdio.h>
#include<stdlib.h>
struct Node {
	int val;
	Node* next;
	Node* random;
};

struct Node* copyRandomList(struct Node* head) {
	if (!head) return NULL;
	struct Node* cur = head;
	while (cur) {
		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		if (!newNode) return NULL; // ��� malloc �Ƿ�ɹ�
		newNode->val = cur->val;
		newNode->next = cur->next;
		cur->next = newNode;
		newNode->random = NULL;	
		cur = newNode->next; // ȷ�� cur ��Ϊ NULL
	}
	struct Node *new_cur = head->next, *newhead = head->next;
	cur = head;
	while (cur) {
		if (cur->random)
			new_cur->random = cur->random->next;
		cur = new_cur->next; // ȷ�� cur ��Ϊ NULL
		if (cur) 
			new_cur = cur->next; // ȷ�� new_cur ��Ϊ NULL
	}
	cur = head;
	new_cur = head->next;
	while (cur && new_cur) {
		cur->next = new_cur->next;
		cur = cur->next;
		if (cur) 
			new_cur->next = cur->next; // ȷ�� new_cur ��Ϊ NULL
		new_cur = new_cur->next;
	}
	return newhead;
}