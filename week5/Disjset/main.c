#include<stdio.h>
#include"DisjSet.h"
void Initialize(DisjSet S)
{
	int i;
	for (i = 0; i < 100; i++)
		S[i] = 0;
}
void SetUnion(DisjSet S, SetType Root1, SetType Root2)
{
	if (S[Root1] < S[Root2])
		S[Root1] = Root2;
	else
	{
		if (S[Root1] == S[Root2])
			S[Root1]--;
		S[Root2] = S[Root1];
	}
}
SetType Find(int X, DisjSet S)
{
	if (S[X] <= 0)
		return X;
	else
		return Find(S[X], S);
}
int main()
{
	int i;
	int S[100];
	for (i = 0; i < 10; i++)
		S[i] = i + 1;
	SetUnion(S, 5,4);
	SetUnion(S, 5, 6);
	SetUnion(S, 5, 7);
	SetUnion(S, 7, 8);
	printf("输出求并数列\n");
	for (i = 0; i < 10; i++)
		printf("%d\t", S[i]);
	int b=Find(4, S);
	printf("%d", b);
	return 0;
}
