#ifndef _Tree_H
struct TreeNode;
typedef struct TreeNode* Position;
typedef struct TreeNode* DistSet;
DistSet MakeEmpty(DistSet T);
Position Find(double X, DistSet T);
Position FindMax(DistSet T);
Position FindMin(DistSet T);
DistSet Insert(double X, DistSet T);
DistSet Delete(double X, DistSet T);
double DeleteMax(DistSet T);
void PrintTree(DistSet T);
void Judge(DistSet T);
int Compare_Judge_Count(DistSet T);
#endif
#include<stdio.h>
#include<malloc.h>
#include<stdilb.h>
#define True 1
#define False 0
struct TreeNode
{
	double X;
	DistSet Left;
	DistSet Right;
	int count;
	int judge;
};
Position Find(double X, DistSet T)
{
	if (T == NULL)
		return NULL;
	if (X < T->X)
		return Find(X, T->Left);
	else if (X > T->X)
		return Find(X, T->Right);
	else
		return T;
}
DistSet MakeEmpty(DistSet T)
{
	if (T != NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}
Position FindMin(DistSet T)
{
	if (T == NULL)
		return NULL;
	else if (T->Left == NULL)
		return T;
	else
		return FindMin(T->Left);
}
Position FindMax(DistSet T)
{
	if (T != NULL)
		while (T->Right != NULL)
			T = T->Right;
	return T;
}
DistSet Insert(double X, DistSet T)
{
	if (T == NULL)
	{
		T = (DistSet)malloc(sizeof(struct TreeNode));
		if (T == NULL)
			printf("error");
		else
		{
			T->X = X;
			T->Left = T->Right = NULL;
			T->count = 1;
		}
	}
	else if (X < T->X)
		T->Left = Insert(X, T->Left);
	else if (X > T->X)
		T->Right = Insert(X, T->Right);
	else
		T->count++;
	return T;
}
DistSet Delete(double X,DistSet T)
{
	Position TmpCell;
	if (T == NULL)
		printf("error");
	else if (X < T->X)
		T->Left = Delete(X, T->Left);
	else if (X > T->X)
		T->Right = Delete(X, T->Right);
	else if (T->Left && T->Right)
	{
		if (T->count == 1)
		{
			TmpCell = FindMin(T->Right);
			T->X = TmpCell->X;
			T->count = TmpCell->count;
			TmpCell->count = 1;
			T->Right = Delete(T->X, T->Right);
		}
		else
			T->count--;
	}
	else
	{
		if (T->count == 1)
		{
			TmpCell = T;
			if (T->Left == NULL)
				T = T->Right;
			else if (T->Right == NULL)
				T = T->Left;
			free(TmpCell);
		}
		else
			T->count--;
	}
	return T;
}
void PrintTree(DistSet T)
{
	if (T != NULL)
	{
		PrintTree(T->Left);
		printf("Node number:%f,count number:%d,judge number:%d\n", T->X, T->count, T->judge);
		PrintTree(T->Right);
	}
}
double DeleteMax(DistSet T)
{
	Position Tmp_Position;
	double Tmp_Mem;
	if (T == NULL)
		printf("erroe");
	Tmp_Position = FindMax(T);
	Tmp_Mem = Tmp_Position->X;
	Delete(Tmp_Mem, T);
	return Tmp_Mem;
}
void Judge(DistSet T)
{
	if (T != NULL)
	{
		Judge(T->Left);
		T->judge = 0;
		Judge(T->Right);
	}
}
int Compare_Judge_Count(DistSet T)
{
	Position A[15];
	Position P;
	int front, rear;
	int Flag = True;
	front = rear = -1;
	A[++rear] = T;
	while (front != rear)
	{
		front = (front + 1) % 15;
		P = A[front];
		if (P->count < P->judge)
		{
			Flag = False;
			break;
		}
		if (P->Left != NULL)
		{
			rear = (rear + 1) % 15;
			A[rear] = P->Left;
		}
		if (P->Right != NULL)
		{
			rear = (rear + 1) % 15;
			A[rear] = P->Right;
		}
	}
	return Flag;
}
