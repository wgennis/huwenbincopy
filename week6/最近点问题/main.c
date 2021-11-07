#include<stdio.h>
#include<math.h>
struct Point   //定义点的对象
{
	int x;
	int y;
};
void swap(int* a, int* b)   //快速排序的例程在最近点例程中要用到
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
void Insertsort(int A[], int N)
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
void Qsort(int A[], int Left, int Right)
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
		Qsort(A, Left, i - 1);
		Qsort(A, i + 1, Right);
	}
	else
		Insertsort(A + Left, Right - Left + 1);
}
void Quitesort(int A[], int N)
{
	Qsort(A, 0, N - 1);
}
double Distance(Point X1,Point X2 )   //点的距离公式
{
	return sqrt((X1.x - X2.x) * (X1.x - X2.x) + (X1.y - X2.y) * (X1.y - X2.y));
}
double Closest(Point S[], int Left, int Right)
{
	double d1, d2, d3, d;
	int mid, i, j;
	Point P[10];
	Quitesort(&S->x, 10);   //先对点的横坐标进行排序
	if (Right - Left == 1)    //当点只有两个或者三个的时候结束递归
		return Distance(S[Left], S[Right]);
	if (Right - Left == 2)
	{
		d1 = Distance(S[Left], S[Left + 1]);
		d2 = Distance(S[Left + 1], S[Right]);
		d3 = Distance(S[Left], S[Right]);
		if ((d1 < d2) && (d1 < d3))
			return d1;
		else if (d2 < d3)
			return d2;
		else
			return d3;
	}
	mid = (Left + Right) / 2;   //分割线是横坐标的中点，可以保证分割线左右的点个数最多只差一个
	d1 = Closest(S, Left, mid); //分治算法的精髓对函数进行递归不断分点，直到可以简单的算出点的距离，解决点的连线与分割线无交点的问题
	d2 = Closest(S, mid + 1, Right);
	if (d1 < d2)  //d是两边距离的最小值
		d = d1;
	else
		d = d2;
	int Index = 0;    //当点的距离横跨分割线时
	for (i = mid; (i >= Left) && (S[mid].x - S[i].x < d); i--)   //当点的横坐标减中线的横坐标小于d时，将点记录进新的点集中
		P[Index++] = S[i];      //在中线左边
	for (i = mid + 1; (i <= Right) && (S[i].x - S[mid].x < d); i++)   //在中线右边
		P[Index++] = S[i];
	Quitesort(&P->y, Index);  //对P中的y坐标再进行排序
	for (i = 0; i < Index; i++)
		for (j = i + 1; j < Index; j++)  //双重for循环对左右分割线内的点进行二次分割即将点的纵坐标相减的值与d进行比较，小于的时就算出距离d3
		{
			if (P[j].y - P[i].y >= d)
				break;
			else
			{
				d3 = Distance(P[i], P[j]);
				if (d3 < d)    //当d3小于d即最近点在P点集中取到
					d = d3;
			}
		}
	return d;
}

int main()
{
	Point S[8] = { {1,4},{2,1},{7,2},{6,6},{1,8},{3,2},{5,1},{4,4}};
	double d = Closest(S, 0, 7);
	printf("%f", d);
	return 0;
}
