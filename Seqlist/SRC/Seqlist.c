#include <stdio.h>
#include "../INC/Seqlist.h"




//需要改变什么就传递什么的指针，或者返回什么的指针
LTNode* ListInit(void)
{
	LTNode* phead=(LTNode*)malloc(sizeof(LTNode));
	phead->next=phead;
	phead->prev=phead;
	return phead;
}

void listPrint(LTNode* phead)
{
	assert(phead);
	LTNode* cur =phead->next;
	while(cur!=phead)
	{
		printf("%d",cur->data);
		cur=cur->next;
	}
	printf("\n");
}


LTNode* BuyListNode(LTDateType x)
{
	LTNode* Newnode=(LTNode*)malloc(sizeof(LTNode));
	Newnode->next = NULL;
	Newnode->prev = NULL;
	Newnode->data = x;
	return Newnode;
}

//有结构体的指针就可以改变结构体里面的内容（带头结点）
void ListPushBack(LTNode* phead,LTDateType x)
{
	assert(phead);
	LTNode*Newnode=BuyListNode(x);
	LTNode *tail = phead->prev;
	tail->next=Newnode;
	Newnode->data=x;
	Newnode->next=phead;
	Newnode->prev=tail;
	phead->prev=Newnode;
}


//尾删
void ListPopBack(LTNode* phead)
{
	assert(phead);
	//assert(phead->next!=phead);
	if(phead->next==phead)
	{
		printf("链表为空\n");
		return;
	}

	LTNode* tail=NULL;
	tail=phead->prev->prev;
	tail->next=phead;
	free(phead->prev);
	phead->prev=tail;
	
}



void listPushFront(LTNode* phead,LTDateType x)
{
	assert(phead);
	LTNode*Newnode=BuyListNode(x);
	

	LTNode *next = phead->next;

	phead->next = Newnode;
	Newnode->prev = phead;

	Newnode->next = next;
	next->prev = Newnode;
	
}
void ListPopFront(LTNode* phead)
{
	assert(phead);
		//assert(phead->next!=phead);
	if(phead->next==phead)
	{
		printf("链表为空\n");
		return;
	}

	LTNode *next = phead->next;
	LTNode *nextNext = next->next;

	phead->next = nextNext;
	nextNext->prev = phead;
	free(next);
}


LTNode *listFind(LTNode *phead, LTDateType X)
{
	assert(phead);
	LTNode* cur =phead->next;
	while(cur!=phead)
	{
		if(cur->data==X)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//pos位置之前插入,需要先找到列表
void ListInsert(LTNode *pos, LTDateType x)
{
	assert(pos);
	LTNode *posPrev = pos->prev;
	LTNode *newnode = BuyListNode(x);

	posPrev->next = newnode;
	newnode->prev = posPrev;
	newnode->next = pos;
	pos->prev = newnode;
}

void ListErase(LTNode *pos)
{
	assert(pos);
	LTNode *posPrev = pos->prev;
	LTNode *posNext = pos->next;

	posPrev->next = posNext;
	posNext->prev = posPrev;
	free(pos);
	pos = NULL;
}


void listDestroy(LTNode *phead)
{
	assert(phead);
	LTNode *cur = phead->next;
	while(cur!=phead)
	{
		LTNode *next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
	phead = NULL;
}
