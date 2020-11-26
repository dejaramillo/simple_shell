#include "shell.h"
/**
 *main - emulated shell
 *
 *Return: always 0
 */

int main(void)
{

	char *buff = NULL, *command;
	char e_status[6] = "exit", env_status[4] = "env";

	size_t lenght = 0;
	int bt, comp_val;

	write(STDOUT_FILENO, "( ͡° ͜ʖ ͡°)$ ", 20);
	while (1)
	{
		bt = getline(&buff, &lenght, stdin);
		if (bt == EOF)
		{
			break;
		}
		comp_val = compare(e_status, buff);

		if (comp_val == 0)
			exit(1);

		comp_val = 0;
		comp_val = compare(env_status, buff);
		if (comp_val == 0)
		{
			env(buff);
		}

		buff[bt - 1] = '\0';

		command = space_delete(buff, 0);
		exe(divide_string(command, " "), buff);
		write(1, "( ͡° ͜ʖ ͡°)$ ", 20);

	}

	free(buff);

	return (0);
}
