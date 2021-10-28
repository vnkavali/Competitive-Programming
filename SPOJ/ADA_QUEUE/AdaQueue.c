/**
 * @file AdaQueue.c
 * @author Vishnu Kavali (vn.kavali.korea@gmail.com)
 * @brief Implementation of deque
 * @version 0.1.1
 * @date 2021-10-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>

#define QMAX 1000000

typedef struct
{
    int arr[QMAX];
    int size;
    int front;
    int rear;
} Deque;

void pop_back(Deque *Q)
{
    if (Q->rear == -1)
    {
        printf("No job for Ada?\n");
        return;
    }

    printf("%d\n", Q->arr[Q->rear]);

    if (Q->rear == Q->front)
    {
        Q->rear = Q->front = -1;
        return;
    }

    Q->rear = Q->rear ? Q->rear - 1 : QMAX - 1;
}

void pop_front(Deque *Q)
{
    if (Q->front == -1)
    {
        printf("No job for Ada?\n");
        return;
    }

    printf("%d\n", Q->arr[Q->front]);

    if (Q->front == Q->rear)
    {
        Q->front = Q->rear = -1;
        return;
    }

    Q->front += 1;
    if (Q->front == QMAX)
        Q->front = 0;
}

void push_back(Deque *Q, int n)
{
    if (Q->rear == -1)
        Q->front = Q->rear = 0;
    else
    {
        Q->rear += 1;
        if (Q->rear == QMAX)
            Q->rear = 0;
    }

    Q->arr[Q->rear] = n;
}

void push_front(Deque *Q, int n)
{
    if (Q->front == -1)
        Q->front = Q->rear = 0;
    else
        Q->front = Q->front ? Q->front - 1 : QMAX - 1;

    Q->arr[Q->front] = n;
}

void (*pop[])(Deque *) = {pop_back, pop_front};
void (*push[])(Deque *, int) = {push_back, push_front};

Deque Q;

int main(void)
{
    int sz;
    scanf("%d", &sz);

    Q.front = -1;
    Q.rear = -1;
    Q.size = sz;
    int reversed = 0;

    for (int i = 0; i < sz; i++)
    {
        char cmd[10];
        scanf("%s", cmd);

        switch (cmd[0])
        {
        case 'b':
        {
            pop[reversed](&Q);
            break;
        }
        case 'f':
        {
            pop[1 - reversed](&Q);
            break;
        }
        case 'r':
        {
            reversed = 1 - reversed;
            break;
        }
        case 'p':
        {
            int n;
            scanf("%d", &n);

            push[reversed](&Q, n);
            break;
        }
        case 't':
        {
            int n;
            scanf("%d", &n);

            push[1 - reversed](&Q, n);
            break;
        }
        default:
            break;
        }
    }

    return 0;
}
