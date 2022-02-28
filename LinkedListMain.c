#include <stdio.h>
#include "LinkedList.h"

int main(void)
{
	// ë¦¬ìŠ¤?? ?ì„± ë°? ì´ˆê¸°?? /////////////////////////////
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
    if (a == 0) // 1ë¥? ?…ë ¥?˜ë©´
    {
        printf("insert : ");
        scanf("%d", &b); // bë¥? ?…ë ¥?˜ë„ë¡? ?«ì ?„ë¬´ê±°ë‚˜
        LInsert(&list, b); //?°ì´?°ì—, b ????
    }

	// ???¥ëœ ?°ì´?? ?„ì²´ ì¶œë ¥ /////////////////////////

	if(LFirst(&list, &data))    // 
	{
		printf("%d ", data);
		
		while(LNext(&list, &data))    // 
			printf("%d ", data);
	}
	printf("\n\n");
    
    //// ?«ì b ê²??‰í•˜?? ëª¨ë‘ ?? œ ///
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
        // ?? œ ?? ?¨ì•„?ˆëŠ” ?°ì´?? ?„ì²´ ì¶œë ¥ ////////////////////////

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