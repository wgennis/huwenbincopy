#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<math.h>
#include"DistSet.h"
#define True 1
#define False 0
int Check(double X[], double DMax, DistSet D, int Left, int Right, int N, int Mark)
{
	int Flag = True;
	int i, j;
	Position P;
	Judge(D);
	if (Mark == 0)
	{
		for (i = 1, j = Right + 1; i < Left || j < N; i++, j++)
		{
			if (i < Left)
			{
				if (!(P = Find(fabs(X[i] - DMax), D)))
				{
					Flag = False;
					break;
				}
				else
					P->judge++;
			}
			if (j <= N)
			{
				if (!(P = Find(fabs(X[j] - DMax), D)))
				{
					Flag = False;
					break;
				}
				else
					P->judge++;
			}
			Flag = Compare_Judge_Count(D);
			if (Flag == False)
				break;
		}
	}
	if(Mark==1)
	{
		for (i = 1, j = Right + 1; i < Left || j <= N; i++, j++)
		{
			if (i < Left)
			{
				if (!(P = Find(fabs(X[N] - X[i] - DMax), D)))
				{
					Flag = False;
					break;
				}
				else
					P->judge++;
			}
			if (j <= N)
			{
				if (!(P = Find(fabs(X[N] - X[j] - DMax), D)))
				{
					Flag = False;
					break;
				}
				else
					P->judge++;
			}
			Flag = Compare_Judge_Count(D);
			if (Flag == False)
				break;
		}
	}
	return Flag;
}
int Place(double X[], DistSet D, int N, int Left, int Right)
{
	double DMax;
	int Found = False;
	int i, j;
	if (D == NULL || Left > Right)
		return True;
	DMax = FindMax(D)->X;
	if (Check(X, DMax, D, Left, Right, N, 0))
	{
		X[Right] = DMax;
		for (i = 1, j = Right + 1; i < Left || j <= N; i++, j++)
		{
			if (i < Left)
				Delete(fabs(X[i] - DMax), D);
			if (j <= N)
				Delete(fabs(X[j] - DMax), D);
		}
	}
	Found = Place(X, D, N, Left, Right - 1);
	if (!Found)
	{
		for (i = 1, j = Right + 1; i < Left || j <= N; i++, j++)
		{
			if (i < Left)
				Insert(fabs(X[i] - DMax), D);
			if (j <= N)
				Insert(fabs(X[j] - DMax), D);
		}
	}
	if (!Found && Check(X, DMax, D, Left, Right, N, 1))
	{
		X[Left] = X[N] - DMax;
		for (i = 1, j = Right + 1; i < Left || j <= N; i++, j++)
		{
			if (i < Left)
				Delete(fabs(X[N] - X[i] - DMax), D);
			if (j <= N)
				Delete(fabs(X[N] - X[j] - DMax), D);
		}
		Found = Place(X, D, N, Left + 1, Right);
		if (!Found)
		{
			for (i = 1, j = Right + 1; i < Left || j <= N; i++, j++)
			{
				if (i < Left)
					Insert(fabs(X[N] - X[i] - DMax), D);
				if (j <= N)
					Insert(fabs(X[N] - X[j] - DMax), D);
			}
		}
	}
	return Found;
}
int Turnpike(double X[], DistSet D, int N)
{
	X[1] = 0;
	X[N] = FindMax(D)->X;
	Delete(X[N], D);
	X[N - 1] = FindMax(D)->X;
	Delete(X[N - 1], D);
	if (Find(X[N] - X[N - 1], D))
	{
		Delete((X[N] - X[N - 1]), D);
		return Place(X, D, N, 2, N - 2);
	}
	else
		return False;
}
int main()
{
	int d[15] = { 3,3,3,8,6,4,5,5,5,2,2,2,1,7,10 };
	double X[7];
	DistSet D =NULL;
	D = MakeEmpty(D);
	int i;
	for (i = 0; i < 15; i++)
		Insert(d[i], D);
	if (Turnpike(X, D, 6))
	{
		for (i = 1; i <= 6; i++)
			printf("%f", X[i]);
		return 0;
	}
	else
		return 1;
}
