#include "shell.h"

/**
 * main - Function to initialize and execute the shell program
 * @viqu_ac: The parameter for the count of command-line arguments
 * @viqu_av: Pointer to array of strings
 * representing the command-line arguments
 * Return: 0 upon successful execution, 1 if an error occurs
 */

int main(int viqu_ac, char **viqu_av)
{
	info_t viqu_info[] = { VIQU_DEFAULT_INIT };

	int viqu_fd = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (viqu_fd)
			: "r" (viqu_fd));
	if (viqu_ac == 2)
	{
		viqu_fd = open(viqu_av[1], O_RDONLY);
		if (viqu_fd == -1)
		{
			switch (errno)
			{
				case EACCES:
					exit(126);
				case ENOENT:
					viqu_puts_error(viqu_av[0]);
					viqu_puts_error(": 0: can't open ");
					viqu_puts_error(viqu_av[1]);
					exit(127);
				default:
					return (EXIT_FAILURE);
			}
		}
		viqu_info->viqu_read_fd = viqu_fd;
	}
	viqu_occupy_environ_list(viqu_info);
	viqu_read_file_hist(viqu_info);
	viqu_shell_loop(viqu_info, viqu_av);
	return (EXIT_SUCCESS);
}
