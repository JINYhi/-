#include <stdio.h>
#include "ListBaseQueue.h"

int main(void)
{
	// Queue�� ���� �� �ʱ�ȭ ///////
	Queue q;
	QueueInit(&q);
	int n,a,n1;
	while(1)
	{
		printf("\n\n0:���� 1:������ �ֱ�\n->");
		scanf("%d", &n);
		if(n==0)
		{
			printf("����");
			break;
		}
		if(n==1)
		{
			printf("\n���� ����: ");
			scanf("%d", &a);
			for(int i=0; i<a; i++)
			{
				scanf("%d", &n1);
				Enqueue(&q, n1);
			}

			printf("\n ������ ������ \n");
			while(!QIsEmpty(&q))
				printf("%d ", Dequeue(&q)); 
		}
	}
	/*
	// ������ �ֱ� ///////
	Enqueue(&q, 1);  Enqueue(&q, 2);
	Enqueue(&q, 3);  Enqueue(&q, 4);
	Enqueue(&q, 5);

	// ������ ������ ///////
	while(!QIsEmpty(&q))
		printf("%d ", Dequeue(&q)); 
		*/

	return 0;
}