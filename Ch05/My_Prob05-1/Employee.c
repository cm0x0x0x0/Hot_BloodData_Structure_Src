#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

Employee * NewEmployee(int code, char * name){
    Employee * ret = (Employee *)malloc(sizeof(Employee));
    ret->codeNum = code;
    strcpy(ret->name, name);

    return ret;
}