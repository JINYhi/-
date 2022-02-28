#include <stdio.h>
#include <stdlib.h> //  ������
#include <time.h>
//#define CLOCKS_PER_SEC 1000

void BubbleSort(int arr[], int n) // ���� ����
{
	int i, j;
	int temp;

	for(i=0; i<n-1; i++)
	{
		for(j=0; j<(n-i)-1; j++)
		{
			if(arr[j] > arr[j+1]) // �� ������ �߻��ϴ� ���
			{
				/// �������� ��ȯ///
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

void SelSort(int arr[], int n) // ���� ����
{
	int i, j;
	int maxIdx;
	int temp;

	for(i=0; i<n-1; i++)
	{
		maxIdx = i;    // ���� ������ ���� �ռ��� �������� index

		for(j=i+1; j<n; j++)   // �ּҰ� Ž��
		{
			if(arr[j] < arr[maxIdx])
				maxIdx = j;
		}

		/* ��ȯ */
		temp = arr[i];
		arr[i] = arr[maxIdx];
		arr[maxIdx] = temp;
	}
}

void InserSort(int arr[], int n)//���� ����
{
	int i, j;
	int insData;

	for(i=1; i<n; i++)
	{
		insData = arr[i];   // ���� ����� insData�� ����

		for(j=i-1; j>=0 ; j--)
		{
			if(arr[j] > insData) 
				arr[j+1] = arr[j];    // �� ��� �� ĭ �ڷ� �б�
			else
				break;   // ���� ��ġ ã������ Ż��!
		}

		arr[j+1] = insData;  // ã�� ��ġ�� ���� ��� ����!
	}
}

// ���� ���� //
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
		// �߰� ������ ����Ѵ�.
		mid = (left+right) / 2;

		// �ѷ� ������ ������ �����Ѵ�.
		MergeSort(arr, left, mid);
		MergeSort(arr, mid+1, right);

		// ���ĵ� �� �迭�� �����Ѵ�.
		MergeTwoArea(arr, left, mid, right);
	}
}
/////////////////////////////////////////////////////////////////////

//�� ���� //
void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}	


int Partition(int arr[], int left, int right)
{
	int pivot = arr[left];    // �ǹ��� ��ġ�� ���� ����! 
	int low = left+1;
	int high = right;

	while(low <= high)    // �������� ���� ������ �ݺ�
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

		if(low <= high)    // �������� ���� ���¶�� Swap ����
			Swap(arr, low, high);    // low�� high�� ����Ű�� ��� ��ȯ
	}

	Swap(arr, left, high);    // �ǹ��� high�� ����Ű�� ��� ��ȯ
	return high;    // �Ű��� �ǹ��� ��ġ ���� ��ȯ
}

void QuickSort(int arr[], int left, int right)
{
	if(left <= right)
	{
		int pivot = Partition(arr, left, right);    // �ѷ� ������ 
		QuickSort(arr, left, pivot-1);    // ���� ������ ����
		QuickSort(arr, pivot+1, right);    // ������ ������ ����
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
		printf("\n0:���߱� 1: ����, 2: ����, 3:����, 4:����, 5: ��\n->");
		scanf("%d", &n);
		if(n == 0)
			break;
		if(n == 1)
		{
    		start = clock(); // ���� �ð� ����

			BubbleSort(arr, sizeof(arr)/sizeof(int)); // ���� ����
			printf("���� �Ϸ� : ");
			for(int i=0; i<10 ; i++)
			{
				printf("%d ", arr[i]);
			}

			printf("\n");
    		finish = clock(); // �ڵ尡 ���� �ð� ����


			duration = (double)(finish-start)/CLOCKS_PER_SEC;
			printf("���� ���� �ɸ� �ð� : %f��", duration);
			printf("\n");
		}
	
		if(n == 2)
		{
    		start = clock(); // ���� �ð� ����

			SelSort(arr, sizeof(arr)/sizeof(int)); // ��������
			printf("���� �Ϸ� : ");
			for(int i=0; i<10 ; i++)
			{
				printf("%d ", arr[i]);
			}

			printf("\n");
    		finish = clock(); // �ڵ尡 ���� �ð� ����


			duration = (double)(finish-start)/CLOCKS_PER_SEC;
			printf("���� ���� �ɸ� �ð� : %f��", duration);
			printf("\n");
		}	

		if(n == 3)
		{
    		start = clock(); // ���� �ð� ����

			InserSort(arr, sizeof(arr)/sizeof(int)); //��������
			printf("���� �Ϸ� : ");
			for(int i=0; i<10 ; i++)
			{
				printf("%d ", arr[i]);
			}

			printf("\n");
    		finish = clock(); // �ڵ尡 ���� �ð� ����


			duration = (double)(finish-start)/CLOCKS_PER_SEC;
			printf("���� ���� �ɸ� �ð� : %f��", duration);
			printf("\n");
		}

		if(n == 4)
		{
    		start = clock(); // ���� �ð� ����

			MergeSort(arr, 0, sizeof(arr)/sizeof(int)-1); // ��������
			printf("���� �Ϸ� : ");
			for(int i=0; i<10 ; i++)
			{
				printf("%d ", arr[i]);
			}

			printf("\n");
    		finish = clock(); // �ڵ尡 ���� �ð� ����


			duration = (double)(finish-start)/CLOCKS_PER_SEC;
			printf("���� ���� �ɸ� �ð� : %f��", duration);
			printf("\n");
		}

		if(n == 5)
		{
    		start = clock(); // ���� �ð� ����

			int len = sizeof(arr) / sizeof(int);
			QuickSort(arr, 0, sizeof(arr)/sizeof(int)-1);
			printf("���� �Ϸ� : ");
			for(int i=0; i<10 ; i++)
			{
				printf("%d ", arr[i]);
			}

			printf("\n");
    		finish = clock(); // �ڵ尡 ���� �ð� ����


			duration = (double)(finish-start)/CLOCKS_PER_SEC;
			printf("�� ���� �ɸ� �ð� : %f��", duration);
			printf("\n");
		}
	}

    return 0;
}



/*
    // �ʿ��� �ڵ�� �ۼ�
	BubbleSort(arr, sizeof(arr)/sizeof(int)); // ���� ����
	SelSort(arr, sizeof(arr)/sizeof(int)); // ��������
	InserSort(arr, sizeof(arr)/sizeof(int)); //��������
	MergeSort(arr, 0, sizeof(arr)/sizeof(int)-1); // ��������
	//�� ����
	int len = sizeof(arr) / sizeof(int);
	QuickSort(arr, 0, sizeof(arr)/sizeof(int)-1);
	//��
*/