//�����ڵ�
#include <stdio.h>
#include "BinaryTree3.h"	// Ʈ���� ������ Ȯ���ϱ� ���ؼ�
#include "BinarySearchTree3.h"

void print()
{
	BTreeNode * avlRoot;
	BTreeNode * clNode;		// current left node
	BTreeNode * crNode;		// current right node
	BSTMakeAndInit(&avlRoot);
	printf("��Ʈ ���: %d \n", GetData(avlRoot));

	clNode = GetLeftSubTree(avlRoot);
	crNode = GetRightSubTree(avlRoot);
	printf("����1: %d, ������1: %d \n", GetData(clNode), GetData(crNode));

	clNode = GetLeftSubTree(clNode);
	crNode = GetRightSubTree(crNode);
	printf("����2: %d, ������2: %d \n", GetData(clNode), GetData(crNode));

	clNode = GetLeftSubTree(clNode);
	crNode = GetRightSubTree(crNode);
	printf("����3: %d, ������3: %d \n", GetData(clNode), GetData(crNode));

	clNode = GetLeftSubTree(clNode);
	crNode = GetRightSubTree(crNode);
	printf("����4: %d, ������4: %d \n", GetData(clNode), GetData(crNode));
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
		printf("%d��° -> ", i+1);
		scanf("%d", &a);
		BSTInsert(&avlRoot, a);
	}
	*/

	while(1)
	{
		printf("\n0:���� 1: RRȸ�� 2: LR ���� 3: RL���� \n�Է�: ");
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
			printf("RR��Ʈ ���: %d \n", GetData(avlRoot));

			clNode = GetLeftSubTree(avlRoot);
			crNode = GetRightSubTree(avlRoot);
			printf("����1: %d, ������1: %d \n", GetData(clNode), GetData(crNode));

			clNode = GetLeftSubTree(clNode);
			crNode = GetRightSubTree(crNode);
			printf("����2: %d, ������2: %d \n", GetData(clNode), GetData(crNode));

			clNode = GetLeftSubTree(clNode);
			crNode = GetRightSubTree(crNode);
			printf("����3: %d, ������3: %d \n", GetData(clNode), GetData(crNode));

			clNode = GetLeftSubTree(clNode);
			crNode = GetRightSubTree(crNode);
			printf("����4: %d, ������4: %d \n", GetData(clNode), GetData(crNode));
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
			printf("LR��Ʈ ���: %d \n", GetData(avlRoot));

			clNode = GetLeftSubTree(avlRoot);
			crNode = GetRightSubTree(avlRoot);
			printf("����1: %d, ������1: %d \n", GetData(clNode), GetData(crNode));
			/*
			clNode = GetLeftSubTree(clNode);
			crNode = GetRightSubTree(crNode);
			printf("����2: %d, ������2: %d \n", GetData(clNode), GetData(crNode));

		
			clNode = GetLeftSubTree(clNode);
			crNode = GetRightSubTree(crNode);
			printf("����3: %d, ������3: %d \n", GetData(clNode), GetData(crNode));

			clNode = GetLeftSubTree(clNode);
			crNode = GetRightSubTree(crNode);
			printf("����4: %d, ������4: %d \n", GetData(clNode), GetData(crNode));
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
			printf("RL��Ʈ ���: %d \n", GetData(avlRoot));

			clNode = GetLeftSubTree(avlRoot);
			crNode = GetRightSubTree(avlRoot);
			printf("����1: %d, ������1: %d \n", GetData(clNode), GetData(crNode));
			/*
			clNode = GetLeftSubTree(clNode);
			crNode = GetRightSubTree(crNode);
			printf("����2: %d, ������2: %d \n", GetData(clNode), GetData(crNode));

			
			clNode = GetLeftSubTree(clNode);
			crNode = GetRightSubTree(crNode);
			printf("����3: %d, ������3: %d \n", GetData(clNode), GetData(crNode));

			clNode = GetLeftSubTree(clNode);
			crNode = GetRightSubTree(crNode);
			printf("����4: %d, ������4: %d \n", GetData(clNode), GetData(crNode));
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
	printf("��Ʈ ���: %d \n", GetData(avlRoot));

	clNode = GetLeftSubTree(avlRoot);
	crNode = GetRightSubTree(avlRoot);
	printf("����1: %d, ������1: %d \n", GetData(clNode), GetData(crNode));

	clNode = GetLeftSubTree(clNode);
	crNode = GetRightSubTree(crNode);
	printf("����2: %d, ������2: %d \n", GetData(clNode), GetData(crNode));

	clNode = GetLeftSubTree(clNode);
	crNode = GetRightSubTree(crNode);
	printf("����3: %d, ������3: %d \n", GetData(clNode), GetData(crNode));

	clNode = GetLeftSubTree(clNode);
	crNode = GetRightSubTree(crNode);
	printf("����4: %d, ������4: %d \n", GetData(clNode), GetData(crNode));
	*/

	return 0;
}