#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(struct TreeNode)
#ifndef _Tree_H
struct TreeNode;
typedef struct TreeNode* Position;
typedef struct TreeNode* SearchTree;
SearchTree MakeEmpty(SearchTree T);
Position Find(int X, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(int X, SearchTree T);
SearchTree Delete(int X, SearchTree T);
#endif
struct TreeNode
{
	int Data;
	SearchTree Left;
	SearchTree Right;
};
SearchTree MakeEmpty(SearchTree T)
{
	if (T != NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}
Position Find(int X, SearchTree T)
{
	if (T == NULL)
		return NULL;
	if (X < T->Data)
		return Find(X, T->Left);
	if (X > T->Data)
		return Find(X, T->Right);
	else
		return T;
}
Position FindMin(SearchTree T)
{
	if (T == NULL)
		return NULL;
	else
		if (T->Left == NULL)
			return T;
		else
			return FindMin(T->Left);
}
Position FindMax(SearchTree T)
{
	if (T == NULL)
		return NULL;
	else
		if (T->Right == NULL)
			return T;
		else
			return FindMax(T->Right);
}
SearchTree Insert(int X, SearchTree T)
{
	if (T == NULL)
	{
		T = (struct TreeNode*)malloc(LEN);
		if (T == NULL)
			printf("wrong");
		else
		{
			T->Data = X;
			T->Left = T->Right = NULL;
		}
	}
	else
		if (X < T->Data)
			T->Left = Insert(X, T->Left);
		else
			if (X > T->Data)
				T->Right = Insert(X, T->Right);
	return T;
}
SearchTree Delete(int X, SearchTree T)
{
	Position Tmpell;
	if (T == NULL)
		printf("Not Found");
	else
		if (X < T->Data)
			T->Left = Delete(X, T->Left);
		else
			if (X > T->Data)
				T->Right = Delete(X, T->Left);
			else
				if (T->Left && T->Right)
				{
					Tmpell = FindMin(T->Right);
					T->Data = Tmpell->Data;
					T->Right = Delete(T->Data, T->Right);
				}
				else
				{
					Tmpell = T;
					if (T->Left == NULL)
					T = T->Right;
					else
						if (T->Right == NULL)
							T = T->Left;
					free(Tmpell);
				}
	return T;
}
