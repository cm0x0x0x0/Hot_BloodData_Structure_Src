#include <stdio.h>
#include <string.h>
#include "CLinkedList.h"
#include "Employee.h"

void whoIsNext(List * plist, char * name, int days){
	int nodeNum = LCount(plist);
	Data data;
	// strcpy(data->name, name); // This line makes bug.
	if(nodeNum == 0){
		printf("[Error] : nodeNum is zero.\n");
		return;
	}

	// find employee
	if(LFirst(plist, &data)){
		if(strcmp(data->name, name) != 0){
			for(int i=0; i<nodeNum-1; i++){
				if(!LNext(plist, &data)){
					printf("[Error] : LNext is return by False.\n");
					return;
				}

				if(strcmp(data->name, name) == 0){
					break;
				}
			}
			printf("[Error] : There is not employee who has such name.\n");
			return; 
		}
	}

	for(int i=0; i<days; i++){
		if(!LNext(plist, &data)){
			printf("[Error] : LNext is return by False.\n");
			return;
		}
	}

	printf("code : %d, name : %s\n", data->codeNum, data->name);
}

int main(void)
{
	// 원형 연결 리스트의 생성 및 초기화 ///////
	List list;
	int i, nodeNum;
	Data data;
	ListInit(&list);

	// 리스트에 5개의 데이터를 저장 /////// 
	LInsert(&list, NewEmployee(100, "Park"));
	LInsert(&list, NewEmployee(101, "Kim"));
	LInsert(&list, NewEmployee(102, "Lee"));
	LInsertFront(&list, NewEmployee(103, "Song"));
	LInsertFront(&list, NewEmployee(104, "Choi"));
	

	// 전체 데이터 1회 출력 ///////
	if(LFirst(&list, &data))
	{
		printf("%d, %s\n", data->codeNum, data->name);
		
		for(i=0; i<LCount(&list)-1; i++)
		{
			if(LNext(&list, &data))
				printf("%d, %s\n", data->codeNum, data->name);
		}
	}

	whoIsNext(&list, "Kim", 3);
	whoIsNext(&list, "Kim", 3);
	whoIsNext(&list, "Park", 2);

	return 0;
}