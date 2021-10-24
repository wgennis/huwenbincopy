#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include"LeftHeap.h"
struct TreeNode
{
	int a;
	PrioityQueue Left;
	PrioityQueue Right;
	int Npl;
};
PrioityQueue Initialize(int X)
{
	PrioityQueue H;
	H = (PrioityQueue)malloc(sizeof(struct TreeNode));
	if (H == NULL)
		printf("error");
	H->a = X;
	H->Npl = -1;
	H->Left = H->Right = NULL;
	return H;
}
static PrioityQueue Merge1(PrioityQueue H1, PrioityQueue H2)
{
	if (H1->Left == NULL)
		H1->Left = H2;
	else
	{
		H1->Right = Merge(H1->Right, H2);
		if (H1->Left->Npl < H1->Right->Npl)
		{
			PrioityQueue NewCell;
			NewCell= H1->Left;
			H1->Left = H1->Right;
			H1->Right = NewCell;
		}
		H1->Npl = H1->Right->Npl + 1;
	}
	return H1;
}
PrioityQueue Merge(PrioityQueue H1, PrioityQueue H2)
{
	if (H1 == NULL)
		return H2;
	if (H2 == NULL)
		return H1;
	if (H1->a < H2->a)
		return Merge1(H1, H2);
	else
		return Merge1(H2, H1);
}
PrioityQueue Insert1(int X, PrioityQueue H)
{
	PrioityQueue SingleNode;
	SingleNode = (PrioityQueue)malloc(sizeof(struct TreeNode));
	if (SingleNode == NULL)
		printf("error");
	else
	{
		SingleNode->a = X;
		SingleNode->Npl = 0;
		SingleNode->Left = SingleNode->Right = NULL;
		H = Merge(SingleNode, H);
	}
	return H;
}
PrioityQueue DeleteMin1(PrioityQueue H)
{
	PrioityQueue LeftHeap, RightHeap;
	LeftHeap = H->Left;
	RightHeap = H->Right;
	free(H);
	return Merge(LeftHeap, RightHeap);
}
int FindMin(PrioityQueue H)
{
	return H->a;
}
int main()
{
	PrioityQueue T1 =Initialize(2);
	int i;
	Insert1(3, T1);
	Insert1(6, T1);
	Insert1(4, T1);
	Insert1(10,T1);
	Insert1(23, T1);
	int a = FindMin(T1);
	printf("最小值%d\n", a);
	PrioityQueue H1 = DeleteMin1(T1);
	int b = FindMin(H1);
	printf("删除后的最小值%d\n", b);
	PrioityQueue H2 = Initialize(1);
	Insert1(5, H2);
	Insert1(7, H2);
	Insert1(11, H2);
	PrioityQueue H = Merge1(H2, H1);
	printf("合并后的最小值%d\n", FindMin(H));
	return 0;
}
