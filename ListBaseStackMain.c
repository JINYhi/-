#include <stdio.h>
#include "ListBaseStack.h"

int main(void)
{
	// Stack의 생성 및 초기화 ///////
	Stack stack;
	StackInit(&stack);
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
				SPush(&stack, n1);
			}

			printf("\n 데이터 꺼내기 \n");
			while(!SIsEmpty(&stack))
				printf("%d ", SPop(&stack)); 
		}
	}
	// 데이터 넣기 ///////
	/*
	SPush(&stack, 1);  SPush(&stack, 2);
	SPush(&stack, 3);  SPush(&stack, 4);
	SPush(&stack, 5);

	// 데이터 꺼내기 ///////
	while(!SIsEmpty(&stack))
		printf("%d ", SPop(&stack)); 
*/
	return 0;
}