#pragma warning(disable:4996)

#include<stdio.h>
#include<stdlib.h>
#include"Reader.h"
#include"SearchHeader.h"

#define UNUSED_PARAMETER(name) (void)name

int main(void)
{
	char* str = NULL;
	char* res = NULL;
	int n; // Num of position in string
	int i;
	int flag = 0;
	int** L;

	str = ReadLine(stdin, &n);
	if (str != NULL)
	{
		printf("%s \n", str); // Check string
	}
	else
	{
		printf("Error: not enough memory \n");
		return -1;
	}

	L = (int**)malloc(sizeof(int*) * n);
	if (L == NULL)
	{
		if (str != NULL)
			free(str);
		printf("Error: not enough memory \n");

	}

	for (i = 0; i < n; i++)
	{
		L[i] = (int*)malloc(sizeof(int) * n);
		if (L[i] == NULL)
			flag = -1; // If not enough memory
	}

	// If not enough memory
	if (flag == -1)
		for (i = 0; i < n; i++)
			if (L[i] != NULL)
				free(L[i]);

	inStringPalindromeSearch(n, str, res, L);

	if (str != NULL)
		free(str);
	if (res != NULL)
		free(res);

	for (i = 0; i < n; i++)
		free(L[i]);
	free(L);

	return 0;
}