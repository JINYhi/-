#include <stdio.h>
#include <stdlib.h>
#ifndef __BINARY_TREE3_H__
#define __BINARY_TREE3_H__

typedef int BTData;

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode * left;
	struct _bTreeNode * right;
} BTreeNode;

BTreeNode * MakeBTreeNode(void);
BTData GetData(BTreeNode * bt);
void SetData(BTreeNode * bt, BTData data);

BTreeNode * GetLeftSubTree(BTreeNode * bt);
BTreeNode * GetRightSubTree(BTreeNode * bt);

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub);
void MakeRightSubTree(BTreeNode * main, BTreeNode * sub);

typedef void VisitFuncPtr(BTData data);
// pre ���� ��ȸ
void PreorderTraverse(BTreeNode * bt, VisitFuncPtr action);
void InorderTraverse(BTreeNode * bt, VisitFuncPtr action);
void PostorderTraverse(BTreeNode * bt, VisitFuncPtr action);
// pos ��������
// ���� �ڽ� ��� ����, ���ŵ� ����� �ּ� ���� ��ȯ�ȴ�.
BTreeNode * RemoveLeftSubTree(BTreeNode * bt);

// ������ �ڽ� ��� ����, ���ŵ� ����� �ּ� ���� ��ȯ�ȴ�.
BTreeNode * RemoveRightSubTree(BTreeNode * bt);

// �޸� �Ҹ��� �������� �ʰ� main�� ���� �ڽ� ��带 �����Ѵ�. 
void ChangeLeftSubTree(BTreeNode * main, BTreeNode * sub);

// �޸� �Ҹ��� �������� �ʰ� main�� ������ �ڽ� ��带 �����Ѵ�. 
void ChangeRightSubTree(BTreeNode * main, BTreeNode * sub);

#endif

#ifndef __BINARY_SEARCH_TREE2_H__
#define __BINARY_SEARCH_TREE2_H__


typedef BTData	BSTData;

// ���� Ž�� Ʈ���� ���� �� �ʱ�ȭ
void BSTMakeAndInit(BTreeNode ** pRoot);

// ��忡 ����� ������ ��ȯ
BSTData BSTGetNodeData(BTreeNode * bst);

// ���� Ž�� Ʈ���� ������� ������ ����(����� �������� ����)
void BSTInsert(BTreeNode ** pRoot, BSTData data);

// ���� Ž�� Ʈ���� ������� ������ Ž��
BTreeNode * BSTSearch(BTreeNode * bst, BSTData target);

// Ʈ������ ��带 �����ϰ� ���ŵ� ����� �ּ� ���� ��ȯ�Ѵ�. 
BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target);

// ���� Ž�� Ʈ���� ����� ��� ����� �����͸� ����Ѵ�.
void BSTShowAll_pos(BTreeNode * bst);

void BSTShowAll_ino(BTreeNode * bst);

void BSTShowAll_pre(BTreeNode * bst);

#endif

/////

BTreeNode * MakeBTreeNode(void)
{
	BTreeNode * nd = (BTreeNode*)malloc(sizeof(BTreeNode));

	nd->left = NULL;
	nd->right = NULL;
	return nd;
}

BTData GetData(BTreeNode * bt)
{
	return bt->data;
}

void SetData(BTreeNode * bt, BTData data)
{
	bt->data = data;
}

BTreeNode * GetLeftSubTree(BTreeNode * bt)
{
	return bt->left;
}

BTreeNode * GetRightSubTree(BTreeNode * bt)
{
	return bt->right;
}

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub)
{
	if(main->left != NULL)
		free(main->left);

	main->left = sub;
}

void MakeRightSubTree(BTreeNode * main, BTreeNode * sub)
{
	if(main->right != NULL)
		free(main->right);

	main->right = sub;
}
// ����
void PreorderTraverse(BTreeNode * bt, VisitFuncPtr action)
{
	if(bt == NULL)
		return;

	action(bt->data);
	PreorderTraverse(bt->left, action);
	PreorderTraverse(bt->right, action);
}
//����
void InorderTraverse(BTreeNode * bt, VisitFuncPtr action)
{
	if(bt == NULL)
		return;

	InorderTraverse(bt->left, action);
	action(bt->data);
	InorderTraverse(bt->right, action);
}
//����
void PostorderTraverse(BTreeNode * bt, VisitFuncPtr action)
{
	if(bt == NULL)
		return;

	PostorderTraverse(bt->left, action);
	PostorderTraverse(bt->right, action);
	action(bt->data);
}

BTreeNode * RemoveLeftSubTree(BTreeNode * bt)
{
	BTreeNode * delNode;

	if(bt != NULL) {
		delNode = bt->left;
		bt->left = NULL;
	}
	return delNode;
}

BTreeNode * RemoveRightSubTree(BTreeNode * bt)
{
	BTreeNode * delNode;

	if(bt != NULL) {
		delNode = bt->right;
		bt->right = NULL;
	}
	return delNode;
}

void ChangeLeftSubTree(BTreeNode * main, BTreeNode * sub) 
{
	main->left = sub;
}
 
void ChangeRightSubTree(BTreeNode * main, BTreeNode * sub)
{
	main->right = sub;
}
////



///

void BSTMakeAndInit(BTreeNode ** pRoot)
{
	*pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode * bst)
{
	return GetData(bst);
}

void BSTInsert(BTreeNode ** pRoot, BSTData data)
{
	BTreeNode * pNode = NULL;    // parent node
	BTreeNode * cNode = *pRoot;    // current node
	BTreeNode * nNode = NULL;    // new node

	// ���ο� ��尡 �߰��� ��ġ�� ã�´�.
	while(cNode != NULL)
	{
		if(data == GetData(cNode))
			return;    // Ű�� �ߺ��� ������� ����

		pNode = cNode;

		if(GetData(cNode) > data)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}
	
	// pNode�� ���� ��忡 �߰��� �� ����� ����
	nNode = MakeBTreeNode();    // �� ����� ����
	SetData(nNode, data);    // �� ��忡 ������ ����

	// pNode�� ���� ��忡 �� ��带 �߰�
	if(pNode != NULL)    // �� ��尡 ��Ʈ ��尡 �ƴ϶��,
	{
		if(data < GetData(pNode))
			MakeLeftSubTree(pNode, nNode);
		else
			MakeRightSubTree(pNode, nNode);
	}
	else    // �� ��尡 ��Ʈ �����,
	{
		*pRoot = nNode;
	}
}

BTreeNode * BSTSearch(BTreeNode * bst, BSTData target)
{
	BTreeNode * cNode = bst;    // current node
	BSTData cd;    // current data

	while(cNode != NULL)
	{
		cd = GetData(cNode);

		if(target == cd)
			return cNode;
		else if(target < cd)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	return NULL;
}

BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target)
{
	// ���� ����� ��Ʈ ����� ��츦 ������ ����ؾ� �Ѵ�.

	BTreeNode * pVRoot = MakeBTreeNode();    // ���� ��Ʈ ���;

	BTreeNode * pNode = pVRoot;    // parent node
	BTreeNode * cNode = *pRoot;    // current node
	BTreeNode * dNode;    // delete node

	// ��Ʈ ��带 pVRoot�� ����Ű�� ����� ������ ���� ��尡 �ǰ� �Ѵ�.
	ChangeRightSubTree(pVRoot, *pRoot);
	
	// ���� ����� ������ ��� Ž��
	while(cNode != NULL && GetData(cNode) != target)
	{
		pNode = cNode;

		if(target < GetData(cNode))
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	if(cNode == NULL)    // ���� ����� �������� �ʴ´ٸ�,
		return NULL;

	dNode = cNode;    // ���� ����� dNode�� ����Ű�� �Ѵ�.

	// ù ��° ���: ������ ��尡 �ܸ� ����� ���
	if(GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL)
	{
		if(GetLeftSubTree(pNode) == dNode)
			RemoveLeftSubTree(pNode);
		else
			RemoveRightSubTree(pNode);
	}

	// �� ��° ���: �ϳ��� �ڽ� ��带 ���� ���
	else if(GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL)
	{
		BTreeNode * dcNode;    // delete node�� �ڽ� ���

		if(GetLeftSubTree(dNode) != NULL)
			dcNode = GetLeftSubTree(dNode);
		else
			dcNode = GetRightSubTree(dNode);

		if(GetLeftSubTree(pNode) == dNode)
			ChangeLeftSubTree(pNode, dcNode);
		else
			ChangeRightSubTree(pNode, dcNode);
	}

	// �� ��° ���: �� ���� �ڽ� ��带 ��� ���� ���
	else
	{
		BTreeNode * mNode = GetRightSubTree(dNode);    // mininum node
		BTreeNode * mpNode = dNode;    // mininum node�� �θ� ���
		int delData;

		// ������ ��带 ��ü�� ��带 ã�´�.
		while(GetLeftSubTree(mNode) != NULL)
		{
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}
		
		// ��ü�� ��忡 ����� ���� ������ ��忡 �����Ѵ�.
		delData = GetData(dNode);    // ���� �� ������ ���
		SetData(dNode, GetData(mNode));

		// ��ü�� ����� �θ� ���� �ڽ� ��带 �����Ѵ�.
		if(GetLeftSubTree(mpNode) == mNode)
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		else
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));

		dNode = mNode;
		SetData(dNode, delData);    // ��� ������ ����
	}

	// ������ ��尡 ��Ʈ ����� ��쿡 ���� ó��
	if(GetRightSubTree(pVRoot) != *pRoot)
		*pRoot = GetRightSubTree(pVRoot);

	free(pVRoot);
	return dNode;
}

void ShowIntData(int data)
{
	printf("%d ", data);
}

void BSTShowAll_ino(BTreeNode * bst)//����
{
	InorderTraverse(bst, ShowIntData);
}

void BSTShowAll_pre(BTreeNode * bst)//����
{
	PreorderTraverse(bst, ShowIntData);
}

void BSTShowAll_pos(BTreeNode * bst)//����
{
	PostorderTraverse(bst, ShowIntData);
}
///

////





int main(void)
{
	BTreeNode * bstRoot;
	BTreeNode * sNode;    // search node

	BSTMakeAndInit(&bstRoot);
	printf("<< BinarySerchTree >>\n");
	printf("Number of inputs: 9\n");
	int a;
	int i = 0;
	while( i<9) // eof�Լ��� ���� ���� ���ڰ� ������ �� eof �� �ƴ� ��� ��� �ݺ��ؼ� while���� ���� �� ���� ������ �𸣰����� �ϴ� �׷�
	{
		printf("%d -> ", i+1);
		scanf("%d", &a);
		BSTInsert(&bstRoot, a);
		i++;
	}


	printf("\n\n<PreorderTraverse>\n"); // ����
	BSTShowAll_pre(bstRoot);

	printf("\n\n<InorderTraverse>\n"); // ����
	BSTShowAll_ino(bstRoot);

	printf("\n\n<PostorderTraverse>\n"); // ����
	BSTShowAll_pos(bstRoot);
	return 0;
}
//�� ����?