/**
 * @file main.c
 * @author Vishnu Kavali (vn.kavali.korea@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-10-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <malloc.h>

typedef struct Rect
{
    int h;
    int w;
    struct Rect *next;
} Rectangle;

int main(void)
{
    while (1)
    {
        int n;
        scanf("%d", &n);

        if (n == 0)
            break;

        long long int Amax = 0;
        Rectangle *top = NULL;
        for (int i = 0; i < n; i++)
        {
            int h, w = 1;
            scanf("%d", &h);

            int included = 0;
            for (Rectangle *i = top; i != NULL; i = i->next)
            {
                if (included)
                {
                    i->w += 1;
                    continue;
                }

                if (i->h > h)
                {
                    long long int Ai = ((long long int)(i->h) * (long long int)(i->w));
                    if (Ai > Amax)
                        Amax = Ai;

                    w = i->w + 1;
                }
                else if (i->h == h)
                {
                    i->w += 1;

                    top = i;
                    included = 1;
                }
                else if (h != 0)
                {
                    Rectangle *tmp = (Rectangle *)malloc(sizeof(Rectangle));
                    tmp->h = h;
                    tmp->w = w;
                    tmp->next = i;

                    top = tmp;
                    included = 1;

                    i->w += 1;
                }
            }

            if (included == 0)
            {
                if (h == 0)
                    top = NULL;
                else
                {
                    Rectangle *tmp = (Rectangle *)malloc(sizeof(Rectangle));
                    tmp->h = h;
                    tmp->w = w;
                    tmp->next = NULL;

                    top = tmp;
                }
            }
        }

        for (Rectangle *i = top; i != NULL; i = i->next)
        {
            long long int Ai = ((long long int)(i->h) * (long long int)(i->w));

            if (Ai > Amax)
                Amax = Ai;
        }

        printf("%lld\n", Amax);
    }

    return 0;
}
