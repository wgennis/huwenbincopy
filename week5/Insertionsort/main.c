#include<stdio.h>
int main()
{
	void InsertionSort(int A[], int N);
	int A[10];
	int i;
	for (i = 0; i < 9; i++)
		scanf_s("%d", &A[i]);
	InsertionSort(&A[0],9);
	printf("输出排好序的数列");
	for (i = 0; i < 9; i++)
		printf(" % d\t", A[i]);
	return 0;
}
void InsertionSort(int A[], int N)
{
	int j, p;
	int Tmp;
	for (p = 1; p < N; p++)
	{
		Tmp = A[p];
		for (j = p; j > 0 && A[j - 1] > Tmp; j--)
			A[j] = A[j - 1];
		A[j] = Tmp;
	}
}
