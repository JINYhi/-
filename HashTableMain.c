#include <stdio.h>
#include <stdlib.h>
#include "Person.h"
#include "Table2.h"

int MyHashFunc(int k)
{
	return k % 100;
}

int main(void)
{
	Table myTbl;
	Person * np;
	Person * sp;
	Person * rp;

	TBLInit(&myTbl, MyHashFunc);

	int a1;

	
	int a = 900254;
	int b = 900139;
	int c = 900827;
	// ������ �Է� ///////

	np = MakePersonData(a, "Lee", "Seoul");
	TBLInsert(&myTbl, GetSSN(np), np);


	np = MakePersonData(b, "KIM", "Jeju");
	TBLInsert(&myTbl, GetSSN(np), np);

	np = MakePersonData(c, "HAN", "Kangwon");
	TBLInsert(&myTbl, GetSSN(np), np);

	while(1)
	{
		printf("���� : 0, ��ü ������ ���� : 1 , ������ ���� : 2 ,������ Ž�� : 3\n->");
		scanf("%d", &a1);
		printf("\n");
		if(a1==0)
			break;
		if(a1==1)
		{
			///// ��ü ������ ////
			sp = TBLSearch(&myTbl, a);
			if(sp != NULL)
				ShowPerInfo(sp);
			sp = TBLSearch(&myTbl, b);
			if(sp != NULL)
				ShowPerInfo(sp);
			sp = TBLSearch(&myTbl, c);
			if(sp != NULL)
				ShowPerInfo(sp);
		}

		if(a1==2)
		{
			// ������ ���� ///////
			int sak;
			printf("������ ������ ->");
			scanf("%d", &sak);

			rp = TBLDelete(&myTbl, sak);
			if(rp != NULL)
				free(rp);
		}


		if(a1 ==3)
		{
			// ������ Ž�� ///////
			int tam;
			printf("Ž���� ������->");
			scanf("%d", &tam);
			sp = TBLSearch(&myTbl, tam);
			if(sp != NULL)
				ShowPerInfo(sp);

		}



	


	}

	return 0;
}

/*
int main(void)
{
	Table myTbl;
	Person * np;
	Person * sp;
	Person * rp;

	TBLInit(&myTbl, MyHashFunc);

	// ������ �Է� ///////
	np = MakePersonData(900254, "Lee", "Seoul");
	TBLInsert(&myTbl, GetSSN(np), np);

	np = MakePersonData(900139, "KIM", "Jeju");
	TBLInsert(&myTbl, GetSSN(np), np);

	np = MakePersonData(900827, "HAN", "Kangwon");
	TBLInsert(&myTbl, GetSSN(np), np);

	// ������ Ž�� ///////
	sp = TBLSearch(&myTbl, 900254);
	if(sp != NULL)
		ShowPerInfo(sp);

	sp = TBLSearch(&myTbl, 900139);
	if(sp != NULL)
		ShowPerInfo(sp);

	sp = TBLSearch(&myTbl, 900827);
	if(sp != NULL)
		ShowPerInfo(sp);

	// ������ ���� ///////
	rp = TBLDelete(&myTbl, 900254);
	if(rp != NULL)
		free(rp);

	rp = TBLDelete(&myTbl, 900139);
	if(rp != NULL)
		free(rp);

	rp = TBLDelete(&myTbl, 900827);
	if(rp != NULL)
		free(rp);

	return 0;
}
*/