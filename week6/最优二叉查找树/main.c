#include<stdio.h>
void OpiFind(double C[], int N, double M[][8], double LastChange[][8])
{
	int i, k, Left, Right;
	double ThisM;
	for (Left = 1; Left <= N; Left++)
		M[Left][Left] = C[Left - 1];
	for (k = 1; k < N; k++)
		for (Left = 1; Left <= N - k; Left++)
		{
			Right = Left + k;
			M[Left][Right] = 10000;
			for (i = Left; i <= Right; i++)
			{
				double sum = 0;
				sum = sum + C[i];
				ThisM = M[Left][i - 1] + M[i + 1][Right] + sum;
				if (ThisM < M[Left][Right])
				{
					M[Left][Right] = ThisM;
					LastChange[Left][Right] = i;
				}
			}
		}
}
int main()
{
	double C[7];
	int i;
	for (i = 1; i < 7; i++)
		scanf_s("%f", &C[i]);
	double A[8][8];
	double B[8][8];
	OpiFind(C, 7, A, B);
	printf("输出最小代价");
	printf("%f\t", A[1][7]);
}
