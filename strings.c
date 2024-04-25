#include "shell.h"
/**
* _strtok_r - Tokenizes a string by splitting it into W separated by delimiters
* @str: The string to tokenize if starting anew,
* or NULL to continue tokenizing the previous string.
* @delim: The delimiters used to split the string.
* @saveptr: Pointer to a char* variable that stores the context.
* Return: Pointer to the next token, or NULL if there are no more tokens.
* Description: This function is a reentrant version of strtok.
*/
char *_strtok_r(char *str, const char *delim, char **saveptr)
{
	char *end;

	if (str == NULL)
	{
		str = *saveptr;
	}
	if (*str == '\0')
	{
		*saveptr = str;
		return (NULL);
	}

	/* Scan leading delimiters */
	str += strspn(str, delim);
	if (*str == '\0')
	{
		*saveptr = str;
		return (NULL);
	}

	/* Find the end of the token */
	end = str + strcspn(str, delim);
	if (*end == '\0')
	{
		*saveptr = end;
		return (str);
	}

	/* Terminate the token and make saveptr point past it */
	*end = '\0';
	*saveptr = end + 1;
	return (str);
}
