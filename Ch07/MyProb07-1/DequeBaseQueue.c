// #include <stdio.h>
// #include <stdlib.h>
// #include <Deque.h>
#include "DequeBaseQueue.h"

void QueueInit(Queue * pq){
    // pq->dq = (Deque *)malloc(sizeof(Deque));
    // DequeInit(pq->dq);
    DequeInit(pq);
}

int QIsEmpty(Queue * pq){
    // if(DQIsEmpty(pq->dq)){
    //     return TRUE;
    // }else{
    //     return FALSE;
    // }
    return DQIsEmpty(pq);
}

void  Enqueue(Queue * pq, Data data){
    // DQAddLast(pq->dq, data);
    DQAddLast(pq, data);
}

Data Dequeue(Queue * pq){
    // return DQRemoveFirst(pq->dq);
    return DQRemoveFirst(pq);
}

Data Qpeek(Queue * pq){
    // return DQGetFirst(pq->dq);
    return DQGetFirst(pq);
}