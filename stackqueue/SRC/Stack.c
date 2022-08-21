#include "Stack.h"



void StackInit(ST* ps)
{
	assert(ps);
	ps->a=NULL;
	//指定栈顶数据下一位，-1位指定栈顶数据
	ps->top=0;
	ps->capacity=0;
	
}
void StackDesroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a=NULL;
	ps->capacity=ps->top=0;
	
}


void StackPush(ST* ps,STDataType x)
{
	assert(ps);
	
	if(ps->top==ps->capacity)
	{
		int newCapacity = (ps->capacity== 0 ? 4: ps->capacity*2);
		STDataType *tmp = realloc(ps->a,sizeof(STDataType)*newCapacity);
		//STDataType *tmp=(STDataType*)malloc(sizeof(STDataType)*newCapacity);
		if(tmp==NULL)
		{
			printf("relloc fail\n");
			exit(-1);
		}
		ps->a=tmp;
		ps->capacity=newCapacity;
	}
	
	ps->a[ps->top]=x;
	ps->top++;
}

void StackPop(ST* ps)
{
	assert(ps);
	assert(ps->top>0);
	ps->top--;
	
}

STDataType StackTop(ST*ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	
	return ps->a[ps->top-1];	
}
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}
bool StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top==0;
}

