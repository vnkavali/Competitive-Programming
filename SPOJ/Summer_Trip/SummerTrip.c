/**
 * @file SummerTrip.c
 * @author Vishnu Kavali (vn.kavali.korea@gmail.com)
 * @brief Solved using Disjoint Set and Heap
 * @version 1.0
 * @date 2021-10-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>

#define NMAX 1000

int Money[NMAX];
int TotalMoneyOfSet[NMAX];

int DSU[NMAX];
int DSUcount[NMAX];

int CountDisjointSets;

int GetRoot(int node)
{
    if (DSU[node] != node)
    {
        //path compression
        DSU[node] = GetRoot(DSU[node]);

        return DSU[node];
    }

    return node;
}

void DSUUnion(int node1, int node2)
{
    node1 = GetRoot(node1);
    node2 = GetRoot(node2);

    if (node1 != node2)
    {
        CountDisjointSets--;
        if (DSUcount[node2] > DSUcount[node1])
        {
            DSU[node1] = node2;
            DSUcount[node2] += DSUcount[node1];

            TotalMoneyOfSet[node2] += TotalMoneyOfSet[node1];
        }
        else
        {
            DSU[node2] = node1;
            DSUcount[node1] += DSUcount[node2];

            TotalMoneyOfSet[node1] += TotalMoneyOfSet[node2];
        }
    }
}

int MoneyHeap[NMAX];
int MoneyHeapSize;

#define PARENT(i) (((i)-1) / 2)
#define CHILDl(i) (2 * (i) + 1)
#define CHILDr(i) (2 * (i) + 2)

void swap(int *i, int *j)
{
    int temp = *i;

    *i = *j;
    *j = temp;
}

void siftdown(int i)
{
    int l = CHILDl(i);
    int r = CHILDr(i);
    if (l < MoneyHeapSize)
    {
        if (MoneyHeap[i] > MoneyHeap[l])
        {
            if (r < MoneyHeapSize)
            {
                if (MoneyHeap[r] < MoneyHeap[l])
                {
                    swap(&MoneyHeap[i], &MoneyHeap[r]);
                    siftdown(r);
                    return;
                }
            }

            swap(&MoneyHeap[i], &MoneyHeap[l]);
            siftdown(l);
            return;
        }

        if (r < MoneyHeapSize)
        {
            if (MoneyHeap[i] > MoneyHeap[r])
            {
                swap(&MoneyHeap[i], &MoneyHeap[r]);
                siftdown(r);
                return;
            }
        }
    }
}

void BuildHeap()
{
    int start = MoneyHeapSize / 2 - 1;

    for (int i = start; i >= 0; i--)
        siftdown(i);
}

int HeapGetMin()
{
    int ret = MoneyHeap[0];

    MoneyHeap[0] = MoneyHeap[MoneyHeapSize - 1];
    MoneyHeapSize--;

    siftdown(0);

    return ret;
}

int main(void)
{
    int tc;
    scanf("%d", &tc);

    for (int t = 0; t < tc; t++)
    {
        int N, M;
        scanf("%d %d", &N, &M);

        MoneyHeapSize = 0;
        CountDisjointSets = N;
        for (int i = 0; i < N; i++)
        {
            scanf("%d", Money + i);
            TotalMoneyOfSet[i] = Money[i];

            DSU[i] = i;
            DSUcount[i] = 1;
        }

        for (int i = 0; i < M; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);

            DSUUnion(a - 1, b - 1);
        }

        printf("Case %d: %d\n", t + 1, CountDisjointSets);

        for (int i = 0; i < N; i++)
        {
            if (DSU[i] == i)
            {
                MoneyHeap[MoneyHeapSize] = TotalMoneyOfSet[i];
                MoneyHeapSize++;
            }
        }

        //printf("Case %d: %d\n", t + 1, MoneyHeapSize);

        BuildHeap();

        while (MoneyHeapSize)
            printf("%d ", HeapGetMin());
    }

    return 0;
}
