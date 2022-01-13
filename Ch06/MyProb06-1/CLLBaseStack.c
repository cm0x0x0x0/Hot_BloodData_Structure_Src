#include <stdio.h>
#include <stdlib.h>
#include "CLLBaseStack.h"

void StackInit(Stack * pstack){
    pstack->list = (List *)malloc(sizeof(List));
    ListInit(pstack->list);
}

int SIsEmpty(Stack * pstack){
    if(LCount(pstack->list) == 0){
        return TRUE;
    }else{
        return FALSE;
    }
}

void SPush(Stack * pstack, Data data){
    LInsertFront(pstack->list, data);
}

Data SPop(Stack * pstack){
    Data data;
    Node * rnode;

    if(!LFirst(pstack->list, &data)){
        printf("Stack is Empty!\n");
        exit(-1);
    }

    LRemove(pstack->list);
    return data;
}

Data SPeek(Stack * pstack){
    Data data;
    if(!LFirst(pstack->list, &data)){
        printf("Stack is Empty!\n");
        exit(-1);
    }

    return data;
}