#include <stdio.h>
#include <stdlib.h>
#include "DBDLinkedList.h"

void ListInit(List * plist){
    Node * dummyHead = (Node *)malloc(sizeof(Node));
    dummyHead->prev = NULL;
    dummyHead->next = NULL;
    dummyHead->data = -1;

    Node * dummyTail = (Node *)malloc(sizeof(Node));
    dummyTail->prev = NULL;
    dummyTail->next = NULL;
    dummyTail->data = -1;

    plist->head = dummyHead;
    plist->tail = dummyTail;
    plist->head->next = plist->tail;
    plist->tail->prev = plist->head;
    plist->numOfData = 0;
}

void LInsert(List * plist, Data data){
    // append to tail
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    
    newNode->next = plist->tail;
    newNode->prev = plist->tail->prev;
    plist->tail->prev->next = newNode;
    plist->tail->prev = newNode;

    (plist->numOfData)++;
}

int LFirst(List * plist, Data * pdata){
    if(plist->head->next == NULL){
        return FALSE;
    }

    plist->cur = plist->head->next;
    *pdata = plist->cur->data;

    return TRUE;
}

int LNext(List * plist, Data * pdata){
    // due to dummy node on tail
    if(plist->cur->next->next == NULL){
        return FALSE;
    }

    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;

    return TRUE;
}

Data LRemove(List * plist){
    Node * rpos = plist->cur;
	Data rdata = rpos->data;

    rpos->prev->next = rpos->next;
    rpos->next->prev = rpos->prev;
    plist->cur = rpos->prev;

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List * plist){
    return plist->numOfData;
}