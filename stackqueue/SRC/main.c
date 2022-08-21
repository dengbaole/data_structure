#include "Stack.h"

/*

栈先进后出
*/

void TestStack()
{
	ST st;
	StackInit(&st);
 	StackPush(&st,1);
	StackPush(&st,2);
	StackPush(&st,12);

	
	while(!StackEmpty(&st)){
		//TODO
		printf("%d\n",StackTop(&st));
		StackPop(&st);
	}
	
	StackDesroy(&st);
	
}



int main()
{
	TestStack();
	
	return 0;
}