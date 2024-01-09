#include "main.h"

/**
 * _strcmp - Compares two strings.
 * @s1: First string.
 * @s2: Second string.
 *
 * Return: Integer less than, equal to, or greater than zero
 * if s1 is found to be less than, equal to, or greater than s2.
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;
	int len1 = _strlen(s1);
	int len2 = _strlen(s2);
	int len = len1;

	if (len1 > len2)
		len = len2;

	while (i <= len)
	{
		if (s1[i] > s2[i])
			return (1);
		if (s1[i] < s2[i])
			return (-1);
		i++;
	}

	return (0);
}

/**
 * _strlen - Computes the length of a string.
 * @s: String.
 *
 * Return: Length of the string.
 */

int _strlen(char *s)
{
	int i;

	if (s == NULL)
		return (-1);

	for (i = 0; s[i] != '\0'; i++)
	{
	}

	return (i);
}

/**
 * _strdup - Duplicates a string.
 * @s: String to be duplicated.
 *
 * Return: Pointer to the newly allocated duplicated string.
 */

char *_strdup(char *s)
{
	char *str;

	if (s == NULL)
		return (NULL);
	str = malloc(sizeof(char) * _strlen(s) + 1);
	if (str == NULL)
		return (NULL);

	_strcpy(str, s);

	return (str);

}

/**
 * _strcpy - Copies a string from source to destination.
 * @dst: Destination string.
 * @src: Source string.
 *
 * Return: Pointer to the destination string.
 */

char *_strcpy(char *dst, char *src)
{
	int i;

	for (i = 0; i <= _strlen(src); i++)
		dst[i] = src[i];

	return (dst);
}

/**
 * _strcat - Concatenates two strings.
 * @dst: Destination string to which the source is appended.
 * @src: Source string to be appended.
 *
 * Return: Pointer to the concatenated string (dst).
 */

char *_strcat(char *dst, char *src)
{
	_strcpy(dst + _strlen(dst), src);
	return (dst);
}
