#include <stdio.h>
#include "../INC/list.h"




//需要改变什么就传递什么的指针，或者返回什么的指针

/// @brief 初始化
/// @param  
/// @return 
LTNode* ListInit(void)
{
	LTNode* phead=(LTNode*)malloc(sizeof(LTNode));
	phead->next=phead;
	phead->prev=phead;
	return phead;
}

/// @brief 打印
/// @param phead 
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

/// @brief 新建结点
/// @param x 
/// @return 
LTNode* BuyListNode(LTDateType x)
{
	LTNode* Newnode=(LTNode*)malloc(sizeof(LTNode));
	Newnode->next = NULL;
	Newnode->prev = NULL;
	Newnode->data = x;
	return Newnode;
}

//有结构体的指针就可以改变结构体里面的内容（带头结点）

/// @brief 尾插
/// @param phead 
/// @param x 
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


/// @brief 尾删
/// @param phead 
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


/// @brief 头插
/// @param phead 
/// @param x 
void listPushFront(LTNode* phead,LTDateType x)
{
	//链表是否是空
	assert(phead);
	LTNode*Newnode=BuyListNode(x);
	
	//定义指针
	LTNode *next = phead->next;

	phead->next = Newnode;
	Newnode->prev = phead;

	Newnode->next = next;
	next->prev = Newnode;
	
}

/// @brief 头删
/// @param phead 
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

/// @brief 查找
/// @param phead 
/// @param X 
/// @return 
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


/// @brief 在pos位置之前插入
/// @param pos 
/// @param x 
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

/// @brief 删除pos位置上的结点
/// @param pos 
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

/// @brief 清空链表
/// @param phead 
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
