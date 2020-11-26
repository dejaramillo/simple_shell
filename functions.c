#include "shell.h"
/**
 **_strdup - return the pointer
 *@str: entry point
 *Return: char
 */

char *_strdup(char *str)
{
	int i, j;
	char *s;

	if (str == NULL)
	{
		return (NULL);
	}
	for (i = 0; str[i]; i++)
	{}
	s = malloc((i + 1) * sizeof(char));
	if (s == NULL)
	{
		return (NULL);
	}
	for (j = 0; j <= i; j++)
	{
		s[j] = str[j];
	}

	return (s);
}

/**
 *_concat - concatenate two strings
 *@str: firts string
 *@strconcat: second string
 *Return: pointer whit concatenate string
 */

char *_concat(char *str, char *strconcat)
{
	int i = 0, j = 0, k, l;
	char *con;

	if (str == NULL)
		str = "";
	if (strconcat == NULL)
		str = "";
	while (str[i] != '\0')
		i++;
	while (strconcat[j] != '\0')
		j++;
	con = malloc(sizeof(char) * (i + j + 2));
	if (con == 0)
		return (NULL);
	for (k = 0; k < i; k++)
		con[k] = str[k];
	con[k++] = '/';
	for (l = 0; l < j; l++)
		con[k++] = strconcat[l];
	con[k] = '\0';
	return (con);

}

/**
 *divide_string - create array of strings
 *@str: string argument
 *@divide: character for create division
 *Return: pointer to pointer
 */

char **divide_string(char *str, char *divide)
{
	char *token, *token2, *str2;
	int strings = 0, i = 0;
	char **stringArr;

	str2 = _strdup(str);
	token = strtok(str, divide);

	while (token)
	{
		token = strtok(NULL, divide);
		strings++;
	}

	token2 = strtok(str2, divide);

	stringArr = malloc(sizeof(char *) * (strings + 1));

	while (token2)
	{
		stringArr[i] = _strdup(token2);
		token2 = strtok(NULL, divide);
		i++;
	}

	stringArr[i] = '\0';
	free(str2);
	free(token2);
	return (stringArr);
}

/**
 *free_mem_string - free memory of string array
 *@args: pointer to pointer
 *Return:void
 */

void free_mem_string(char **args)
{
	int i = 0;

	while (args[i])
	{
		free(args[i]);
		i++;
	}
}

/**
 *space_delete - function that delete space in command
 *@str: array
 *@index: position when is the position
 *Return: char
 */

char *space_delete(char *str, int index)
{
	char *cp = NULL, *sp = " ";
	int i = index, j, len = 0;

	if (!str)
		return (NULL);
	while (str[len++])
	;
	while (str[i])
	{
		if (str[i] != sp[0])
			break;
		i++;
	}
	cp = malloc(sizeof(char) * (len + 1));

	if (cp == NULL)
		return (NULL);
	for (j = 0; j < len; j++)
		cp[j] = str[i++];
	cp[j] = '\0';
	return (cp);
}
