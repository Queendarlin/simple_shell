#include "shell.h"

/**
 * viqu_main_string_token - Function takes an input string
 * and splits it into words using the specified delimiters
 * @viqu_str: The string to get the input from.
 * @viqu_delim: The string to show the delimiter.
 * Return: Pointer to each string from the input string or NULL on failure.
 */

char **viqu_main_string_token(char *viqu_str, char *viqu_delim)
{
	int viqu_i, viqu_j, viqu_k, viqu_m, viqu_num_words = 0;
	char **viqu_words;

	if (viqu_str == NULL || viqu_str[0] == '\0')
		return (NULL);
	if (!viqu_delim)
		viqu_delim = " ";
	for (viqu_i = 0; viqu_str[viqu_i] != '\0'; viqu_i++)
		if (!viqu_checks_delimiter(viqu_str[viqu_i], viqu_delim) &&
				(viqu_checks_delimiter(viqu_str[viqu_i + 1],
						       viqu_delim) || !viqu_str[viqu_i + 1]))
			viqu_num_words++;
	if (viqu_num_words == 0)
		return (NULL);
	viqu_words = malloc((1 + viqu_num_words) * sizeof(char *));
	if (!viqu_words)
		return (NULL);
	for (viqu_i = 0, viqu_j = 0; viqu_j < viqu_num_words; viqu_j++)
	{
		while (viqu_checks_delimiter(viqu_str[viqu_i], viqu_delim))
			viqu_i++;
		viqu_k = 0;
		while (!viqu_checks_delimiter(viqu_str[viqu_i + viqu_k], viqu_delim) &&
				viqu_str[viqu_i + viqu_k])
			viqu_k++;
		viqu_words[viqu_j] = malloc((viqu_k + 1) * sizeof(char));
		if (!viqu_words[viqu_j])
		{
			for (viqu_k = 0; viqu_k < viqu_j; viqu_k++)
				free(viqu_words[viqu_k]);
			free(viqu_words);
			return (NULL);
		}
		for (viqu_m = 0; viqu_m < viqu_k; viqu_m++)
			viqu_words[viqu_j][viqu_m] = viqu_str[viqu_i++];
		viqu_words[viqu_j][viqu_m] = '\0';
	}
	viqu_words[viqu_j] = NULL;
	return (viqu_words);
}


