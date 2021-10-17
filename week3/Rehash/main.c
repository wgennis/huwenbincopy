附上程序：
HashTable Rehash(HashTable H)
{
	int i, OldSize;
	Cell* OldCells;
	OldCells = H->ThCells;
	OldSize = H->TableSize;
	H = InitializeTable(2 * OldSize);
	for (i = 0; i < OldSize; i++)
		if (OldCells[i].Info == Legitimate)
			Insert(OldCells[i].X, H);
	free(OldCells);
	return H;
  int main()
  {
    HashTable H;
		H = InitializeTable(7);
		int N = 0;
		Insert(6, H);
		++N;
		Insert(15, H);
		++N;
		Insert(24, H);
		++N;
		Insert(13, H);
		++N;
		if (N <= 3)
		{
			for (i = 0; i < 7; i++)
				printf("不用再散列%d\n", H->ThCells[i].X);
		}
		else
		{
			H = Rehash(H);
			for (i = 0; i < 14; i++)
				printf("用再散列%d\n", H->ThCells[i].X);
		}
	return 0;
}
