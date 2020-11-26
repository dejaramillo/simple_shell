#include "shell.h"

/**
 *getpath - search path diretory
 *@direction: path name
 *Return: char
 */


char *getpath(const char *direction)
{
	int index;
	char *tmp, **tmp2, *rt = NULL;

	if (direction)
	{
		index = ubicationpath(direction);
		if (index >= 0)
		{
			tmp = _strdup(environ[index]);
			tmp2 = divide_string(tmp, "=");
			rt = _strdup(tmp2[1]);
		}
		else
			return (NULL);
		free_mem_string(tmp2);
		free(tmp2);
		free(tmp);
	}
	return (rt);
}

/**
 *ubicationpath - search position of path in the enviroment file
 *@direction: name of directory
 *Return: position in file
 */


int ubicationpath(const char *direction)
{
	int i = 0, j = 0, len = 0, len1 = 0;

	while (environ && environ[i])
	{
		while (environ[i][len] != '=')
			len++;
		len1 = len;
		while (len > 0)
		{
			if (environ[i][j] == direction[j])
				j++;
			else
				break;
			len--;
		}
		if (len1 == j && j != 0)

			return (i);
		i++;
		j = 0;
		len = 0;
		len1 = 0;
	}
	free_mem_string(environ);
	return (-1);
}

/**
 *_getenv - function that ubicationof path
 *@direction: name of direction of path
 *Return: char
 */


char *_getenv(char *direction)
{
	char *name = "PATH", *route;
	char *getenvp, **directory;
	int i = 0;
	struct stat st;

	getenvp = getpath(name);
	directory = divide_string(getenvp, ":");
	for (i = 0; directory[i]; i++)
	{
		route = _concat(directory[i], direction);
		if (stat(route, &st) == 0)
			return (route);
		free(route);
	}
	i = 0;
	while (directory[i])
	{
		free(directory[i++]);
	}
	free(getenvp);
	return (NULL);
}



/**
 *compare - function that comapre two strings
 *@str1: frist string
 *@str2: second string
 *Return: int
 */



int compare(char *str1, char *str2)
{
	int x = 0, diff = 0;

	for (x = 0; str1[x] != '\0' && str2[x] != '\0'; x++)
	{
		if (str1[x] == str2[x])
		{
			diff = 0;
		}
		else
		{
			diff = str1[x] - str2[x];
			return(diff);
		}
	}

	return (diff);
}



/**
 *free_mem - free memory
 *@str: array for free
 *Return: void
 */



void free_mem(char *str)
{
	free(str);
}

