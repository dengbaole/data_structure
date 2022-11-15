#include "Queue.h"


void TestQueue()
{
	Node *Q = initQueue();
	enQueue(Q, 6);
	enQueue(Q, 3);
	enQueue(Q, 3);
	enQueue(Q, 4);
	enQueue(Q, 5);
	printQueue(Q);
	int data = deQueue(Q);
	printQueue(Q);
}

int main()
{
	TestQueue();

	return 0;
}