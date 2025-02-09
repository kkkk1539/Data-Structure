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

// ��̬����һ���ڵ�
LNode* BuyLinkListNode(SLTDateType x);
// �������ӡ
void LinkListPrint(LinkList p);
// ������β��
void LinkListPushBack(LNode** pplist, SLTDateType x);
// �������ͷ��
void LinkListPushFront(LNode** pplist, SLTDateType x);
// �������βɾ
void LinkListPopBack(LNode** pplist);
// ������ͷɾ
void LinkListPopFront(LNode** pplist);
// ���������
LNode* LinkListFind(LNode* plist, SLTDateType x);
// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
void LinkListInsertAfter(LNode* pos, SLTDateType x);
// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
void LinkListEraseAfter(LNode* pos);
