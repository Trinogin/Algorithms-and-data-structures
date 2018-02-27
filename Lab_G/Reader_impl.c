#include"Reader.h"

char* ReadLine(FILE* in, int* n)
{
	char* line = NULL;
	char* str;
	char ch;

	(*n) = 1;
	while (((ch = (char)getc(in)) != '\n'))
	{
		str = realloc(line, (*n) * sizeof(char));
		if (str != NULL)
		{
			line = str;
			if (ch != '\n')
			{
				line[(*n) - 1] = ch;
				(*n)++;
			}
			else
			{
				line[(*n) - 1] = '\0';
				break;
			}
		}
		else
		{
			free(line);
			line = NULL;
			str = NULL;
			return NULL;
		}
	}
	str = realloc(line, (*n) * sizeof(char));
	if (str != NULL)
	{
		line = str;
		line[(*n) - 1] = '\0';
	}
	else
	{
		free(line);
		line = NULL;
		str = NULL;
		return NULL;
	}
	return line;
}