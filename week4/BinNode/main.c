#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include"BinHeap.h"
struct BinNode
{
	int X;
	Position LeftChild;
	Position NextSibling;
};
struct Collection
{
	int CurrentSize;
	BinTree TheTrees[100];
};
BinQueue Initialize(void)
{
	BinQueue H;
	H = (BinQueue)malloc(sizeof(struct Collection));
	if (H == NULL)
		printf("error");
	H->CurrentSize = 0;
	H->TheTrees[0] = NULL;
	return H;
}
static BinTree CombinTrees(BinTree T1, BinTree T2)
{
	if (T1->X > T2->X)
	{
		return CombinTrees(T2, T1);
	}
	T2->NextSibling = T1->LeftChild;
	T1->LeftChild = T2;
	return T1;
}
BinQueue Merge(BinQueue H1, BinQueue H2)
{
	BinTree T1, T2, Carry = NULL;
	int i, j;
	H1->CurrentSize += H2->CurrentSize;
	for (i = 0, j = 1; j <= H1->CurrentSize; i++, j++)
	{
		T1 = H1->TheTrees[i];
		T2 = H2->TheTrees[i];
		switch (!!T1 + 2 * !!T2 + 4 * !!Carry)
		{
		case 0:
		case 1:
			break;
		case 2:
			H1->TheTrees[i] = T2;
			H2->TheTrees[i] = NULL;
			break;
		case 4:
			H1->TheTrees[i] = Carry;
			Carry = NULL;
			break;
		case 3:
			Carry = CombinTrees(T1, T2);
			H1->TheTrees[i] = H2->TheTrees[i] = NULL;
			break;
		case 5:
			Carry = CombinTrees(T1, Carry);
			H1->TheTrees[i] = NULL;
			break;
		case 6:
			Carry = CombinTrees(T2, Carry);
			H2->TheTrees[i] = NULL;
			break;
		case 7:
			H1->TheTrees[i] = Carry;
			Carry = CombinTrees(T1, T2);
			H2->TheTrees[i] = NULL;
			break;
		}
	}
	return H1;
}
int DeleteMin(BinQueue H)
{
	int i, j;
	int MinTree;
	BinQueue DeletedQueue;
	Position DeletedTree, OldRoot;
	int MinItem;
	MinItem = 100;
	for (i = 0; i < 100; i++)
	{
		if (H->TheTrees[i] && H->TheTrees[i]->X < MinItem)
		{
			MinItem = H->TheTrees[i]->X;
			MinTree = i;
		}
	}
	DeletedTree = H->TheTrees[MinTree];
	OldRoot = DeletedTree;
	DeletedTree = DeletedTree->LeftChild;
	free(OldRoot);
	DeletedQueue = Initialize();
	DeletedQueue->CurrentSize = (1 << MinTree) - 1;
	for (j = MinTree - 1; j >= 0; j--)
	{
		DeletedQueue->TheTrees[j] = DeletedTree;
		DeletedTree = DeletedTree->NextSibling;
		DeletedQueue->TheTrees[j]->NextSibling = NULL;
	}
	H->TheTrees[MinTree] = NULL;
	H->CurrentSize -= DeletedQueue->CurrentSize + 1;
	Merge(H, DeletedQueue);
	return MinItem;
}
BinQueue Insert(int X, BinQueue H)
{
	BinQueue B0 = Initialize();
	B0->CurrentSize = 1;
	B0->TheTrees[0] = (BinTree)malloc(sizeof(struct BinNode));
	if (B0->TheTrees[0] == NULL)
		printf("error");
	B0->TheTrees[0]->X = X;
	B0->TheTrees[0]->LeftChild = NULL;
	B0->TheTrees[0]->NextSibling = NULL;
	return Merge(B0, H);
}
int main()
{
	BinQueue T1, T2, T3;
	T1 = T2 = T3 = Initialize();
	T1 = Insert(1, T1);
	T2 = Insert(2, T2);
	T3 = Insert(3, T3);
	T1 = Merge(T1, T2);
	T1 = Merge(T1, T3);
	int a = DeleteMin(T1);
	printf("最小值%d\n", a);
}
