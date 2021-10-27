/**
 * @file main.c
 * @author Vishnu Kavali (vn.kavali.korea@gmail.com)
 * @brief In a histogram of length n, find the area of the largest rectangle with base on the x axis
 * @version 0.2
 * @details In O(n) time using stack
 * @date 2021-10-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <malloc.h>

typedef struct
{
    int h;
    int wstart;
} Rectangle;

#define MAX 100000

Rectangle stack[MAX];
int top;

int main(void)
{
    while (1)
    {
        int n;
        scanf("%d", &n);

        if (n == 0)
            break;

        long long int Amax = 0;
        top = -1;
        for (int i = 0; i < n; i++)
        {
            int h;
            scanf("%d", &h);

            if (h == 0)
            {
                for (int j = top; j >= 0; j--)
                {
                    long long int Aj = ((long long int)(stack[j].h) * (long long int)(i - stack[j].wstart));
                    if (Aj > Amax)
                        Amax = Aj;
                }

                top = -1;
                continue;
            }

            int cur_h_wstart = i;
            for (int j = top; j >= 0; j--)
            {
                if (stack[j].h > h)
                {
                    long long int Aj = ((long long int)(stack[j].h) * (long long int)(i - stack[j].wstart));
                    if (Aj > Amax)
                        Amax = Aj;

                    cur_h_wstart = stack[j].wstart;
                }
                else if (stack[j].h == h)
                {
                    top = j;

                    cur_h_wstart = -1;
                    break;
                }
                else
                {
                    stack[j + 1].h = h;
                    stack[j + 1].wstart = cur_h_wstart;

                    top = j + 1;

                    cur_h_wstart = -1;
                    break;
                }
            }

            if (cur_h_wstart != -1)
            {
                stack[0].h = h;
                stack[0].wstart = cur_h_wstart;

                top = 0;
            }
        }

        for (int j = top; j >= 0; j--)
        {
            long long int Aj = ((long long int)(stack[j].h) * (long long int)(n - stack[j].wstart));

            if (Aj > Amax)
                Amax = Aj;
        }

        printf("%lld\n", Amax);
    }

    return 0;
}
