#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include"HashSep.h"
struct ListNode
{
	int X;
	Position Next;
};
typedef Position List;
struct HashTbl
{
	int TableSize;
	List* TheLists;
};
typedef int Index;
Index Hash(int Key, int TableSize)
{
	return Key%TableSize;
}
static int Nextprime(int N)
{
	int i;
	if (N % 2 == 0)
		++N;
	for (;; N +=2)
	{
		for (i = 3; i * i <= N; i+=2)
			if (N % i == 0)
				goto ContOuter;
		return N;
	ContOuter:;
	}
}
HashTable InitializeTable(int TableSize)
{
	HashTable H;
	int i;
	H = (HashTable)malloc(sizeof(struct HashTbl));
	if (H == NULL)
		printf("error");
	H->TableSize = Nextprime(TableSize);
	H->TheLists = (List*)malloc(sizeof(List) * H->TableSize);
	if (H->TheLists == NULL)
		printf("error");
	for (i = 0; i < H->TableSize; i++)
	{
		H->TheLists[i] = (List)malloc(sizeof(struct ListNode));
		if (H->TheLists[i] == NULL)
			printf("error");
		else
			H->TheLists[i]->Next = NULL;
	}
	return H;
}
Position Find(int Key, HashTable H)
{
	Position P;
	List L;
	L = H->TheLists[Hash(Key, H->TableSize)];
	P = L->Next;
	while (P != NULL && P->X != Key)
		P = P->Next;
	return P;
}
void Insert(int Key, HashTable H)
{
	Position Pos, NewCell;
	List L;
	Pos = Find(Key, H);
	if (Pos == NULL)
	{
		NewCell = (Position)malloc(sizeof(struct ListNode));
		if (NewCell == NULL)
			printf("error");
		else
		{
			L = H->TheLists[Hash(Key, H->TableSize)];
			NewCell->Next = L->Next;
			NewCell->X = Key;
			L->Next = NewCell;
		}
	}
}
int main()
{
	printf("测试散列表");
	HashTable T = InitializeTable(13);
	printf("散列表大小%d\n", T->TableSize);
	int i;
	Insert(17, T);
	Insert(2, T);
	Insert(12, T);
	for (i = 0; i < 13; i++)
		printf("%d\n",T->TheLists[i]->X);
	return 0;
}
