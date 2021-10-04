#include<list>
#include<stdio.h>
void PrintLots(List L, List p)
{
	Position q;
	Position s;
	q = Advance(L); //使指针跳过表头直接指向链表第一个元素
	s = Advance(q);
	while (q != NULL && s != NULL)
	{
		int i;
		int sum = Retrieve(s); //用sum来记住指针s所指的链表q的值
		for (i = 0; i < sum; i++)//这步是程序的核心步骤：当i遍历sum次时指针q也从指向L的第一个值跳到第sum个值从而完美地实现了程序
		{
			q = Advance(q);
			printf("%d", Retrieve(q));
		}
		s = Advance(s);//这句是令s指向q的下一个值，从而改变下一个循环里的sum的值。
	}
}
int main()
{
	List L;
	List P;
	Position q = Advance(L);
	Position s = Advance(p);
	int i;
	for (i = 1; i <= 10; i + 2) //插入函数的应用可实现数组的输入
	{
		Insert(i, P, s);
		s = Advance(s);
	}
	for (i = 1; i <= 10; i++)
	{
		Insert(i, L, q);
		q = Advance(q);
	}
	PrintList(L, P);
	return 0;
}
