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
// pre 전위 순회
void PreorderTraverse(BTreeNode * bt, VisitFuncPtr action);
void InorderTraverse(BTreeNode * bt, VisitFuncPtr action);
void PostorderTraverse(BTreeNode * bt, VisitFuncPtr action);
// pos 후위순외
// 왼쪽 자식 노드 제거, 제거된 노드의 주소 값이 반환된다.
BTreeNode * RemoveLeftSubTree(BTreeNode * bt);

// 오른쪽 자식 노드 제거, 제거된 노드의 주소 값이 반환된다.
BTreeNode * RemoveRightSubTree(BTreeNode * bt);

// 메모리 소멸을 수반하지 않고 main의 왼쪽 자식 노드를 변경한다. 
void ChangeLeftSubTree(BTreeNode * main, BTreeNode * sub);

// 메모리 소멸을 수반하지 않고 main의 오른쪽 자식 노드를 변경한다. 
void ChangeRightSubTree(BTreeNode * main, BTreeNode * sub);

#endif

#ifndef __BINARY_SEARCH_TREE2_H__
#define __BINARY_SEARCH_TREE2_H__


typedef BTData	BSTData;

// 이진 탐색 트리의 생성 및 초기화
void BSTMakeAndInit(BTreeNode ** pRoot);

// 노드에 저장된 데이터 반환
BSTData BSTGetNodeData(BTreeNode * bst);

// 이진 탐색 트리를 대상으로 데이터 저장(노드의 생성과정 포함)
void BSTInsert(BTreeNode ** pRoot, BSTData data);

// 이진 탐색 트리를 대상으로 데이터 탐색
BTreeNode * BSTSearch(BTreeNode * bst, BSTData target);

// 트리에서 노드를 제거하고 제거된 노드의 주소 값을 반환한다. 
BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target);

// 이진 탐색 트리에 저장된 모든 노드의 데이터를 출력한다.
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
// 전위
void PreorderTraverse(BTreeNode * bt, VisitFuncPtr action)
{
	if(bt == NULL)
		return;

	action(bt->data);
	PreorderTraverse(bt->left, action);
	PreorderTraverse(bt->right, action);
}
//중위
void InorderTraverse(BTreeNode * bt, VisitFuncPtr action)
{
	if(bt == NULL)
		return;

	InorderTraverse(bt->left, action);
	action(bt->data);
	InorderTraverse(bt->right, action);
}
//후위
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

	// 새로운 노드가 추가될 위치를 찾는다.
	while(cNode != NULL)
	{
		if(data == GetData(cNode))
			return;    // 키의 중복을 허용하지 않음

		pNode = cNode;

		if(GetData(cNode) > data)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}
	
	// pNode의 서브 노드에 추가할 새 노드의 생성
	nNode = MakeBTreeNode();    // 새 노드의 생성
	SetData(nNode, data);    // 새 노드에 데이터 저장

	// pNode의 서브 노드에 새 노드를 추가
	if(pNode != NULL)    // 새 노드가 루트 노드가 아니라면,
	{
		if(data < GetData(pNode))
			MakeLeftSubTree(pNode, nNode);
		else
			MakeRightSubTree(pNode, nNode);
	}
	else    // 새 노드가 루트 노드라면,
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
	// 삭제 대상이 루트 노드인 경우를 별도로 고려해야 한다.

	BTreeNode * pVRoot = MakeBTreeNode();    // 가상 루트 노드;

	BTreeNode * pNode = pVRoot;    // parent node
	BTreeNode * cNode = *pRoot;    // current node
	BTreeNode * dNode;    // delete node

	// 루트 노드를 pVRoot가 가리키는 노드의 오른쪽 서브 노드가 되게 한다.
	ChangeRightSubTree(pVRoot, *pRoot);
	
	// 삭제 대상을 저장한 노드 탐색
	while(cNode != NULL && GetData(cNode) != target)
	{
		pNode = cNode;

		if(target < GetData(cNode))
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	if(cNode == NULL)    // 삭제 대상이 존재하지 않는다면,
		return NULL;

	dNode = cNode;    // 삭제 대상을 dNode가 가리키게 한다.

	// 첫 번째 경우: 삭제할 노드가 단말 노드인 경우
	if(GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL)
	{
		if(GetLeftSubTree(pNode) == dNode)
			RemoveLeftSubTree(pNode);
		else
			RemoveRightSubTree(pNode);
	}

	// 두 번째 경우: 하나의 자식 노드를 갖는 경우
	else if(GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL)
	{
		BTreeNode * dcNode;    // delete node의 자식 노드

		if(GetLeftSubTree(dNode) != NULL)
			dcNode = GetLeftSubTree(dNode);
		else
			dcNode = GetRightSubTree(dNode);

		if(GetLeftSubTree(pNode) == dNode)
			ChangeLeftSubTree(pNode, dcNode);
		else
			ChangeRightSubTree(pNode, dcNode);
	}

	// 세 번째 경우: 두 개의 자식 노드를 모두 갖는 경우
	else
	{
		BTreeNode * mNode = GetRightSubTree(dNode);    // mininum node
		BTreeNode * mpNode = dNode;    // mininum node의 부모 노드
		int delData;

		// 삭제할 노드를 대체할 노드를 찾는다.
		while(GetLeftSubTree(mNode) != NULL)
		{
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}
		
		// 대체할 노드에 저장된 값을 삭제할 노드에 대입한다.
		delData = GetData(dNode);    // 대입 전 데이터 백업
		SetData(dNode, GetData(mNode));

		// 대체할 노드의 부모 노드와 자식 노드를 연결한다.
		if(GetLeftSubTree(mpNode) == mNode)
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		else
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));

		dNode = mNode;
		SetData(dNode, delData);    // 백업 데이터 복원
	}

	// 삭제된 노드가 루트 노드인 경우에 대한 처리
	if(GetRightSubTree(pVRoot) != *pRoot)
		*pRoot = GetRightSubTree(pVRoot);

	free(pVRoot);
	return dNode;
}

void ShowIntData(int data)
{
	printf("%d ", data);
}

void BSTShowAll_ino(BTreeNode * bst)//중위
{
	InorderTraverse(bst, ShowIntData);
}

void BSTShowAll_pre(BTreeNode * bst)//전위
{
	PreorderTraverse(bst, ShowIntData);
}

void BSTShowAll_pos(BTreeNode * bst)//후위
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
	while( i<9) // eof함수란 파일 안의 문자가 파일의 끝 eof 이 아닐 경우 계속 반복해서 while문을 도는 것 무슨 말인지 모르겠지만 일단 그럼
	{
		printf("%d -> ", i+1);
		scanf("%d", &a);
		BSTInsert(&bstRoot, a);
		i++;
	}


	printf("\n\n<PreorderTraverse>\n"); // 전위
	BSTShowAll_pre(bstRoot);

	printf("\n\n<InorderTraverse>\n"); // 중위
	BSTShowAll_ino(bstRoot);

	printf("\n\n<PostorderTraverse>\n"); // 후위
	BSTShowAll_pos(bstRoot);
	return 0;
}
//왜 되지?