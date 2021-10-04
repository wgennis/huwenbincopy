#include<stdio.h>
#include<stdlib.h>
#define EmptyTOS(-1);
struct StackRecord;
typedef struct StackRecord* Stack;
struct StackRecord
{
	int Capacity;
	int TopOfStack;
	int a[10];       //后缀算法中在没有括号时，只有数字会被压入，所以用int
};
void Push(int x, Stack S) //书包上原本的算法程序
{
	S->a[++S->TopOfStack] = x;
}
int TopAndPop(Stack S)
{
	if (!IsEmpty(S))
		return S->a[S->TopOfStack--];
	else
		printf("Empty stack");
}
int IsEmpty(Stack S)
{
	return S->TopOfStack == EmptyTOS;
}
int main()
{
	Stack S;
	char a[10];
	int i, x;
	for (i = 0; i < 10; i++)  
		scanf_s("%s", % a[i]);
	int a, b;
	while (--S->TopOfStack != NULL&&S->TOpOfStack!=)    //只有只剩栈顶元素时才能退出循环
	{
		for (i = 0; i < 10; i++)
		{
			if (a[i] >= '0' && a[i] <= '9')     //当a[i]在0~9之间才能压入栈中
				Push(a[i], S);
			if (a[i] == '+')                   //当a[i]=+时连续弹出两个栈顶元素，加法计算后再压入栈中
      {
				a = TopAndPop(S);
				b = TopAndPop(S);
				Push(a + b, S);
			}
			if (a[i] == '*')           //同理乘法也和加法一样
			{
				a = TopAndPop(S);
				b = TopAndPop(s);
				Push(a * b, S);
			}
		}
	}
	x = S->a[S->TopOfStack];      //最后输入栈中仅剩的栈顶元素
	printf("%d", x);
	return 0;
}
