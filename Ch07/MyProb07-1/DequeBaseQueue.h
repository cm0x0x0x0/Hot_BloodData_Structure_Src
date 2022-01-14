#ifndef __DEQUE_BASE_QUEUE_H__
#define __DEQUE_BASE_QUEUE_H__

#include "Deque.h"

// typedef struct _DQBaseQueue{
//     Deque * dq;
// } DQBaseQueue;

// typedef DQBaseQueue Queue;

typedef Deque Queue;

void QueueInit(Queue * pq);
int QIsEmpty(Queue * pq);
void  Enqueue(Queue * pq, Data data);
Data Dequeue(Queue * pq);
Data Qpeek(Queue * pq);

#endif