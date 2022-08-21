#include "Queue.h"


void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q,5);
}

int main()
{
	TestQueue();

	return 0;
}