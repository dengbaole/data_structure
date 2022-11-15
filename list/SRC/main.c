#include <stdio.h>
#include "../INC/list.h"



void TestList1()
{
	LTNode* plist =ListInit();
	ListPushBack(plist,1);
	ListPushBack(plist,1);
	ListPushBack(plist,2);
	listPushFront(plist, 3);
	
	ListPopBack(plist);


	

listPrint(plist);

	LTNode *pos = listFind(plist, 2);
	if(pos)
	{
		ListErase(pos);

	}
	ListPopBack(plist);
	listDestroy(plist);
	plist = NULL;
}

int main()
{
	TestList1();
	printf("ok\n");

	return 0;
}
