#include <stdio.h>

void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int MedianPivot(int arr[], int left, int right){
	int tempArr[3] = {left, (left+right)/2, right};
	int tempIdx;
	for(int i=0; i<2; i++){
		for(int j=i+1; j<3; j++){
			if(arr[tempArr[i]] >= arr[tempArr[j]]){
				tempIdx = tempArr[i];
				tempArr[i] = tempArr[j];
				tempArr[j] = tempIdx;
			}
		}
	}
	return tempArr[1];
}


int Partition(int arr[], int left, int right)
{
	// int pivot = arr[left];    // 피벗의 위치는 가장 왼쪽! 
	int pIdx = MedianPivot(arr, left, right);
	int pivot = arr[pIdx];
	int low = left+1;
	int high = right;

	Swap(arr, left, pIdx);

	printf("피벗 : %d \n", pivot); // 피벗의 확인을 위해서 추가할 문장!

	while(low <= high)    // 교차되지 않을 때까지 반복
	{	
		// while(pivot > arr[low])
		// 	low++;

		// while(pivot < arr[high])
		// 	high--;
		
		
		while(pivot >= arr[low] && low <= right)
			low++;

		while(pivot <= arr[high] && high >= (left+1))
			high--;
		

		if(low <= high)    // 교차되지 않은 상태라면 Swap 실행
			Swap(arr, low, high);    // low와 high가 가리키는 대상 교환
	}

	Swap(arr, left, high);    // 피벗과 high가 가리키는 대상 교환
	return high;    // 옮겨진 피벗의 위치 정보 반환
}

void QuickSort(int arr[], int left, int right)
{
	if(left < right)
	{
		int pivot = Partition(arr, left, right);    // 둘로 나눠서 
		QuickSort(arr, left, pivot-1);    // 왼쪽 영역을 정렬
		QuickSort(arr, pivot+1, right);    // 오른쪽 영역을 정렬
	}
}

int main(void)
{
	//	int arr[7] = {3, 2, 4, 1, 7, 6, 5};
	// int arr[3] = {3, 3, 3};
	int arr[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};


	int len = sizeof(arr) / sizeof(int);
	int i;

	QuickSort(arr, 0, sizeof(arr)/sizeof(int)-1);

	for(i=0; i<len; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}