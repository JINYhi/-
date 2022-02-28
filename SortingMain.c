#include <stdio.h>
#include <stdlib.h> //  퀵정렬
#include <time.h>
//#define CLOCKS_PER_SEC 1000

void BubbleSort(int arr[], int n) // 버블 정렬
{
	int i, j;
	int temp;

	for(i=0; i<n-1; i++)
	{
		for(j=0; j<(n-i)-1; j++)
		{
			if(arr[j] > arr[j+1]) // 비교 연산이 발생하는 장소
			{
				/// 데이터의 교환///
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

void SelSort(int arr[], int n) // 선택 정렬
{
	int i, j;
	int maxIdx;
	int temp;

	for(i=0; i<n-1; i++)
	{
		maxIdx = i;    // 정렬 순서상 가장 앞서는 데이터의 index

		for(j=i+1; j<n; j++)   // 최소값 탐색
		{
			if(arr[j] < arr[maxIdx])
				maxIdx = j;
		}

		/* 교환 */
		temp = arr[i];
		arr[i] = arr[maxIdx];
		arr[maxIdx] = temp;
	}
}

void InserSort(int arr[], int n)//삽입 정렬
{
	int i, j;
	int insData;

	for(i=1; i<n; i++)
	{
		insData = arr[i];   // 정렬 대상을 insData에 저장

		for(j=i-1; j>=0 ; j--)
		{
			if(arr[j] > insData) 
				arr[j+1] = arr[j];    // 비교 대상 한 칸 뒤로 밀기
			else
				break;   // 삽입 위치 찾았으니 탈출!
		}

		arr[j+1] = insData;  // 찾은 위치에 정렬 대상 삽입!
	}
}

// 병합 정렬 //
void MergeTwoArea(int arr[], int left, int mid, int right)
{
	int fIdx = left;
	int rIdx = mid+1;
	int i;

	int * sortArr = (int*)malloc(sizeof(int)*(right+1));
	int sIdx = left;

	while(fIdx<=mid && rIdx<=right)
	{
		if(arr[fIdx] <= arr[rIdx])
			sortArr[sIdx] = arr[fIdx++];
		else
			sortArr[sIdx] = arr[rIdx++];

		sIdx++;
	}

	if(fIdx > mid)
	{
		for(i=rIdx; i<=right; i++, sIdx++)
			sortArr[sIdx] = arr[i];
	}
	else
	{
		for(i=fIdx; i<=mid; i++, sIdx++)
			sortArr[sIdx] = arr[i];
	}

	for(i=left; i<=right; i++)
		arr[i] = sortArr[i];
	
	free(sortArr);
}

void MergeSort(int arr[], int left, int right)
{
	int mid;

	if(left < right)
	{
		// 중간 지점을 계산한다.
		mid = (left+right) / 2;

		// 둘로 나눠서 각각을 정렬한다.
		MergeSort(arr, left, mid);
		MergeSort(arr, mid+1, right);

		// 정렬된 두 배열을 병합한다.
		MergeTwoArea(arr, left, mid, right);
	}
}
/////////////////////////////////////////////////////////////////////

//퀵 정렬 //
void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}	


int Partition(int arr[], int left, int right)
{
	int pivot = arr[left];    // 피벗의 위치는 가장 왼쪽! 
	int low = left+1;
	int high = right;

	while(low <= high)    // 교차되지 않을 때까지 반복
	{	
		while(pivot > arr[low])
			low++;

		while(pivot < arr[high])
			high--;
		
		/*
		while(pivot >= arr[low] && low <= right)
			low++;

		while(pivot <= arr[high] && high >= (left+1))
			high--;
		*/

		if(low <= high)    // 교차되지 않은 상태라면 Swap 실행
			Swap(arr, low, high);    // low와 high가 가리키는 대상 교환
	}

	Swap(arr, left, high);    // 피벗과 high가 가리키는 대상 교환
	return high;    // 옮겨진 피벗의 위치 정보 반환
}

void QuickSort(int arr[], int left, int right)
{
	if(left <= right)
	{
		int pivot = Partition(arr, left, right);    // 둘로 나눠서 
		QuickSort(arr, left, pivot-1);    // 왼쪽 영역을 정렬
		QuickSort(arr, pivot+1, right);    // 오른쪽 영역을 정렬
	}
}
/////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

int main(){
	int arr[10] = {1,3,5,7,9,8,6,4,10,2};
	clock_t finish, start;
	int temp;
    double duration;
	int n;
	while(1){
		printf("\n0:멈추기 1: 버블, 2: 선택, 3:삽입, 4:병합, 5: 퀵\n->");
		scanf("%d", &n);
		if(n == 0)
			break;
		if(n == 1)
		{
    		start = clock(); // 시작 시간 저장

			BubbleSort(arr, sizeof(arr)/sizeof(int)); // 버블 정렬
			printf("정렬 완료 : ");
			for(int i=0; i<10 ; i++)
			{
				printf("%d ", arr[i]);
			}

			printf("\n");
    		finish = clock(); // 코드가 끝난 시간 저장


			duration = (double)(finish-start)/CLOCKS_PER_SEC;
			printf("버블 정렬 걸린 시간 : %f초", duration);
			printf("\n");
		}
	
		if(n == 2)
		{
    		start = clock(); // 시작 시간 저장

			SelSort(arr, sizeof(arr)/sizeof(int)); // 선택정렬
			printf("정렬 완료 : ");
			for(int i=0; i<10 ; i++)
			{
				printf("%d ", arr[i]);
			}

			printf("\n");
    		finish = clock(); // 코드가 끝난 시간 저장


			duration = (double)(finish-start)/CLOCKS_PER_SEC;
			printf("선택 정렬 걸린 시간 : %f초", duration);
			printf("\n");
		}	

		if(n == 3)
		{
    		start = clock(); // 시작 시간 저장

			InserSort(arr, sizeof(arr)/sizeof(int)); //삽입정렬
			printf("정렬 완료 : ");
			for(int i=0; i<10 ; i++)
			{
				printf("%d ", arr[i]);
			}

			printf("\n");
    		finish = clock(); // 코드가 끝난 시간 저장


			duration = (double)(finish-start)/CLOCKS_PER_SEC;
			printf("삽입 정렬 걸린 시간 : %f초", duration);
			printf("\n");
		}

		if(n == 4)
		{
    		start = clock(); // 시작 시간 저장

			MergeSort(arr, 0, sizeof(arr)/sizeof(int)-1); // 병합정렬
			printf("정렬 완료 : ");
			for(int i=0; i<10 ; i++)
			{
				printf("%d ", arr[i]);
			}

			printf("\n");
    		finish = clock(); // 코드가 끝난 시간 저장


			duration = (double)(finish-start)/CLOCKS_PER_SEC;
			printf("병합 정렬 걸린 시간 : %f초", duration);
			printf("\n");
		}

		if(n == 5)
		{
    		start = clock(); // 시작 시간 저장

			int len = sizeof(arr) / sizeof(int);
			QuickSort(arr, 0, sizeof(arr)/sizeof(int)-1);
			printf("정렬 완료 : ");
			for(int i=0; i<10 ; i++)
			{
				printf("%d ", arr[i]);
			}

			printf("\n");
    		finish = clock(); // 코드가 끝난 시간 저장


			duration = (double)(finish-start)/CLOCKS_PER_SEC;
			printf("퀵 정렬 걸린 시간 : %f초", duration);
			printf("\n");
		}
	}

    return 0;
}



/*
    // 필요한 코드들 작성
	BubbleSort(arr, sizeof(arr)/sizeof(int)); // 버블 정렬
	SelSort(arr, sizeof(arr)/sizeof(int)); // 선택정렬
	InserSort(arr, sizeof(arr)/sizeof(int)); //삽입정렬
	MergeSort(arr, 0, sizeof(arr)/sizeof(int)-1); // 병합정렬
	//퀵 정렬
	int len = sizeof(arr) / sizeof(int);
	QuickSort(arr, 0, sizeof(arr)/sizeof(int)-1);
	//퀵
*/