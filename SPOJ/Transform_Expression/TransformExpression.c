/**
 * @file main.c
 * @author Vishnu Kavali (vn.kavali.korea@gmail.com)
 * @brief Solution to https://www.spoj.com/problems/ONP/
 * @version 0.1
 * @date 2021-10-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>

#define EXPRESSION_SIZE_MAX 400

char exp[EXPRESSION_SIZE_MAX + 1];

char *ConvertExpToRPN(char *exp)
{
	if (exp[0] >= 'a' && exp[0] <= 'z')
	{
		printf("%c", exp[0]);
		return exp + 1;
	}

	char *l = ConvertExpToRPN(exp + 1);
	char *r = ConvertExpToRPN(l + 1);
	printf("%c", l[0]);

	if (r[0] != ')')
		printf("[%d] Logic gone wrong", __LINE__);

	return r + 1;
}

int main(void)
{
	int tc;
	scanf("%d", &tc);

	for (int i = 0; i < tc; i++)
	{
		scanf("%s", &exp);

		char *end = ConvertExpToRPN(exp);
		printf("\n");

		if (*end != '\0')
			printf("[%d] Logic gone wrong", __LINE__);
	}

	return 0;
}