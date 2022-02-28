#include <stdio.h>
#include "ListBaseQueue.h"

int main(void)
{
	// Queue의 생성 및 초기화 ///////
	Queue q;
	QueueInit(&q);
	int n,a,n1;
	while(1)
	{
		printf("\n\n0:종료 1:데이터 넣기\n->");
		scanf("%d", &n);
		if(n==0)
		{
			printf("종료");
			break;
		}
		if(n==1)
		{
			printf("\n넣을 개수: ");
			scanf("%d", &a);
			for(int i=0; i<a; i++)
			{
				scanf("%d", &n1);
				Enqueue(&q, n1);
			}

			printf("\n 데이터 꺼내기 \n");
			while(!QIsEmpty(&q))
				printf("%d ", Dequeue(&q)); 
		}
	}
	/*
	// 데이터 넣기 ///////
	Enqueue(&q, 1);  Enqueue(&q, 2);
	Enqueue(&q, 3);  Enqueue(&q, 4);
	Enqueue(&q, 5);

	// 데이터 꺼내기 ///////
	while(!QIsEmpty(&q))
		printf("%d ", Dequeue(&q)); 
		*/

	return 0;
}