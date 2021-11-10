#ifndef _Splay_H
struct SplayNode;
typedef struct SplayNode* SplayTree;
SplayTree Initialize(void);
SplayTree Insert(int X, SplayTree T);
SplayTree Remove(int X, SplayTree T);
#endif;
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct SplayNode
{
	int X;
	SplayTree Left;
	SplayTree Right;
};
typedef struct SplyNode* Position;
static Position NullNode = NULL;
SplayTree splay(int Item, Position X)
{
	static struct SplayNode Header;
	Position LeftTreeMax, RightTreeMin;
	Header.Left = Header.Right = NullNode;
	LeftTreeMax = RightTreeMin = &Header;
	NullNode->X = Item;
	while (Item != X->X)
	{
		if (Item < X->X)
		{
			if (Item < X->Left->X)
				X = SingleRotateWinLeft(X);
			if (X->Left == NullNode)
				break;
			RightTreeMin->Left = X;
			RightTreeMin = X;
			X = X->Left;
		}
		else
		{
			if (Item > X->Right->X)
				X = SingleRotetateWithRight(X);
			if (X->Right == NullNode)
				break;
			LeftTreeMax->Right = X;
			LeftTreeMax = X;
			X = X->Left;
		}
	}
	LeftTreeMax->Right = X->Left;
	RightTreeMin->Left = X->Right;
	X->Left = Header.Right;
	X->Right = Header.Left;
	return X;
}
SplayTree Insert(int  Item, SplayTree T)
{
	static Position NewNode = NULL;
	if (NewNode == NULL)
	{
		NewNode = (Position)malloc(sizeof(struct SplayNode));
		if (NewNode == NULL)
			printf("error");
	}
	NewNode->X = Item;
	if (T == NullNode)
	{
		NewNode->Left = NewNode->Right = NullNode;
		T = NewNode;
	}
	else
	{
		T = Splay(Item, T);
		if (Item < T->X)
		{
			NewNode->Left = T->Left;
			NewNode->Right = T;
			T->Left = NullNode;
			T = NewNode;
		}
		else
			if (T->X < Item)
			{
				NewNode->Right = T->Right;
				NewNode->Left = T;
				T->Right = NullNode;
				T = NewNode;
			}
			else
				return T;
	}
	NewNode = NULL;
	return T;
}
SplayTree Remove(int Item, SplayTree T)
{
	Position NewTree
		if (T != NullNode)
		{
			T = Splay(Item, T);
			if (Item == T->X)
			{
				if (T->Left == NullNode)
					NewTree = T->Right;
				else
				{
					NewTree = T->Left;
					NewTree = Splay(Item, NewTree);
					NewTree->Right = T->Right;
				}
				free(T);
				T = NewTree;
			}
		}
	return T;
}
