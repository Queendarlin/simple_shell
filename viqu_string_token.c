#include "shell.h"

/**
 * viqu_string_token - Function to split an input string
 * into words using a single delimiter character
 * @viqu_str: The input string to split
 * @viqu_delim: The delimiter character to use in splitting the string
 *   Return: Returns a pointer to the word from the input string or NULL
 */

char **viqu_string_token(char *viqu_str, char viqu_delim)
{
	int viqu_index, viqu_j, viqu_k, viqu_m, viqu_num_words = 0;
	char **viqu_words;

	if (viqu_str == NULL || viqu_str[0] == '\0')
		return (NULL);
	for (viqu_index = 0; viqu_str[viqu_index] != '\0'; viqu_index++)
		if ((viqu_str[viqu_index] != viqu_delim &&
					viqu_str[viqu_index + 1] == viqu_delim) ||
				(viqu_str[viqu_index] != viqu_delim &&
				 !viqu_str[viqu_index + 1]) || viqu_str[viqu_index + 1] == viqu_delim)
			viqu_num_words++;
	if (viqu_num_words == 0)
		return (NULL);
	viqu_words = malloc((1 + viqu_num_words) * sizeof(char *));
	if (!viqu_words)
		return (NULL);
	for (viqu_index = 0, viqu_j = 0; viqu_j < viqu_num_words; viqu_j++)
	{
		while (viqu_str[viqu_index] == viqu_delim &&
				viqu_str[viqu_index] != viqu_delim)
			viqu_index++;
		viqu_k = 0;
		while (viqu_str[viqu_index + viqu_k] !=
				viqu_delim && viqu_str[viqu_index + viqu_k] &&
				viqu_str[viqu_index + viqu_k] != viqu_delim)
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
			viqu_words[viqu_j][viqu_m] = viqu_str[viqu_index++];
		viqu_words[viqu_j][viqu_m] = '\0';
	}
	viqu_words[viqu_j] = NULL;
	return (viqu_words);
}
