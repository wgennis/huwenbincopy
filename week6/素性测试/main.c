#include<stdio.h>
static int Seed = 1;
#define A 48271L
#define M 2147483647L
#define Q (M/A)
#define R (M%A)
int Pow(int X, int N)
{
	if (N == 0)
		return 1;
	if (N == 1)
		return X;
	if (N % 2 == 0)
		return Pow(X * X, N / 2);
	else
		return Pow(X * X, N / 2) * X;
}
int Rand()
{
	int TmpSeed;
	TmpSeed = A * (Seed % Q) - R * (Seed / Q);
	if (TmpSeed >= 0)
		Seed = TmpSeed;
	else
		Seed = TmpSeed + M;
		return Seed/M;
}
int RandInt(int Left, int Right)
{
	int X = Rand();
	if (X >= Left && X <= Right)
		return X;
}
int Witness(int a, int i, int N)
{
	int X = Pow(a, i);
	if (N%X == 1)
		return 1;
	else
		return 0;
}
int IsPrime(int N)
{
	return Witness(RandInt(2, N - 2), N - 1, N);
}
int main()
{
	int N;
	scanf_s("%d", &N);
	if (IsPrime(N) ==1)
		printf("是素数");
	else
		printf("不是素数");
	return 0;
}
