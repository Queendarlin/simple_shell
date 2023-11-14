#include "shell.h"

/**
 * main - Function to initialize and execute the shell program
 * @viqu_ac: The parameter for the count of command-line arguments
 * @viqu_av: Pointer to array of strings representing
 * the command-line arguments
 *
 * Return: 0 upon successful execution, 1 if an error occurs
 */
int main(int viqu_ac, char **viqu_av)
{
	info_t viqu_info[] = { VIQU_INFO_INIT };
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
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				viqu_eputs(viqu_av[0]);
				viqu_eputs(": 0: Can't open ");
				viqu_eputs(viqu_av[1]);
				viqu_eputchar('\n');
				viqu _eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		viqu_info->viqu_readfd = viqu_fd;
	}

	viqu_populate_env_list(viqu_info);
	viqu_read_history(viqu_info);
	viqu_hsh(viqu_info, viqu_av);

	return (EXIT_SUCCESS);
}
