#include <stdio.h>
#include "LinkedList.h"

int main(void)
{
	// 리스?? ?�성 �? 초기?? /////////////////////////////
	List list;
	int data;
	ListInit(&list);
	printf("0:insert\n1:delete\n2:stop\n");

while (1)
{
	int a,b;
    printf("select menu -> ");
    scanf("%d", &a);
    if (a == 2)
        break;
    if (a == 0) // 1�? ?�력?�면
    {
        printf("insert : ");
        scanf("%d", &b); // b�? ?�력?�도�? ?�자 ?�무거나
        LInsert(&list, b); //?�이?�에, b ????
    }

	// ???�된 ?�이?? ?�체 출력 /////////////////////////

	if(LFirst(&list, &data))    // 
	{
		printf("%d ", data);
		
		while(LNext(&list, &data))    // 
			printf("%d ", data);
	}
	printf("\n\n");
    
    //// ?�자 b �??�하?? 모두 ??�� ///
    if (a == 1)
    {
        printf("delete : ");
        scanf("%d", &b);
        if(LFirst(&list, &data))
	    {
		    if(data == b)
			    LRemove(&list);
		
		    while(LNext(&list, &data))
		    {
			    if(data == b)
				    LRemove(&list);
		    }
	    }
        // ??�� ?? ?�아?�는 ?�이?? ?�체 출력 ////////////////////////

	    if(LFirst(&list, &data))
	    {
		    printf("%d ", data);
		
		    while(LNext(&list, &data))
			    printf("%d ", data);
	    }
	    printf("\n\n");   
    }
}

	return 0;
}