#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * splitString - Splits a string into words and returns an array of words.
 * Uses strtok for splitting.
 * @str: The string to split.
 * @wordCount: Pointer to store the number of words found.
 * Return: An array of strings containing the words.
 */
char **splitString(const char *str, int *wordCount)
{
	char **words = NULL;
	char *token;
	char *strCopy;
	int count = 0;

	if (str == NULL || strlen(str) == 0)
	{
		*wordCount = 0;
		return (NULL);
	}

	strCopy = strdup(str);
	token = strtok(strCopy, " ");

	while (token != NULL)
	{
		words = realloc(words, (count + 1) * sizeof(char *));
		words[count] = strdup(token);
		count++;
		token = strtok(NULL, " ");
	}

	free(strCopy);
	*wordCount = count;
	return (words);
}
