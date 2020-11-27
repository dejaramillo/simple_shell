#include "shell.h"
/**
 *main - emulated shell
 *
 *Return: always 0
 */

int main(void)
{

	char *buff = NULL, space[1] = " ";
	char e_status[6] = "exit", env_status[4] = "env";

	size_t lenght = 0;
	int bt, comp_val;

	if (isatty(STDIN_FILENO) > 0)
		write(STDOUT_FILENO, "( ͡° ͜ʖ ͡°)$ ", 20);
	while (1)
	{
		bt = getline(&buff, &lenght, stdin);
		if (bt == EOF)
		{
			break;
		}
		buff[bt - 1] = '\0';
		comp_val = compare(e_status, buff);

		if (comp_val == 0)
		{
			free(buff);
			exit(1);
		}
		comp_val = 0;
		comp_val = compare(env_status, buff);
		if (comp_val == 0)
		{
			env();
		}
		else
		{
			if(buff[0] == space[0])
				buff = space_delete(buff, 0);
			exe(divide_string(buff, " "), buff);
		}


		if (isatty(STDIN_FILENO) > 0)
			write(1, "( ͡° ͜ʖ ͡°)$ ", 20);

	}
	return (0);
}
