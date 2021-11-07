#include<stdio.h>
void OptMatrix(int C[], int N, int M[][5], int LastChange[][5]) //建立一个表记录最小的乘法顺序
{
	int i, k, Left, Right;
	long ThisM;
	for (Left = 1; Left <= N; Left++) //因为矩阵不能和自己相乘，所以将对角线元素都取0
		M[Left][Left] = 0;
	for(k=1;k<N;k++)
		for (Left = 1; Left <= N - k; Left++)  //关键性步骤，这个双重for循环是为了遍历12，13，23等上半角矩阵，因为矩阵相乘不符合交换律故下半角为0
		{
			Right = Left + k;
			M[Left][Right] = 1000000;  //先将上半角矩阵都取一个绝对的值，为了下面的取最小值操作
			for (i = Left; i < Right; i++)
			{
				ThisM = M[Left][i] + M[i + 1][Right] + C[Left - 1] * C[i] * C[Right];	//最关键步骤即12是A1*A2，23是A2*A3等，13是(A1*A2)*A3或者A1*(A2*A3)等将乘法顺序都罗列了出来
				if (ThisM < M[Left][Right])
				{
					M[Left][Right] = ThisM; //取最小值操作当矩阵中有两个或以上的值时，会取到最小的那一个
					LastChange[Left][Right] = i; //是记录用的矩阵将取最小值的选择记录下来
				}
			}
		}
}
int main()
{
	int C[5];  //Ci是Ai的列数，C0是A1的行数，由矩阵乘法的定义而来
	int i, j;
	for (i = 0; i < 5; i++)
		scanf_s("%d", &C[i]);
	int A[5][5];
	int B[5][5];
	OptMatrix(C, 4, A, B);
	printf("%d\n", A[1][4]); //由左向右，由下到上的不断选择，故最小值在第一行的最后一列取到
	printf("输出顺序\t");
	for(i=3;i>0;i--)
	printf("%d\t", B[i][4]); //输出选择的顺序
}
