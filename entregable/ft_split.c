/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rartigue <rartigue@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 00:00:00 by rartigue          #+#    #+#             */
/*   Updated: 2026/06/06 10:45:00 by rartigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Resumen: Divide una string en varias subcadenas usando un separador. */

/* Cuenta cuántas palabras reales hay antes de reservar memoria. */
static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			count++;
			in_word = 1;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

/* Reserva y copia una sola palabra hasta el siguiente separador. */
static char	*dup_word(char const *s, char c)
{
	char	*word;
	int		len;
	int		i;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

/* Limpia lo ya reservado si algo falla a mitad del proceso. */
static void	free_result(char **result, int count)
{
	while (count > 0)
	{
		count--;
		free(result[count]);
	}
	free(result);
}

/* Recorre la cadena y va guardando cada palabra en el array final. */
static int	fill_result(char **result, char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			result[i] = dup_word(s, c);
			if (!result[i++])
				return (free_result(result, i - 1), 0);
			while (*s && *s != c)
				s++;
		}
	}
	result[i] = NULL;
	return (1);
}

/* Divide una string en varias subcadenas independientes. */
char	**ft_split(char const *s, char c)
{
	char	**result;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	if (!fill_result(result, s, c))
		return (NULL);
	return (result);
}

/*
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char **parts;

    parts = ft_split("uno,dos,tres", ',');
    if (!parts)
        return (1);
    printf("%s\n", parts[0]);
    printf("%s\n", parts[1]);
    printf("%s\n", parts[2]);
    free(parts[0]);
    free(parts[1]);
    free(parts[2]);
    free(parts);
    return (0);
}
*/
