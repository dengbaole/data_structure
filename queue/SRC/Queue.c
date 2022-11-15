#include "Queue.h"

/// @brief 初始化
/// @return
Node *initQueue()
{
    Node *Q = (Node *)malloc(sizeof(Node));
    Q->data = 0; //用来存储数据的个数
    Q->next = NULL;
    return Q;
}

/// @brief 队列插入数据
/// @param Q 
/// @param data 
void enQueue(Node *Q, int data)
{
    Node *q = Q;
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    for (int i = 0; i < Q->data; i++)
    {
        q = q->next;
    }
    node->next = q->next;
    q->next = node;
    Q->data++;
}

/// @brief 队列打印
/// @param Q 
void printQueue(Node *Q)
{
    Node *node = Q->next;
    while (node)
    {
        printf("%d->", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

/// @brief 判断队列是否是空
/// @param Q 
/// @return 
int isEmpty(Node* Q)
{
    if(Q->data==0||Q->next->data==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/// @brief 队列删除一个数据(先进先出，删除第一个)
/// @param Q 
/// @return 
int deQueue(Node* Q)
{
    if(isEmpty(Q))
    {
        return -1;
    }
    else
    {
        Node *node = Q->next;
        QDataType data = node->data;
        Q->next = node->next;
        free(node);

        Q->data--;
        return data;
    }
}