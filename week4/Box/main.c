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
int IsEmpty(PrioityQueue H)
{
	return H == NULL;
}
PrioityQueue Initialize(void)
{
	PrioityQueue H;
	H = (PrioityQueue)malloc(sizeof(struct TreeNode));
	if (H == NULL)
		printf("error");
	H->a = NULL;
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
	int b[100];
	int c;
	scanf_s("%d\n", &c);
	int n;
	scanf_s("%d\n", &n);
	int i;
	for (i = 0; i < n; i++)
		scanf_s("%d\t", &b[i]);
	PrioityQueue T = Initialize();
	PrioityQueue T_temp = Initialize();
	int box = 0;
	for (i = 0; i < n; i++)
	{
		int flag = 0;
		if (!IsEmpty(T))
		{
			int min = FindMin(T);
			T=DeleteMin(T);
			while (!IsEmpty(T) && min < b[i])
			{
				T_temp=Insert1(min, T_temp);
				min = FindMin(T);
				T=DeleteMin(T);
			}
			if (min >= b[i])
			{
				T=Insert1(min - b[i], T);
				flag = 1;
			}
			T = Merge(T, T_temp);
			T_temp = NULL;
		}
		if (!flag)
		{
			T=Insert1(c - b[i], T);
			box++;
		}
	}
	printf("%d", box);
}
