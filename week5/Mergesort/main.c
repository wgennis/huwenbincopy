#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
void Merge(int A[], int Tmp[], int Lpos, int Rpos, int RightEnd)
{
	int i, LeftEnd, Num, TmpPos;
	LeftEnd = Rpos - 1;
	TmpPos = Lpos;
	Num = RightEnd - Lpos + 1;
	while (Lpos <= LeftEnd && Rpos <= RightEnd)
		if (A[Lpos] <= A[Rpos])
			Tmp[TmpPos++] = A[Lpos++];
		else
			Tmp[TmpPos++] = A[Rpos++];
	while (Lpos <= LeftEnd)
		Tmp[TmpPos++] = A[Lpos++];
	while (Rpos <= RightEnd)
		Tmp[TmpPos++] = A[Rpos++];
	for (i = 0; i < Num; i++, RightEnd--)
		A[RightEnd] = Tmp[RightEnd];
}
void MSort(int A[], int Tmp[], int Left, int Right)
{
	int Center;
	if (Left < Right)
	{
		Center = (Left + Right) / 2;
		MSort(A, Tmp, Left, Center);
		MSort(A, Tmp, Center + 1, Right);
		Merge(A, Tmp, Left, Center + 1, Right);
	}
}
void Mergesort(int A[], int N)
{
	int* Tmp;
	Tmp = (int *)malloc(N * sizeof(int));
	if (Tmp != NULL)
	{
		MSort(A, Tmp, 0, N - 1);
		free(Tmp);
	}
}
int main()
{
	int i, N;
	int A[8];
	printf("输入数的个数\n");
	scanf_s("%d", &N);
	for (i = 0; i < N; i++)
		scanf_s("%d\t", &A[i]);
	Mergesort(A, N);
	printf("输出排好序的数列");
	for (i = 0; i < N; i++)
		printf("%d\t", A[i]);
	return 0;
}
