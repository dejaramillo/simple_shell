#include "shell.h"
/**
 *exe - excute and command  in the cosole
 *@args: array of string
 *@str: string
 *Return: always 0
 */

void exe(char **args, char *str)
{
	int status, i = 0;
	pid_t childn = fork();
	char *path = _getenv(args[0]);

	if (childn == -1)
	{
		perror("Error");
		while (args[i])
			free(args[i++]);
		free(args);
		exit(EXIT_FAILURE);
	}
	if (childn == 0)
	{
		if (args[0][0] == '/')
		{

			if (execve(args[0], args, NULL) == 1)
				exit(EXIT_SUCCESS);
		}
		if (path)
		{
			args[0] = _strdup(path);
			execve(args[0], args, NULL);
			exit(EXIT_SUCCESS);
		}
		else
		{
			while (args[0][i])
				i++;
			write(STDOUT_FILENO, args[0], i), write(STDOUT_FILENO, ": ", 3);
			write(STDOUT_FILENO, "Invalid command\n", 17);
			free_mem_string(args);
			free_mem(str);
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&status);
}

/**
 *env - function that print enviroment variables
 *@str: string for seachr enviroment
 *Return: void
 */

void env(char *str)
{
	int status, x = 0;
	pid_t childn;

	childn = fork();
	if (childn == -1)
	{
		perror("Error");
		free(str);
		exit(EXIT_FAILURE);
	}
	if (childn == 0)
	{
		while (environ && environ[x])
		{
			printf("%s\n", environ[x]);
			x++;
		}
		exit(EXIT_SUCCESS);
	}
	else
		wait(&status);
}
