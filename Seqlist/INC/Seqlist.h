#ifndef _Seqlist_h
#define _Seqlist_h


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LTDateType;

typedef struct ListNode
{
	LTDateType data;
	struct ListNode* next;
	struct ListNode* prev;
}LTNode;

LTNode* ListInit(void);
void listDestroy(LTNode *phead);
void listPrint(LTNode *phead);
void ListPushBack(LTNode* phead,LTDateType x);
void ListPopBack(LTNode* phead);
void listPushFront(LTNode* phead,LTDateType x);
void ListPopFront(LTNode* phead);
LTNode *listFind(LTNode *phead, LTDateType X);
void ListInsert(LTNode *pos, LTDateType x);
void ListErase(LTNode *pos);

#endif