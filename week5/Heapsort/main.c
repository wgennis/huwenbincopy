#include<stdio.h>
#define LeftChild(i)(2*(i)+1)
void PerDown(int A[], int i, int N)
{
	int Child;
	int Tmp;
	for (Tmp = A[i]; LeftChild(i) < N; i = Child)
	{
		Child = LeftChild(i);
		if (Child != N - 1 && A[Child + 1] > A[Child])
			Child++;
		if (Tmp < A[Child])
			A[i] = A[Child];
		else
			break;
	}
	A[i] = Tmp;
}
static void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void Heapsort(int A[], int N)
{
	int i;
	for (i = N / 2; i >= 0; i--)
		PerDown(A, i, N);
	for (i = N - 1; i > 0; i--)
	{
		swap(&A[0], &A[i - 1]);
		PerDown(A, 0, i);
	}
}
int main()
{
	void PercDown(int A[], int i, int N);
	void Heapsort(int A[], int N);
	int i;
	int A[7];
	for (i = 0; i < 7; i++)
		scanf_s("%d", &A[i]);
	Heapsort(A, 7);
	printf("输出排好序的堆");
	for (i = 0; i < 7; i++)
		printf("%d\t", &A[i]);
	return 0;
}
