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
//����һ��ֵΪx���½��.
DCListNode* BuyListNode(DCLDataType x);
// �������������ͷ���.
DCListNode* ListCreate();
// ˫����������
void ListDestory(DCListNode* pHead);
// ˫�������ӡ
void ListPrint(DCListNode* pHead);
// ˫������β��
void ListPushBack(DCListNode* pHead, DCLDataType x);
// ˫������βɾ
void ListPopBack(DCListNode* pHead);
// ˫������ͷ��
void ListPushFront(DCListNode* pHead, DCLDataType x);
// ˫������ͷɾ
void ListPopFront(DCListNode* pHead);
// ˫���������
DCListNode* ListFind(DCListNode* pHead, DCLDataType x);
// ˫��������pos��ǰ����в���
void ListInsert(DCListNode* pos, DCLDataType x);
// ˫������ɾ��posλ�õĽڵ�
void ListErase(DCListNode* pos);