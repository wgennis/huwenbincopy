#ifndef _LeftHeap_H
struct TreeNode;
typedef struct TreeNode* PrioityQueue;
PrioityQueue Initialize(void);
int FindMin(PrioityQueue H);
int IsEmpty(PrioityQueue H);
PrioityQueue Merge(PrioityQueue H1, PrioityQueue H2);
#define Insert(X,H)(H=Insert((X),H))
PrioityQueue Insert1(int X, PrioityQueue H);
PrioityQueue DeleteMin(PrioityQueue H);
#endif
