#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include"HashQuad.h"
enum KindOfEntry{Legitimate,Empty,Deleted};     //声明枚举类型即散列单元的状态（合法，空，已删除）
struct HashEntry
{
	int X;
	enum KindOfEntry Info;   //定义一个枚举型变量对散列单元的状态进行判断
};
typedef struct HashEntry Cell;
struct HashTbl
{
	int TableSize;
	Cell* ThCells;
};
int Hash(int Key, int TableSize)
{
	return Key % TableSize;        //散列函数即返回输入值除表大小的余数
}
static int NextPrime(int N)
{
	if (N % 2 == 0)
		++N;
	int i;
	for (;; N += 2)  //当N是偶数时加一再循环，N是奇数时直接循环，可以保证N+2一直都是奇数（除2以外 偶数一定不是奇数）
	{
		for (i = 3; i * i <= N; i += 2)
			if (N % i == 0)
				goto ContOuter;  //goto语句相当于break语句的效果，作用是退出循环，返回素数
		return N;
	ContOuter:;
	}
}
HashTable InitializeTable(int TableSize)
{
	HashTable H;
	int i;
	if (TableSize == 0)
		printf("error");
	H = (HashTable)malloc(sizeof(struct HashTbl));   //对散列表H开辟一个动态分配空间
	if (H == NULL)
		printf("error");
	H->TableSize = NextPrime(TableSize);
	H->ThCells = (Cell*)malloc(sizeof(Cell) * H->TableSize);  //对散列单元开辟一个动态分配空间来容纳插入的值
	if (H->ThCells == NULL)
		printf("error");
	for (i = 0; i < H->TableSize; i++)
		H->ThCells[i].Info = Empty;    //枚举变量的应用，对各个散列单元声明为空即开拓一个空的散列表
	return H;
}
Position Find(int Key, HashTable H)
{
	Position CurrentPos;
	int CollisionNum;
	CollisionNum = 0;
	CurrentPos = Hash(Key, H->TableSize);
	while (H->ThCells[CurrentPos].Info != Empty && H->ThCells[CurrentPos].X != Key)
	{
		CurrentPos =CurrentPos+ 2 * ++CollisionNum - 1;  //此行是平方探测法的实现即f(i)=f(i-1)+2i-1,此方法可以快速的遍历数组进行查找
		if (CurrentPos >= H->TableSize)          //将定位重新拉回到数组范围内进行查找
			CurrentPos = CurrentPos - H->TableSize;
	}
	return CurrentPos;
}
void Insert(int Key, HashTable H)
{
	Position Pos;
	Pos = Find(Key, H); //对元素进行查找如果存在就不进行操作
	if (H->ThCells[Pos].Info != Legitimate)   //对元素是否存在进行的判定，然后进行插入操作
	{
		H->ThCells[Pos].Info = Legitimate;   //将散列单元状态改成合法即有元素
		H->ThCells[Pos].X = Key;
	}
}
int Retrieve(Position P, HashTable H)
{
	return H->ThCells[P].X;
}
int main()
{
	HashTable T;
	int i;
	T = InitializeTable(7);
	printf("散列表大小%d\n", T->TableSize);
		Insert(6, T);
		Insert(15, T);
		Insert(24, T);
		Insert(13, T);
		for (i = 0; i < 7; i++)
			printf("%d\n", T->ThCells[i].X);
  return 0;
}
