#include<math.h>
#define LEN sizeof(struct Student)
struct Tong;
typedef struct Tong* P;
typedef P Position;
struct Tong
{
	int cishu ;
	int N ;
	Position Next;
};
int main()
{
	P Tong;
	Tong->cishu = 3;
	Tong->N = 1000;
	int a[10];
	int i, j, k;
	for (i = 0; i < 10; i++)
		scanf_s("%d", &a[i]);
	for (i = 0; i < Tong->N; i++)
		Tong->Next = NULL;
	for (j = 0; j < Tong->cishu; j++)
		for (i = 0; i < 10; i++)
		{
			if (Tong->N == (a[i] / pow(1000, j + 1)) % 1000)
				Tong->Next = ((a[i] / pow(1000, j + 1)) % 1000);
		}
	for (k = 0; k < Tong->N; k++)
		printf("%d", Tong->Next);
	return 0;
}
