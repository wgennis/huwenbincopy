#ifndef _HashSep_H
struct ListNode;
typedef struct ListNode* Position;
struct HashTb1;
typedef struct HashTbl* HashTable;
HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(int Key, HashTable H);
void Insert(int Key, HashTable H);
int Retrieve(Position P);
#endif // !_HashSep_H
