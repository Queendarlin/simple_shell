#include "shell.h"

/**
 **viqu_strncpy - copies a string
 *@viqu_dest: the destination string to be copied to
 *@viqu_src: the source string
 *@viqu_n: the amount of characters to be copied
 *Return: the concatenated string
 */
char *viqu_strncpy(char *viqu_dest, char *viqu_src, int viqu_n)
{
	int viqu_idx, viqu_b;
	char *viqu_s = viqu_dest;

	viqu_idx = 0;
	while (viqu_src[viqu_idx] != '\0' && viqu_idx < viqu_n - 1)
	{
		viqu_dest[viqu_idx] = viqu_src[viqu_idx];
		viqu_idx++;
	}
	if (viqu_idx < viqu_n)
	{
		viqu_b = viqu_idx;
		while (viqu_b < viqu_n)
		{
			viqu_dest[viqu_b] = '\0';
			viqu_b++;
		}
	}
	return (viqu_s);
}


/**
 **viqu_strncat - concatenates two strings
 *@viqu_dest: the first string
 *@viqu_src: the second string
 *@viqu_n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *viqu_strncat(char *viqu_dest, char *viqu_src, int viqu_n)
{
	int viqu_idx, viqu_b;
	char *viqu_s = viqu_dest;

	viqu_idx = 0;
	viqu_b = 0;
	while (viqu_dest[viqu_idx] != '\0')
		viqu_idx++;
	while (viqu_src[viqu_b] != '\0' && viqu_b < viqu_n)
	{
		viqu_dest[viqu_idx] = viqu_src[viqu_b];
		viqu_idx++;
		viqu_b++;
	}
	if (viqu_b < viqu_n)
		viqu_dest[viqu_idx] = '\0';
	return (viqu_s);
}


/**
 **viqu_strchr - locates a character in a string
 *@viqu_str: the string to be parsed
 *@viqu_ch: the character to look for
 *Return: (s) a pointer to the memory area s
 */

char *viqu_strchr(char *viqu_str, char viqu_ch)
{
	do {
		if (*viqu_str == viqu_ch)
			return (viqu_str);
	} while (*viqu_str++ != '\0');

	return (NULL);
}
