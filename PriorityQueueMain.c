#include <stdio.h>
#include "PriorityQueue.h"

int DataPriorityComp(char ch1, char ch2)
{
	return ch2-ch1;
}

int main(void)
{
	
	PQueue pq;
	PQueueInit(&pq, DataPriorityComp);

	int a;
	char b;

	printf("\n+: 1, - : 2, stop : 3\n ");
	while(1)
	{
		
		scanf("%d", &a);

		if (a == 1) {
			//printf("+ : ");
			scanf(" %c", &b);
			PEnqueue(&pq, b);
			//printf(" ----->  %c \n", PDequeue(&pq));
		}
	
		if ( a== 3) {
			break;
		}
	/*
	PEnqueue(&pq, 'A');
	PEnqueue(&pq, 'B');
	PEnqueue(&pq, 'C');
	printf("%c \n", PDequeue(&pq));

	PEnqueue(&pq, 'A');
	PEnqueue(&pq, 'B');
	PEnqueue(&pq, 'C');
	printf("%c \n", PDequeue(&pq));
	*/
		if (a == 2){
			while(!PQIsEmpty(&pq))
			printf("%c ", PDequeue(&pq));
			printf("\n");
		}
	
	}
	return 0;
}
