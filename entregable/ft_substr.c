/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rartigue <rartigue@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 00:00:00 by rartigue          #+#    #+#             */
/*   Updated: 2026/06/06 10:45:00 by rartigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Resumen: Extrae una subcadena nueva desde una posicion dada. */

/* Devuelve una string vacía para el caso en que start se salga. */
static char	*empty_str(void)
{
	char	*result;

	result = (char *)malloc(1);
	if (!result)
		return (NULL);
	result[0] = '\0';
	return (result);
}

/* Crea una subcadena desde start copiando como máximo len caracteres. */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (empty_str());
	if (len > s_len - start)
		len = s_len - start;
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

/*
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *sub;

    sub = ft_substr("abcdef", 2, 3);
    if (!sub)
        return (1);
    printf("%s\n", sub);
    free(sub);
    return (0);
}
*/
