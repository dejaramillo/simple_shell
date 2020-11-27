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
	pid_t childn;
	char *path = NULL;

	childn = fork();
	if (childn == -1)
	{
		perror("Error");
		free_mem_string(args);
		exit(EXIT_FAILURE);
	}
	if (childn == 0)
	{
		if (args[0][0] == '/')
		{

			execve(args[0], args, NULL);
		}
		path = _getenv(args[0]);
		if (path)
		{
			args[0] = _strdup(path);
			execve(args[0], args, NULL);
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
	{
		free_mem_string(args);
		free(str);
		wait(&status);
	}
}

/**
 *env - function that print enviroment variables
 *@str: string for seachr enviroment
 *Return: void
 */

int env()
{
	int  x = 0;

	while (environ && environ[x])
		{
			printf("%s\n", environ[x]);
			x++;
		}
	return (0);

}
