/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rartigue <rartigue@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 15:45:20 by rartigue          #+#    #+#             */
/*   Updated: 2026/06/06 10:45:00 by rartigue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Resumen: Busca un byte dentro de un bloque de memoria. */

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	unsigned char		uc;

	str = (const unsigned char *)s;
	uc = (unsigned char)c;
	while (n > 0)
	{
		if (*str == uc)
			return ((void *)str);
		str++;
		n--;
	}
	return (NULL);
}

/*
#include <stdio.h>

int main(void)
{
    char *found;

    found = (char *)ft_memchr("abcde", 'c', 5);
    if (found)
        printf("%c\n", *found);
    return (0);
}
*/
