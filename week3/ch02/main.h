#ifndef _HashQuad_H
typedef int Index;
typedef Index Position;
struct HashTbl;
typedef struct HashTbl* HashTable;
HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(int Key, HashTable H);
void Insert(int Key, HashTable H);
int Retrieve(Position P, HashTable H);
HashTable Rehash(HashTable H);
#endif
