#include"SearchHeader.h"
#include<stdio.h>
#include<stdlib.h>


int PalSubSeq(int left, int right, char* str, int** L)
{
	if (L[left][right] == -1)
		if (str[left] == str[right])
			L[left][right] = PalSubSeq(left + 1, right - 1, str, L) + 2;
		else
			L[left][right] = max(PalSubSeq(left + 1, right, str, L), PalSubSeq(left, right - 1, str, L));
	return L[left][right];
}

void PalChars(int left, int right, int palLeft, int palRight, char* str, char* res, int**L)
{
	while (left <= right)
		if (left == right && L[left][right] == 1)
		{
			res[palLeft] = str[left];
			palLeft++;
			left++;
		}

		else
			if (str[left] == str[right])
			{
				res[palLeft] = str[left];
				palLeft++;
				left++;
				res[palRight] = str[right];
				palRight--;
				right--;
			}
			else
				if (L[left + 1][right] >  L[left][right - 1])
					left++;
				else
					right--;
}

void inStringPalindromeSearch(int n, char* str, char* res, int** L)
{
	int lengthPal;
	int j;
	int i;

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			if (i == j)
				L[i][j] = 1;
			else if (i > j)
			{
				L[i][j] = 0;
			}
			else
				L[i][j] = -1;
		}
	lengthPal = PalSubSeq(0, n - 1, str, L);
	printf("Length of biggest palindrom is %i \n", lengthPal);

	res = (char*)malloc(sizeof(char)*(lengthPal + 1));
	if (res == NULL)
	{
		printf("Error: not enough memory \n");
	}

	PalChars(0, n - 1, 0, lengthPal - 1, str, res, L);
	res[lengthPal] = '\0';
	if (res != NULL)
	{
		printf("%s \n", res);
		free(res);
	}
}