#include<stdio.h>
int main()
{
	void Shellsort(int A[], int N);
	int i;
	int A[9];
	for (i = 0; i < 9; i++)
		scanf_s("%d", &A[i]);
	Shellsort(&A[0], 9);
	printf("输出排好序的数列");
	for (i = 0; i < 9; i++)
		printf("%d\t", A[i]);
	return 0;
}
void Shellsort(int A[], int N)
{
	int i, j, Increment;
	int Tmp;
	for(Increment=7;Increment>0;Increment/=2)
		for (i = Increment; i < N; i++)
		{
			Tmp = A[i];
			for (j = i; j >= Increment; j -= Increment)
				if (Tmp < A[j - Increment])
					A[j] = A[j - Increment];
				else
					break;
			A[j] = Tmp;
		}
}
