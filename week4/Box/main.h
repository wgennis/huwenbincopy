#ifndef _BinHeap_H
typedef struct BinNode* Position;
typedef struct Collection* BinQueue;
typedef Position BinTree;
BinQueue Initialize(void);
BinQueue Merge(BinQueue H1, BinQueue H2);
int DeleteMin(BinQueue H);
int Empty(BinQueue H);
#endif
