#include "shell.h"

/**
 * **viqu_strtow - Function for string splitting into words,
 * without including double delimiters.
 * @viqu_str: The string that will be splitted.
 * @viqu_d: The parameter for delimiter.
 *
 * Return: A pointer to the strings when successful or NULL when it fails.
 */
char **viqu_strtow(char *viqu_str, char *viqu_d)
{
	int viqu_i, viqu_j, viqu_k, viqu_m, viqu_numwords = 0;
	char **viqu_s;

	if (viqu_str == NULL || viqu_str[0] == 0)
		return (NULL);
	if (!viqu_d)
		viqu_d = " ";
	for (viqu_i = 0; viqu_str[viqu_i] != '\0'; viqu_i++)
		if (!viqu_is_delim(viqu_str[viqu_i], d) &&
				(viqu_is_delim(viqu_str[viqu_i + 1], viqu_d) || !viqu_str[viqu_i + 1]))
			viqu_numwords++;

	if (viqu_numwords == 0)
		return (NULL);
	viqu_s = malloc((1 + viqu_numwords) * sizeof(char *));
	if (!viqu_s)
		return (NULL);
	for (viqu_i = 0, viqu_j = 0; viqu_j < viqu_numwords; viqu_j++)
	{
		while (viqu_is_delim(viqu_str[viqu_i], viqu_d))
			viqu_i++;
		viqu_k = 0;
		while (!viqu_is_delim(viqu_str[viqu_i + viqu_k], viqu_d) &&
				viqu_str[viqu_i + viqu_k])
			viqu_k++;
		viqu_s[viqu_j] = malloc((viqu_k + 1) * sizeof(char));
		if (!viqu_s[viqu_j])
		{
			for (viqu_k = 0; viqu_k < viqu_j; viqu_k++)
				free(viqu_s[viqu_k]);
			free(viqu_s);
			return (NULL);
		}
		for (viqu_m = 0; viqu_m < viqu_k; viqu_m++)
			viqu_s[viqu_j][viqu_m] = viqu_str[viqu_i++];
		viqu_s[viqu_j][viqu_m] = 0;
	}
	viqu_s[viqu_j] = NULL;
	return (viqu_s);
}

/**
 * **viqu_strtow2 - Function for string splitting into words.
 * @viqu_str: String to split.
 * @viqu_d: The parameter for delimiter .
 *
 * Return: Pointer to strings when successful or NULL when it fails.
 */

char **viqu_strtow2(char *viqu_str, char viqu_d)
{
	int viqu_i, viqu_j, viqu_k, viqu_m, viqu_numwords = 0;
	char **viqu_s;

	if (viqu_str == NULL || viqu_str[0] == 0)
		return (NULL);
	for (viqu_i = 0; viqu_str[viqu_i] != '\0'; viqu_i++)
		if ((viqu_str[viqu_i] != viqu_d && viqu_str[viqu_i + 1] == d) ||
				(viqu_str[viqu_i] != viqu_d &&
				 !viqu_str[i + 1]) || viqu_str[viqu_i + 1] == viqu_d)
			viqu_numwords++;
	if (viqu_numwords == 0)
		return (NULL);
	viqu_s = malloc((1 + viqu_numwords) * sizeof(char *));
	if (!viqu_s)
		return (NULL);
	for (viqu_i = 0, viqu_j = 0; viqu_j < viqu_numwords; viqu_j++)
	{
		while (viqu_str[viqu_i] == viqu_d && viqu_str[viqu_i] != viqu_d)
			viqu_i++;
		viqu_k = 0;
		while (viqu_str[viqu_i + viqu_k] != viqu_d && viqu_str[viqu_i + viqu_k] &&
				viqu_str[viqu_i + viqu_k] != viqu_d)
			viqu_k++;
		viqu_s[viqu_j] = malloc((viqu_k + 1) * sizeof(char));
		if (!viqu_s[viqu_j])
		{
			for (viqu_k = 0; viqu_k < viqu_j; viqu_k++)
				free(viqu_s[viqu_k]);
			free(viqu_s);
			return (NULL);
		}
		for (viqu_m = 0; viqu_m < viqu_k; viqu_m++)
			viqu_s[viqu_j][viqu_m] = viqu_str[viqu_i++];
		viqu_s[viqu_j][viqu_m] = 0;
	}
	viqu_s[viqu_j] = NULL;
	return (viqu_s);
}
