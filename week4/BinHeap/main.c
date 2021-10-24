#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include"BinHeap.h"
struct HeapStruct
{
	int Capacity; //最大值
	int Size; //当前堆的大小
	int a[100]; //一个数组
};
PriorityQueue Initialize(int Max)
{
	PriorityQueue H;
	if (Max == 0)  //最大值是0时报错
		printf("error");
	H = (PriorityQueue)malloc(sizeof(struct HeapStruct)); //动态分配节点
	if (H == NULL)  //H为空时报错
		printf("error");
	H->Capacity = Max; //初始化数据
	H->Size = 0;
	H->a[0] = 0;
	return H;
}
void Insert(int X, PriorityQueue H)
{
	int i;
	for (i = ++H->Size; H->a[i / 2] > X; i /= 2)  //上滤法，先将i赋予当前位置多一；当a[i/2]>x,i=i/2,一直向上交换元素，直到a[i/2]<x停止
		H->a[i] = H->a[i / 2];
	H->a[i] = X;
}
int DeleteMin(PriorityQueue H)
{
	int i, Child;
	int MinElement, LastElement;
	MinElement = H->a[1];    //最小元一定是a[1]
	LastElement = H->a[H->Size--];  //由于删除了a[1]，所以最后一个元素的位置要减一
	for (i = 1; i * 2 <= H->Size; i = Child)   //下滤法，将i=1，当2*i不超过当前位置时，i=i*2,向下替换元素，
	{
		Child = i * 2;
		if (Child != H->Size && H->a[Child + 1] < H->a[Child])//2*i不等于当前位置且右儿子小于左儿子时，Child++
			Child++;
		if (LastElement > H->a[Child]) //当最后一个元素大于左儿子的元素
			H->a[i] = H->a[Child]; //将儿子上移动
		else
			break;
	}
	H->a[i] = LastElement; //i的值一定接近于当前位置的一半，此时完成最后一步赋值
	return MinElement;
}
int main()
{
	PriorityQueue T = Initialize(10);
	int i;
	for (i = 1; i < 10; i++)
		Insert(i, T);
	int n = DeleteMin(T);
	printf("输出最小元%d\n", n);
	for (i = 1; i < 9; i++)
		printf("输出二叉堆%d\n", T->a[i]);
	int b = 0;
	PriorityQueue H = Initialize(20);
	int c;
	for (i = 1; i < 15; i++)
	{
		Insert(i, H);
	}
	int m;
	printf("请输入m值：\n");
	scanf_s("m=%d", &m);
	while (b != 15 - m)
	{
		c = DeleteMin(H);
		b++;
	}
	printf("%d",c);
	return 0;
}
