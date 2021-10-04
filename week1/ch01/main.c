#include<stdio.h>
#include<stdlib.h>
typedef struct Node* Position;
struct Node
{
	int Data;
	Position Next;
};
Position printlist();
{
	int N;
	Position* p1;
	Position* head;
	head = malloc(sizeof(struct Node));  //开拓一个动态分配空间对表头进行储存
	p1 = malloc(sizeof(struct Node));
	head = p1;
	scanf_s("%d", &N);
	for (i = 0; i < N; i++)   //N的输入和for语句的应用是令指针p不断向下遍历，依次填充链表
	{
		Position p = malloc(sizeof(struct Node));
		p = p1->Next;
		scanf_s("%d", &(p->Data));  
		p - Next->NULL;   //当一个元素输入完成时，对指针p指向下一个元素时是空值
		p1 = p;
	}
	p1 = head->Next;
	while (p1 != NULL)   //与上一条呼应当指针指向空值时，停止输出
	{
		printf("%d", p1->Data);
		p1 = p1->Next;
	}
	return head;   //知道表头的地址就可以遍历出整个链表
}
int main()
{
	Position P = malloc(sizeof(struct Node));
	P = printlist();
	return 0;
}
