#include <stdio.h>
#include "ListBaseStack.h"

int main(void)
{
	// Stack�� ���� �� �ʱ�ȭ ///////
	Stack stack;
	StackInit(&stack);
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
				SPush(&stack, n1);
			}

			printf("\n ������ ������ \n");
			while(!SIsEmpty(&stack))
				printf("%d ", SPop(&stack)); 
		}
	}
	// ������ �ֱ� ///////
	/*
	SPush(&stack, 1);  SPush(&stack, 2);
	SPush(&stack, 3);  SPush(&stack, 4);
	SPush(&stack, 5);

	// ������ ������ ///////
	while(!SIsEmpty(&stack))
		printf("%d ", SPop(&stack)); 
*/
	return 0;
}