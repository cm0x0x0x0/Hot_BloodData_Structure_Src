#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

typedef struct _employee{
    int codeNum;
    char name[15];
} Employee;


Employee * NewEmployee(int code, char * name);
// The following error is occured, when I don't write a function prototype in header file.

//warning: passing argument 2 of 'LInsertFront' makes pointer from integer without a cast [-Wint-conversion]
//    54 |  LInsertFront(&list, NewEmployee(104, "Choi"));
//       |                      ^~~~~~~~~~~~~~~~~~~~~~~~
//       |                      |
//       |                      int

#endif