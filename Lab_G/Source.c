#pragma warning(disable:4996)

#include<stdio.h>
#include<stdlib.h>
#include"Reader.h"

#define UNUSED_PARAMETER(name) (void)name

// TO DO
void inPalindromeSearch(int n, char* str)
{
	UNUSED_PARAMETER(n);
	UNUSED_PARAMETER(str);
}

int main(void)
{
	char* str = NULL;
	int n; // Num of position in string

	str = ReadLine(stdin, &n);
	printf("%s \n", str); // Check string



	if (str != NULL)
		free(str);

	return 0;
}