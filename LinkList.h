#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLTDateType;
typedef struct LinkListNode
{
	SLTDateType data;
	struct LinkListNode* next;
}LNode,*LinkList;

// 动态申请一个节点
LNode* BuyLinkListNode(SLTDateType x);
// 单链表打印
void LinkListPrint(LinkList p);
// 单链表尾插
void LinkListPushBack(LNode** pplist, SLTDateType x);
// 单链表的头插
void LinkListPushFront(LNode** pplist, SLTDateType x);
// 单链表的尾删
void LinkListPopBack(LNode** pplist);
// 单链表头删
void LinkListPopFront(LNode** pplist);
// 单链表查找
LNode* LinkListFind(LNode* plist, SLTDateType x);
// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void LinkListInsertAfter(LNode* pos, SLTDateType x);
// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void LinkListEraseAfter(LNode* pos);
