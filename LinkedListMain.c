#include <stdio.h>
#include "LinkedList.h"

int main(void)
{
	// λ¦¬μ€?? ?μ± λ°? μ΄κΈ°?? /////////////////////////////
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
    if (a == 0) // 1λ₯? ?λ ₯?λ©΄
    {
        printf("insert : ");
        scanf("%d", &b); // bλ₯? ?λ ₯?λλ‘? ?«μ ?λ¬΄κ±°λ
        LInsert(&list, b); //?°μ΄?°μ, b ????
    }

	// ???₯λ ?°μ΄?? ?μ²΄ μΆλ ₯ /////////////////////////

	if(LFirst(&list, &data))    // 
	{
		printf("%d ", data);
		
		while(LNext(&list, &data))    // 
			printf("%d ", data);
	}
	printf("\n\n");
    
    //// ?«μ b κ²??ν?? λͺ¨λ ??  ///
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
        // ??  ?? ?¨μ?λ ?°μ΄?? ?μ²΄ μΆλ ₯ ////////////////////////

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