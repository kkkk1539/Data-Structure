#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int DCLDataType;
typedef struct DCListNode
{
	DCLDataType _data;
	struct DCListNode* _next;
	struct DCListNode* _prev;
}DCListNode;
//创建一个值为x的新结点.
DCListNode* BuyListNode(DCLDataType x);
// 创建返回链表的头结点.
DCListNode* ListCreate();
// 双向链表销毁
void ListDestory(DCListNode* pHead);
// 双向链表打印
void ListPrint(DCListNode* pHead);
// 双向链表尾插
void ListPushBack(DCListNode* pHead, DCLDataType x);
// 双向链表尾删
void ListPopBack(DCListNode* pHead);
// 双向链表头插
void ListPushFront(DCListNode* pHead, DCLDataType x);
// 双向链表头删
void ListPopFront(DCListNode* pHead);
// 双向链表查找
DCListNode* ListFind(DCListNode* pHead, DCLDataType x);
// 双向链表在pos的前面进行插入
void ListInsert(DCListNode* pos, DCLDataType x);
// 双向链表删除pos位置的节点
void ListErase(DCListNode* pos);