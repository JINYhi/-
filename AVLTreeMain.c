//메인코드
#include <stdio.h>
#include "BinaryTree3.h"	// 트리의 구조를 확인하기 위해서
#include "BinarySearchTree3.h"

void print()
{
	BTreeNode * avlRoot;
	BTreeNode * clNode;		// current left node
	BTreeNode * crNode;		// current right node
	BSTMakeAndInit(&avlRoot);
	printf("루트 노드: %d \n", GetData(avlRoot));

	clNode = GetLeftSubTree(avlRoot);
	crNode = GetRightSubTree(avlRoot);
	printf("왼쪽1: %d, 오른쪽1: %d \n", GetData(clNode), GetData(crNode));

	clNode = GetLeftSubTree(clNode);
	crNode = GetRightSubTree(crNode);
	printf("왼쪽2: %d, 오른쪽2: %d \n", GetData(clNode), GetData(crNode));

	clNode = GetLeftSubTree(clNode);
	crNode = GetRightSubTree(crNode);
	printf("왼쪽3: %d, 오른쪽3: %d \n", GetData(clNode), GetData(crNode));

	clNode = GetLeftSubTree(clNode);
	crNode = GetRightSubTree(crNode);
	printf("왼쪽4: %d, 오른쪽4: %d \n", GetData(clNode), GetData(crNode));
}

int main(void)
{
	BTreeNode * avlRoot;
	BTreeNode * clNode;		// current left node
	BTreeNode * crNode;		// current right node
	BSTMakeAndInit(&avlRoot);
	int n, a;
	
	/*
	for(int i=0; i<n; i++)
	{
		printf("%d번째 -> ", i+1);
		scanf("%d", &a);
		BSTInsert(&avlRoot, a);
	}
	*/

	while(1)
	{
		printf("\n0:정지 1: RR회전 2: LR 상태 3: RL상태 \n입력: ");
		scanf("%d", &n);
		if (n==0)
			break;
		if(n==1)
		{
			BTreeNode * avlRoot;
			BTreeNode * clNode;		// current left node
			BTreeNode * crNode;		// current right node
			BSTMakeAndInit(&avlRoot);
			BSTInsert(&avlRoot, 1);
			BSTInsert(&avlRoot, 2);
			BSTInsert(&avlRoot, 3);
			BSTInsert(&avlRoot, 4);
			BSTInsert(&avlRoot, 5);
			BSTInsert(&avlRoot, 6);
			BSTInsert(&avlRoot, 7);
			BSTInsert(&avlRoot, 8);
			BSTInsert(&avlRoot, 9);
			printf("1,2,3,4,5,6,7,8,9\n");
			printf("RR루트 노드: %d \n", GetData(avlRoot));

			clNode = GetLeftSubTree(avlRoot);
			crNode = GetRightSubTree(avlRoot);
			printf("왼쪽1: %d, 오른쪽1: %d \n", GetData(clNode), GetData(crNode));

			clNode = GetLeftSubTree(clNode);
			crNode = GetRightSubTree(crNode);
			printf("왼쪽2: %d, 오른쪽2: %d \n", GetData(clNode), GetData(crNode));

			clNode = GetLeftSubTree(clNode);
			crNode = GetRightSubTree(crNode);
			printf("왼쪽3: %d, 오른쪽3: %d \n", GetData(clNode), GetData(crNode));

			clNode = GetLeftSubTree(clNode);
			crNode = GetRightSubTree(crNode);
			printf("왼쪽4: %d, 오른쪽4: %d \n", GetData(clNode), GetData(crNode));
		}

		if(n==2)
		{	
			BTreeNode * avlRoot;
			BTreeNode * clNode;		// current left node
			BTreeNode * crNode;		// current right node
			BSTMakeAndInit(&avlRoot);
			printf("5,2,3\n");
			BSTInsert(&avlRoot, 5);
			BSTInsert(&avlRoot, 2);
			BSTInsert(&avlRoot, 3);
			printf("LR루트 노드: %d \n", GetData(avlRoot));

			clNode = GetLeftSubTree(avlRoot);
			crNode = GetRightSubTree(avlRoot);
			printf("왼쪽1: %d, 오른쪽1: %d \n", GetData(clNode), GetData(crNode));
			/*
			clNode = GetLeftSubTree(clNode);
			crNode = GetRightSubTree(crNode);
			printf("왼쪽2: %d, 오른쪽2: %d \n", GetData(clNode), GetData(crNode));

		
			clNode = GetLeftSubTree(clNode);
			crNode = GetRightSubTree(crNode);
			printf("왼쪽3: %d, 오른쪽3: %d \n", GetData(clNode), GetData(crNode));

			clNode = GetLeftSubTree(clNode);
			crNode = GetRightSubTree(crNode);
			printf("왼쪽4: %d, 오른쪽4: %d \n", GetData(clNode), GetData(crNode));
			*/

		}


		if(n==3)
		{
			BTreeNode * avlRoot;
			BTreeNode * clNode;		// current left node
			BTreeNode * crNode;		// current right node
			BSTMakeAndInit(&avlRoot);
			printf("2,7,4\n");
			BSTInsert(&avlRoot, 2);
			BSTInsert(&avlRoot, 7);
			BSTInsert(&avlRoot, 4);
			printf("RL루트 노드: %d \n", GetData(avlRoot));

			clNode = GetLeftSubTree(avlRoot);
			crNode = GetRightSubTree(avlRoot);
			printf("왼쪽1: %d, 오른쪽1: %d \n", GetData(clNode), GetData(crNode));
			/*
			clNode = GetLeftSubTree(clNode);
			crNode = GetRightSubTree(crNode);
			printf("왼쪽2: %d, 오른쪽2: %d \n", GetData(clNode), GetData(crNode));

			
			clNode = GetLeftSubTree(clNode);
			crNode = GetRightSubTree(crNode);
			printf("왼쪽3: %d, 오른쪽3: %d \n", GetData(clNode), GetData(crNode));

			clNode = GetLeftSubTree(clNode);
			crNode = GetRightSubTree(crNode);
			printf("왼쪽4: %d, 오른쪽4: %d \n", GetData(clNode), GetData(crNode));
			*/
		}
	}
	/*
	BSTInsert(&avlRoot, 1);
	BSTInsert(&avlRoot, 2);
	BSTInsert(&avlRoot, 3);
	BSTInsert(&avlRoot, 4);
	BSTInsert(&avlRoot, 5);
	BSTInsert(&avlRoot, 6);
	BSTInsert(&avlRoot, 7);
	BSTInsert(&avlRoot, 8);
	BSTInsert(&avlRoot, 9);
	*/
	/*
	printf("루트 노드: %d \n", GetData(avlRoot));

	clNode = GetLeftSubTree(avlRoot);
	crNode = GetRightSubTree(avlRoot);
	printf("왼쪽1: %d, 오른쪽1: %d \n", GetData(clNode), GetData(crNode));

	clNode = GetLeftSubTree(clNode);
	crNode = GetRightSubTree(crNode);
	printf("왼쪽2: %d, 오른쪽2: %d \n", GetData(clNode), GetData(crNode));

	clNode = GetLeftSubTree(clNode);
	crNode = GetRightSubTree(crNode);
	printf("왼쪽3: %d, 오른쪽3: %d \n", GetData(clNode), GetData(crNode));

	clNode = GetLeftSubTree(clNode);
	crNode = GetRightSubTree(crNode);
	printf("왼쪽4: %d, 오른쪽4: %d \n", GetData(clNode), GetData(crNode));
	*/

	return 0;
}