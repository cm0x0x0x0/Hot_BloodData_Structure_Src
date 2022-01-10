#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NameCard.h"

NameCard * MakeNameCard(char * name, char * phone){
    NameCard * ret = (NameCard*)malloc(sizeof(NameCard));
    strcpy(ret->name, name);
    strcpy(ret->phone, phone);
    return ret;
}

void ShowNameCardInfo(NameCard * pcard){
    printf("name : %s\n", pcard->name);
    printf("phone : %s\n", pcard->phone);
}

int NameCompare(NameCard * pcard, char * name){
    return strcmp(pcard->name, name);
}

void ChangePhoneNum(NameCard * pcard, char * phone){
    strcpy(pcard->phone, phone);
}