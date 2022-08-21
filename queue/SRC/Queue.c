#include "Queue.h"

void QueueInit(Queue *pq)
{
    assert(pq);
    pq->head = NULL;
    pq->tail = NULL;
}

void QueueDestroy(Queue *pq)
{
    assert(pq);
    QueueNode *cur = pq->head;
    while(cur!=NULL)
    {
        QueueNode *next = cur->next;
        free(cur);
        cur = next;
    }
    pq->head = pq->tail = NULL;
}

void QueuePush(Queue *pq, QDataType x)
{
    assert(pq);

    QueueNode *newnode = (QueueNode *)malloc(sizeof(QueueNode));
    newnode->data = x;
    newnode->next = NULL;
    if (pq->head == NULL)
    {
        pq->head = pq->tail=newnode;
    }
    else
    {
        pq->tail->next=newnode;
        pq->tail = newnode;
    }

}
void QueuePop(Queue *pq);
QDataType QueueFront(Queue *pq);
QDataType QueueBack(Queue *pq);
int QueueSize(Queue *pq);
bool QueueEmpty(Queue *pq);