#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include"HashSep.h"
struct ListNode
{
	int Coefficient;       //定义系数和幂
	int Exponent;
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
	return Key % TableSize;   //散列函数可以将幂数一样的方程式归到同一个散列单元中
}
static int Nextprime(int N)  //寻找比N大的最近一个素数
{
	int i;
	if (N % 2 == 0)
		++N;
	for (;; N += 2)    
 	{
		for (i = 3; i * i <= N; i += 2)
			if (N % i == 0)
				goto ContOuter;
		return N;
	ContOuter:;
	}
}
HashTable InitializeTable(int TableSize) //初始化散列与前程序无异
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
Position Find(int Key, HashTable H) //注意此时要查找的Key一定是幂数，因为在插入函数中会对方程进行检查，有相同幂存在就不进行插入操作
{
	Position P;
	List L;
	L = H->TheLists[Hash(Key, H->TableSize)];
	P = L->Next;
	while (P != NULL && P->Exponent != Key)
		P = P->Next;
	return P;
}
void Insert(int Key1,int Key2, HashTable H)   //插入函数作了些许改变，增加了一个未知数
{
	Position Pos, NewCell;
	List L;
	Pos = Find(Key2, H);
	if (Pos == NULL)
	{
		NewCell = (Position)malloc(sizeof(struct ListNode));
		if (NewCell == NULL)
			printf("error");
		else
		{
			L = H->TheLists[Hash(Key2, H->TableSize)];
			NewCell->Next = L->Next;
			NewCell->Coefficient = Key1;
			NewCell->Exponent = Key2;
			L->Next = NewCell;
		}
	}
}
HashTable MultPolynomial(HashTable H, HashTable T)
{
	int a[100], b[100];
	HashTable Z = InitializeTable(121); //乘积的操作是M*N次以防大小不足
	int i, j, k;
	for (i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
			for (k = 0; k < 100; k++) //for语句嵌套循环将系数相乘，幂相加存于a[],b[]数列
			{
				a[k] = H->TheLists[i]->Coefficient * T->TheLists[j]->Coefficient;
				b[k] = H->TheLists[i]->Exponent + T->TheLists[j]->Exponent;
			}
	for (k = 0; k < 100; k++)  //最后再插入Z中
		Insert(a[k], b[k], Z);
	return Z;
}
int main()
{
	HashTable H=InitializeTable(10); //初始化
	HashTable T = InitializeTable(10);
	HashTable Z = InitializeTable(121);
	int i;
	for (i = 1; i < 10; i++)  //输入方程
	{
		Insert(i + 1, i, H);
		Insert(i + 2, i, T);
}
	Z = MultPolynomial(H, T); //乘积运算
	for (i = 0; i < 100; i++)  //输出
		printf("%d\t%d\n", Z->TheLists[i]->Coefficient, Z->TheLists[i]->Exponent);
	return 0;
	}
