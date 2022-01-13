#ifndef __CLL_STACK_H__
#define __CLL_STACK_H__

#include "CLinkedList.h"

typedef struct _listStack
{
	List * list;
} ListStack;


typedef ListStack Stack;

void StackInit(Stack * pstack);
int SIsEmpty(Stack * pstack);

void SPush(Stack * pstack, Data data);
Data SPop(Stack * pstack);
Data SPeek(Stack * pstack);

#endif