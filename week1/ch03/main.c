List And(List L1, List L2)
{
	Position p1 = Advance(L1);   //含义是跳过表头，指针直接指向链表的第一个元素
	Position p2 = Advance(L2);
	int i, j, num1, num2;
	num1 = List_len(L1);  //含义是计算链表长度，避免for语句空间浪费
	num2 = List_len(L2);
	while (p1 != NULL && p2 != NULL)
	{
		for (i = 0; i < num1; i++)
		{
			p1 = Advance(p1);          //使指针不断向下一位置跳动，起到遍历的作用
			for (j = 0; j < num2; j++)
				p2 = Advance(p2);
			if (Retrieve(p1) != Retrieve(p2))  //当p1所指的值和p2所指的值相等时，在L1中删除p1指针当时所指的值 即可达到求L1∩L2的效果
				Delete(Retrieve(p1), L1);
		}
		return L1;
	}
}
int List_len(List L)
{
	Position p = Advance(L);
	int num = 0;
	while (p != NULL)
	{
		num++;        //刚开始num为0 在不断遍历中递增，当p指针指到空时，便由num当时的值知晓链表长度
		p = Advance(p);
	}
	return num;
}
