#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "NameCard.h"

int main(void)
{
	// /*** ArrayList의 생성 및 초기화 ***/
	// List list;
	// int data;
	// ListInit(&list);

	// /*** 5개의 데이터 저장 ***/
	// LInsert(&list, 11);  LInsert(&list, 11);
	// LInsert(&list, 22);  LInsert(&list, 22);
	// LInsert(&list, 33);

	// /*** 저장된 데이터의 전체 출력 ***/
	// printf("현재 데이터의 수: %d \n", LCount(&list));

	// if(LFirst(&list, &data))    // 첫 번째 데이터 조회
	// {
	// 	printf("%d ", data);
		
	// 	while(LNext(&list, &data))    // 두 번째 이후의 데이터 조회
	// 		printf("%d ", data);
	// }
	// printf("\n\n");

	// /*** 숫자 22을 탐색하여 모두 삭제 ***/
	// if(LFirst(&list, &data))
	// {
	// 	if(data == 22)
	// 		LRemove(&list);
		
	// 	while(LNext(&list, &data))
	// 	{
	// 		if(data == 22)
	// 			LRemove(&list);
	// 	}
	// }

	// /*** 삭제 후 저장된 데이터 전체 출력 ***/
	// printf("현재 데이터의 수: %d \n", LCount(&list));

	// if(LFirst(&list, &data))
	// {
	// 	printf("%d ", data);
		
	// 	while(LNext(&list, &data))
	// 		printf("%d ", data);
	// }
	// printf("\n\n");

	// // exercise 03-1 //////////////////////
	// List list;
	// int data;
	// int sum = 0;

	// // 1. 
	// ListInit(&list);
	// for(int i=1; i<=9; i++){
	// 	LInsert(&list, i);
	// }

	// // 2.
	// if(LFirst(&list, &data)){
	// 	sum += data;
	// 	while(LNext(&list, &data)){
	// 		sum += data;
	// 	}
	// }
	// printf("sum : %d\n", sum);

	// // 3.
	// if(LFirst(&list, &data)){
	// 	if(data % 3 == 0 || data % 2 == 0)
	// 		LRemove(&list);
		
	// 	while(LNext(&list, &data)){
	// 		if(data % 3 == 0 || data % 2 == 0)
	// 			LRemove(&list);
	// 	}
	// }

	// // 4.
	// if(LFirst(&list, &data)){
	// 	printf("%d\n", data);
	// 	while(LNext(&list, &data)){
	// 		printf("%d\n", data);
	// 	}
	// }
	// //////////////////////////////////////

	// // exercise 03-2 /////////////////////
	List list;
	NameCard * nCard;
	ListInit(&list);

	// 1.
	//	person 1
	nCard = MakeNameCard("steve", "010-1234-5678");
	LInsert(&list, nCard);
	//	person 2
	nCard = MakeNameCard("anna", "010-4239-5678");
	LInsert(&list, nCard);
	//	person 3
	nCard = MakeNameCard("bob", "010-9000-5678");
	LInsert(&list, nCard);

	// 2.
	if(LFirst(&list, &nCard)){
		if(!NameCompare(nCard, "bob")){
			ShowNameCardInfo(nCard);
		}

		while(LNext(&list, &nCard)){
			if(!NameCompare(nCard, "bob")){
				ShowNameCardInfo(nCard);
			}	
		}
	}

	// 3.
	if(LFirst(&list, &nCard)){
		if(!NameCompare(nCard, "anna")){
			ChangePhoneNum(nCard, "010-0000-0000");
		}

		while(LNext(&list, &nCard)){
			if(!NameCompare(nCard, "anna")){
				ChangePhoneNum(nCard, "010-0000-0000");
			}	
		}
	}

	// 4.
	if(LFirst(&list, &nCard)){
		if(!NameCompare(nCard, "bob")){
			LRemove(&list);
			free(nCard);
		}

		while(LNext(&list, &nCard)){
			if(!NameCompare(nCard, "bob")){
				LRemove(&list);
				free(nCard);
			}	
		}
	}

	// 5.
	printf("# of data : %d\n", LCount(&list));
	if(LFirst(&list, &nCard)){
		ShowNameCardInfo(nCard);
		
		while(LNext(&list, &nCard)){
			ShowNameCardInfo(nCard);
		}	
	}
	// ///////////////////////////////////////


	return 0;
}