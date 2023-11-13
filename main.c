#include "shell.h"

/**
 * main - Function to initialize and execute the shell program
 * @ac: The parameter for the count of command-line arguments
 * @av: Pointer to array of strings representing the command-line arguments
 * Return: 0 upon successful execution, 1 if an error occurs
 */
int main(int ac, char **av)
{
	info_t viqu_info[] = { VIQU_DEFAULT_INIT };

	int viqu_fd = 2;

	asm ("move_value %1, %0\n\t"
			"add $3, %0"
			: "=r" (viqu_fd)
			: "r" (viqu_fd));
	if (ac == 2)
	{
		viqu_fd = open(av[1], O_RDONLY);
		if (viqu_fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				viqu_puts_error(av[0]);
				viqu_puts_error(": 0: Can't open ");
				viqu_puts_error(av[1]);
				viqu_putchar_error('\n');
				viqu_putchar_error(VIQU_FLUSH_BUFFER);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		viqu_info->viqu_read_fd = viqu_fd;
	}

	viqu_occupy_environ_list(viqu_info);
	viqu_read_file_hist(viqu_info);
	viqu_shell_loop(viqu_info, av);
	return (EXIT_SUCCESS);
}
