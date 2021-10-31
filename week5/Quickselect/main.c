#include<stdio.h>
void swap(int* a, int* b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
int Median3(int A[], int Left, int Right)
{
	int Center = (Left + Right) / 2;
	if (A[Left] > A[Center])
		swap(&A[Left], &A[Center]);
	if (A[Left] > A[Right])
		swap(&A[Left], &A[Right]);
	if (A[Center] > A[Right])
		swap(&A[Center], &A[Right]);
	swap(&A[Center], &A[Right - 1]);
	return A[Right - 1];
}
void Insertionsort(int A[], int N)
{
	int j, p;
	int Tmp;
	for (p = 1; p < N; p++)
	{
		Tmp = A[p];
		for (j = p; j > 0 && A[j-1] > Tmp; j--)
			A[j] = A[j - 1];
		A[j] = Tmp;
	}
}
void Qselect(int A[], int k, int Left, int Right)
{
	int i, j;
	int Privot;
	if (Left + 3 <= Right)
	{
		Privot = Median3(A, Left, Right);
		i = Left;
		j = Right - 1;
		for (;;)
		{
			while (A[++i] < Privot) {}
			while (A[--j] > Privot) {}
			if (i < j)
				swap(&A[i], &A[j]);
			else
				break;
		}
		swap(&A[i], &A[Right - 1]);
		if (k <= i)
			Qselect(A, k, Left, i - 1);
		else if (k > i + 1)
			Qselect(A, k, i, Right);
	}
	else
		Insertionsort(A + Left, Right - Left + 1);
}
void Quickselect(int A[], int k,int N)
{
	Qselect(A, k, 0, N - 1);
}
int main()
{
	int i, k;
	int A[9];
	printf("输入数组");
	for (i = 0; i < 9; i++)
		scanf_s("%d", &A[i]);
	printf("输入求第k个最小元:\n");
	scanf_s("%d", &k);
	Quickselect(A, k, 9);
	printf("输出%d\t", A[k-1]);
	return 0;
}
