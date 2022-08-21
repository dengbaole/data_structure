#ifndef _stack_h
#define _stack_h
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

void StackInit(ST* ps);
void StackDesroy(ST* ps);
void StackPush(ST* ps,STDataType x);
void StackPop(ST* ps);
STDataType StackTop(ST*ps);
int StackSize(ST* ps);
bool StackEmpty(ST* ps);




#endif